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
	LABYRINTHOFCOLLOSIA_API UFunction* Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorHit();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
// End Cross Module References
	void ATlocHumanPlayer::StaticRegisterNativesATlocHumanPlayer()
	{
		UClass* Class = ATlocHumanPlayer::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OnHumanActorHit", &ATlocHumanPlayer::execOnHumanActorHit },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorHit_Statics
	{
		struct TlocHumanPlayer_eventOnHumanActorHit_Parms
		{
			AActor* player;
			AActor* enemy;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_enemy;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_player;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorHit_Statics::NewProp_enemy = { "enemy", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(TlocHumanPlayer_eventOnHumanActorHit_Parms, enemy), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorHit_Statics::NewProp_player = { "player", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(TlocHumanPlayer_eventOnHumanActorHit_Parms, player), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorHit_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorHit_Statics::NewProp_enemy,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorHit_Statics::NewProp_player,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorHit_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Characters/TlocHumanPlayer.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorHit_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATlocHumanPlayer, nullptr, "OnHumanActorHit", sizeof(TlocHumanPlayer_eventOnHumanActorHit_Parms), Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorHit_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorHit_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorHit_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorHit_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorHit()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorHit_Statics::FuncParams);
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
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ATlocHumanPlayer_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_LabyrinthOfCollosia,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ATlocHumanPlayer_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ATlocHumanPlayer_OnHumanActorHit, "OnHumanActorHit" }, // 3982590403
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
		FuncInfo,
		nullptr,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		ARRAY_COUNT(FuncInfo),
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
	IMPLEMENT_CLASS(ATlocHumanPlayer, 2825952306);
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
