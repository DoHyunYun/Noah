// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef NOAH_Craft_generated_h
#error "Craft.generated.h already included, missing '#pragma once' in Craft.h"
#endif
#define NOAH_Craft_generated_h

#define Noah_Source_Noah_Craft_h_22_GENERATED_BODY \
	friend NOAH_API class UScriptStruct* Z_Construct_UScriptStruct_FCraftItemStruct(); \
	NOAH_API static class UScriptStruct* StaticStruct();


#define Noah_Source_Noah_Craft_h_11_GENERATED_BODY \
	friend NOAH_API class UScriptStruct* Z_Construct_UScriptStruct_FSimpleItemStruct(); \
	NOAH_API static class UScriptStruct* StaticStruct();


#define Noah_Source_Noah_Craft_h_40_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetCraftApiSet) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->GetCraftApiSet(); \
		P_NATIVE_END; \
	}


#define Noah_Source_Noah_Craft_h_40_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetCraftApiSet) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->GetCraftApiSet(); \
		P_NATIVE_END; \
	}


#define Noah_Source_Noah_Craft_h_40_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesUCraft(); \
	friend NOAH_API class UClass* Z_Construct_UClass_UCraft(); \
	public: \
	DECLARE_CLASS(UCraft, UActorComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/Noah"), NO_API) \
	DECLARE_SERIALIZER(UCraft) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Noah_Source_Noah_Craft_h_40_INCLASS \
	private: \
	static void StaticRegisterNativesUCraft(); \
	friend NOAH_API class UClass* Z_Construct_UClass_UCraft(); \
	public: \
	DECLARE_CLASS(UCraft, UActorComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/Noah"), NO_API) \
	DECLARE_SERIALIZER(UCraft) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Noah_Source_Noah_Craft_h_40_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCraft(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCraft) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCraft); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCraft); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UCraft(UCraft&&); \
	NO_API UCraft(const UCraft&); \
public:


#define Noah_Source_Noah_Craft_h_40_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UCraft(UCraft&&); \
	NO_API UCraft(const UCraft&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCraft); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCraft); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UCraft)


#define Noah_Source_Noah_Craft_h_40_PRIVATE_PROPERTY_OFFSET
#define Noah_Source_Noah_Craft_h_37_PROLOG
#define Noah_Source_Noah_Craft_h_40_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Noah_Source_Noah_Craft_h_40_PRIVATE_PROPERTY_OFFSET \
	Noah_Source_Noah_Craft_h_40_RPC_WRAPPERS \
	Noah_Source_Noah_Craft_h_40_INCLASS \
	Noah_Source_Noah_Craft_h_40_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Noah_Source_Noah_Craft_h_40_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Noah_Source_Noah_Craft_h_40_PRIVATE_PROPERTY_OFFSET \
	Noah_Source_Noah_Craft_h_40_RPC_WRAPPERS_NO_PURE_DECLS \
	Noah_Source_Noah_Craft_h_40_INCLASS_NO_PURE_DECLS \
	Noah_Source_Noah_Craft_h_40_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Noah_Source_Noah_Craft_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS