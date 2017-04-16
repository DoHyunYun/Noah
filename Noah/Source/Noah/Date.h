// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Date.generated.h"

UCLASS()
class NOAH_API ADate : public AActor
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "DateSystem")
		float SunDrive;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "DateSystem")
		float DayDuration;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "DateSystem")
		float MaxSunHeight;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "DateSystem")
		AActor* SunLight;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "DateSystem")
		AActor* SkySphere;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "DateSystem")
		AActor* AmbLight;
public:	
	// Sets default values for this actor's properties
	ADate();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
