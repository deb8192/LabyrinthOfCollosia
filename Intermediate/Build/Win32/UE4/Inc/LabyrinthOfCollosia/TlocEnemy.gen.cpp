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
// End Cross Module References
	void ATlocEnemy::StaticRegisterNativesATlocEnemy()
	{
	}
	UClass* Z_Construct_UClass_ATlocEnemy_NoRegister()
	{
		return ATlocEnemy::StaticClass();
	}
	struct Z_Construct_UClass_ATlocEnemy_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ATlocEnemy_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_LabyrinthOfCollosia,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATlocEnemy_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Characters/TlocEnemy.h" },
		{ "ModuleRelativePath", "Public/Characters/TlocEnemy.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ATlocEnemy_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATlocEnemy>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ATlocEnemy_Statics::ClassParams = {
		&ATlocEnemy::StaticClass,
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
	IMPLEMENT_CLASS(ATlocEnemy, 2399528683);
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
