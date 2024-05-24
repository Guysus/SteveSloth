/****************************************************************************************
* Copyright: SteveSloth
 * Name: Jeff Moreau
 * Script: MyGameManager.h
 * Date: May 3, 2024
 * Description: This is the Game Manager that will direct the flow of the game
 * TODO: 
 * Known Bugs: 
 ****************************************************************************************/

#pragma once

// INCLUDES HERE
#include "CoreMinimal.h"
#include "SteveSingleton.h"
#include "LevelInstance/LevelInstanceActor.h"

// MAKE SURE THIS INCLUDE IS LAST
#include "MyGameManager.generated.h"

UCLASS()
class STEVESLOTH_API AMyGameManager : public AActor
{
	GENERATED_BODY()

public:// SINGLETON STUFF
	static AMyGameManager* pInstance;
	AMyGameManager* Instance();

	UFUNCTION(BlueprintCallable)
	static AMyGameManager* GetInstance();

public:	// CONSTRUCTOR HERE
	AMyGameManager();
};