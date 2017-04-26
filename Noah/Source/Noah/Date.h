// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Engine/DirectionalLight.h"
#include "Runtime/Engine/Classes/Engine/SkyLight.h"
#include "Date.generated.h"

UCLASS()
class NOAH_API ADate : public AActor
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "DateSystem")
		float SunDrive;	//해의 위치
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "DateSystem")
		float DayDuration; //하루가 지나는데 걸리는 시간.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "DateSystem")
		float MaxSunHeight; //해의 최대 높이(-1~-99)
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "DateSystem")
		ADirectionalLight* DirectionLight;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "DateSystem")
		AActor* SkySphere;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "DateSystem")
		ASkyLight* SkyLight;
public:	
	// Sets default values for this actor's properties
	ADate();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "DateSystem")
		void Tomorrow();
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "DateSystem")
		void SunUp();
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "DateSystem")
		void SunDown();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//변수에 따른 해의 위치(회전값)를 구해온다.
	UFUNCTION(BlueprintCallable, Category = "DateSystem")
		FRotator SeekSunRotator(float _sunDrive, float _dayDuration, float _maxSunHeight);
};