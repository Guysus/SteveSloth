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

#include "CoreMinimal.h"
#include "LevelInstance/LevelInstanceActor.h"
#include "MyPlayer.h"

// MAKE SURE THIS INCLUDE IS LAST
#include "MyGameManager.generated.h"

UCLASS()
class STEVESLOTH_API AMyGameManager : public AActor
{
	GENERATED_BODY()

	// SINGLETON STUFF
public:
	static AMyGameManager* pInstance;
	AMyGameManager* Instance();

	UFUNCTION(BlueprintCallable)
	static AMyGameManager* GetInstance();
	
	// SINGLETON END

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<AMyPlayer> PlayerBlueprint;

	AMyPlayer* Player;
	
public:
	AMyGameManager();
	AMyPlayer* GetPlayer() const { return Player; }
};