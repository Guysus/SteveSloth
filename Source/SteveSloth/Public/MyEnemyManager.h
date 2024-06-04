/****************************************************************************************
* Copyright: SteveSloth
 * Name: Jeff Moreau
 * Script: MyEnemyManager.h
 * Date: May 8, 2024
 * Description: To take care of all Enemy entities in the game. Easy place to access
 * TODO: 
 * Known Bugs:
 ****************************************************************************************/

#pragma once

// INCLUDES HERE
#include "CoreMinimal.h"
#include "Engine/World.h"

// MAKE SURE THIS INCLUDE IS LAST
#include "MyEnemyManager.generated.h"

UCLASS()
class STEVESLOTH_API AMyEnemyManager : public AActor
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SpawnPoints")
	TArray<AActor*> SpawnPoints;

public:	// CONSTRUCTOR HERE
	AMyEnemyManager();

protected: // INITIALIZE INHERITABLE FUNCTIONS
	virtual void BeginPlay() override;

public:	// UPDATE ACCESS ANYWHERE FUNCTIONS
	virtual void Tick(float DeltaTime) override;
};