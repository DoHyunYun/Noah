// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Item.generated.h"


USTRUCT(BlueprintType)
struct FItemStruct : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "ItemInformation")
		FString NameCode;
	UPROPERTY(BlueprintReadOnly, Category = "ItemInformation")
		FString Name;
	UPROPERTY(BlueprintReadOnly, Category = "ItemInformation")
		FString Information;
	UPROPERTY(BlueprintReadOnly, Category = "ItemInformation")
		FString DeleteType;
	UPROPERTY(BlueprintReadOnly, Category = "ItemInformation")
		FString WorldImgCode;
	UPROPERTY(BlueprintReadOnly, Category = "ItemInformation")
		FString InvenImgCode;
	UPROPERTY(BlueprintReadOnly, Category = "ItemInformation")
		int32  ItemType;
	UPROPERTY(BlueprintReadOnly, Category = "ItemInformation")
		FString DropSound;
	UPROPERTY(BlueprintReadOnly, Category = "ItemInformation")
		int32 Durability;
	UPROPERTY(BlueprintReadOnly, Category = "ItemInformation")
		int32 ItemPrice;
	UPROPERTY(BlueprintReadOnly, Category = "ItemInformation")
		int32 AttackPower;
	UPROPERTY(BlueprintReadOnly, Category = "ItemInformation")
		int32 GatherPower;
	UPROPERTY(BlueprintReadOnly, Category = "ItemInformation")
		int32 Weight;
	UPROPERTY(BlueprintReadOnly, Category = "ItemInformation")
		FString Recipe;
};

UCLASS()
class NOAH_API AItem : public AActor
{
	GENERATED_BODY()
public:	
	// Sets default values for this actor's properties
	AItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
public:
	UFUNCTION(BlueprintCallable, Category = "ItemClass")
		AItem* InitItem(int32 itemCode, int32 number = 1);
	UFUNCTION(BlueprintCallable, Category = "ItemClass")
		UTexture2D* GetItemImage(FString imageName);
	UFUNCTION(BlueprintCallable, Category = "ItemClass")
		void SetMesh();

public:
	UPROPERTY(BlueprintReadWrite, Category = "ItemClass")
	FItemStruct ThisItem;
	UPROPERTY(BlueprintReadWrite, Category = "ItemClass")
	int32 Number;
	UPROPERTY(BlueprintReadWrite, Category = "ItemClass")
	int32 CurrentDurability; //현재 내구도.
	UPROPERTY(BlueprintReadWrite, Category = "ItemClass")
	int32 ItemCode; //데이터 테이블의 아이템 코드.

	UPROPERTY(BlueprintReadWrite, Category = "ItemClass")
	class UStaticMeshComponent* ItemMeshComponent;
};
