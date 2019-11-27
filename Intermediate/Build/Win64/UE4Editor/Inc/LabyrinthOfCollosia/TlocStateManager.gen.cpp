// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LabyrinthOfCollosia/Public/GameState/TlocStateManager.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTlocStateManager() {}
// Cross Module References
	LABYRINTHOFCOLLOSIA_API UClass* Z_Construct_UClass_UTlocStateManager_NoRegister();
	LABYRINTHOFCOLLOSIA_API UClass* Z_Construct_UClass_UTlocStateManager();
	COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
	UPackage* Z_Construct_UPackage__Script_LabyrinthOfCollosia();
// End Cross Module References
	void UTlocStateManager::StaticRegisterNativesUTlocStateManager()
	{
	}
	UClass* Z_Construct_UClass_UTlocStateManager_NoRegister()
	{
		return UTlocStateManager::StaticClass();
	}
	struct Z_Construct_UClass_UTlocStateManager_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UTlocStateManager_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_LabyrinthOfCollosia,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTlocStateManager_Statics::Class_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/GameState/TlocStateManager.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UTlocStateManager_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ITlocStateManager>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UTlocStateManager_Statics::ClassParams = {
		&UTlocStateManager::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x000840A1u,
		METADATA_PARAMS(Z_Construct_UClass_UTlocStateManager_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UTlocStateManager_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UTlocStateManager()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UTlocStateManager_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UTlocStateManager, 575224199);
	template<> LABYRINTHOFCOLLOSIA_API UClass* StaticClass<UTlocStateManager>()
	{
		return UTlocStateManager::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UTlocStateManager(Z_Construct_UClass_UTlocStateManager, &UTlocStateManager::StaticClass, TEXT("/Script/LabyrinthOfCollosia"), TEXT("UTlocStateManager"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UTlocStateManager);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
