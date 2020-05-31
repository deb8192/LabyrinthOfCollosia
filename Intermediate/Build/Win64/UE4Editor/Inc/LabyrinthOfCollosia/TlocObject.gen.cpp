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
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
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
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp__wpnMesh_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp__wpnMesh;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
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
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATlocObject_Statics::NewProp__wpnMesh_MetaData[] = {
		{ "Category", "TlocObject" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Objects/TlocObject.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATlocObject_Statics::NewProp__wpnMesh = { "_wpnMesh", nullptr, (EPropertyFlags)0x00200800000a0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATlocObject, _wpnMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ATlocObject_Statics::NewProp__wpnMesh_MetaData, ARRAY_COUNT(Z_Construct_UClass_ATlocObject_Statics::NewProp__wpnMesh_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ATlocObject_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATlocObject_Statics::NewProp__wpnMesh,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ATlocObject_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATlocObject>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ATlocObject_Statics::ClassParams = {
		&ATlocObject::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ATlocObject_Statics::PropPointers,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		0,
		ARRAY_COUNT(Z_Construct_UClass_ATlocObject_Statics::PropPointers),
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
	IMPLEMENT_CLASS(ATlocObject, 2271467166);
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
