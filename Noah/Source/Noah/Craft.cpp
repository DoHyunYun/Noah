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


	//���� ����Ʈ �ʱ�ȭ

	//DataTable �ҷ�����
	UDataTable* GameObjectLookupTable = LoadObject<UDataTable>(nullptr, TEXT("DataTable'/Game/DataTable/DT_Item.DT_Item'"));

	int32 Length = GameObjectLookupTable->GetTableData().Num() - 1;// DataTable ��Data ����
	
	for (int i = 1; i <= Length; i++) {
		//CraftList�� �ֱ����� temp ���� �� �ʱ�ȭ
		FCraftItemStruct TempItemStruct;
		TempItemStruct.ItemCode = i;
		TempItemStruct.RequireItemNum = 1;
		
		//DataTable�� i��° ��� ������
		FString ContextString;
		FItemStruct Item = *GameObjectLookupTable->FindRow<FItemStruct>(FName(*FString::FromInt(i)), ContextString);

		FString RecipeString = Item.Recipe; //�ش� ���� Recipie FString �Է�
		
		//�����ǰ� 0�̸� ����
		if (RecipeString[0] == '0') continue;

		//������ ������ �Է�
		int32 Type = 0;
		FString ItemCodeString = "";
		FString NumberString = "";

		for (int j = 0; j < RecipeString.Len() + 1; j++) {
			//������ ����
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

		//���� �Է�
		TempItemStruct.Price = Item.ItemPrice;


		//������ �ϳ� ���� ����
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