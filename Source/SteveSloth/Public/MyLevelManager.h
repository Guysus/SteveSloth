/****************************************************************************************
* Copyright: SteveSloth
 * Name: Jeff Moreau
 * Script: MyLevelManager.h
 * Date: April 24. 2024
 * Description: This is where we can manage all levels and get information for levels
 * TODO: 
 * Known Bugs: 
 ****************************************************************************************/

#pragma once

#include "CoreMinimal.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Actor.h"
#include "MyGameManager.h"
#include "MyLevelManager.generated.h"

class ALevelInstance;

enum ELevels
{
	Hub,
	LevelOne,
	LevelTwo,
	LevelThree,
	LevelFour,
	LevelFive
};

UCLASS()
class STEVESLOTH_API AMyLevelManager : public AActor
{
	GENERATED_BODY()

public: // SINGLETON STUFF
	static AMyLevelManager* pInstance;
	AMyLevelManager* Instance();

	UFUNCTION(BlueprintCallable)
	static AMyLevelManager* GetInstance();
	
public: // DETAILS PANEL VARIABLES
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<FString> GameLevels;

private: // PRIVATE VARIABLES
	int TotalLevels;
	FString CurrentLevelName;
	AMyGameManager* MyGameManager;
	AMyPlayer* Player;
	
public: // GETTERS/ACCESSORS
	int GetTotalLevels() const { return TotalLevels; }
	FString GetCurrentLevelName() { return CurrentLevelName; }
	
public: // CONSTRUCTORS / DESTRUCTOR
	AMyLevelManager();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	void ChangeLevel(ELevels level);
	
private: // INTERNAL FUNCTIONS
	void InitializeVariables();
};