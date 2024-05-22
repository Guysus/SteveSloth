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
	
protected: // PROTECTED DETAILS PANEL VARIABLES 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (RowType = "MyItemData"), Category = "Data")
	FDataTableRowHandle ItemDataTable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Attributes")
	bool bIsItemUnlocked;

private: // PRIVATE INTERNAL VARIABLES
	FString Name;
	int StackAmount;
	bool bIsCurrency;
	float DropChance;
	UStaticMeshComponent* Mesh;

public:	// CONSTRUCTOR HERE
	AItemBaseClass();

protected: // INITIALIZE INHERITABLE FUNCTIONS
	virtual void BeginPlay() override;

public:	// UPDATE ACCESS ANYWHERE FUNCTIONS
	virtual void Tick(float DeltaTime) override;
};