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

private: // PRIVATE VARIABLES
	AMyPlayer* Steve;
	ACharacter* Player;
 
public:	
	// Sets default values for this actor's properties
	AItemBaseClass();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

protected:
	UPROPERTY(EditAnywhere, Category = "Sound")
	class USoundBase* ItemSound;

private:	
	//Box Component to get collision
	UPROPERTY(EditDefaultsOnly, Category = "Components") 
	class UBoxComponent* BoxComp;

	//Create the mesh we will see in the world
	UPROPERTY(EditDefaultsOnly, Category = "Components") 
	class UStaticMeshComponent* BaseMesh;

	//Create Sprite component
	/*UPROPERTY(EditDefaultsOnly, Category = "Sprite ")
	class UPaperSpite* Sprite;*/

	//Pointer to component,					  
	UFUNCTION() void OnOverlapStart(UPrimitiveComponent* OverlappedComponent, 
		//Pointer to other actor in the overlap,
		AActor* OtherActor,
		//Pointer to component on other actor
		UPrimitiveComponent* OtherComp, 
		int32 OtherBodyIndex, bool bFromSweep, 
		const FHitResult& SweepResult);
	
};
