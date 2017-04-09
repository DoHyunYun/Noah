// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include <queue>
#include "GameFramework/Actor.h"
#include "Inventory.generated.h"


USTRUCT(BlueprintType)
struct FItemStruct { //아이템 구조체
	GENERATED_USTRUCT_BODY();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
		int itemIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
		int number;//갯수

	char namecode[100];
	char name[100];//이름
	char info[500];//설명
	int lapseType;//소멸타입
	int itemType;//일반/착용
	int durability;//내구도
	int price;//가격

	int att;//공격력
	int hp;//채집시
	int weight;//중량
			//이후 아이템 속성 추가.
};

UCLASS(BlueprintType)
class NOAH_API AInventory : public AActor
{
	GENERATED_BODY(BlueprintType)

public:
	// Sets default values for this actor's properties
	AInventory();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//=========================== 인벤토리 ==============================
	//변수
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Inventory")
		TArray<FItemStruct> m_myInventory;	//아이템을 담을 인벤토리 배열
private:
	//GENERATED_BODY()

	int m_maxInvenSize;		//최대 아이템 보유량
	int m_currentInvenSize;	//현재 아이템 보유량

	//함수
public:
	//input
	UFUNCTION(BlueprintCallable, Category = "Inventory")
		bool AddItem(FItemStruct _item); //아이템 추가

	UFUNCTION(BlueprintCallable, Category = "Inventory")
		bool RemoveItem(int _arrayIndex); //아이템 삭제

	UFUNCTION(BlueprintCallable, Category = "Inventory")
		bool SwapItemIndex(int _index, int _swapIndex); //아이템 위치교환

	UFUNCTION(BlueprintCallable, Category = "Inventory")
		void SortInventory();

private:
	void InitItem(FItemStruct *_item);
	//output
	//=========================== 인벤토리 ==============================
};
