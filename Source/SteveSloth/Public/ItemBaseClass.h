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
#include "MyPlayer.h"
#include "MyItemData.h"
#include "CoreMinimal.h"
#include "SteveSingleton.h"
#include "MyEnemyBaseClass.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"

// MAKE SURE THIS INCLUDE IS LAST
#include "ItemBaseClass.generated.h"

UCLASS()
class STEVESLOTH_API AItemBaseClass : public AActor
{
	GENERATED_BODY()
	
protected: // PROTECTED DETAILS PANEL VARIABLES 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (RowType = "MyItemData"), Category = "Data")
	FDataTableRowHandle ItemDataTable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UBoxComponent* ItemHitBox;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Attributes")
	bool bIsItemUnlocked;

private: // PRIVATE INTERNAL VARIABLES
	AMyPlayer* Steve;
	ACharacter* Player;

	AMyEnemyBaseClass* Enemy;
	UStaticMeshComponent* Mesh;

	TEnumAsByte<EItemType> ItemType;

	FString Name;

	float Health;
	float DropChance;

	int StackAmount;
	bool bIsCurrency;

public:	// CONSTRUCTOR HERE
	AItemBaseClass();

protected: // INITIALIZE INHERITABLE FUNCTIONS
	virtual void BeginPlay() override;

public:	// UPDATE ACCESS ANYWHERE FUNCTIONS
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnHitboxOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};