/****************************************************************************************
* Copyright: SteveSloth
 * Name: Jeff Moreau
 * Script: MyAchievementManager.h
 * Date: April 23. 2024
 * Description: Keep Track of In game Achievements per 
 * TODO: 
 * Known Bugs: 
 ****************************************************************************************/

#pragma once

 // INCLUDES HERE
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

// MAKE SURE THIS INCLUDE IS LAST
#include "MyAchievementManager.generated.h"

// Structure for Achievements
USTRUCT(BlueprintType)
struct FMyAchievements
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString Name;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString Description;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool IsUnlocked;
};

UCLASS()
class STEVESLOTH_API AMyAchievementManager : public AActor
{
	GENERATED_BODY()

protected: // PROTECTED DETAILS PANEL VARIABLES 
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<FMyAchievements> AchievementList;
	
public:	// CONSTRUCTOR HERE
	AMyAchievementManager();

protected: // INITIALIZE INHERITABLE FUNCTIONS
	virtual void BeginPlay() override;

public:	// UPDATE ACCESS ANYWHERE FUNCTIONS
	virtual void Tick(float DeltaTime) override;
};