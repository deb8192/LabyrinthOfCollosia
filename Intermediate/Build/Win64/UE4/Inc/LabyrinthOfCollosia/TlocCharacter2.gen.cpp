// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LabyrinthOfCollosia/Public/Characters/TlocCharacter2.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTlocCharacter2() {}
// Cross Module References
	LABYRINTHOFCOLLOSIA_API UClass* Z_Construct_UClass_ATlocCharacter2_NoRegister();
	LABYRINTHOFCOLLOSIA_API UClass* Z_Construct_UClass_ATlocCharacter2();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	UPackage* Z_Construct_UPackage__Script_LabyrinthOfCollosia();
// End Cross Module References
	void ATlocCharacter2::StaticRegisterNativesATlocCharacter2()
	{
	}
	UClass* Z_Construct_UClass_ATlocCharacter2_NoRegister()
	{
		return ATlocCharacter2::StaticClass();
	}
	struct Z_Construct_UClass_ATlocCharacter2_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ATlocCharacter2_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_LabyrinthOfCollosia,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATlocCharacter2_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Characters/TlocCharacter2.h" },
		{ "ModuleRelativePath", "Public/Characters/TlocCharacter2.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ATlocCharacter2_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATlocCharacter2>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ATlocCharacter2_Statics::ClassParams = {
		&ATlocCharacter2::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_ATlocCharacter2_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_ATlocCharacter2_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ATlocCharacter2()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ATlocCharacter2_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ATlocCharacter2, 768345720);
	template<> LABYRINTHOFCOLLOSIA_API UClass* StaticClass<ATlocCharacter2>()
	{
		return ATlocCharacter2::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ATlocCharacter2(Z_Construct_UClass_ATlocCharacter2, &ATlocCharacter2::StaticClass, TEXT("/Script/LabyrinthOfCollosia"), TEXT("ATlocCharacter2"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ATlocCharacter2);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
