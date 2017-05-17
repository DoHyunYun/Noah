// Fill out your copyright notice in the Description page of Project Settings.

#include "Noah.h"
#include "NPC.h"


// Sets default values
ANPC::ANPC() : Health(100.f)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ANPC::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANPC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ANPC::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

bool ANPC::FindStateList(ENPCStateEnum state)
{
	if (NPCStateList.Find(state) != -1) {
		return true;
	}
	return false;
}

ENPCStateEnum ANPC::NPCStateUpdate(APawn* target)
{
	float distance = FVector::Dist(target->GetActorLocation(), this->GetActorLocation());

	if (NPCStateList.Find(ENPCStateEnum::VE_Attack) != -1) {
		if (distance <= 200) {
			return ENPCStateEnum::VE_Attack;
		}
	}

	if (NPCStateList.Find(ENPCStateEnum::VE_Trace) != -1) {
		if (distance <= 1500) {
			return ENPCStateEnum::VE_Trace;
		}
	}

	return ENPCStateEnum::VE_Idle;
}