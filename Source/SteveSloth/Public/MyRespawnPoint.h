/****************************************************************************************
 * Copyright: SteveSloth
 * Name: Elad Saretzky
 * Script: MyRespawnPoint.h
 * Date: June 7, 2024
 * Description: Updates the respawn point for the player
 * TODO:
 * Known Bugs:
 ****************************************************************************************/

#pragma once

// INCLUDES HERE
#include "MyPlayer.h"
#include "CoreMinimal.h"
#include "SteveSingleton.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"

// MAKE SURE THIS INCLUDE IS LAST
#include "MyRespawnPoint.generated.h"

UCLASS()
class STEVESLOTH_API AMyRespawnPoint : public AActor
{
	GENERATED_BODY()
	
protected: // PROTECTED DETAILS PANEL VARIABLES 
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UBoxComponent* RespawnHitBox;

private: // PRIVATE INTERNAL VARIABLES
	AMyPlayer* Steve;
	ACharacter* Player;

public:	// CONSTRUCTOR HERE
	AMyRespawnPoint();

protected: // INITIALIZE INHERITABLE FUNCTIONS
	virtual void BeginPlay() override;

public:	// UPDATE ACCESS ANYWHERE FUNCTIONS
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnHitboxOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
		bool bFromSweep, const FHitResult& SweepResult);
};
