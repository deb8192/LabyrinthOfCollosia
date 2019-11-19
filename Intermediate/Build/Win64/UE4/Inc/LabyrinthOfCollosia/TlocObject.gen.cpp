// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LabyrinthOfCollosia/Public/Objects/TlocObject.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTlocObject() {}
// Cross Module References
	LABYRINTHOFCOLLOSIA_API UClass* Z_Construct_UClass_ATlocObject_NoRegister();
	LABYRINTHOFCOLLOSIA_API UClass* Z_Construct_UClass_ATlocObject();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_LabyrinthOfCollosia();
// End Cross Module References
	void ATlocObject::StaticRegisterNativesATlocObject()
	{
	}
	UClass* Z_Construct_UClass_ATlocObject_NoRegister()
	{
		return ATlocObject::StaticClass();
	}
	struct Z_Construct_UClass_ATlocObject_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ATlocObject_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_LabyrinthOfCollosia,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATlocObject_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Objects/TlocObject.h" },
		{ "ModuleRelativePath", "Public/Objects/TlocObject.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ATlocObject_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATlocObject>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ATlocObject_Statics::ClassParams = {
		&ATlocObject::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_ATlocObject_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_ATlocObject_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ATlocObject()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ATlocObject_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ATlocObject, 2889578853);
	template<> LABYRINTHOFCOLLOSIA_API UClass* StaticClass<ATlocObject>()
	{
		return ATlocObject::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ATlocObject(Z_Construct_UClass_ATlocObject, &ATlocObject::StaticClass, TEXT("/Script/LabyrinthOfCollosia"), TEXT("ATlocObject"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ATlocObject);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
