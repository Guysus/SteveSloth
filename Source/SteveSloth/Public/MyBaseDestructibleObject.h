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
#include "MyBaseDestructibleObject.generated.h"

UCLASS()
class STEVESLOTH_API AMyBaseDestructibleObject : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyBaseDestructibleObject();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
