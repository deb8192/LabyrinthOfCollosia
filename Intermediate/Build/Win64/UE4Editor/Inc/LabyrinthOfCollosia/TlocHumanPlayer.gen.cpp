// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LabyrinthOfCollosia/Public/Characters/TlocHumanPlayer.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTlocHumanPlayer() {}
// Cross Module References
	LABYRINTHOFCOLLOSIA_API UClass* Z_Construct_UClass_ATlocHumanPlayer_NoRegister();
	LABYRINTHOFCOLLOSIA_API UClass* Z_Construct_UClass_ATlocHumanPlayer();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	UPackage* Z_Construct_UPackage__Script_LabyrinthOfCollosia();
	LABYRINTHOFCOLLOSIA_API UFunction* Z_Construct_UFunction_ATlocHumanPlayer_moveHorizontally();
	LABYRINTHOFCOLLOSIA_API UFunction* Z_Construct_UFunction_ATlocHumanPlayer_moveVertically();
	LABYRINTHOFCOLLOSIA_API UFunction* Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorHit();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
	ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	LABYRINTHOFCOLLOSIA_API UFunction* Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorOverlap();
	LABYRINTHOFCOLLOSIA_API UFunction* Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorStopHit();
	LABYRINTHOFCOLLOSIA_API UFunction* Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorStopOverlap();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	LABYRINTHOFCOLLOSIA_API UClass* Z_Construct_UClass_UTlocHud_NoRegister();
	LABYRINTHOFCOLLOSIA_API UClass* Z_Construct_UClass_UTlocIngameMenu_NoRegister();
