// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Class.h"
#include "PawnState.generated.h"

// SimplePawnState.h - Simplified Pawn State System
// A lightweight state management system with mutex relations

/**
 * State mutex relation types
 * X_ : X interrupts Y, but Y cannot interrupt X
 * _Y : Y interrupts X, but X cannot interrupt Y
 * XY : Both interrupt each other (bidirectional mutex)
 */
UENUM(BlueprintType)
enum class EPawnStateRelation : uint8
{
    None = 0,
    X_ = 1,    // X -> Y (one-way)
    _Y = 2,    // Y -> X (one-way)
    XY = 3     // X <-> Y (bidirectional)
};

/**
 * Pawn state enum - customize according to your game needs
 * Each state occupies 1 bit in the bitmask (max 64 states with uint64)
 */
UENUM(BlueprintType)
enum class EPawnState : uint8
{
    // Movement states
    Move = 0,
    Sprint = 1,
    Jump = 2,
    Crouch = 3,
    Prone = 4,
    Swim = 5,
    Vault = 6,

    // Action states
    GunFire = 10,
    GunReload = 11,
    GunADS = 12,
    MeleeAttack = 13,

    // Vehicle states
    DriveVehicle = 20,
    InVehicle = 21,

    // Status states
    Dying = 30,
    Dead = 31,
    Stun = 32,

    // Custom states can be added here
    Interacting = 40,
    CastingSkill = 41,

    // Max count
    __MAX = 54
};

/**
 * Simple bitmask container for state storage
 * Uses uint64 to support up to 64 states
 */
USTRUCT(BlueprintType)
struct FSimpleBitMask
{
    GENERATED_BODY()

    UPROPERTY()
    uint64 Bits = 0;

    FORCEINLINE bool Has(EPawnState State) const
    {
        return (Bits & (1ULL << (uint8)State)) != 0;
    }

    FORCEINLINE void Add(EPawnState State)
    {
        Bits |= (1ULL << (uint8)State);
    }

    FORCEINLINE void Remove(EPawnState State)
    {
        Bits &= ~(1ULL << (uint8)State);
    }

    FORCEINLINE void Clear()
    {
        Bits = 0;
    }

    FORCEINLINE bool IsEmpty() const
    {
        return Bits == 0;
    }

    FORCEINLINE uint64 GetBits() const { return Bits; }

    // Get all active states as array
    TArray<EPawnState> GetActiveStates() const
    {
        TArray<EPawnState> States;
        for (int32 i = 0; i < (int32)EPawnState::__MAX; ++i)
        {
            if (Bits & (1ULL << i))
            {
                States.Add((EPawnState)i);
            }
        }
        return States;
    }
};

/**
 * State counter for disabled states (reference counting)
 */
USTRUCT()
struct FStateCounter
{
    GENERATED_BODY()

    UPROPERTY()
    EPawnState State = EPawnState::__MAX;

    UPROPERTY()
    int8 Counter = 0;

    FStateCounter() {}
    FStateCounter(EPawnState InState) : State(InState), Counter(0) {}
};

/**
 * Delegate declarations
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPawnStateEnter, EPawnState, State);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPawnStateLeave, EPawnState, State);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPawnStateInterrupt, EPawnState, State, EPawnState, InterruptedBy);

/**
 * Convert state to string (for debugging)
 */
inline FString PawnStateToString(EPawnState State)
{
    const UEnum* EnumPtr = StaticEnum<EPawnState>();
    return EnumPtr ? EnumPtr->GetNameStringByValue((int64)State) : FString::Printf(TEXT("State_%d"), (int32)State);
}
