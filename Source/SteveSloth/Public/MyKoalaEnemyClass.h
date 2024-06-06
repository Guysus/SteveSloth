/****************************************************************************************
 * Copyright: SteveSloth
 * Name: Elad Saretzky
 * Script: MyKoalaEnemyClass.h
 * Date: May 10, 2024
 * Description: Does all of the specific to Koala things
 * TODO:
 * Known Bugs:
 ****************************************************************************************/

#pragma once

// INCLUDES HERE
#include "CoreMinimal.h"
#include "MyEnemyBaseClass.h"

// MAKE SURE THIS INCLUDE IS LAST
#include "MyKoalaEnemyClass.generated.h"

UCLASS()
class STEVESLOTH_API AMyKoalaEnemyClass : public AMyEnemyBaseClass
{
	GENERATED_BODY()

protected: //PRIVATE CONST VARIABLES
	const float IDLE_TIMER_AMOUNT = 3.0f;
	const float IDLE_VELOCITY_TOLERANCE = 0.001f;
	const float IDLE_RESET_TIMER_AMOUNT = 5.0f;
	const float RANGED_RESET_TIMER_AMOUNT = 1.0f;

protected: // PRIVATE VARIABLES 
	FTimerHandle StartFleeTimerHandle;
	FTimerHandle StartPatrolTimerHandle;
	FTimerHandle IdleResetTimerHandle;
	FTimerHandle RangedResetTimerHandle;

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
	AMyKoalaEnemyClass();

protected: // INITIALIZE INHERITABLE FUNCTIONS
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:	// UPDATE ACCESS ANYWHERE FUNCTIONS
	virtual void Tick(float DeltaTime) override;

protected: // PRIVATE INTERNAL FUNCTIONS
	void IdleReset();
	void StartPatrol();
	void StartFleeState();
	void RangedAttackOver();
};