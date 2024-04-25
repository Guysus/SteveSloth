/****************************************************************************************
 * Copyright: SteveSloth
 * Name: Tammy Boisvert edited by Jeff
 * Script: MyPlayer.h
 * Date: April 23. 2024
 * Description: This is the Player Base Class Script
 * TODO:
 * Known Bugs:
 ****************************************************************************************/

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyPlayer.generated.h"

enum class AmmoTypes
{
	Pebble,
	FireCracker,
	WaterBalloon,
	PoisonSac,
	ChristmasBeetle,
	BigRock
};

UCLASS()
class STEVESLOTH_API AMyPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	AMyPlayer();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override; 
	
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float CurrentHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CurrentSlingshotAmmo;

	
	int LevelsCompleted;
	int BossesKilled;
	int LeavesFound;
    int GrubsCollected;

	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
