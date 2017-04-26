// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef NOAH_NoahGameModeBase_generated_h
#error "NoahGameModeBase.generated.h already included, missing '#pragma once' in NoahGameModeBase.h"
#endif
#define NOAH_NoahGameModeBase_generated_h

#define Noah_Source_Noah_NoahGameModeBase_h_14_RPC_WRAPPERS
#define Noah_Source_Noah_NoahGameModeBase_h_14_RPC_WRAPPERS_NO_PURE_DECLS
#define Noah_Source_Noah_NoahGameModeBase_h_14_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesANoahGameModeBase(); \
	friend NOAH_API class UClass* Z_Construct_UClass_ANoahGameModeBase(); \
	public: \
	DECLARE_CLASS(ANoahGameModeBase, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient), 0, TEXT("/Script/Noah"), NO_API) \
	DECLARE_SERIALIZER(ANoahGameModeBase) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Noah_Source_Noah_NoahGameModeBase_h_14_INCLASS \
	private: \
	static void StaticRegisterNativesANoahGameModeBase(); \
	friend NOAH_API class UClass* Z_Construct_UClass_ANoahGameModeBase(); \
	public: \
	DECLARE_CLASS(ANoahGameModeBase, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient), 0, TEXT("/Script/Noah"), NO_API) \
	DECLARE_SERIALIZER(ANoahGameModeBase) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Noah_Source_Noah_NoahGameModeBase_h_14_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ANoahGameModeBase(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ANoahGameModeBase) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ANoahGameModeBase); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ANoahGameModeBase); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ANoahGameModeBase(ANoahGameModeBase&&); \
	NO_API ANoahGameModeBase(const ANoahGameModeBase&); \
public:


#define Noah_Source_Noah_NoahGameModeBase_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ANoahGameModeBase(ANoahGameModeBase&&); \
	NO_API ANoahGameModeBase(const ANoahGameModeBase&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ANoahGameModeBase); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ANoahGameModeBase); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ANoahGameModeBase)


#define Noah_Source_Noah_NoahGameModeBase_h_14_PRIVATE_PROPERTY_OFFSET
#define Noah_Source_Noah_NoahGameModeBase_h_11_PROLOG
#define Noah_Source_Noah_NoahGameModeBase_h_14_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Noah_Source_Noah_NoahGameModeBase_h_14_PRIVATE_PROPERTY_OFFSET \
	Noah_Source_Noah_NoahGameModeBase_h_14_RPC_WRAPPERS \
	Noah_Source_Noah_NoahGameModeBase_h_14_INCLASS \
	Noah_Source_Noah_NoahGameModeBase_h_14_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Noah_Source_Noah_NoahGameModeBase_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Noah_Source_Noah_NoahGameModeBase_h_14_PRIVATE_PROPERTY_OFFSET \
	Noah_Source_Noah_NoahGameModeBase_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	Noah_Source_Noah_NoahGameModeBase_h_14_INCLASS_NO_PURE_DECLS \
	Noah_Source_Noah_NoahGameModeBase_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Noah_Source_Noah_NoahGameModeBase_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS