// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Inventory.h"
#include "MapObject.generated.h"


UCLASS()
class NOAH_API AMapObject : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMapObject();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadWrite, Category = "MapObject")
		int HP;
	UPROPERTY(BlueprintReadWrite, Category = "MapObject")
		UInventory* Inventory;

	UFUNCTION(BlueprintCallable, Category = "MapObject")
		int Damaged(int damage);

};
