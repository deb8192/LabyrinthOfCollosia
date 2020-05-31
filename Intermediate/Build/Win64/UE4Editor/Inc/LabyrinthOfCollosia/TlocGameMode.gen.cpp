// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LabyrinthOfCollosia/Public/TlocGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTlocGameMode() {}
// Cross Module References
	LABYRINTHOFCOLLOSIA_API UClass* Z_Construct_UClass_ATlocGameMode_NoRegister();
	LABYRINTHOFCOLLOSIA_API UClass* Z_Construct_UClass_ATlocGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameMode();
	UPackage* Z_Construct_UPackage__Script_LabyrinthOfCollosia();
// End Cross Module References
	void ATlocGameMode::StaticRegisterNativesATlocGameMode()
	{
	}
	UClass* Z_Construct_UClass_ATlocGameMode_NoRegister()
	{
		return ATlocGameMode::StaticClass();
	}
	struct Z_Construct_UClass_ATlocGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ATlocGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameMode,
		(UObject* (*)())Z_Construct_UPackage__Script_LabyrinthOfCollosia,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATlocGameMode_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "TlocGameMode.h" },
		{ "ModuleRelativePath", "Public/TlocGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ATlocGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATlocGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ATlocGameMode_Statics::ClassParams = {
		&ATlocGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_ATlocGameMode_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_ATlocGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ATlocGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ATlocGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ATlocGameMode, 3577643240);
	template<> LABYRINTHOFCOLLOSIA_API UClass* StaticClass<ATlocGameMode>()
	{
		return ATlocGameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ATlocGameMode(Z_Construct_UClass_ATlocGameMode, &ATlocGameMode::StaticClass, TEXT("/Script/LabyrinthOfCollosia"), TEXT("ATlocGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ATlocGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
