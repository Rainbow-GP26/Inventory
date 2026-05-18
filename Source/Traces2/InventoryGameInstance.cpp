// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryGameInstance.h"

void UInventoryGameInstance::Init()
{
	Super::Init();
	
	TArray<FItemRow*> AllRows;
	ItemsTable->GetAllRows<FItemRow>(TEXT("BuildItemMap"), AllRows);

	for (FItemRow* Row : AllRows)
	{
		Items.Add(Row->ItemId, *Row);
	}
	
}

FItemRow UInventoryGameInstance::GetItemByID(FString ItemID)
{
	return *Items.Find(ItemID);
}
