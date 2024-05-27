/****************************************************************************************
* Copyright: SteveSloth
 * Name: Jeff Moreau, Edited by Guy Lapensee
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

UENUM(BlueprintType)
enum class EItemType
{
	Leaf UMETA(DisplayName = "Leaf"),
	Grub UMETA(DisplayName = "Grub"),
	Eucalyptus UMETA(DisplayName = "Eucalyptus"),
	GreenBud UMETA(DisplayName = "GreenBud"),
	BlueBud UMETA(DisplayName = "BlueBud"),
	RedBud UMETA(DisplayName = "RedBud"),
	GrapplingHook UMETA(DisplayName = "GrapplingHook")
};

USTRUCT(BlueprintType)
struct STEVESLOTH_API FUMyItemData : public FTableRowBase
{
	GENERATED_BODY()
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FString Name;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UStaticMesh* Mesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TEnumAsByte<EItemType> ItemType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float Health;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	int StackAmount;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float DropChance;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	bool bIsCurrency;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float AddHealthAmount;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float AddHealthPercentage;
};