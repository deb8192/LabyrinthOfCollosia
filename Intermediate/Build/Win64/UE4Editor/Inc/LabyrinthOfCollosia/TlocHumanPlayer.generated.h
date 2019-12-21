// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
#ifdef LABYRINTHOFCOLLOSIA_TlocHumanPlayer_generated_h
#error "TlocHumanPlayer.generated.h already included, missing '#pragma once' in TlocHumanPlayer.h"
#endif
#define LABYRINTHOFCOLLOSIA_TlocHumanPlayer_generated_h

#define LabyrinthOfCollosia_Source_LabyrinthOfCollosia_Public_Characters_TlocHumanPlayer_h_13_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnHumanActorHit) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_player); \
		P_GET_OBJECT(AActor,Z_Param_enemy); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnHumanActorHit(Z_Param_player,Z_Param_enemy); \
		P_NATIVE_END; \
	}


#define LabyrinthOfCollosia_Source_LabyrinthOfCollosia_Public_Characters_TlocHumanPlayer_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnHumanActorHit) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_player); \
		P_GET_OBJECT(AActor,Z_Param_enemy); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnHumanActorHit(Z_Param_player,Z_Param_enemy); \
		P_NATIVE_END; \
	}


#define LabyrinthOfCollosia_Source_LabyrinthOfCollosia_Public_Characters_TlocHumanPlayer_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesATlocHumanPlayer(); \
	friend struct Z_Construct_UClass_ATlocHumanPlayer_Statics; \
public: \
	DECLARE_CLASS(ATlocHumanPlayer, ACharacter, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/LabyrinthOfCollosia"), NO_API) \
	DECLARE_SERIALIZER(ATlocHumanPlayer)


#define LabyrinthOfCollosia_Source_LabyrinthOfCollosia_Public_Characters_TlocHumanPlayer_h_13_INCLASS \
private: \
	static void StaticRegisterNativesATlocHumanPlayer(); \
	friend struct Z_Construct_UClass_ATlocHumanPlayer_Statics; \
public: \
	DECLARE_CLASS(ATlocHumanPlayer, ACharacter, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/LabyrinthOfCollosia"), NO_API) \
	DECLARE_SERIALIZER(ATlocHumanPlayer)


#define LabyrinthOfCollosia_Source_LabyrinthOfCollosia_Public_Characters_TlocHumanPlayer_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ATlocHumanPlayer(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ATlocHumanPlayer) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATlocHumanPlayer); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATlocHumanPlayer); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATlocHumanPlayer(ATlocHumanPlayer&&); \
	NO_API ATlocHumanPlayer(const ATlocHumanPlayer&); \
public:


#define LabyrinthOfCollosia_Source_LabyrinthOfCollosia_Public_Characters_TlocHumanPlayer_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATlocHumanPlayer(ATlocHumanPlayer&&); \
	NO_API ATlocHumanPlayer(const ATlocHumanPlayer&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATlocHumanPlayer); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATlocHumanPlayer); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ATlocHumanPlayer)


#define LabyrinthOfCollosia_Source_LabyrinthOfCollosia_Public_Characters_TlocHumanPlayer_h_13_PRIVATE_PROPERTY_OFFSET
#define LabyrinthOfCollosia_Source_LabyrinthOfCollosia_Public_Characters_TlocHumanPlayer_h_10_PROLOG
#define LabyrinthOfCollosia_Source_LabyrinthOfCollosia_Public_Characters_TlocHumanPlayer_h_13_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	LabyrinthOfCollosia_Source_LabyrinthOfCollosia_Public_Characters_TlocHumanPlayer_h_13_PRIVATE_PROPERTY_OFFSET \
	LabyrinthOfCollosia_Source_LabyrinthOfCollosia_Public_Characters_TlocHumanPlayer_h_13_RPC_WRAPPERS \
	LabyrinthOfCollosia_Source_LabyrinthOfCollosia_Public_Characters_TlocHumanPlayer_h_13_INCLASS \
	LabyrinthOfCollosia_Source_LabyrinthOfCollosia_Public_Characters_TlocHumanPlayer_h_13_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define LabyrinthOfCollosia_Source_LabyrinthOfCollosia_Public_Characters_TlocHumanPlayer_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	LabyrinthOfCollosia_Source_LabyrinthOfCollosia_Public_Characters_TlocHumanPlayer_h_13_PRIVATE_PROPERTY_OFFSET \
	LabyrinthOfCollosia_Source_LabyrinthOfCollosia_Public_Characters_TlocHumanPlayer_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	LabyrinthOfCollosia_Source_LabyrinthOfCollosia_Public_Characters_TlocHumanPlayer_h_13_INCLASS_NO_PURE_DECLS \
	LabyrinthOfCollosia_Source_LabyrinthOfCollosia_Public_Characters_TlocHumanPlayer_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> LABYRINTHOFCOLLOSIA_API UClass* StaticClass<class ATlocHumanPlayer>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID LabyrinthOfCollosia_Source_LabyrinthOfCollosia_Public_Characters_TlocHumanPlayer_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
