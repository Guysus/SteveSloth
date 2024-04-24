/****************************************************************************************
 * Copyright:
 * Name: Guy Lapensee
 * Script: ItemBaseClass
 * Date: April 23, 2024
 * Description:Base Class for Items
 * TODO: 
 * Known Bugs: 
 ****************************************************************************************/

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemBaseClass.generated.h"

UCLASS()
class STEVESLOTH_API AItemBaseClass : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItemBaseClass();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Attributes")
	//Store all the item names
	FString ItemName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Attributes")
	int StackAmount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Attributes")
	bool isItemUnlocked;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Attributes")
	float DropChance;

	
};