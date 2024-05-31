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
	GreenBud UMETA(DisplayName = "Green Bud"),
	BlueBud UMETA(DisplayName = "Blue Bud"),
	RedBud UMETA(DisplayName = "Red Bud"),
	PebbleAmmo UMETA(DisplayName = "Pebble Ammo"),
	FirecrackerAmmo UMETA(DisplayName = "Firecracker Ammo"),
	WaterBalloonAmmo UMETA(DisplayName = "Water Balloon Ammo"),
	PoisonSacAmmo UMETA(DisplayName = "Poison Sac Ammo"),
	ChristmasBeetleAmmo UMETA(DisplayName = "Christmas Beetle Ammo"),
	BigRockAmmo UMETA(DisplayName = "Big Rock Ammo"),
	GrapplingHook UMETA(DisplayName = "Grappling Hook")
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
	bool bIsAmmo;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float AddHealthAmount;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float AddHealthPercentage;
};