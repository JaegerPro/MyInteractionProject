// SimplePawnStateComponent.cpp

#include "PawnStateComponent.h"
#include "Net/UnrealNetwork.h"

UPawnStateComponent::UPawnStateComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
    SetIsReplicatedByDefault(true);
}

void UPawnStateComponent::BeginPlay()
{
    Super::BeginPlay();

    // Initialize from config if available
    if (StateConfig)
    {
        for (const auto& RelationConfig : StateConfig->StateRelations)
        {
            AddStateRelation(RelationConfig.StateA, RelationConfig.StateB, RelationConfig.Relation);
        }

        for (EPawnState State : StateConfig->DefaultDisabledStates)
        {
            SetStateDisabled(State, true);
        }
    }
}

void UPawnStateComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    DOREPLIFETIME_CONDITION(UPawnStateComponent, CurrentStates, COND_None);
}

// ==================== State Query ====================

bool UPawnStateComponent::HasState(EPawnState State) const
{
    return CurrentStates.Has(State);
}

bool UPawnStateComponent::HasAnyStates(const TArray<EPawnState>& States) const
{
    for (EPawnState State : States)
    {
        if (CurrentStates.Has(State))
        {
            return true;
        }
    }
    return false;
}

bool UPawnStateComponent::HasAllStates(const TArray<EPawnState>& States) const
{
    for (EPawnState State : States)
    {
        if (!CurrentStates.Has(State))
        {
            return false;
        }
    }
    return true;
}

bool UPawnStateComponent::OnlyHasStates(const TArray<EPawnState>& States) const
{
    uint64 TargetMask = 0;
    for (EPawnState State : States)
    {
        TargetMask |= (1ULL << (uint8)State);
    }
    return CurrentStates.Bits == TargetMask;
}

TArray<EPawnState> UPawnStateComponent::GetActiveStates() const
{
    return CurrentStates.GetActiveStates();
}

// ==================== State Modification ====================

bool UPawnStateComponent::CanEnterState(EPawnState State) const
{
    // Check if already in this state
    if (HasState(State))
    {
        return true;
    }

    // Check if disabled
    if (IsStateDisabled(State))
    {
        return false;
    }

    // Check mutex relations
    for (int32 i = 0; i < (int32)EPawnState::__MAX; ++i)
    {
        EPawnState OtherState = (EPawnState)i;
        if (CurrentStates.Has(OtherState))
        {
            EPawnStateRelation Relation = GetRelation(State, OtherState);

            // _Y means OtherState(Y) interrupts State(X), so State cannot enter
            // XY means bidirectional mutex
            if (Relation == EPawnStateRelation::_Y || Relation == EPawnStateRelation::XY)
            {
                return false;
            }
        }
    }

    return true;
}

bool UPawnStateComponent::EnterState(EPawnState State)
{
    if (!CanEnterState(State))
    {
        return false;
    }

    // Already in state
    if (HasState(State))
    {
        return true;
    }

    // Find and interrupt states
    TArray<EPawnState> StatesToInterrupt;
    GetStatesToInterrupt(State, StatesToInterrupt);

    for (EPawnState StateToInterrupt : StatesToInterrupt)
    {
        if (CurrentStates.Has(StateToInterrupt))
        {
            CurrentStates.Remove(StateToInterrupt);
            OnStateInterrupt.Broadcast(StateToInterrupt, State);
            OnStateLeave.Broadcast(StateToInterrupt);
        }
    }

    // Add new state
    CurrentStates.Add(State);
    OnStateEnter.Broadcast(State);

    return true;
}

bool UPawnStateComponent::LeaveState(EPawnState State)
{
    if (!CurrentStates.Has(State))
    {
        return false;
    }

    CurrentStates.Remove(State);
    OnStateLeave.Broadcast(State);

    return true;
}

void UPawnStateComponent::LeaveAllStates()
{
    TArray<EPawnState> ActiveStates = GetActiveStates();
    for (EPawnState State : ActiveStates)
    {
        CurrentStates.Remove(State);
        OnStateLeave.Broadcast(State);
    }
}

// ==================== State Disable ====================

void UPawnStateComponent::SetStateDisabled(EPawnState State, bool bDisabled)
{
    int32 FoundIndex = INDEX_NONE;

    for (int32 i = 0; i < DisabledStates.Num(); ++i)
    {
        if (DisabledStates[i].State == State)
        {
            FoundIndex = i;
            break;
        }
    }

    if (bDisabled)
    {
        if (FoundIndex == INDEX_NONE)
        {
            FStateCounter NewCounter(State);
            NewCounter.Counter = 1;
            DisabledStates.Add(NewCounter);
        }
        else
        {
            DisabledStates[FoundIndex].Counter++;
        }
    }
    else
    {
        if (FoundIndex != INDEX_NONE)
        {
            DisabledStates[FoundIndex].Counter--;

            if (DisabledStates[FoundIndex].Counter <= 0)
            {
                DisabledStates.RemoveAtSwap(FoundIndex);
            }
        }
    }
}

