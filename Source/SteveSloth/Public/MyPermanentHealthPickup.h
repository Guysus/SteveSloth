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
#include "MyPermanentHealthPickup.generated.h"

/**
 * 
 */
UCLASS()
class STEVESLOTH_API AMyPermanentHealthPickup : public AItemBaseClass
{
	GENERATED_BODY()
	
private: // PRIVATE VARIABLES
	AItemBaseClass* ItemClass;

public: // CONSTRUCTOR HERE
	AMyPermanentHealthPickup();
};
