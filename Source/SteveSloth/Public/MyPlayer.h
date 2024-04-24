/****************************************************************************************
 * Copyright: SteveSloth
 * Name: Tammy Boisvert
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

UCLASS()
class STEVESLOTH_API AMyPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override; 

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category "Health")
	float MaxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category "Health")
	float CurrentHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category "Inventory")
	int CurrentSlingshotAmmo;

	// empty aray to store abilities unlocked
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category "Progress")
	array<String>AbilitiesUnlocked;

	// empty array to store unlocked ammo types
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category "Progress")
	array<String>UnlockedAmmoTypes;

	// Count Levels completed
	int LevelsCompleted;
	//Count Bosses Killed
	int BossesKilled;
	//Count Leaves Found
	int LeavesFound;
	//Count Grubs Collected
    int GrubsCollected;


	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
