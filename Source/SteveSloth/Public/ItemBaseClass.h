/****************************************************************************************
 * Copyright:
 * Name: Guy Lapensee, Jeff Moreau
 * Script: ItemBaseClass.h
 * Date: April 23, 2024
 * Description:Base Class for Items
 * TODO: 
 * Known Bugs: 
 ****************************************************************************************/

#pragma once

// INCLUDES HERE
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

// MAKE SURE THIS INCLUDE IS LAST
#include "ItemBaseClass.generated.h"

UCLASS()
class STEVESLOTH_API AItemBaseClass : public AActor
{
	GENERATED_BODY()
	
public:	
	AItemBaseClass();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Attributes")
	int StackAmount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Attributes")
	bool isItemUnlocked;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Attributes")
	float DropChance;
};