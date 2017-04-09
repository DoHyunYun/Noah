// Fill out your copyright notice in the Description page of Project Settings.

#include "Noah.h"
#include "Inventory.h"

// Sets default values
AInventory::AInventory()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_maxInvenSize = 24;
	m_currentInvenSize = 0;


	//인벤토리 초기화
	//초기화 아이템
	FItemStruct item;
	InitItem(&item);
	
	//인벤토리 아이템 슬롯 생성
	for (int i = 0; i < m_maxInvenSize; i++) {
		m_myInventory.Add(item);
	}
	/*
	FItemStruct item1 = { 1, 1 };
	AddItem(item1);
	FItemStruct item2 = { 2, 1 };
	AddItem(item2);
	FItemStruct item3 = { 3, 2 };
	AddItem(item3);
	FItemStruct item4 = { 4, 2 };
	AddItem(item4);
	FItemStruct item5 = { 10, 99 };
	AddItem(item5);*/
}

void AInventory::InitItem(FItemStruct *_item) {
	_item->itemIndex = -1;
	_item->number = -1;
}

// Called when the game starts or when spawned
void AInventory::BeginPlay()
{

	Super::BeginPlay();

}

// Called every frame
void AInventory::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//아이템 추가
bool AInventory::AddItem(FItemStruct _item)
{
	//아이템이 비어있을 경우 추가. 그렇지 않으면 return false
	for (int i = 0; i < m_maxInvenSize; i++) {
		if (m_myInventory[i].itemIndex == -1) {
			m_myInventory[i] = _item;
			return true;
		}
	}

	return false;
}

//아이템 삭제
bool AInventory::RemoveItem(int _arrayIndex)
{
	//예외처리
	if (_arrayIndex < 0 || _arrayIndex >= m_maxInvenSize) return false;

	//초기화
	m_myInventory[_arrayIndex].itemIndex = -1;

	return true;
}

bool AInventory::SwapItemIndex(int _arrayIndex, int _swapIndex)
{
	//예외처리
	if (_arrayIndex < 0 || _arrayIndex >= m_maxInvenSize ||
		_swapIndex < 0 || _swapIndex >= m_maxInvenSize) return false;

	FItemStruct tempItem;

	tempItem = m_myInventory[_arrayIndex];
	m_myInventory[_arrayIndex] = m_myInventory[_swapIndex];
	m_myInventory[_swapIndex] = tempItem;

	//UE_LOG(LogTemp, Warning, TEXT("%d"), m_myInventory.Max());

	return true;
}

//인벤토리 정렬
void AInventory::SortInventory()
{
	//C++ STL Queue http://www.cplusplus.com/reference/queue/queue/
	std::queue<int> tempSlot;
	
	for (int i = 0; i < m_maxInvenSize; i++) {
		if (m_myInventory[i].itemIndex == -1) {
			tempSlot.push(i);
		}
		else if(!tempSlot.empty()){
			SwapItemIndex(i, tempSlot.front());
			tempSlot.pop();
			tempSlot.push(i);
		}
	}
}