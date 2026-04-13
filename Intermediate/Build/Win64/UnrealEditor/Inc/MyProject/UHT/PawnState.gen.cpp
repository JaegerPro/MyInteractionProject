// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MyProject/PawnState.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodePawnState() {}

// ********** Begin Cross Module References ********************************************************
MYPROJECT_API UEnum* Z_Construct_UEnum_MyProject_EPawnState();
MYPROJECT_API UEnum* Z_Construct_UEnum_MyProject_EPawnStateRelation();
MYPROJECT_API UFunction* Z_Construct_UDelegateFunction_MyProject_OnPawnStateEnter__DelegateSignature();
MYPROJECT_API UFunction* Z_Construct_UDelegateFunction_MyProject_OnPawnStateInterrupt__DelegateSignature();
MYPROJECT_API UFunction* Z_Construct_UDelegateFunction_MyProject_OnPawnStateLeave__DelegateSignature();
MYPROJECT_API UScriptStruct* Z_Construct_UScriptStruct_FSimpleBitMask();
MYPROJECT_API UScriptStruct* Z_Construct_UScriptStruct_FStateCounter();
UPackage* Z_Construct_UPackage__Script_MyProject();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum EPawnStateRelation ********************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EPawnStateRelation;
static UEnum* EPawnStateRelation_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EPawnStateRelation.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EPawnStateRelation.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_MyProject_EPawnStateRelation, (UObject*)Z_Construct_UPackage__Script_MyProject(), TEXT("EPawnStateRelation"));
	}
	return Z_Registration_Info_UEnum_EPawnStateRelation.OuterSingleton;
}
template<> MYPROJECT_NON_ATTRIBUTED_API UEnum* StaticEnum<EPawnStateRelation>()
{
	return EPawnStateRelation_StaticEnum();
}
struct Z_Construct_UEnum_MyProject_EPawnStateRelation_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "_Y.Comment", "// X -> Y (one-way)\n" },
		{ "_Y.Name", "EPawnStateRelation::_Y" },
		{ "_Y.ToolTip", "X -> Y (one-way)" },
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * State mutex relation types\n * X_ : X interrupts Y, but Y cannot interrupt X\n * _Y : Y interrupts X, but X cannot interrupt Y\n * XY : Both interrupt each other (bidirectional mutex)\n */" },
#endif
		{ "ModuleRelativePath", "PawnState.h" },
		{ "None.Name", "EPawnStateRelation::None" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "State mutex relation types\nX_ : X interrupts Y, but Y cannot interrupt X\n_Y : Y interrupts X, but X cannot interrupt Y\nXY : Both interrupt each other (bidirectional mutex)" },
