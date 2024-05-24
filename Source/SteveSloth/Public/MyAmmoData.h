/****************************************************************************************
* Copyright: SteveSloth
 * Name: Elad Saretzky
 * Script: MyAmmoData.h
 * Date: May 24, 2024
 * Description: data table that holds all the Ammo variables
 * TODO:
 * Known Bugs:
 ****************************************************************************************/

#pragma once

 // INCLUDES HERE
#include "CoreMinimal.h"
#include "Engine/DataTable.h"

// MAKE SURE THIS INCLUDE IS LAST
#include "MyAmmoData.generated.h"

USTRUCT(BlueprintType)
struct STEVESLOTH_API FMyAmmoData : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FString Name;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UTexture2D* AmmoIcon;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	int MaxAmmo;
};
