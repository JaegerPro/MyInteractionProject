// SimplePawnStateComponent.h - State Management Component

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PawnState.h"
#include "PawnStateComponent.generated.h"

/**
 * State relation configuration (editable in Blueprint/DataAsset)
 */
USTRUCT(BlueprintType)
struct FStateRelationConfig
{
    GENERATED_BODY()

    // State X
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EPawnState StateA = EPawnState::__MAX;

    // State Y
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EPawnState StateB = EPawnState::__MAX;

    // Relation type
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EPawnStateRelation Relation = EPawnStateRelation::XY;
};

/**
 * Configuration asset for state relations
 */
UCLASS(BlueprintType)
class USimpleStateConfig : public UDataAsset
{
    GENERATED_BODY()

public:
    // State mutex relations
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State Relations")
    TArray<FStateRelationConfig> StateRelations;

    // States that are disabled by default
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default")
    TArray<EPawnState> DefaultDisabledStates;
};

/**
 * Main state management component
 * Attach to any Character or Actor that needs state management
 */
UCLASS(ClassGroup = "Game", meta = (BlueprintSpawnableComponent))
class UPawnStateComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UPawnStateComponent();

    // ==================== State Query ====================

    // Check if state is active
    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "State")
    bool HasState(EPawnState State) const;

    // Check if any of the given states is active
    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "State")
    bool HasAnyStates(const TArray<EPawnState>& States) const;

    // Check if all given states are active
    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "State")
    bool HasAllStates(const TArray<EPawnState>& States) const;

    // Check if only these states are active
    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "State")
    bool OnlyHasStates(const TArray<EPawnState>& States) const;

    // Get all active states
    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "State")
    TArray<EPawnState> GetActiveStates() const;

    // Get raw bitmask
    UFUNCTION()
    uint64 GetCurrentStatesBits() const { return CurrentStates.Bits; }

    // ==================== State Modification ====================
    // NOTE: These functions are server-authority only.
    // Clients must use RPCs to request state changes from the server.

    // Check if state can be entered (mutex check)
    UFUNCTION(BlueprintCallable, Category = "State")
    bool CanEnterState(EPawnState State) const;

    // Enter a state (returns true if successful) - Server only
    UFUNCTION(BlueprintCallable, Category = "State")
    bool EnterState(EPawnState State);

    // Leave a state (returns true if successful) - Server only
    UFUNCTION(BlueprintCallable, Category = "State")
    bool LeaveState(EPawnState State);

    // Leave all states - Server only
    UFUNCTION(BlueprintCallable, Category = "State")
    void LeaveAllStates();

    // ==================== State Disable ====================
    // NOTE: These functions are server-authority only.

    // Disable a state (prevents entering) - Server only
    UFUNCTION(BlueprintCallable, Category = "State")
    void SetStateDisabled(EPawnState State, bool bDisabled);

    // Check if state is disabled
    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "State")
    bool IsStateDisabled(EPawnState State) const;

    // Reset disabled state - Server only
    UFUNCTION(BlueprintCallable, Category = "State")
    void ResetStateDisabled(EPawnState State);

    // ==================== Configuration ====================
    // NOTE: These functions are server-authority only.

    // Set state configuration - Server only
    UFUNCTION(BlueprintCallable, Category = "State")
    void SetStateConfig(USimpleStateConfig* InConfig);

    // Add a state relation - Server only
    UFUNCTION(BlueprintCallable, Category = "State")
    void AddStateRelation(EPawnState StateA, EPawnState StateB, EPawnStateRelation Relation);

    // Clear all state relations - Server only
    UFUNCTION(BlueprintCallable, Category = "State")
    void ClearStateRelations();

    // ==================== Delegates ====================

    // Called when a state is entered
    UPROPERTY(BlueprintAssignable, Category = "State")
    FOnPawnStateEnter OnStateEnter;

    // Called when a state is left
    UPROPERTY(BlueprintAssignable, Category = "State")
    FOnPawnStateLeave OnStateLeave;

    // Called when a state is interrupted by another
    UPROPERTY(BlueprintAssignable, Category = "State")
    FOnPawnStateInterrupt OnStateInterrupt;

    // ==================== Debug ====================

    UFUNCTION(BlueprintCallable, Category = "State|Debug")
    FString GetStateDebugString() const;

protected:
    virtual void BeginPlay() override;

    // Current active states
    UPROPERTY(ReplicatedUsing = OnRep_CurrentStates)
    FSimpleBitMask CurrentStates;

    // Disabled states with reference counting
    UPROPERTY()
    TArray<FStateCounter> DisabledStates;

    // State configuration
    UPROPERTY(EditAnywhere, Category = "State")
    USimpleStateConfig* StateConfig = nullptr;

    // State relation matrix: [StateA][StateB] = Relation
    // Stored in a flattened map for quick lookup
    UPROPERTY()
    TMap<uint32, EPawnStateRelation> StateRelations;

    // Helper functions
    FORCEINLINE uint32 MakeRelationKey(EPawnState A, EPawnState B) const
    {
        return ((uint32)A << 8) | (uint32)B;
    }

    EPawnStateRelation GetRelation(EPawnState StateA, EPawnState StateB) const;

    void GetStatesToInterrupt(EPawnState StateToEnter, TArray<EPawnState>& OutStatesToInterrupt) const;

    UFUNCTION()
    void OnRep_CurrentStates(FSimpleBitMask OldStates);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