#endif
		{ "X_.Name", "EPawnStateRelation::X_" },
		{ "XY.Comment", "// Y -> X (one-way)\n" },
		{ "XY.Name", "EPawnStateRelation::XY" },
		{ "XY.ToolTip", "Y -> X (one-way)" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EPawnStateRelation::None", (int64)EPawnStateRelation::None },
		{ "EPawnStateRelation::X_", (int64)EPawnStateRelation::X_ },
		{ "EPawnStateRelation::_Y", (int64)EPawnStateRelation::_Y },
		{ "EPawnStateRelation::XY", (int64)EPawnStateRelation::XY },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_MyProject_EPawnStateRelation_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_MyProject_EPawnStateRelation_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_MyProject,
	nullptr,
	"EPawnStateRelation",
	"EPawnStateRelation",
	Z_Construct_UEnum_MyProject_EPawnStateRelation_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_MyProject_EPawnStateRelation_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_MyProject_EPawnStateRelation_Statics::Enum_MetaDataParams), Z_Construct_UEnum_MyProject_EPawnStateRelation_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_MyProject_EPawnStateRelation()
{
	if (!Z_Registration_Info_UEnum_EPawnStateRelation.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EPawnStateRelation.InnerSingleton, Z_Construct_UEnum_MyProject_EPawnStateRelation_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EPawnStateRelation.InnerSingleton;
}
// ********** End Enum EPawnStateRelation **********************************************************

// ********** Begin Enum EPawnState ****************************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EPawnState;
static UEnum* EPawnState_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EPawnState.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EPawnState.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_MyProject_EPawnState, (UObject*)Z_Construct_UPackage__Script_MyProject(), TEXT("EPawnState"));
	}
	return Z_Registration_Info_UEnum_EPawnState.OuterSingleton;
}
template<> MYPROJECT_NON_ATTRIBUTED_API UEnum* StaticEnum<EPawnState>()
{
	return EPawnState_StaticEnum();
}
struct Z_Construct_UEnum_MyProject_EPawnState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "__MAX.Comment", "// Max count\n" },
		{ "__MAX.Name", "EPawnState::__MAX" },
		{ "__MAX.ToolTip", "Max count" },
		{ "BlueprintType", "true" },
		{ "CastingSkill.Name", "EPawnState::CastingSkill" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Pawn state enum - customize according to your game needs\n * Each state occupies 1 bit in the bitmask (max 64 states with uint64)\n */" },
#endif
		{ "Crouch.Name", "EPawnState::Crouch" },
		{ "Dead.Name", "EPawnState::Dead" },
		{ "DriveVehicle.Comment", "// Vehicle states\n" },
		{ "DriveVehicle.Name", "EPawnState::DriveVehicle" },
		{ "DriveVehicle.ToolTip", "Vehicle states" },
		{ "Dying.Comment", "// Status states\n" },
		{ "Dying.Name", "EPawnState::Dying" },
		{ "Dying.ToolTip", "Status states" },
		{ "GunADS.Name", "EPawnState::GunADS" },
		{ "GunFire.Comment", "// Action states\n" },
		{ "GunFire.Name", "EPawnState::GunFire" },
		{ "GunFire.ToolTip", "Action states" },
		{ "GunReload.Name", "EPawnState::GunReload" },
		{ "Interacting.Comment", "// Custom states can be added here\n" },
		{ "Interacting.Name", "EPawnState::Interacting" },
		{ "Interacting.ToolTip", "Custom states can be added here" },
		{ "InVehicle.Name", "EPawnState::InVehicle" },
		{ "Jump.Name", "EPawnState::Jump" },
		{ "MeleeAttack.Name", "EPawnState::MeleeAttack" },
		{ "ModuleRelativePath", "PawnState.h" },
		{ "Move.Comment", "// Movement states\n" },
		{ "Move.Name", "EPawnState::Move" },
		{ "Move.ToolTip", "Movement states" },
		{ "Prone.Name", "EPawnState::Prone" },
		{ "Sprint.Name", "EPawnState::Sprint" },
		{ "Stun.Name", "EPawnState::Stun" },
		{ "Swim.Name", "EPawnState::Swim" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Pawn state enum - customize according to your game needs\nEach state occupies 1 bit in the bitmask (max 64 states with uint64)" },
#endif
		{ "Vault.Name", "EPawnState::Vault" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EPawnState::Move", (int64)EPawnState::Move },
		{ "EPawnState::Sprint", (int64)EPawnState::Sprint },
		{ "EPawnState::Jump", (int64)EPawnState::Jump },
		{ "EPawnState::Crouch", (int64)EPawnState::Crouch },
		{ "EPawnState::Prone", (int64)EPawnState::Prone },
		{ "EPawnState::Swim", (int64)EPawnState::Swim },
		{ "EPawnState::Vault", (int64)EPawnState::Vault },
		{ "EPawnState::GunFire", (int64)EPawnState::GunFire },
		{ "EPawnState::GunReload", (int64)EPawnState::GunReload },
		{ "EPawnState::GunADS", (int64)EPawnState::GunADS },
		{ "EPawnState::MeleeAttack", (int64)EPawnState::MeleeAttack },
		{ "EPawnState::DriveVehicle", (int64)EPawnState::DriveVehicle },
		{ "EPawnState::InVehicle", (int64)EPawnState::InVehicle },
		{ "EPawnState::Dying", (int64)EPawnState::Dying },
		{ "EPawnState::Dead", (int64)EPawnState::Dead },
		{ "EPawnState::Stun", (int64)EPawnState::Stun },
		{ "EPawnState::Interacting", (int64)EPawnState::Interacting },
		{ "EPawnState::CastingSkill", (int64)EPawnState::CastingSkill },
		{ "EPawnState::__MAX", (int64)EPawnState::__MAX },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_MyProject_EPawnState_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_MyProject_EPawnState_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_MyProject,
	nullptr,
	"EPawnState",
	"EPawnState",
	Z_Construct_UEnum_MyProject_EPawnState_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_MyProject_EPawnState_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_MyProject_EPawnState_Statics::Enum_MetaDataParams), Z_Construct_UEnum_MyProject_EPawnState_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_MyProject_EPawnState()
{
	if (!Z_Registration_Info_UEnum_EPawnState.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EPawnState.InnerSingleton, Z_Construct_UEnum_MyProject_EPawnState_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EPawnState.InnerSingleton;
}
// ********** End Enum EPawnState ******************************************************************

// ********** Begin ScriptStruct FSimpleBitMask ****************************************************
struct Z_Construct_UScriptStruct_FSimpleBitMask_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FSimpleBitMask); }
	static inline consteval int16 GetStructAlignment() { return alignof(FSimpleBitMask); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Simple bitmask container for state storage\n * Uses uint64 to support up to 64 states\n */" },
#endif
		{ "ModuleRelativePath", "PawnState.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Simple bitmask container for state storage\nUses uint64 to support up to 64 states" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Bits_MetaData[] = {
		{ "ModuleRelativePath", "PawnState.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FSimpleBitMask constinit property declarations ********************
	static const UECodeGen_Private::FUInt64PropertyParams NewProp_Bits;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FSimpleBitMask constinit property declarations **********************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSimpleBitMask>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FSimpleBitMask_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FSimpleBitMask;
class UScriptStruct* FSimpleBitMask::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FSimpleBitMask.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FSimpleBitMask.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSimpleBitMask, (UObject*)Z_Construct_UPackage__Script_MyProject(), TEXT("SimpleBitMask"));
	}
	return Z_Registration_Info_UScriptStruct_FSimpleBitMask.OuterSingleton;
	}

// ********** Begin ScriptStruct FSimpleBitMask Property Definitions *******************************
const UECodeGen_Private::FUInt64PropertyParams Z_Construct_UScriptStruct_FSimpleBitMask_Statics::NewProp_Bits = { "Bits", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::UInt64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSimpleBitMask, Bits), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Bits_MetaData), NewProp_Bits_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSimpleBitMask_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSimpleBitMask_Statics::NewProp_Bits,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSimpleBitMask_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FSimpleBitMask Property Definitions *********************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSimpleBitMask_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_MyProject,
	nullptr,
	&NewStructOps,
	"SimpleBitMask",
	Z_Construct_UScriptStruct_FSimpleBitMask_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSimpleBitMask_Statics::PropPointers),
	sizeof(FSimpleBitMask),
	alignof(FSimpleBitMask),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSimpleBitMask_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FSimpleBitMask_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FSimpleBitMask()
{
	if (!Z_Registration_Info_UScriptStruct_FSimpleBitMask.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FSimpleBitMask.InnerSingleton, Z_Construct_UScriptStruct_FSimpleBitMask_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FSimpleBitMask.InnerSingleton);
}
// ********** End ScriptStruct FSimpleBitMask ******************************************************

