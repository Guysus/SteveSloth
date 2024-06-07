/****************************************************************************************
 * Copyright: SteveSloth
 * Name: Elad Saretzky
 * Script: MyPossumEnemyClass.h
 * Date: May 6, 2024
 * Description: Does all of the specific to possum things
 * TODO:
 * Known Bugs:
 ****************************************************************************************/

#pragma once

// INCLUDES HERE
#include "CoreMinimal.h"
#include "MyEnemyBaseClass.h"

// MAKE SURE THIS INCLUDE IS LAST
#include "MyPossumEnemyClass.generated.h"

UCLASS()
class STEVESLOTH_API AMyPossumEnemyClass : public AMyEnemyBaseClass
{
	GENERATED_BODY()

private: //PRIVATE CONST VARIABLES
	const float IDLE_TIMER_AMOUNT = 1.0f;
	const float IDLE_VELOCITY_TOLERANCE = 0.001f;
	const float IDLE_RESET_TIMER_AMOUNT = 1.0f;
	const float RANGED_RESET_TIMER_AMOUNT = 1.0f;

private: // PRIVATE INTERNAL VARIABLES
	FTimerHandle StartFleeTimerHandle;
	FTimerHandle IdleResetTimerHandle;
	FTimerHandle RangedResetTimerHandle;
	UMyEnemyStateComponent* StateMachine;
public:	// CONSTRUCTOR HERE
	AMyPossumEnemyClass();

protected: // INITIALIZE INHERITABLE FUNCTIONS
	virtual void BeginPlay() override;

public:	// UPDATE ACCESS ANYWHERE FUNCTIONS
	virtual void Tick(float DeltaTime) override;

private: // PRIVATE INTERNAL FUNCTIONS
	void IdleReset();
	void StartFleeState(); 
	void RangedAttackOver();
};