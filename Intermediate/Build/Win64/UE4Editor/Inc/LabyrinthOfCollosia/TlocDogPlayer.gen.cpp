// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LabyrinthOfCollosia/Public/Characters/TlocDogPlayer.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTlocDogPlayer() {}
// Cross Module References
	LABYRINTHOFCOLLOSIA_API UClass* Z_Construct_UClass_ATlocDogPlayer_NoRegister();
	LABYRINTHOFCOLLOSIA_API UClass* Z_Construct_UClass_ATlocDogPlayer();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	UPackage* Z_Construct_UPackage__Script_LabyrinthOfCollosia();
// End Cross Module References
	void ATlocDogPlayer::StaticRegisterNativesATlocDogPlayer()
	{
	}
	UClass* Z_Construct_UClass_ATlocDogPlayer_NoRegister()
	{
		return ATlocDogPlayer::StaticClass();
	}
	struct Z_Construct_UClass_ATlocDogPlayer_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ATlocDogPlayer_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_LabyrinthOfCollosia,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATlocDogPlayer_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Characters/TlocDogPlayer.h" },
		{ "ModuleRelativePath", "Public/Characters/TlocDogPlayer.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ATlocDogPlayer_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATlocDogPlayer>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ATlocDogPlayer_Statics::ClassParams = {
		&ATlocDogPlayer::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_ATlocDogPlayer_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_ATlocDogPlayer_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ATlocDogPlayer()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ATlocDogPlayer_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ATlocDogPlayer, 1320327591);
	template<> LABYRINTHOFCOLLOSIA_API UClass* StaticClass<ATlocDogPlayer>()
	{
		return ATlocDogPlayer::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ATlocDogPlayer(Z_Construct_UClass_ATlocDogPlayer, &ATlocDogPlayer::StaticClass, TEXT("/Script/LabyrinthOfCollosia"), TEXT("ATlocDogPlayer"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ATlocDogPlayer);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