// ********** Begin ScriptStruct FStateCounter *****************************************************
struct Z_Construct_UScriptStruct_FStateCounter_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FStateCounter); }
	static inline consteval int16 GetStructAlignment() { return alignof(FStateCounter); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * State counter for disabled states (reference counting)\n */" },
#endif
		{ "ModuleRelativePath", "PawnState.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "State counter for disabled states (reference counting)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_State_MetaData[] = {
		{ "ModuleRelativePath", "PawnState.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Counter_MetaData[] = {
		{ "ModuleRelativePath", "PawnState.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FStateCounter constinit property declarations *********************
	static const UECodeGen_Private::FBytePropertyParams NewProp_State_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_State;
	static const UECodeGen_Private::FInt8PropertyParams NewProp_Counter;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FStateCounter constinit property declarations ***********************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FStateCounter>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FStateCounter_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FStateCounter;
class UScriptStruct* FStateCounter::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FStateCounter.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FStateCounter.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FStateCounter, (UObject*)Z_Construct_UPackage__Script_MyProject(), TEXT("StateCounter"));
	}
	return Z_Registration_Info_UScriptStruct_FStateCounter.OuterSingleton;
	}

// ********** Begin ScriptStruct FStateCounter Property Definitions ********************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FStateCounter_Statics::NewProp_State_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FStateCounter_Statics::NewProp_State = { "State", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FStateCounter, State), Z_Construct_UEnum_MyProject_EPawnState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_State_MetaData), NewProp_State_MetaData) }; // 2115640282
const UECodeGen_Private::FInt8PropertyParams Z_Construct_UScriptStruct_FStateCounter_Statics::NewProp_Counter = { "Counter", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Int8, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FStateCounter, Counter), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Counter_MetaData), NewProp_Counter_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FStateCounter_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStateCounter_Statics::NewProp_State_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStateCounter_Statics::NewProp_State,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStateCounter_Statics::NewProp_Counter,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStateCounter_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FStateCounter Property Definitions **********************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FStateCounter_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_MyProject,
	nullptr,
	&NewStructOps,
	"StateCounter",
	Z_Construct_UScriptStruct_FStateCounter_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStateCounter_Statics::PropPointers),
	sizeof(FStateCounter),
	alignof(FStateCounter),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStateCounter_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FStateCounter_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FStateCounter()
{
	if (!Z_Registration_Info_UScriptStruct_FStateCounter.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FStateCounter.InnerSingleton, Z_Construct_UScriptStruct_FStateCounter_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FStateCounter.InnerSingleton);
}
// ********** End ScriptStruct FStateCounter *******************************************************

