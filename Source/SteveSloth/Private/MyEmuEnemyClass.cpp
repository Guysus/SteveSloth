/****************************************************************************************
 * Copyright: SteveSloth
 * Name: Elad Saretzky
 * Script: MyEmuEnemyClass.h
 * Date: May 10, 2024
 * Description: Does all of the specific to emu things
 * TODO:
 * Known Bugs:
 ****************************************************************************************/

#include "MyEmuEnemyClass.h"
#include "MyGenericEnemyIdleState.h"
#include "MyGenericEnemyPatrolState.h"
#include "MyGenericEnemyChaseState.h"
#include "MyGenericEnemyFleeState.h"
#include "MyEmuAttackState.h"
#include "MyGenericEnemyRangeAttackState.h"
#include "MyGenericEnemyFrozenState.h"
#include "MyGenericEnemyConfusionState.h"
#include "MyGenericEnemyDieState.h"

AMyEmuEnemyClass::AMyEmuEnemyClass()
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

void AMyEmuEnemyClass::BeginPlay()
{
	Super::BeginPlay();

	StateMachine->ClearStateList();

	if (StateMachine)
	{
		IdleState = NewObject<UMyGenericEnemyIdleState>();
		PatrolState = NewObject<UMyGenericEnemyPatrolState>();
		ChaseState = NewObject<UMyGenericEnemyChaseState>();
		FleeState = NewObject<UMyGenericEnemyFleeState>();
		AttackState = NewObject<UMyEmuAttackState>();
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

			StateMachine->States.Add(IdleState);
			StateMachine->States.Add(PatrolState);
			StateMachine->States.Add(ChaseState);
			StateMachine->States.Add(FleeState);
			StateMachine->States.Add(AttackState);
			StateMachine->States.Add(RangedAttackState);
			StateMachine->States.Add(FrozenState);
			StateMachine->States.Add(ConfusedState);
			StateMachine->States.Add(DieState);
		}
	}
	if (StateMachine && StateMachine->GetStateList().Num() > 0)
	{
		StateMachine->ChangeState(StateMachine->GetState(Idle));
	}
}

void AMyEmuEnemyClass::Tick(float DeltaTime)
{
	int rand = FMath::RandRange(MIN_RANDOM_RANGE, MAX_RANDOM_RANGE);

	Super::Tick(DeltaTime);

	//Switching States:
	//if the enemy is in melee distance
	if (FVector::Dist(this->GetActorLocation(), Player->GetActorLocation()) <= MeleeAttackRange && 
		!bIsAttackingMelee)
	{
		StateMachine->ChangeState(StateMachine->GetState(Attack));
		bIsAttackingMelee = true;

		//reset other state bools & clear start flee timer
		GetWorldTimerManager().ClearTimer(StartFleeTimerHandle);
		bIsIdle = false;
		bIsPatroling = false;
		bIsChasing = false;
	}
	//if the enemy is within the chasing distance
	else if (FVector::Dist(this->GetActorLocation(), Player->GetActorLocation()) <= ChaseRange && 
		FVector::Dist(this->GetActorLocation(), Player->GetActorLocation()) > MeleeAttackRange && 
		!bIsChasing)
	{
		UE_LOG(LogTemp, Warning, TEXT("CHASING"));
		StateMachine->ChangeState(StateMachine->GetState(Chase));
		bIsChasing = true;

		//reset other state bools & clear start flee timer
		GetWorldTimerManager().ClearTimer(StartFleeTimerHandle);
		bIsIdle = false;
		bIsPatroling = false;
		bIsAttackingMelee = false;
	}
	//trigger idle state
	else if (FVector::Dist(this->GetActorLocation(), Player->GetActorLocation()) > ChaseRange &&
		FVector::Dist(this->GetActorLocation(), Player->GetActorLocation()) > MeleeAttackRange &&
		rand == IDLE_TRIGGER && !bIsIdle)
	{
		UE_LOG(LogTemp, Warning, TEXT("IDLE"));
		StateMachine->ChangeState(StateMachine->GetState(Idle));
		/*GetWorldTimerManager().SetTimer(StartFleeTimerHandle, this, &AMyEmuEnemyClass::StartFleeState, IDLE_TIMER_AMOUNT, false);
		bIsIdle = true;*/

		//reset other state bools
		bIsChasing = false;
		bIsPatroling = false;
		bIsAttackingMelee = false;
	}
	//trigger patrol state
	else if (FVector::Dist(this->GetActorLocation(), Player->GetActorLocation()) >= PatrolRange && 
		rand == PATROL_TRIGGER && !bIsPatroling)
	{
		UE_LOG(LogTemp, Warning, TEXT("PATROLING"));
		StateMachine->ChangeState(StateMachine->GetState(Patrol));
		bIsPatroling = true;

		//reset other state bools & clear start flee timer
		GetWorldTimerManager().ClearTimer(StartFleeTimerHandle);
		bIsIdle = false;
		bIsChasing = false;
		bIsAttackingMelee = false;

		rand = FMath::RandRange(MIN_RANDOM_RANGE, MAX_RANDOM_RANGE);
	}

	if (CurrentHealth <= 0)
	{
		GetWorldTimerManager().ClearTimer(StartFleeTimerHandle);
	}
}

void AMyEmuEnemyClass::StartFleeState()
{
	// ---- change to flee state here ----
	GetWorldTimerManager().SetTimer(IdleResetTimerHandle, this, &AMyEmuEnemyClass::IdleReset, IDLE_RESET_TIMER_AMOUNT, false);
}

void AMyEmuEnemyClass::IdleReset()
{
	bIsIdle = false;
}