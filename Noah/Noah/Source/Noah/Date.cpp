// Fill out your copyright notice in the Description page of Project Settings.

#include "Noah.h"
#include "Date.h"


// Sets default values
ADate::ADate() : SunDrive(0), DayDuration(0), MaxSunHeight(0), SunLight(nullptr), SkySphere(nullptr), AmbLight(nullptr)
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

