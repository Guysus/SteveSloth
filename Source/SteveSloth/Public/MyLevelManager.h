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

// INCLUDES HERE
#include "CoreMinimal.h"
#include "MyGameManager.h"
#include "SteveSingleton.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"

// MAKE SURE THIS INCLUDE IS LAST
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
	
protected: // PROTECTED DETAILS PANEL VARIABLES 
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<FString> GameLevels;

	UPROPERTY(BlueprintReadWrite)
	bool isValveOneOpen;

	UPROPERTY(BlueprintReadWrite)
	bool isInValveOneArea;

	UPROPERTY(BlueprintReadWrite)
	bool isValveOneOperated;
	
	UPROPERTY(BlueprintReadWrite)
	bool isVavleTwoOpen;

	UPROPERTY(BlueprintReadWrite)
	bool isInValveTwoArea;

	UPROPERTY(BlueprintReadWrite)
	bool isValveTwoOperated;

	UPROPERTY(BlueprintReadWrite)
	bool isValveThreeOpen;

	UPROPERTY(BlueprintReadWrite)
	bool isInValveThreeArea;

	UPROPERTY(BlueprintReadWrite)
	bool isValveThreeOperated;

private: // PRIVATE INTERNAL VARIABLES
	int TotalLevels;

	FString CurrentLevelName;
	
public: // GETTERS/ACCESSORS
	UFUNCTION(BlueprintCallable)
	int GetTotalLevels() const { return TotalLevels; }

	UFUNCTION(BlueprintCallable)
	bool GetValveAreaOne() { return isInValveOneArea; }

	UFUNCTION(BlueprintCallable)
	bool GetValveAreaTwo() { return isInValveTwoArea; }

	UFUNCTION(BlueprintCallable)
	bool GetValveAreaThree() { return isInValveThreeArea; }

	UFUNCTION(BlueprintCallable)
	bool GetValveOneOperated() { return isValveOneOperated; }

	UFUNCTION(BlueprintCallable)
	FString GetCurrentLevelName() { return CurrentLevelName; }

public: // SETTERS/MUTATORS
	UFUNCTION(BlueprintCallable)
	void SetValveOneOperated(bool yesno) { isValveOneOperated = yesno; }

	UFUNCTION(BlueprintCallable)
	void SetValveAreaOne(bool yesno) { isInValveOneArea = yesno; }

public:	// CONSTRUCTOR HERE
	AMyLevelManager();

protected: // INITIALIZE INHERITABLE FUNCTIONS
	virtual void BeginPlay() override;

public:	// UPDATE ACCESS ANYWHERE FUNCTIONS
	virtual void Tick(float DeltaTime) override;
	void ChangeLevel(ELevels level);
};