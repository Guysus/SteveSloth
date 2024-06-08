/****************************************************************************************
 * Copyright: SteveSloth
 * Name: Elad Saretzky, Brandon Thomas
 * Script: MyEmuEnemyClass.cpp
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
	StateMachine = CreateDefaultSubobject<UMyEnemyStateComponent>(TEXT("State Machine"));
	StateMachine->States.Empty();

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

	IdleState = NewObject<UMyGenericEnemyIdleState>();
	PatrolState = NewObject<UMyGenericEnemyPatrolState>();
	ChaseState = NewObject<UMyGenericEnemyChaseState>();
	FleeState = NewObject<UMyGenericEnemyFleeState>();
	AttackState = NewObject<UMyEmuAttackState>();
	RangedAttackState = NewObject<UMyGenericEnemyRangeAttackState>();
	FrozenState = NewObject<UMyGenericEnemyFrozenState>();
	ConfusedState = NewObject<UMyGenericEnemyConfusionState>();
	DieState = NewObject<UMyGenericEnemyDieState>();

	IdleState->SetEnemyBaseClass(this);
	PatrolState->SetEnemyBaseClass(this);
	ChaseState->SetEnemyBaseClass(this);
	FleeState->SetEnemyBaseClass(this);
	AttackState->SetEnemyBaseClass(this);
	RangedAttackState->SetEnemyBaseClass(this);
	FrozenState->SetEnemyBaseClass(this);
	ConfusedState->SetEnemyBaseClass(this);
	DieState->SetEnemyBaseClass(this);

	if (StateMachine)
	{
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

void AMyEmuEnemyClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	int rand = FMath::RandRange(MIN_RANDOM_RANGE, MAX_RANDOM_RANGE);

	//Switching States:
	//if the enemy is in melee distance
	if (FVector::Dist(this->GetActorLocation(), Player->GetActorLocation()) <= MeleeAttackRange && !bIsAttackingMelee)
	{
		StateMachine->ChangeState(StateMachine->GetState(Attack));
		bIsAttackingMelee = true;

		//reset other state bools & clear start flee timer
		bIsIdle = false;
		bIsPatroling = false;
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
		bIsIdle = false;
		bIsPatroling = false;
		bIsAttackingMelee = false;
	}
	//trigger idle state
	else if (FVector::Dist(this->GetActorLocation(), Player->GetActorLocation()) > ChaseRange &&
		FVector::Dist(this->GetActorLocation(), Player->GetActorLocation()) > MeleeAttackRange &&
		rand == IDLE_TRIGGER && !bIsIdle)
	{
		StateMachine->ChangeState(StateMachine->GetState(Idle));
		bIsIdle = true;

		//reset other state bools
		bIsChasing = false;
		bIsPatroling = false;
		bIsAttackingMelee = false;
	}
	//trigger patrol state
	else if (FVector::Dist(this->GetActorLocation(), Player->GetActorLocation()) >= PatrolRange &&
		rand == PATROL_TRIGGER && !bIsPatroling)
	{
		StateMachine->ChangeState(StateMachine->GetState(Patrol));
		bIsPatroling = true;

		//reset other state bools & clear start flee timer
		bIsIdle = false;
		bIsChasing = false;
		bIsAttackingMelee = false;
	}

	if (CurrentHealth <= 0 && !bIsDead)
	{
		StateMachine->ChangeState(StateMachine->GetState(Die));
		
		bIsDead = true;
		bIsIdle = true;
		bIsChasing = true;
		bIsAttackingMelee = true;
		bIsPatroling = true;

		GetWorldTimerManager().SetTimer(DespawnTimerHandle, this, &AMyEmuEnemyClass::Despawn, DESPAWN_TIMER_AMOUNT, false);
	}
}

void AMyEmuEnemyClass::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	IdleState = nullptr;
	PatrolState = nullptr;
	ChaseState = nullptr;
	FleeState = nullptr;
	AttackState = nullptr;
	RangedAttackState = nullptr;
	FrozenState = nullptr;
	ConfusedState = nullptr;
	DieState = nullptr;
}

void AMyEmuEnemyClass::Despawn() 
{
	this->Destroy();
}