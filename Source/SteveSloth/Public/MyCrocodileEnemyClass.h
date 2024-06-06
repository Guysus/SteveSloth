/****************************************************************************************
 * Copyright: SteveSloth
 * Name: Elad Saretzky
 * Script: MyCrocodileEnemyClass.h
 * Date: May 10, 2024
 * Description: Does all of the specific to Crocodile things
 * TODO:
 * Known Bugs:
 ****************************************************************************************/

#pragma once

// INCLUDES HERE
#include "CoreMinimal.h"
#include "MyEnemyBaseClass.h"

// MAKE SURE THIS INCLUDE IS LAST
#include "MyCrocodileEnemyClass.generated.h"

UCLASS()
class STEVESLOTH_API AMyCrocodileEnemyClass : public AMyEnemyBaseClass
{
	GENERATED_BODY()

private: //PRIVATE CONST VARIABLES
	const float IDLE_TIMER_AMOUNT = 2.5f;
	const float IDLE_VELOCITY_TOLERANCE = 0.001f;
	const float IDLE_RESET_TIMER_AMOUNT = 1.0f;

private: // PRIVATE INTERNAL VARIABLES
	FTimerHandle StartFleeTimerHandle;
	FTimerHandle IdleResetTimerHandle;

	bool bIsFrozen;
	bool bIsCurrentlyFrozen;
	bool bIsConfused;
	bool bIsCurrentlyConfused;
	bool bIsDead;
	bool bIsIdle;
	bool bIsChasing;
	bool bIsPatroling;
	bool bIsAttackingMelee;
	bool bIsAttackingRanged;

	UMyEnemyBaseState* IdleState;
	UMyEnemyBaseState* PatrolState;
	UMyEnemyBaseState* ChaseState;
	UMyEnemyBaseState* FleeState;
	UMyEnemyBaseState* AttackState;
	UMyEnemyBaseState* RangedAttackState;
	UMyEnemyBaseState* FrozenState;
	UMyEnemyBaseState* ConfusedState;
	UMyEnemyBaseState* DieState;

public:	// CONSTRUCTOR HERE
	AMyCrocodileEnemyClass();

protected: // INITIALIZE INHERITABLE FUNCTIONS
	virtual void BeginPlay() override;

public:	// UPDATE ACCESS ANYWHERE FUNCTIONS
	virtual void Tick(float DeltaTime) override;

//private: // PRIVATE INTERNAL FUNCTIONS
//	void StartFleeState();
//	void IdleReset();
};