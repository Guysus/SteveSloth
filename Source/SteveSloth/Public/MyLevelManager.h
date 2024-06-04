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
	bool bIsValveOneOpen;

	UPROPERTY(BlueprintReadWrite)
	bool bIsInValveOneArea;

	UPROPERTY(BlueprintReadWrite)
	bool bIsValveOneOperated;
	
	UPROPERTY(BlueprintReadWrite)
	bool bIsValveTwoOpen;

	UPROPERTY(BlueprintReadWrite)
	bool bIsInValveTwoArea;

	UPROPERTY(BlueprintReadWrite)
	bool bIsValveTwoOperated;

	UPROPERTY(BlueprintReadWrite)
	bool bIsValveThreeOpen;

	UPROPERTY(BlueprintReadWrite)
	bool bIsInValveThreeArea;

	UPROPERTY(BlueprintReadWrite)
	bool bIsValveThreeOperated;

private: // PRIVATE INTERNAL VARIABLES
	int TotalLevels;

	FString CurrentLevelName;
	
public: // GETTERS/ACCESSORS
	UFUNCTION(BlueprintCallable)
	int GetTotalLevels() const { return TotalLevels; }

	UFUNCTION(BlueprintCallable)
	bool GetValeOneOpen() const { return bIsValveOneOpen; }

	UFUNCTION(BlueprintCallable)
	bool GetValeTwoOpen() const { return bIsValveTwoOpen; }

	UFUNCTION(BlueprintCallable)
	bool GetValeThreeOpen() const { return bIsValveThreeOpen; }

	UFUNCTION(BlueprintCallable)
	bool GetValveAreaOne() { return bIsInValveOneArea; }

	UFUNCTION(BlueprintCallable)
	bool GetValveAreaTwo() { return bIsInValveTwoArea; }

	UFUNCTION(BlueprintCallable)
	bool GetValveAreaThree() { return bIsInValveThreeArea; }

	UFUNCTION(BlueprintCallable)
	bool GetValveOneOperated() { return bIsValveOneOperated; }

	UFUNCTION(BlueprintCallable)
	bool GetValveTwoOperated() { return bIsValveTwoOperated; }

	UFUNCTION(BlueprintCallable)
	bool GetValveThreeOperated() { return bIsValveThreeOperated; }

	UFUNCTION(BlueprintCallable)
	FString GetCurrentLevelName() { return CurrentLevelName; }

public: // SETTERS/MUTATORS
	UFUNCTION(BlueprintCallable)
	void SetValveOneOperated(bool yesno) { bIsValveOneOperated = yesno; }

	UFUNCTION(BlueprintCallable)
	void SetValveTwoOperated(bool yesno) { bIsValveTwoOperated = yesno; }

	UFUNCTION(BlueprintCallable)
	void SetValveThreeOperated(bool yesno) { bIsValveThreeOperated = yesno; }

	UFUNCTION(BlueprintCallable)
	void SetValveAreaOne(bool yesno) { bIsInValveOneArea = yesno; }

	UFUNCTION(BlueprintCallable)
	void SetValveAreaTwo(bool yesno) { bIsInValveTwoArea = yesno; }

	UFUNCTION(BlueprintCallable)
	void SetValveAreaThree(bool yesno) { bIsInValveThreeArea = yesno; }

	UFUNCTION(BlueprintCallable)
	void SetValveOneOpen(bool yesno) { bIsValveOneOpen = yesno; }

	UFUNCTION(BlueprintCallable)
	void SetValveTwoOpen(bool yesno) { bIsValveTwoOpen = yesno; }

	UFUNCTION(BlueprintCallable)
	void SetValveThreeOpen(bool yesno) { bIsValveThreeOpen = yesno; }

public:	// CONSTRUCTOR HERE
	AMyLevelManager();

protected: // INITIALIZE INHERITABLE FUNCTIONS
	virtual void BeginPlay() override;

public:	// UPDATE ACCESS ANYWHERE FUNCTIONS
	virtual void Tick(float DeltaTime) override;
	void ChangeLevel(ELevels level);
};