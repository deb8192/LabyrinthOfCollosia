// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class AActor;
struct FHitResult;
#ifdef LABYRINTHOFCOLLOSIA_TlocEnemy_generated_h
#error "TlocEnemy.generated.h already included, missing '#pragma once' in TlocEnemy.h"
#endif
#define LABYRINTHOFCOLLOSIA_TlocEnemy_generated_h

#define LabyrinthOfCollosia_Source_LabyrinthOfCollosia_Public_Characters_TlocEnemy_h_14_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnEnemyActorStopHit) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param__attackCollision); \
		P_GET_OBJECT(AActor,Z_Param__other); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param__otherComp); \
		P_GET_PROPERTY(UIntProperty,Z_Param_OtherBodyIndex); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnEnemyActorStopHit(Z_Param__attackCollision,Z_Param__other,Z_Param__otherComp,Z_Param_OtherBodyIndex); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnEnemyActorHit) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param__attackCollision); \
		P_GET_OBJECT(AActor,Z_Param__other); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param__otherComp); \
		P_GET_PROPERTY(UIntProperty,Z_Param_OtherBodyIndex); \
		P_GET_UBOOL(Z_Param_bFromSweep); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_Hit); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnEnemyActorHit(Z_Param__attackCollision,Z_Param__other,Z_Param__otherComp,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_Hit); \
		P_NATIVE_END; \
	}


#define LabyrinthOfCollosia_Source_LabyrinthOfCollosia_Public_Characters_TlocEnemy_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnEnemyActorStopHit) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param__attackCollision); \
		P_GET_OBJECT(AActor,Z_Param__other); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param__otherComp); \
		P_GET_PROPERTY(UIntProperty,Z_Param_OtherBodyIndex); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnEnemyActorStopHit(Z_Param__attackCollision,Z_Param__other,Z_Param__otherComp,Z_Param_OtherBodyIndex); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnEnemyActorHit) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param__attackCollision); \
		P_GET_OBJECT(AActor,Z_Param__other); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param__otherComp); \
		P_GET_PROPERTY(UIntProperty,Z_Param_OtherBodyIndex); \
		P_GET_UBOOL(Z_Param_bFromSweep); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_Hit); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnEnemyActorHit(Z_Param__attackCollision,Z_Param__other,Z_Param__otherComp,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_Hit); \
		P_NATIVE_END; \
	}


#define LabyrinthOfCollosia_Source_LabyrinthOfCollosia_Public_Characters_TlocEnemy_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesATlocEnemy(); \
	friend struct Z_Construct_UClass_ATlocEnemy_Statics; \
public: \
	DECLARE_CLASS(ATlocEnemy, ACharacter, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/LabyrinthOfCollosia"), NO_API) \
	DECLARE_SERIALIZER(ATlocEnemy)


#define LabyrinthOfCollosia_Source_LabyrinthOfCollosia_Public_Characters_TlocEnemy_h_14_INCLASS \
private: \
	static void StaticRegisterNativesATlocEnemy(); \
	friend struct Z_Construct_UClass_ATlocEnemy_Statics; \
public: \
	DECLARE_CLASS(ATlocEnemy, ACharacter, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/LabyrinthOfCollosia"), NO_API) \
	DECLARE_SERIALIZER(ATlocEnemy)


#define LabyrinthOfCollosia_Source_LabyrinthOfCollosia_Public_Characters_TlocEnemy_h_14_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ATlocEnemy(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ATlocEnemy) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATlocEnemy); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATlocEnemy); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATlocEnemy(ATlocEnemy&&); \
	NO_API ATlocEnemy(const ATlocEnemy&); \
public:


#define LabyrinthOfCollosia_Source_LabyrinthOfCollosia_Public_Characters_TlocEnemy_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATlocEnemy(ATlocEnemy&&); \
	NO_API ATlocEnemy(const ATlocEnemy&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATlocEnemy); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATlocEnemy); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ATlocEnemy)


#define LabyrinthOfCollosia_Source_LabyrinthOfCollosia_Public_Characters_TlocEnemy_h_14_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO___targetCameraSpringArm() { return STRUCT_OFFSET(ATlocEnemy, _targetCameraSpringArm); } \
	FORCEINLINE static uint32 __PPO___targetCamera() { return STRUCT_OFFSET(ATlocEnemy, _targetCamera); }


#define LabyrinthOfCollosia_Source_LabyrinthOfCollosia_Public_Characters_TlocEnemy_h_11_PROLOG
#define LabyrinthOfCollosia_Source_LabyrinthOfCollosia_Public_Characters_TlocEnemy_h_14_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	LabyrinthOfCollosia_Source_LabyrinthOfCollosia_Public_Characters_TlocEnemy_h_14_PRIVATE_PROPERTY_OFFSET \
	LabyrinthOfCollosia_Source_LabyrinthOfCollosia_Public_Characters_TlocEnemy_h_14_RPC_WRAPPERS \
	LabyrinthOfCollosia_Source_LabyrinthOfCollosia_Public_Characters_TlocEnemy_h_14_INCLASS \
	LabyrinthOfCollosia_Source_LabyrinthOfCollosia_Public_Characters_TlocEnemy_h_14_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define LabyrinthOfCollosia_Source_LabyrinthOfCollosia_Public_Characters_TlocEnemy_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	LabyrinthOfCollosia_Source_LabyrinthOfCollosia_Public_Characters_TlocEnemy_h_14_PRIVATE_PROPERTY_OFFSET \
	LabyrinthOfCollosia_Source_LabyrinthOfCollosia_Public_Characters_TlocEnemy_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	LabyrinthOfCollosia_Source_LabyrinthOfCollosia_Public_Characters_TlocEnemy_h_14_INCLASS_NO_PURE_DECLS \
	LabyrinthOfCollosia_Source_LabyrinthOfCollosia_Public_Characters_TlocEnemy_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> LABYRINTHOFCOLLOSIA_API UClass* StaticClass<class ATlocEnemy>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID LabyrinthOfCollosia_Source_LabyrinthOfCollosia_Public_Characters_TlocEnemy_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
