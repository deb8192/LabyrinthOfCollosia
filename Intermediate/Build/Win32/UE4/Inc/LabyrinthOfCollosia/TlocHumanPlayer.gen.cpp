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
// End Cross Module References
	void ATlocHumanPlayer::StaticRegisterNativesATlocHumanPlayer()
	{
	}
	UClass* Z_Construct_UClass_ATlocHumanPlayer_NoRegister()
	{
		return ATlocHumanPlayer::StaticClass();
	}
	struct Z_Construct_UClass_ATlocHumanPlayer_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ATlocHumanPlayer_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_LabyrinthOfCollosia,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATlocHumanPlayer_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Characters/TlocHumanPlayer.h" },
		{ "ModuleRelativePath", "Public/Characters/TlocHumanPlayer.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ATlocHumanPlayer_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATlocHumanPlayer>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ATlocHumanPlayer_Statics::ClassParams = {
		&ATlocHumanPlayer::StaticClass,
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
	IMPLEMENT_CLASS(ATlocHumanPlayer, 1072339226);
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
