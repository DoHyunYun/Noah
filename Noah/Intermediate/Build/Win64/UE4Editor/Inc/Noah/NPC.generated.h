// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class APawn;
enum class ENPCStateEnum : uint8;
#ifdef NOAH_NPC_generated_h
#error "NPC.generated.h already included, missing '#pragma once' in NPC.h"
#endif
#define NOAH_NPC_generated_h

#define Noah_Source_Noah_NPC_h_23_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execNPCStateUpdate) \
	{ \
		P_GET_OBJECT(APawn,Z_Param_target); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ENPCStateEnum*)Z_Param__Result=this->NPCStateUpdate(Z_Param_target); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execFindStateList) \
	{ \
		P_GET_ENUM(ENPCStateEnum,Z_Param_state); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->FindStateList(ENPCStateEnum(Z_Param_state)); \
		P_NATIVE_END; \
	}


#define Noah_Source_Noah_NPC_h_23_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execNPCStateUpdate) \
	{ \
		P_GET_OBJECT(APawn,Z_Param_target); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ENPCStateEnum*)Z_Param__Result=this->NPCStateUpdate(Z_Param_target); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execFindStateList) \
	{ \
		P_GET_ENUM(ENPCStateEnum,Z_Param_state); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->FindStateList(ENPCStateEnum(Z_Param_state)); \
		P_NATIVE_END; \
	}


#define Noah_Source_Noah_NPC_h_23_EVENT_PARMS \
	struct NPC_eventDamaged_Parms \
	{ \
		float damage; \
	};


extern NOAH_API  FName NOAH_Damaged;
#define Noah_Source_Noah_NPC_h_23_CALLBACK_WRAPPERS
#define Noah_Source_Noah_NPC_h_23_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesANPC(); \
	friend NOAH_API class UClass* Z_Construct_UClass_ANPC(); \
	public: \
	DECLARE_CLASS(ANPC, ACharacter, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/Noah"), NO_API) \
	DECLARE_SERIALIZER(ANPC) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Noah_Source_Noah_NPC_h_23_INCLASS \
	private: \
	static void StaticRegisterNativesANPC(); \
	friend NOAH_API class UClass* Z_Construct_UClass_ANPC(); \
	public: \
	DECLARE_CLASS(ANPC, ACharacter, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/Noah"), NO_API) \
	DECLARE_SERIALIZER(ANPC) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Noah_Source_Noah_NPC_h_23_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ANPC(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ANPC) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ANPC); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ANPC); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ANPC(ANPC&&); \
	NO_API ANPC(const ANPC&); \
public:


#define Noah_Source_Noah_NPC_h_23_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ANPC(ANPC&&); \
	NO_API ANPC(const ANPC&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ANPC); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ANPC); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ANPC)


#define Noah_Source_Noah_NPC_h_23_PRIVATE_PROPERTY_OFFSET
#define Noah_Source_Noah_NPC_h_20_PROLOG \
	Noah_Source_Noah_NPC_h_23_EVENT_PARMS


#define Noah_Source_Noah_NPC_h_23_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Noah_Source_Noah_NPC_h_23_PRIVATE_PROPERTY_OFFSET \
	Noah_Source_Noah_NPC_h_23_RPC_WRAPPERS \
	Noah_Source_Noah_NPC_h_23_CALLBACK_WRAPPERS \
	Noah_Source_Noah_NPC_h_23_INCLASS \
	Noah_Source_Noah_NPC_h_23_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Noah_Source_Noah_NPC_h_23_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Noah_Source_Noah_NPC_h_23_PRIVATE_PROPERTY_OFFSET \
	Noah_Source_Noah_NPC_h_23_RPC_WRAPPERS_NO_PURE_DECLS \
	Noah_Source_Noah_NPC_h_23_CALLBACK_WRAPPERS \
	Noah_Source_Noah_NPC_h_23_INCLASS_NO_PURE_DECLS \
	Noah_Source_Noah_NPC_h_23_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Noah_Source_Noah_NPC_h


#define FOREACH_ENUM_ENPCSTATEENUM(op) \
	op(ENPCStateEnum::VE_Idle) \
	op(ENPCStateEnum::VE_Trace) \
	op(ENPCStateEnum::VE_Attack) \
	op(ENPCStateEnum::VE_Run) \
	op(ENPCStateEnum::VE_RunAway) \
	op(ENPCStateEnum::VE_Dead) 
PRAGMA_ENABLE_DEPRECATION_WARNINGS
