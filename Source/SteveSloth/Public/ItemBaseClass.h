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
#include "SteveSingleton.h"
#include "MyPlayer.h"
#include "ItemBaseClass.generated.h"


UCLASS()
class STEVESLOTH_API AItemBaseClass : public AActor
{
	GENERATED_BODY()


public:	// DETAILS PANEL VARIABLES (UPROPERTY) NEED TO BE PUBLIC
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Attributes")
	//Store all the item names
	FString ItemName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Attributes")
	int StackAmount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Attributes")
	bool isItemUnlocked;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Attributes")
	float DropChance;

protected:
	UPROPERTY(EditAnywhere, Category = "Sound")
	class USoundBase* ItemSound;

	//Create Sprite component
	/*UPROPERTY(EditDefaultsOnly, Category = "Sprite ")
	class UPaperSpite* Sprite;*/

public:
	UFUNCTION() void OnOverlapStart(UPrimitiveComponent* OverlappedComponent,
		//POINTER TO OTHER ACTOR,
		AActor* OtherActor,
		//POINTER TO COMPONENT ON OTHER ACTOR
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep,
		const FHitResult& SweepResult);

private: // PRIVATE VARIABLES
	AMyPlayer* Steve;
	ACharacter* Player;
	
public:	
	// Sets default values for this actor's properties
	AItemBaseClass();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	// UPDATE ACCESS ANYWHERE FUNCTIONS
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private://PRIVATE INTERNAL FUNCTIONS
	void DespawnItem();
};
