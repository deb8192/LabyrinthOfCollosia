// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LabyrinthOfCollosia/Public/Characters/TlocEnemy.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTlocEnemy() {}
// Cross Module References
	LABYRINTHOFCOLLOSIA_API UClass* Z_Construct_UClass_ATlocEnemy_NoRegister();
	LABYRINTHOFCOLLOSIA_API UClass* Z_Construct_UClass_ATlocEnemy();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	UPackage* Z_Construct_UPackage__Script_LabyrinthOfCollosia();
	LABYRINTHOFCOLLOSIA_API UFunction* Z_Construct_UFunction_ATlocEnemy_OnEnemyActorHit();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
	ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	LABYRINTHOFCOLLOSIA_API UFunction* Z_Construct_UFunction_ATlocEnemy_OnEnemyActorStopHit();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
// End Cross Module References
	void ATlocEnemy::StaticRegisterNativesATlocEnemy()
	{
		UClass* Class = ATlocEnemy::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OnEnemyActorHit", &ATlocEnemy::execOnEnemyActorHit },
			{ "OnEnemyActorStopHit", &ATlocEnemy::execOnEnemyActorStopHit },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ATlocEnemy_OnEnemyActorHit_Statics
	{
		struct TlocEnemy_eventOnEnemyActorHit_Parms
		{
			UPrimitiveComponent* _attackCollision;
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
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp__attackCollision_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp__attackCollision;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATlocEnemy_OnEnemyActorHit_Statics::NewProp_Hit_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ATlocEnemy_OnEnemyActorHit_Statics::NewProp_Hit = { "Hit", nullptr, (EPropertyFlags)0x0010008008000182, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(TlocEnemy_eventOnEnemyActorHit_Parms, Hit), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(Z_Construct_UFunction_ATlocEnemy_OnEnemyActorHit_Statics::NewProp_Hit_MetaData, ARRAY_COUNT(Z_Construct_UFunction_ATlocEnemy_OnEnemyActorHit_Statics::NewProp_Hit_MetaData)) };
	void Z_Construct_UFunction_ATlocEnemy_OnEnemyActorHit_Statics::NewProp_bFromSweep_SetBit(void* Obj)
	{
		((TlocEnemy_eventOnEnemyActorHit_Parms*)Obj)->bFromSweep = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ATlocEnemy_OnEnemyActorHit_Statics::NewProp_bFromSweep = { "bFromSweep", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(TlocEnemy_eventOnEnemyActorHit_Parms), &Z_Construct_UFunction_ATlocEnemy_OnEnemyActorHit_Statics::NewProp_bFromSweep_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ATlocEnemy_OnEnemyActorHit_Statics::NewProp_OtherBodyIndex = { "OtherBodyIndex", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(TlocEnemy_eventOnEnemyActorHit_Parms, OtherBodyIndex), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATlocEnemy_OnEnemyActorHit_Statics::NewProp__otherComp_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ATlocEnemy_OnEnemyActorHit_Statics::NewProp__otherComp = { "_otherComp", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(TlocEnemy_eventOnEnemyActorHit_Parms, _otherComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_ATlocEnemy_OnEnemyActorHit_Statics::NewProp__otherComp_MetaData, ARRAY_COUNT(Z_Construct_UFunction_ATlocEnemy_OnEnemyActorHit_Statics::NewProp__otherComp_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ATlocEnemy_OnEnemyActorHit_Statics::NewProp__other = { "_other", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(TlocEnemy_eventOnEnemyActorHit_Parms, _other), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATlocEnemy_OnEnemyActorHit_Statics::NewProp__attackCollision_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ATlocEnemy_OnEnemyActorHit_Statics::NewProp__attackCollision = { "_attackCollision", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(TlocEnemy_eventOnEnemyActorHit_Parms, _attackCollision), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_ATlocEnemy_OnEnemyActorHit_Statics::NewProp__attackCollision_MetaData, ARRAY_COUNT(Z_Construct_UFunction_ATlocEnemy_OnEnemyActorHit_Statics::NewProp__attackCollision_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATlocEnemy_OnEnemyActorHit_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATlocEnemy_OnEnemyActorHit_Statics::NewProp_Hit,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATlocEnemy_OnEnemyActorHit_Statics::NewProp_bFromSweep,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATlocEnemy_OnEnemyActorHit_Statics::NewProp_OtherBodyIndex,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATlocEnemy_OnEnemyActorHit_Statics::NewProp__otherComp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATlocEnemy_OnEnemyActorHit_Statics::NewProp__other,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATlocEnemy_OnEnemyActorHit_Statics::NewProp__attackCollision,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATlocEnemy_OnEnemyActorHit_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Characters/TlocEnemy.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ATlocEnemy_OnEnemyActorHit_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATlocEnemy, nullptr, "OnEnemyActorHit", nullptr, nullptr, sizeof(TlocEnemy_eventOnEnemyActorHit_Parms), Z_Construct_UFunction_ATlocEnemy_OnEnemyActorHit_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ATlocEnemy_OnEnemyActorHit_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00480401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATlocEnemy_OnEnemyActorHit_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ATlocEnemy_OnEnemyActorHit_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATlocEnemy_OnEnemyActorHit()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ATlocEnemy_OnEnemyActorHit_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATlocEnemy_OnEnemyActorStopHit_Statics
	{
		struct TlocEnemy_eventOnEnemyActorStopHit_Parms
		{
			UPrimitiveComponent* _attackCollision;
			AActor* _other;
			UPrimitiveComponent* _otherComp;
			int32 OtherBodyIndex;
		};
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_OtherBodyIndex;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp__otherComp_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp__otherComp;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp__other;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp__attackCollision_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp__attackCollision;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ATlocEnemy_OnEnemyActorStopHit_Statics::NewProp_OtherBodyIndex = { "OtherBodyIndex", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(TlocEnemy_eventOnEnemyActorStopHit_Parms, OtherBodyIndex), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATlocEnemy_OnEnemyActorStopHit_Statics::NewProp__otherComp_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ATlocEnemy_OnEnemyActorStopHit_Statics::NewProp__otherComp = { "_otherComp", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(TlocEnemy_eventOnEnemyActorStopHit_Parms, _otherComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_ATlocEnemy_OnEnemyActorStopHit_Statics::NewProp__otherComp_MetaData, ARRAY_COUNT(Z_Construct_UFunction_ATlocEnemy_OnEnemyActorStopHit_Statics::NewProp__otherComp_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ATlocEnemy_OnEnemyActorStopHit_Statics::NewProp__other = { "_other", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(TlocEnemy_eventOnEnemyActorStopHit_Parms, _other), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATlocEnemy_OnEnemyActorStopHit_Statics::NewProp__attackCollision_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ATlocEnemy_OnEnemyActorStopHit_Statics::NewProp__attackCollision = { "_attackCollision", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(TlocEnemy_eventOnEnemyActorStopHit_Parms, _attackCollision), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_ATlocEnemy_OnEnemyActorStopHit_Statics::NewProp__attackCollision_MetaData, ARRAY_COUNT(Z_Construct_UFunction_ATlocEnemy_OnEnemyActorStopHit_Statics::NewProp__attackCollision_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATlocEnemy_OnEnemyActorStopHit_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATlocEnemy_OnEnemyActorStopHit_Statics::NewProp_OtherBodyIndex,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATlocEnemy_OnEnemyActorStopHit_Statics::NewProp__otherComp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATlocEnemy_OnEnemyActorStopHit_Statics::NewProp__other,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATlocEnemy_OnEnemyActorStopHit_Statics::NewProp__attackCollision,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATlocEnemy_OnEnemyActorStopHit_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Characters/TlocEnemy.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ATlocEnemy_OnEnemyActorStopHit_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATlocEnemy, nullptr, "OnEnemyActorStopHit", nullptr, nullptr, sizeof(TlocEnemy_eventOnEnemyActorStopHit_Parms), Z_Construct_UFunction_ATlocEnemy_OnEnemyActorStopHit_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ATlocEnemy_OnEnemyActorStopHit_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATlocEnemy_OnEnemyActorStopHit_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ATlocEnemy_OnEnemyActorStopHit_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATlocEnemy_OnEnemyActorStopHit()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ATlocEnemy_OnEnemyActorStopHit_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ATlocEnemy_NoRegister()
	{
		return ATlocEnemy::StaticClass();
	}
	struct Z_Construct_UClass_ATlocEnemy_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp__targetCamera_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp__targetCamera;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp__targetCameraSpringArm_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp__targetCameraSpringArm;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ATlocEnemy_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_LabyrinthOfCollosia,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ATlocEnemy_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ATlocEnemy_OnEnemyActorHit, "OnEnemyActorHit" }, // 3664288819
		{ &Z_Construct_UFunction_ATlocEnemy_OnEnemyActorStopHit, "OnEnemyActorStopHit" }, // 2066546684
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATlocEnemy_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Characters/TlocEnemy.h" },
		{ "ModuleRelativePath", "Public/Characters/TlocEnemy.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATlocEnemy_Statics::NewProp__targetCamera_MetaData[] = {
		{ "Category", "TlocEnemy" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Characters/TlocEnemy.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATlocEnemy_Statics::NewProp__targetCamera = { "_targetCamera", nullptr, (EPropertyFlags)0x00400000000a0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATlocEnemy, _targetCamera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ATlocEnemy_Statics::NewProp__targetCamera_MetaData, ARRAY_COUNT(Z_Construct_UClass_ATlocEnemy_Statics::NewProp__targetCamera_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATlocEnemy_Statics::NewProp__targetCameraSpringArm_MetaData[] = {
		{ "Category", "TlocEnemy" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Characters/TlocEnemy.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATlocEnemy_Statics::NewProp__targetCameraSpringArm = { "_targetCameraSpringArm", nullptr, (EPropertyFlags)0x00400000000a0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATlocEnemy, _targetCameraSpringArm), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ATlocEnemy_Statics::NewProp__targetCameraSpringArm_MetaData, ARRAY_COUNT(Z_Construct_UClass_ATlocEnemy_Statics::NewProp__targetCameraSpringArm_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ATlocEnemy_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATlocEnemy_Statics::NewProp__targetCamera,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATlocEnemy_Statics::NewProp__targetCameraSpringArm,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ATlocEnemy_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATlocEnemy>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ATlocEnemy_Statics::ClassParams = {
		&ATlocEnemy::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ATlocEnemy_Statics::PropPointers,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		ARRAY_COUNT(FuncInfo),
		ARRAY_COUNT(Z_Construct_UClass_ATlocEnemy_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(Z_Construct_UClass_ATlocEnemy_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_ATlocEnemy_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ATlocEnemy()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ATlocEnemy_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ATlocEnemy, 3851440116);
	template<> LABYRINTHOFCOLLOSIA_API UClass* StaticClass<ATlocEnemy>()
	{
		return ATlocEnemy::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ATlocEnemy(Z_Construct_UClass_ATlocEnemy, &ATlocEnemy::StaticClass, TEXT("/Script/LabyrinthOfCollosia"), TEXT("ATlocEnemy"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ATlocEnemy);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