// ********** Begin Delegate FOnPawnStateEnter *****************************************************
struct Z_Construct_UDelegateFunction_MyProject_OnPawnStateEnter__DelegateSignature_Statics
{
	struct _Script_MyProject_eventOnPawnStateEnter_Parms
	{
		EPawnState State;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Delegate declarations\n */" },
#endif
		{ "ModuleRelativePath", "PawnState.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Delegate declarations" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Delegate FOnPawnStateEnter constinit property declarations *********************
	static const UECodeGen_Private::FBytePropertyParams NewProp_State_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_State;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FOnPawnStateEnter constinit property declarations ***********************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FOnPawnStateEnter Property Definitions ********************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UDelegateFunction_MyProject_OnPawnStateEnter__DelegateSignature_Statics::NewProp_State_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UDelegateFunction_MyProject_OnPawnStateEnter__DelegateSignature_Statics::NewProp_State = { "State", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_MyProject_eventOnPawnStateEnter_Parms, State), Z_Construct_UEnum_MyProject_EPawnState, METADATA_PARAMS(0, nullptr) }; // 2115640282
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_MyProject_OnPawnStateEnter__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_MyProject_OnPawnStateEnter__DelegateSignature_Statics::NewProp_State_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_MyProject_OnPawnStateEnter__DelegateSignature_Statics::NewProp_State,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_MyProject_OnPawnStateEnter__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FOnPawnStateEnter Property Definitions **********************************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_MyProject_OnPawnStateEnter__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_MyProject, nullptr, "OnPawnStateEnter__DelegateSignature", 	Z_Construct_UDelegateFunction_MyProject_OnPawnStateEnter__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_MyProject_OnPawnStateEnter__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_MyProject_OnPawnStateEnter__DelegateSignature_Statics::_Script_MyProject_eventOnPawnStateEnter_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_MyProject_OnPawnStateEnter__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_MyProject_OnPawnStateEnter__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_MyProject_OnPawnStateEnter__DelegateSignature_Statics::_Script_MyProject_eventOnPawnStateEnter_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_MyProject_OnPawnStateEnter__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_MyProject_OnPawnStateEnter__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnPawnStateEnter_DelegateWrapper(const FMulticastScriptDelegate& OnPawnStateEnter, EPawnState State)
{
	struct _Script_MyProject_eventOnPawnStateEnter_Parms
	{
		EPawnState State;
	};
	_Script_MyProject_eventOnPawnStateEnter_Parms Parms;
	Parms.State=State;
	OnPawnStateEnter.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnPawnStateEnter *******************************************************

// ********** Begin Delegate FOnPawnStateLeave *****************************************************
struct Z_Construct_UDelegateFunction_MyProject_OnPawnStateLeave__DelegateSignature_Statics
{
	struct _Script_MyProject_eventOnPawnStateLeave_Parms
	{
		EPawnState State;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "PawnState.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FOnPawnStateLeave constinit property declarations *********************
	static const UECodeGen_Private::FBytePropertyParams NewProp_State_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_State;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FOnPawnStateLeave constinit property declarations ***********************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FOnPawnStateLeave Property Definitions ********************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UDelegateFunction_MyProject_OnPawnStateLeave__DelegateSignature_Statics::NewProp_State_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UDelegateFunction_MyProject_OnPawnStateLeave__DelegateSignature_Statics::NewProp_State = { "State", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_MyProject_eventOnPawnStateLeave_Parms, State), Z_Construct_UEnum_MyProject_EPawnState, METADATA_PARAMS(0, nullptr) }; // 2115640282
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_MyProject_OnPawnStateLeave__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_MyProject_OnPawnStateLeave__DelegateSignature_Statics::NewProp_State_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_MyProject_OnPawnStateLeave__DelegateSignature_Statics::NewProp_State,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_MyProject_OnPawnStateLeave__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FOnPawnStateLeave Property Definitions **********************************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_MyProject_OnPawnStateLeave__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_MyProject, nullptr, "OnPawnStateLeave__DelegateSignature", 	Z_Construct_UDelegateFunction_MyProject_OnPawnStateLeave__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_MyProject_OnPawnStateLeave__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_MyProject_OnPawnStateLeave__DelegateSignature_Statics::_Script_MyProject_eventOnPawnStateLeave_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_MyProject_OnPawnStateLeave__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_MyProject_OnPawnStateLeave__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_MyProject_OnPawnStateLeave__DelegateSignature_Statics::_Script_MyProject_eventOnPawnStateLeave_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_MyProject_OnPawnStateLeave__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_MyProject_OnPawnStateLeave__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnPawnStateLeave_DelegateWrapper(const FMulticastScriptDelegate& OnPawnStateLeave, EPawnState State)
{
	struct _Script_MyProject_eventOnPawnStateLeave_Parms
	{
		EPawnState State;
	};
	_Script_MyProject_eventOnPawnStateLeave_Parms Parms;
	Parms.State=State;
	OnPawnStateLeave.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnPawnStateLeave *******************************************************

// ********** Begin Delegate FOnPawnStateInterrupt *************************************************
struct Z_Construct_UDelegateFunction_MyProject_OnPawnStateInterrupt__DelegateSignature_Statics
{
	struct _Script_MyProject_eventOnPawnStateInterrupt_Parms
	{
		EPawnState State;
		EPawnState InterruptedBy;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "PawnState.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FOnPawnStateInterrupt constinit property declarations *****************
	static const UECodeGen_Private::FBytePropertyParams NewProp_State_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_State;
	static const UECodeGen_Private::FBytePropertyParams NewProp_InterruptedBy_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_InterruptedBy;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FOnPawnStateInterrupt constinit property declarations *******************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FOnPawnStateInterrupt Property Definitions ****************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UDelegateFunction_MyProject_OnPawnStateInterrupt__DelegateSignature_Statics::NewProp_State_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UDelegateFunction_MyProject_OnPawnStateInterrupt__DelegateSignature_Statics::NewProp_State = { "State", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_MyProject_eventOnPawnStateInterrupt_Parms, State), Z_Construct_UEnum_MyProject_EPawnState, METADATA_PARAMS(0, nullptr) }; // 2115640282
const UECodeGen_Private::FBytePropertyParams Z_Construct_UDelegateFunction_MyProject_OnPawnStateInterrupt__DelegateSignature_Statics::NewProp_InterruptedBy_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UDelegateFunction_MyProject_OnPawnStateInterrupt__DelegateSignature_Statics::NewProp_InterruptedBy = { "InterruptedBy", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_MyProject_eventOnPawnStateInterrupt_Parms, InterruptedBy), Z_Construct_UEnum_MyProject_EPawnState, METADATA_PARAMS(0, nullptr) }; // 2115640282
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_MyProject_OnPawnStateInterrupt__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_MyProject_OnPawnStateInterrupt__DelegateSignature_Statics::NewProp_State_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_MyProject_OnPawnStateInterrupt__DelegateSignature_Statics::NewProp_State,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_MyProject_OnPawnStateInterrupt__DelegateSignature_Statics::NewProp_InterruptedBy_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_MyProject_OnPawnStateInterrupt__DelegateSignature_Statics::NewProp_InterruptedBy,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_MyProject_OnPawnStateInterrupt__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FOnPawnStateInterrupt Property Definitions ******************************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_MyProject_OnPawnStateInterrupt__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_MyProject, nullptr, "OnPawnStateInterrupt__DelegateSignature", 	Z_Construct_UDelegateFunction_MyProject_OnPawnStateInterrupt__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_MyProject_OnPawnStateInterrupt__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_MyProject_OnPawnStateInterrupt__DelegateSignature_Statics::_Script_MyProject_eventOnPawnStateInterrupt_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_MyProject_OnPawnStateInterrupt__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_MyProject_OnPawnStateInterrupt__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_MyProject_OnPawnStateInterrupt__DelegateSignature_Statics::_Script_MyProject_eventOnPawnStateInterrupt_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_MyProject_OnPawnStateInterrupt__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_MyProject_OnPawnStateInterrupt__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnPawnStateInterrupt_DelegateWrapper(const FMulticastScriptDelegate& OnPawnStateInterrupt, EPawnState State, EPawnState InterruptedBy)
{
	struct _Script_MyProject_eventOnPawnStateInterrupt_Parms
	{
		EPawnState State;
		EPawnState InterruptedBy;
	};
	_Script_MyProject_eventOnPawnStateInterrupt_Parms Parms;
	Parms.State=State;
	Parms.InterruptedBy=InterruptedBy;
	OnPawnStateInterrupt.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnPawnStateInterrupt ***************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UnrealProjects_MyProject_Source_MyProject_PawnState_h__Script_MyProject_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EPawnStateRelation_StaticEnum, TEXT("EPawnStateRelation"), &Z_Registration_Info_UEnum_EPawnStateRelation, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3503330507U) },
		{ EPawnState_StaticEnum, TEXT("EPawnState"), &Z_Registration_Info_UEnum_EPawnState, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2115640282U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FSimpleBitMask::StaticStruct, Z_Construct_UScriptStruct_FSimpleBitMask_Statics::NewStructOps, TEXT("SimpleBitMask"),&Z_Registration_Info_UScriptStruct_FSimpleBitMask, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSimpleBitMask), 1093497791U) },
		{ FStateCounter::StaticStruct, Z_Construct_UScriptStruct_FStateCounter_Statics::NewStructOps, TEXT("StateCounter"),&Z_Registration_Info_UScriptStruct_FStateCounter, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FStateCounter), 2607366446U) },
	};
}; // Z_CompiledInDeferFile_FID_UnrealProjects_MyProject_Source_MyProject_PawnState_h__Script_MyProject_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealProjects_MyProject_Source_MyProject_PawnState_h__Script_MyProject_621843514{
	TEXT("/Script/MyProject"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_UnrealProjects_MyProject_Source_MyProject_PawnState_h__Script_MyProject_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealProjects_MyProject_Source_MyProject_PawnState_h__Script_MyProject_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_UnrealProjects_MyProject_Source_MyProject_PawnState_h__Script_MyProject_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealProjects_MyProject_Source_MyProject_PawnState_h__Script_MyProject_Statics::EnumInfo),
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
