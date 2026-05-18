// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Backpack.generated.h"

USTRUCT(BlueprintType)
struct FBackpackSlot
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector Offset;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool inUse;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AActor* PreviewActor;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ItemID;
};


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TRACES2_API UBackpack : public USceneComponent
{
	GENERATED_BODY()

public:	
	UBackpack();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FBackpackSlot> Slot;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector OpenLocation;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector CloseLocation;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Open;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	void ToggleInventory();
	
	UFUNCTION(BlueprintCallable)
	void AddItemToNextFreeSlot(FString ItemID);
		
};
