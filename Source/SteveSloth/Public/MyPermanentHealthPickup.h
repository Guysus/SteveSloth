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

UCLASS(Blueprintable)
class STEVESLOTH_API AMyPermanentHealthPickup : public AItemBaseClass
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Attributes")
	float HealthIncrease;

private:
	//Box Component to get collision
	UPROPERTY(EditDefaultsOnly, Category = "Components")
	class UBoxComponent* BoxComp;

	//Create the mesh we will see in the world
	UPROPERTY(EditDefaultsOnly, Category = "Components")
	class UStaticMeshComponent* BaseMesh;

private: // PRIVATE VARIABLES
	AMyPlayer* Steve;
	ACharacter* Player;

public: // CONSTRUCTOR HERE
	AMyPermanentHealthPickup();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private: // PRIVATE INTERNAL FUNCTIONS
	void IncreaseHealthBar();
};
