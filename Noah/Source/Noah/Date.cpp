// Fill out your copyright notice in the Description page of Project Settings.

#include "Noah.h"
#include "Date.h"

// Sets default values
ADate::ADate() : SunDrive(0.f), DayDuration(0.f), MaxSunHeight(0.f), DirectionLight(nullptr), SkySphere(nullptr),
SkyLight(nullptr)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADate::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADate::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FRotator ADate::SeekSunRotator(float _sunDrive, float _dayDuration, float _maxSunHeight)
{
	float pitch = FMath::Sin((((_sunDrive / _dayDuration) * 2) * PI)) * _maxSunHeight;
	float yaw = (_sunDrive * 360) / _dayDuration;
	FRotator rot(pitch, yaw, 0.f);

	return rot;
}
