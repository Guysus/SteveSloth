/****************************************************************************************
 * Copyright: SteveSloth
 * Name: Elad Saretzky
 * Script: MyEmuEnemyClass.h
 * Date: May 10, 2024
 * Description: Does all of the specific to emu things
 * TODO:
 * Known Bugs:
 ****************************************************************************************/

#pragma once

// INCLUDES HERE
#include "CoreMinimal.h"
#include "MyEnemyBaseClass.h"

// MAKE SURE THIS INCLUDE IS LAST
#include "MyEmuEnemyClass.generated.h"

UCLASS()
class STEVESLOTH_API AMyEmuEnemyClass : public AMyEnemyBaseClass
{
	GENERATED_BODY()

private: //PRIVATE CONST VARIABLES
	const float IDLE_TIMER_AMOUNT = 10.0f;
	const float IDLE_VELOCITY_TOLERANCE = 0.001f;
	const float IDLE_RESET_TIMER_AMOUNT = 1.0f;
	const int MIN_RANDOM_RANGE = 0;
	const int MAX_RANDOM_RANGE = 50;
	const int IDLE_TRIGGER = 1;
	const int PATROL_TRIGGER = 42;

private: // PRIVATE VARIABLES 
	FTimerHandle StartFleeTimerHandle;
	FTimerHandle IdleResetTimerHandle;

public:	// CONSTRUCTOR HERE
	AMyEmuEnemyClass();

protected: // INITIALIZE INHERITABLE FUNCTIONS
	virtual void BeginPlay() override;

public:	// UPDATE ACCESS ANYWHERE FUNCTIONS
	virtual void Tick(float DeltaTime) override;

private: // PRIVATE INTERNAL FUNCTIONS
	void StartFleeState();
	void IdleReset();
};