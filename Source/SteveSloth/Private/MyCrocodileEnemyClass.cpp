/****************************************************************************************
 * Copyright: SteveSloth
 * Name: Elad Saretzky, Brandon Thomas
 * Script: MyCrocodileEnemyClass.cpp
 * Date: May 10, 2024
 * Description: Does all of the specific to Crocodile things
 * TODO:
 * Known Bugs:
 ****************************************************************************************/

#include "MyCrocodileEnemyClass.h"
#include "MyGenericEnemyIdleState.h"
#include "MyGenericEnemyPatrolState.h"
#include "MyGenericEnemyChaseState.h"
#include "MyGenericEnemyFleeState.h"
#include "MyGenericEnemyAttackState.h"
#include "MyGenericEnemyRangeAttackState.h"
#include "MyGenericEnemyFrozenState.h"
#include "MyGenericEnemyConfusionState.h"
#include "MyGenericEnemyDieState.h"

AMyCrocodileEnemyClass::AMyCrocodileEnemyClass()
{
	bIsDead = false;
	bIsConfused = false;
	bIsIdle = false;
	bIsFrozen = false;
	bIsChasing = false;
	bIsPatroling = false;
	bIsAttackingMelee = false;
	bIsCurrentlyFrozen = false;
	bIsCurrentlyConfused = false;
	bIsAttackingRanged = false;
}

void AMyCrocodileEnemyClass::BeginPlay()
{
	Super::BeginPlay();

	StateMachine->ClearStateList();

	if (StateMachine) 
	{
		IdleState = NewObject<UMyGenericEnemyIdleState>();
		PatrolState = NewObject<UMyGenericEnemyPatrolState>();
		ChaseState = NewObject<UMyGenericEnemyChaseState>();
		FleeState = NewObject<UMyGenericEnemyFleeState>();
		AttackState = NewObject<UMyGenericEnemyAttackState>();
		RangedAttackState = NewObject<UMyGenericEnemyRangeAttackState>();
		FrozenState = NewObject<UMyGenericEnemyFrozenState>();
		ConfusedState = NewObject<UMyGenericEnemyConfusionState>();
		DieState = NewObject<UMyGenericEnemyDieState>();

		if (IdleState) 
		{
			IdleState->SetEnemyBaseClass(this);
			PatrolState->SetEnemyBaseClass(this);
			ChaseState->SetEnemyBaseClass(this);
			FleeState->SetEnemyBaseClass(this);
			AttackState->SetEnemyBaseClass(this);
			RangedAttackState->SetEnemyBaseClass(this);
			FrozenState->SetEnemyBaseClass(this);
			ConfusedState->SetEnemyBaseClass(this);
			DieState->SetEnemyBaseClass(this);

			StateMachine->SetStateList(IdleState);
			StateMachine->SetStateList(PatrolState);
			StateMachine->SetStateList(ChaseState);
			StateMachine->SetStateList(FleeState);
			StateMachine->SetStateList(AttackState);
			StateMachine->SetStateList(RangedAttackState);
			StateMachine->SetStateList(FrozenState);
			StateMachine->SetStateList(ConfusedState);
			StateMachine->SetStateList(DieState);
		}
	}
	if (StateMachine && StateMachine->GetStateList().Num() > 0)
	{
		StateMachine->ChangeState(StateMachine->GetState(Idle));
	}
}

void AMyCrocodileEnemyClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Switching States:
	//if the enemy is in melee distance
	if (FVector::Dist(this->GetActorLocation(), Player->GetActorLocation()) <= MeleeAttackRange && !bIsAttackingMelee)
	{
		StateMachine->ChangeState(StateMachine->GetState(Attack));
		bIsAttackingMelee = true;

		//reset other state bools & clear start flee timer
		/*GetWorldTimerManager().ClearTimer(StartFleeTimerHandle);*/
		bIsIdle = false;
		bIsChasing = false;
	}
	//if the enemy is within the chasing distance
	else if (FVector::Dist(this->GetActorLocation(), Player->GetActorLocation()) <= ChaseRange && 
		FVector::Dist(this->GetActorLocation(), Player->GetActorLocation()) > MeleeAttackRange &&
		!bIsChasing)
	{
		StateMachine->ChangeState(StateMachine->GetState(Chase));
		bIsChasing = true;

		//reset other state bools & clear start flee timer
		/*GetWorldTimerManager().ClearTimer(StartFleeTimerHandle);*/
		bIsIdle = false;
		bIsAttackingMelee = false;
	}
	//if the enemy is still, do idle for a bit
	else if (FVector::Dist(this->GetActorLocation(), Player->GetActorLocation()) > ChaseRange && 
		FVector::Dist(this->GetActorLocation(), Player->GetActorLocation()) > MeleeAttackRange &&
		 !bIsIdle)
	{
		StateMachine->ChangeState(StateMachine->GetState(Idle));
		/*GetWorldTimerManager().SetTimer(StartFleeTimerHandle, this, &AMyCrocodileEnemyClass::StartFleeState, IDLE_TIMER_AMOUNT, false);*/
		bIsIdle = true;

		//reset other state bools
		bIsChasing = false;
		bIsAttackingMelee = false;
	}

	if (CurrentHealth <= 0)
	{
		/*GetWorldTimerManager().ClearTimer(StartFleeTimerHandle);*/
	}
}

//void AMyCrocodileEnemyClass::StartFleeState()
//{
//	// ---- change to flee state here ----
//	GetWorldTimerManager().SetTimer(IdleResetTimerHandle, this, &AMyCrocodileEnemyClass::IdleReset, IDLE_RESET_TIMER_AMOUNT, false);
//}
//
//void AMyCrocodileEnemyClass::IdleReset()
//{
//	bIsIdle = false;
//}