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
#include "MyGameManager.generated.h"

UCLASS()
class STEVESLOTH_API UMyGameManager : public UGameInstance
{
	GENERATED_BODY()

// SINGLETON STUFF
public:
	static UMyGameManager* pInstance;
	UMyGameManager* Instance();

	UFUNCTION(BlueprintCallable)
	static UMyGameManager* GetInstance();
// SINGLETON END
	
private:
	//ELevels CurrentLevel;
	
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<ALevelInstance*> GameLevels;

public:
	UMyGameManager();

private:
	void InitializeVariables();
};
