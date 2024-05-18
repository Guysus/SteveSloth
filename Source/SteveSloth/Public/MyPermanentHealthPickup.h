/****************************************************************************************
 * Copyright:
 * Name: Guy Lapensee
 * Script: AMyPermanentHealthPickup
 * Date: May 16, 2024
 * Description:Leaf  pickup for 25 permanent health boost
 * TODO: Permanently add health to the players health bar 
 * Known Bugs:
 ****************************************************************************************/

#pragma once

#include "CoreMinimal.h"
#include "ItemBaseClass.h"
#include "MyPlayer.h"
#include "MyPermanentHealthPickup.generated.h"

/**
 * 
 */
UCLASS()
class STEVESLOTH_API AMyPermanentHealthPickup : public AItemBaseClass
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Attributes")
	float HealthIncrease;

private:
	AMyPlayer* Steve;
	ACharacter* Player;

private: // PRIVATE VARIABLES	

public: // CONSTRUCTOR HERE
	AMyPermanentHealthPickup();

private: // PRIVATE INTERNAL FUNCTIONS
	void OnPickUp();
};