bool UPawnStateComponent::IsStateDisabled(EPawnState State) const
{
    for (const FStateCounter& Counter : DisabledStates)
    {
        if (Counter.State == State)
        {
            return Counter.Counter > 0;
        }
    }
    return false;
}

void UPawnStateComponent::ResetStateDisabled(EPawnState State)
{
    for (int32 i = DisabledStates.Num() - 1; i >= 0; --i)
    {
        if (DisabledStates[i].State == State)
        {
            DisabledStates.RemoveAtSwap(i);
            break;
        }
    }
}

// ==================== Configuration ====================

void UPawnStateComponent::SetStateConfig(USimpleStateConfig* InConfig)
{
    StateConfig = InConfig;
}

void UPawnStateComponent::AddStateRelation(EPawnState StateA, EPawnState StateB, EPawnStateRelation Relation)
{
    // Store bidirectional mapping for quick lookup
    StateRelations.Add(MakeRelationKey(StateA, StateB), Relation);
}

void UPawnStateComponent::ClearStateRelations()
{
    StateRelations.Empty();
}

// ==================== Helper Functions ====================

EPawnStateRelation UPawnStateComponent::GetRelation(EPawnState StateA, EPawnState StateB) const
{
    uint32 Key = MakeRelationKey(StateA, StateB);

    if (const EPawnStateRelation* Found = StateRelations.Find(Key))
    {
        return *Found;
    }

    // Check reverse key and flip direction
    uint32 ReverseKey = MakeRelationKey(StateB, StateA);
    if (const EPawnStateRelation* ReverseFound = StateRelations.Find(ReverseKey))
    {
        EPawnStateRelation RevRelation = *ReverseFound;
        if (RevRelation == EPawnStateRelation::X_)
        {
            // Reverse: B interrupts A -> From A's view: A cannot interrupt B
            return EPawnStateRelation::_Y;
        }
        else if (RevRelation == EPawnStateRelation::_Y)
        {
            // Reverse: A interrupts B -> From A's view: A can interrupt B
            return EPawnStateRelation::X_;
        }
        // XY stays XY
        return RevRelation;
    }

    // No relation defined = states can coexist
    return EPawnStateRelation::None;
}
void UPawnStateComponent::GetStatesToInterrupt(EPawnState StateToEnter, TArray<EPawnState>& OutStatesToInterrupt) const
{
    OutStatesToInterrupt.Empty();

    for (int32 i = 0; i < (int32)EPawnState::__MAX; ++i)
    {
        EPawnState OtherState = (EPawnState)i;

        if (CurrentStates.Has(OtherState))
        {
            EPawnStateRelation Relation = GetRelation(StateToEnter, OtherState);

            // X_ or XY means StateToEnter(X) interrupts OtherState(Y)
            if (Relation == EPawnStateRelation::X_ || Relation == EPawnStateRelation::XY)
            {
                OutStatesToInterrupt.Add(OtherState);
            }
        }
    }
}

void UPawnStateComponent::OnRep_CurrentStates(FSimpleBitMask OldStates)
{
    // Detect changes and broadcast
    uint64 NewBits = CurrentStates.Bits;
    uint64 OldBits = OldStates.Bits;
    uint64 Changed = OldBits ^ NewBits;

    for (int32 i = 0; i < (int32)EPawnState::__MAX; ++i)
    {
        if (Changed & (1ULL << i))
        {
            EPawnState State = (EPawnState)i;

            if (NewBits & (1ULL << i))
            {
                OnStateEnter.Broadcast(State);
            }
            else
            {
                OnStateLeave.Broadcast(State);
            }
        }
    }
}

// ==================== Debug ====================

FString UPawnStateComponent::GetStateDebugString() const
{
    FString Result = TEXT("Active States: ");

    TArray<EPawnState> States = GetActiveStates();
    for (int32 i = 0; i < States.Num(); ++i)
    {
        Result += PawnStateToString(States[i]);
        if (i < States.Num() - 1)
        {
            Result += TEXT(", ");
        }
    }

    if (DisabledStates.Num() > 0)
    {
        Result += TEXT(" | Disabled: ");
        for (int32 i = 0; i < DisabledStates.Num(); ++i)
        {
            Result += FString::Printf(TEXT("%s(%d)"), *PawnStateToString(DisabledStates[i].State), DisabledStates[i].Counter);
            if (i < DisabledStates.Num() - 1)
            {
                Result += TEXT(", ");
            }
        }
    }

    return Result;
}
