// Fill out your copyright notice in the Description page of Project Settings.


#include "Backpack.h"
#include "Traces2/FItemRow.h"
#include "Traces2/InventoryGameInstance.h"

// Sets default values for this component's properties
UBackpack::UBackpack()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UBackpack::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

// Called every frame
void UBackpack::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	
}

void UBackpack::ToggleInventory()
{
	if (Open)
	{
		SetRelativeLocation(CloseLocation);
	}
	else
	{
		SetRelativeLocation(OpenLocation);
	}
	
	Open = !Open;
}

void UBackpack::AddItemToNextFreeSlot(FString ItemID)
{
	for (auto &ItemSlot : Slot)
	{
		if (ItemSlot.inUse == false)
		{
			ItemSlot.inUse = true;	
			ItemSlot.ItemID = ItemID;

			UInventoryGameInstance* InventoryGameInstance = Cast<UInventoryGameInstance>(GetWorld()->GetGameInstance());
			
			FItemRow ItemRow = InventoryGameInstance->GetItemByID(ItemID);
			
			 FVector SpawnLocation = GetComponentLocation() + ItemSlot.Offset;
			 FRotator Rotation = GetComponentRotation();
			
			 FActorSpawnParameters SpawnParams;
			 SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
			
			 AActor* PreviewActor = GetWorld()->SpawnActor<AActor>(ItemRow.PreviewActor, SpawnLocation, Rotation, SpawnParams);
			 PreviewActor->AttachToComponent(this, FAttachmentTransformRules::KeepWorldTransform);
			
			PreviewActor->SetActorRelativeLocation(ItemSlot.Offset);
			ItemSlot.PreviewActor = PreviewActor;
			
			return;
		}
	}
}

