// Fill out your copyright notice in the Description page of Project Settings.

#include "Noah.h"
#include "Craft.h"


// Sets default values for this component's properties
UCraft::UCraft()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
	
	IsSet = false;
}


// Called when the game starts
void UCraft::BeginPlay()
{
	Super::BeginPlay();

	// ...


	//제작 리스트 초기화

	//DataTable 불러오기
	UDataTable* GameObjectLookupTable = LoadObject<UDataTable>(nullptr, TEXT("DataTable'/Game/DataTable/DT_Item.DT_Item'"));

	int32 Length = GameObjectLookupTable->GetTableData().Num() - 1;// DataTable 행Data 개수
	
	for (int i = 1; i <= Length; i++) {
		//CraftList에 넣기위한 temp 선언 및 초기화
		FCraftItemStruct TempItemStruct;
		TempItemStruct.ItemCode = i;
		TempItemStruct.RequireItemNum = 1;
		
		//DataTable의 i번째 목록 가져옴
		FString ContextString;
		FItemStruct Item = *GameObjectLookupTable->FindRow<FItemStruct>(FName(*FString::FromInt(i)), ContextString);

		FString RecipeString = Item.Recipe; //해당 행의 Recipie FString 입력
		
		//레시피가 0이면 무시
		if (RecipeString[0] == '0') continue;

		//레시피 추출후 입력
		int32 Type = 0;
		FString ItemCodeString = "";
		FString NumberString = "";

		for (int j = 0; j < RecipeString.Len() + 1; j++) {
			//마지막 루프
			if (j == RecipeString.Len()) Type = 3;
			else {
				if (RecipeString[j] == 'x') Type = 2;
				else if (RecipeString[j] == '_') Type = 3;
			}

			switch (Type)
			{
			case 0:
				ItemCodeString += RecipeString[j];
				break;
			case 1:
				NumberString += RecipeString[j];
				break;
			case 2:
				Type = 1;
				break;
			case 3:
				FSimpleItemStruct TempSimpleItemStruct;
				TempSimpleItemStruct.ItemCode = FCString::Atoi(*ItemCodeString);
				TempSimpleItemStruct.Number = FCString::Atoi(*NumberString);
				TempItemStruct.RequireItem.Add(TempSimpleItemStruct);

				ItemCodeString = "";
				NumberString = "";
				Type = 0;
				break;
			default:
				break;
			}
		}

		//가격 입력
		TempItemStruct.Price = Item.ItemPrice;


		//아이템 하나 최종 적용
		CraftList.Add(TempItemStruct);
	}
	
	IsSet = true;
}


// Called every frame
void UCraft::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


bool UCraft::GetCraftApiSet()
{
	return IsSet;
}