/****************************************************************************************
 * Copyright: SteveSloth
 * Name: Elad Saretzky
 * Script: MyBaseDestructibleObject.h
 * Date: May 30, 2024
 * Description: Handles the logic for destructible objects such as crates
 * TODO:
 * Known Bugs:
 ****************************************************************************************/

#pragma once

// INCLUDES HERE

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"

// MAKE SURE THIS INCLUDE IS LAST
#include "MyBaseDestructibleObject.generated.h"

UCLASS()
class STEVESLOTH_API AMyBaseDestructibleObject : public AActor
{
	GENERATED_BODY()
	
protected: // PROTECTED DETAILS PANEL VARIABLES 
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UBoxComponent* ObjectHitBox;


public:	// CONSTRUCTOR HERE
	AMyBaseDestructibleObject();

protected: // INITIALIZE INHERITABLE FUNCTIONS
	virtual void BeginPlay() override;

public:	// UPDATE ACCESS ANYWHERE FUNCTIONS
	virtual void Tick(float DeltaTime) override;

};
