/****************************************************************************************
 * Copyright: SteveSloth
 * Name: Elad Saretzky, Brandon Thomas
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
	const float DESPAWN_TIMER_AMOUNT = 5.0f;
	const int MIN_RANDOM_RANGE = 0;
	const int MAX_RANDOM_RANGE = 50;
	const int IDLE_TRIGGER = 1;
	const int PATROL_TRIGGER = 42;

private: // PRIVATE VARIABLES 
	FTimerHandle DespawnTimerHandle;
	UMyEnemyStateComponent* StateMachine;

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
	AMyEmuEnemyClass();

protected: // INITIALIZE INHERITABLE FUNCTIONS
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:	// UPDATE ACCESS ANYWHERE FUNCTIONS
	virtual void Tick(float DeltaTime) override;

private: // PRIVATE INTERNAL FUNCTIONS
	void Despawn();
};