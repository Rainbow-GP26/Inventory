#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include  "FItemRow.generated.h"

USTRUCT(BlueprintType)
struct FItemRow: public FTableRowBase
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString ItemId;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString ItemName;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UTexture2D* ItemIcon;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int Weight;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<AActor> ActorClass;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<AActor> PreviewActor;
	
	
};
