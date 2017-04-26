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
		float SunDrive;	//���� ��ġ
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "DateSystem")
		float DayDuration; //�Ϸ簡 �����µ� �ɸ��� �ð�.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "DateSystem")
		float MaxSunHeight; //���� �ִ� ����(-1~-99)
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

	//������ ���� ���� ��ġ(ȸ����)�� ���ؿ´�.
	UFUNCTION(BlueprintCallable, Category = "DateSystem")
		FRotator SeekSunRotator(float _sunDrive, float _dayDuration, float _maxSunHeight);
};