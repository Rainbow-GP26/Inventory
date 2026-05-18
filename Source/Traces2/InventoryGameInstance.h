// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "FItemRow.h"
#include "InventoryGameInstance.generated.h"


/**
 * 
 */
UCLASS()
class TRACES2_API UInventoryGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
	public:
	
	virtual void Init() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UDataTable* ItemsTable;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TMap<FString, FItemRow> Items;
	
	UFUNCTION()
	FItemRow GetItemByID(FString ItemID);
};
