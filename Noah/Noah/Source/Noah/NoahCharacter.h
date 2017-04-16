// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "Inventory.h"
#include "Craft.h"
#include "NoahCharacter.generated.h"

UCLASS()
class NOAH_API ANoahCharacter : public ACharacter
{
	GENERATED_BODY()
private:
	//카메라 줌이 가능한 최대값과 최소값
	int m_zoomMax;
	int m_zoomMin;
public:
	UPROPERTY(BlueprintReadWrite, Category = "NoahCharacter")
		UInventory* Inventory;
	UPROPERTY(BlueprintReadWrite, Category = "NoahCharacter")
		UCraft* Craft;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* CameraBoom;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* FollowCamera;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseTurnRate;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseLookUpRate;
public:
	// Sets default values for this character's properties
	ANoahCharacter();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveForward(float Value);
	void MoveRight(float Value);
	void LookUpAtRate(float Rate);
	void TurnAtRate(float Rate);
	void CameraZoomRate(float Rate);
	void Attack();
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//Object Detect
public:
	TArray<AActor*> DetectedObject;

public:
	UFUNCTION(BlueprintCallable, Category = "NoahCharacter")
		bool DetectObject(AActor* detectedObject); //탐색 오브젝트 입력
	UFUNCTION(BlueprintCallable, Category = "NoahCharacter")
		bool MissObject(AActor* missedObject); //오브젝트 제거
	UFUNCTION(BlueprintCallable, Category = "NoahCharacter")
		AActor* FindNearItem(); //가장 가까운 아이템 검색
};