// End Cross Module References
	void ATlocHumanPlayer::StaticRegisterNativesATlocHumanPlayer()
	{
		UClass* Class = ATlocHumanPlayer::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "moveHorizontally", &ATlocHumanPlayer::execmoveHorizontally },
			{ "moveVertically", &ATlocHumanPlayer::execmoveVertically },
			{ "OnHumanActorHit", &ATlocHumanPlayer::execOnHumanActorHit },
			{ "OnHumanActorOverlap", &ATlocHumanPlayer::execOnHumanActorOverlap },
			{ "OnHumanActorStopHit", &ATlocHumanPlayer::execOnHumanActorStopHit },
			{ "OnHumanActorStopOverlap", &ATlocHumanPlayer::execOnHumanActorStopOverlap },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ATlocHumanPlayer_moveHorizontally_Statics
	{
		struct TlocHumanPlayer_eventmoveHorizontally_Parms
		{
			float value;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_value;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ATlocHumanPlayer_moveHorizontally_Statics::NewProp_value = { "value", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(TlocHumanPlayer_eventmoveHorizontally_Parms, value), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATlocHumanPlayer_moveHorizontally_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATlocHumanPlayer_moveHorizontally_Statics::NewProp_value,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATlocHumanPlayer_moveHorizontally_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Characters/TlocHumanPlayer.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ATlocHumanPlayer_moveHorizontally_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATlocHumanPlayer, nullptr, "moveHorizontally", nullptr, nullptr, sizeof(TlocHumanPlayer_eventmoveHorizontally_Parms), Z_Construct_UFunction_ATlocHumanPlayer_moveHorizontally_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ATlocHumanPlayer_moveHorizontally_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATlocHumanPlayer_moveHorizontally_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ATlocHumanPlayer_moveHorizontally_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATlocHumanPlayer_moveHorizontally()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ATlocHumanPlayer_moveHorizontally_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATlocHumanPlayer_moveVertically_Statics
	{
		struct TlocHumanPlayer_eventmoveVertically_Parms
		{
			float value;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_value;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ATlocHumanPlayer_moveVertically_Statics::NewProp_value = { "value", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(TlocHumanPlayer_eventmoveVertically_Parms, value), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATlocHumanPlayer_moveVertically_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATlocHumanPlayer_moveVertically_Statics::NewProp_value,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATlocHumanPlayer_moveVertically_Statics::Function_MetaDataParams[] = {
		{ "Comment", "//Functions to move and rotate character\n" },
		{ "ModuleRelativePath", "Public/Characters/TlocHumanPlayer.h" },
		{ "ToolTip", "Functions to move and rotate character" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ATlocHumanPlayer_moveVertically_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATlocHumanPlayer, nullptr, "moveVertically", nullptr, nullptr, sizeof(TlocHumanPlayer_eventmoveVertically_Parms), Z_Construct_UFunction_ATlocHumanPlayer_moveVertically_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ATlocHumanPlayer_moveVertically_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATlocHumanPlayer_moveVertically_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ATlocHumanPlayer_moveVertically_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATlocHumanPlayer_moveVertically()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ATlocHumanPlayer_moveVertically_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorHit_Statics
	{
		struct TlocHumanPlayer_eventOnHumanActorHit_Parms
		{
			UPrimitiveComponent* _weaponMesh;
			AActor* _other;
			UPrimitiveComponent* _otherComp;
			int32 OtherBodyIndex;
			bool bFromSweep;
			FHitResult Hit;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Hit_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Hit;
		static void NewProp_bFromSweep_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bFromSweep;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_OtherBodyIndex;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp__otherComp_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp__otherComp;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp__other;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp__weaponMesh_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp__weaponMesh;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorHit_Statics::NewProp_Hit_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorHit_Statics::NewProp_Hit = { "Hit", nullptr, (EPropertyFlags)0x0010008008000182, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(TlocHumanPlayer_eventOnHumanActorHit_Parms, Hit), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorHit_Statics::NewProp_Hit_MetaData, ARRAY_COUNT(Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorHit_Statics::NewProp_Hit_MetaData)) };
	void Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorHit_Statics::NewProp_bFromSweep_SetBit(void* Obj)
	{
		((TlocHumanPlayer_eventOnHumanActorHit_Parms*)Obj)->bFromSweep = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorHit_Statics::NewProp_bFromSweep = { "bFromSweep", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(TlocHumanPlayer_eventOnHumanActorHit_Parms), &Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorHit_Statics::NewProp_bFromSweep_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorHit_Statics::NewProp_OtherBodyIndex = { "OtherBodyIndex", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(TlocHumanPlayer_eventOnHumanActorHit_Parms, OtherBodyIndex), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorHit_Statics::NewProp__otherComp_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorHit_Statics::NewProp__otherComp = { "_otherComp", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(TlocHumanPlayer_eventOnHumanActorHit_Parms, _otherComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorHit_Statics::NewProp__otherComp_MetaData, ARRAY_COUNT(Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorHit_Statics::NewProp__otherComp_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorHit_Statics::NewProp__other = { "_other", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(TlocHumanPlayer_eventOnHumanActorHit_Parms, _other), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorHit_Statics::NewProp__weaponMesh_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorHit_Statics::NewProp__weaponMesh = { "_weaponMesh", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(TlocHumanPlayer_eventOnHumanActorHit_Parms, _weaponMesh), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorHit_Statics::NewProp__weaponMesh_MetaData, ARRAY_COUNT(Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorHit_Statics::NewProp__weaponMesh_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorHit_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorHit_Statics::NewProp_Hit,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorHit_Statics::NewProp_bFromSweep,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorHit_Statics::NewProp_OtherBodyIndex,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorHit_Statics::NewProp__otherComp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorHit_Statics::NewProp__other,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorHit_Statics::NewProp__weaponMesh,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorHit_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Characters/TlocHumanPlayer.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorHit_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATlocHumanPlayer, nullptr, "OnHumanActorHit", nullptr, nullptr, sizeof(TlocHumanPlayer_eventOnHumanActorHit_Parms), Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorHit_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorHit_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorHit_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorHit_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorHit()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorHit_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorOverlap_Statics
	{
		struct TlocHumanPlayer_eventOnHumanActorOverlap_Parms
		{
			AActor* _player;
			AActor* _obj;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp__obj;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp__player;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorOverlap_Statics::NewProp__obj = { "_obj", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(TlocHumanPlayer_eventOnHumanActorOverlap_Parms, _obj), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorOverlap_Statics::NewProp__player = { "_player", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(TlocHumanPlayer_eventOnHumanActorOverlap_Parms, _player), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorOverlap_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorOverlap_Statics::NewProp__obj,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorOverlap_Statics::NewProp__player,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorOverlap_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Characters/TlocHumanPlayer.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorOverlap_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATlocHumanPlayer, nullptr, "OnHumanActorOverlap", nullptr, nullptr, sizeof(TlocHumanPlayer_eventOnHumanActorOverlap_Parms), Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorOverlap_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorOverlap_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorOverlap_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorOverlap_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorOverlap()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorOverlap_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorStopHit_Statics
	{
		struct TlocHumanPlayer_eventOnHumanActorStopHit_Parms
		{
			UPrimitiveComponent* _weaponMesh;
			AActor* Other;
			UPrimitiveComponent* OtherComp;
			int32 OtherBodyIndex;
		};
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_OtherBodyIndex;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OtherComp_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OtherComp;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Other;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp__weaponMesh_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp__weaponMesh;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorStopHit_Statics::NewProp_OtherBodyIndex = { "OtherBodyIndex", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(TlocHumanPlayer_eventOnHumanActorStopHit_Parms, OtherBodyIndex), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorStopHit_Statics::NewProp_OtherComp_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorStopHit_Statics::NewProp_OtherComp = { "OtherComp", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(TlocHumanPlayer_eventOnHumanActorStopHit_Parms, OtherComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorStopHit_Statics::NewProp_OtherComp_MetaData, ARRAY_COUNT(Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorStopHit_Statics::NewProp_OtherComp_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorStopHit_Statics::NewProp_Other = { "Other", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(TlocHumanPlayer_eventOnHumanActorStopHit_Parms, Other), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorStopHit_Statics::NewProp__weaponMesh_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorStopHit_Statics::NewProp__weaponMesh = { "_weaponMesh", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(TlocHumanPlayer_eventOnHumanActorStopHit_Parms, _weaponMesh), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorStopHit_Statics::NewProp__weaponMesh_MetaData, ARRAY_COUNT(Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorStopHit_Statics::NewProp__weaponMesh_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorStopHit_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorStopHit_Statics::NewProp_OtherBodyIndex,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorStopHit_Statics::NewProp_OtherComp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorStopHit_Statics::NewProp_Other,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorStopHit_Statics::NewProp__weaponMesh,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorStopHit_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Characters/TlocHumanPlayer.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorStopHit_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATlocHumanPlayer, nullptr, "OnHumanActorStopHit", nullptr, nullptr, sizeof(TlocHumanPlayer_eventOnHumanActorStopHit_Parms), Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorStopHit_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorStopHit_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorStopHit_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorStopHit_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorStopHit()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorStopHit_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorStopOverlap_Statics
	{
		struct TlocHumanPlayer_eventOnHumanActorStopOverlap_Parms
		{
			AActor* _player;
			AActor* _obj;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp__obj;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp__player;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorStopOverlap_Statics::NewProp__obj = { "_obj", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(TlocHumanPlayer_eventOnHumanActorStopOverlap_Parms, _obj), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorStopOverlap_Statics::NewProp__player = { "_player", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(TlocHumanPlayer_eventOnHumanActorStopOverlap_Parms, _player), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorStopOverlap_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorStopOverlap_Statics::NewProp__obj,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorStopOverlap_Statics::NewProp__player,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorStopOverlap_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Characters/TlocHumanPlayer.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorStopOverlap_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATlocHumanPlayer, nullptr, "OnHumanActorStopOverlap", nullptr, nullptr, sizeof(TlocHumanPlayer_eventOnHumanActorStopOverlap_Parms), Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorStopOverlap_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorStopOverlap_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorStopOverlap_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorStopOverlap_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorStopOverlap()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorStopOverlap_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ATlocHumanPlayer_NoRegister()
	{
		return ATlocHumanPlayer::StaticClass();
	}
	struct Z_Construct_UClass_ATlocHumanPlayer_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp__playerCameraSpringArm_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp__playerCameraSpringArm;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp__playerCamera_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp__playerCamera;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PlayerHud_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_PlayerHud;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_IngameMenu_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_IngameMenu;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ATlocHumanPlayer_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_LabyrinthOfCollosia,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ATlocHumanPlayer_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ATlocHumanPlayer_moveHorizontally, "moveHorizontally" }, // 2004839724
		{ &Z_Construct_UFunction_ATlocHumanPlayer_moveVertically, "moveVertically" }, // 1305881957
		{ &Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorHit, "OnHumanActorHit" }, // 3439251746
		{ &Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorOverlap, "OnHumanActorOverlap" }, // 3407071836
		{ &Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorStopHit, "OnHumanActorStopHit" }, // 1544873263
		{ &Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorStopOverlap, "OnHumanActorStopOverlap" }, // 2814686245
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATlocHumanPlayer_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Characters/TlocHumanPlayer.h" },
		{ "ModuleRelativePath", "Public/Characters/TlocHumanPlayer.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATlocHumanPlayer_Statics::NewProp__playerCameraSpringArm_MetaData[] = {
		{ "Category", "TlocHumanPlayer" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Characters/TlocHumanPlayer.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATlocHumanPlayer_Statics::NewProp__playerCameraSpringArm = { "_playerCameraSpringArm", nullptr, (EPropertyFlags)0x00400000000a0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATlocHumanPlayer, _playerCameraSpringArm), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ATlocHumanPlayer_Statics::NewProp__playerCameraSpringArm_MetaData, ARRAY_COUNT(Z_Construct_UClass_ATlocHumanPlayer_Statics::NewProp__playerCameraSpringArm_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATlocHumanPlayer_Statics::NewProp__playerCamera_MetaData[] = {
		{ "Category", "TlocHumanPlayer" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Characters/TlocHumanPlayer.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATlocHumanPlayer_Statics::NewProp__playerCamera = { "_playerCamera", nullptr, (EPropertyFlags)0x00400000000a0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATlocHumanPlayer, _playerCamera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ATlocHumanPlayer_Statics::NewProp__playerCamera_MetaData, ARRAY_COUNT(Z_Construct_UClass_ATlocHumanPlayer_Statics::NewProp__playerCamera_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATlocHumanPlayer_Statics::NewProp_PlayerHud_MetaData[] = {
		{ "Category", "UI" },
		{ "Comment", "// Ingame HUD object\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Characters/TlocHumanPlayer.h" },
		{ "ToolTip", "Ingame HUD object" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATlocHumanPlayer_Statics::NewProp_PlayerHud = { "PlayerHud", nullptr, (EPropertyFlags)0x002008000008000c, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATlocHumanPlayer, PlayerHud), Z_Construct_UClass_UTlocHud_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ATlocHumanPlayer_Statics::NewProp_PlayerHud_MetaData, ARRAY_COUNT(Z_Construct_UClass_ATlocHumanPlayer_Statics::NewProp_PlayerHud_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATlocHumanPlayer_Statics::NewProp_IngameMenu_MetaData[] = {
		{ "Category", "UI" },
		{ "Comment", "// Ingame menu object\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Characters/TlocHumanPlayer.h" },
		{ "ToolTip", "Ingame menu object" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATlocHumanPlayer_Statics::NewProp_IngameMenu = { "IngameMenu", nullptr, (EPropertyFlags)0x002008000008000c, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATlocHumanPlayer, IngameMenu), Z_Construct_UClass_UTlocIngameMenu_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ATlocHumanPlayer_Statics::NewProp_IngameMenu_MetaData, ARRAY_COUNT(Z_Construct_UClass_ATlocHumanPlayer_Statics::NewProp_IngameMenu_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ATlocHumanPlayer_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATlocHumanPlayer_Statics::NewProp__playerCameraSpringArm,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATlocHumanPlayer_Statics::NewProp__playerCamera,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATlocHumanPlayer_Statics::NewProp_PlayerHud,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATlocHumanPlayer_Statics::NewProp_IngameMenu,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ATlocHumanPlayer_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATlocHumanPlayer>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ATlocHumanPlayer_Statics::ClassParams = {
		&ATlocHumanPlayer::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ATlocHumanPlayer_Statics::PropPointers,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		ARRAY_COUNT(FuncInfo),
		ARRAY_COUNT(Z_Construct_UClass_ATlocHumanPlayer_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(Z_Construct_UClass_ATlocHumanPlayer_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_ATlocHumanPlayer_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ATlocHumanPlayer()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ATlocHumanPlayer_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ATlocHumanPlayer, 536603310);
	template<> LABYRINTHOFCOLLOSIA_API UClass* StaticClass<ATlocHumanPlayer>()
	{
		return ATlocHumanPlayer::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ATlocHumanPlayer(Z_Construct_UClass_ATlocHumanPlayer, &ATlocHumanPlayer::StaticClass, TEXT("/Script/LabyrinthOfCollosia"), TEXT("ATlocHumanPlayer"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ATlocHumanPlayer);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
