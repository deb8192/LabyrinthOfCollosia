// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LabyrinthOfCollosia/LabyrinthOfCollosiaGameModeBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLabyrinthOfCollosiaGameModeBase() {}
// Cross Module References
	LABYRINTHOFCOLLOSIA_API UClass* Z_Construct_UClass_ALabyrinthOfCollosiaGameModeBase_NoRegister();
	LABYRINTHOFCOLLOSIA_API UClass* Z_Construct_UClass_ALabyrinthOfCollosiaGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_LabyrinthOfCollosia();
// End Cross Module References
	void ALabyrinthOfCollosiaGameModeBase::StaticRegisterNativesALabyrinthOfCollosiaGameModeBase()
	{
	}
	UClass* Z_Construct_UClass_ALabyrinthOfCollosiaGameModeBase_NoRegister()
	{
		return ALabyrinthOfCollosiaGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_ALabyrinthOfCollosiaGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ALabyrinthOfCollosiaGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_LabyrinthOfCollosia,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALabyrinthOfCollosiaGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "LabyrinthOfCollosiaGameModeBase.h" },
		{ "ModuleRelativePath", "LabyrinthOfCollosiaGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ALabyrinthOfCollosiaGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ALabyrinthOfCollosiaGameModeBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ALabyrinthOfCollosiaGameModeBase_Statics::ClassParams = {
		&ALabyrinthOfCollosiaGameModeBase::StaticClass,
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
		0x009002A8u,
		METADATA_PARAMS(Z_Construct_UClass_ALabyrinthOfCollosiaGameModeBase_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_ALabyrinthOfCollosiaGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ALabyrinthOfCollosiaGameModeBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ALabyrinthOfCollosiaGameModeBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ALabyrinthOfCollosiaGameModeBase, 2879710770);
	template<> LABYRINTHOFCOLLOSIA_API UClass* StaticClass<ALabyrinthOfCollosiaGameModeBase>()
	{
		return ALabyrinthOfCollosiaGameModeBase::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ALabyrinthOfCollosiaGameModeBase(Z_Construct_UClass_ALabyrinthOfCollosiaGameModeBase, &ALabyrinthOfCollosiaGameModeBase::StaticClass, TEXT("/Script/LabyrinthOfCollosia"), TEXT("ALabyrinthOfCollosiaGameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ALabyrinthOfCollosiaGameModeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
