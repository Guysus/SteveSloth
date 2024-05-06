/****************************************************************************************
* Copyright: SteveSloth
 * Name: Jeff Moreau
 * Script: MyGameManager.h
 * Date: April 23. 2024
 * Description: This is the Game Manager that will direct the flow of the game
 * TODO: 
 * Known Bugs: 
 ****************************************************************************************/

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "LevelInstance/LevelInstanceActor.h"
#include "MyPlayer.h"
#include "MyOldGameManager.generated.h"

UCLASS()
class STEVESLOTH_API UMyOldGameManager : public UGameInstance
{
	GENERATED_BODY()

// SINGLETON STUFF
public:
	static UMyOldGameManager* pInstance;
	UMyOldGameManager* Instance();

	UFUNCTION(BlueprintCallable)
	static UMyOldGameManager* GetInstance();
	
// SINGLETON END
	
private:
	//ELevels CurrentLevel;
	
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<ALevelInstance*> GameLevels;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	AMyPlayer* Player;

public:
	UMyOldGameManager();
	AMyPlayer* GetPlayer() const { return Player; }

private:
	void InitializeVariables();
};
