/****************************************************************************************
* Copyright: SteveSloth
 * Name: Jeff Moreau
 * Script: MyItemData.h
 * Date: May 21, 2024
 * Description: data table that holds all the item variables
 * TODO:
 * Known Bugs:
 ****************************************************************************************/

#pragma once

// INCLUDES HERE
#include "CoreMinimal.h"
#include "Engine/DataTable.h"

// MAKE SURE THIS INCLUDE IS LAST
#include "MyItemData.generated.h"

USTRUCT(BlueprintType)
struct STEVESLOTH_API FUMyItemData : public FTableRowBase
{
	GENERATED_BODY()
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FString Name;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	int StackAmount;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float DropChance;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	bool bIsCurrency;
};