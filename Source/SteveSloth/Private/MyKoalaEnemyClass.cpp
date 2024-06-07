/****************************************************************************************
* Copyright: SteveSloth
* Name: Elad Saretzky
* Script: MyKoalaEnemyClass.cpp
* Date: May 10, 2024
* Description: Does all of the specific to Koala things
* TODO:
* Known Bugs:
****************************************************************************************/

#include "MyKoalaEnemyClass.h"
#include "MyGenericEnemyIdleState.h"
#include "MyGenericEnemyPatrolState.h"
#include "MyGenericEnemyChaseState.h"
#include "MyGenericEnemyFleeState.h"
#include "MyGenericEnemyAttackState.h"
#include "MyGenericEnemyRangeAttackState.h"
#include "MyGenericEnemyFrozenState.h"
#include "MyGenericEnemyConfusionState.h"
#include "MyGenericEnemyDieState.h"

AMyKoalaEnemyClass::AMyKoalaEnemyClass()
{
	StateMachine = CreateDefaultSubobject<UMyEnemyStateComponent>(TEXT("State Machine"));

	bIsDead = false;
	bIsConfused = false;
	bIsIdle = true;
	bIsFrozen = false;
	bIsChasing = false;
	bIsPatroling = false;
	bIsAttackingMelee = false;
	bIsCurrentlyFrozen = false;
	bIsCurrentlyConfused = false;
	bIsAttackingRanged = false;
}

void AMyKoalaEnemyClass::BeginPlay()
{
	Super::BeginPlay();

	//StateMachine->ClearStateList();
	StateMachine->States.Empty();

	IdleState = NewObject<UMyGenericEnemyIdleState>();
	PatrolState = NewObject<UMyGenericEnemyPatrolState>();
	ChaseState = NewObject<UMyGenericEnemyChaseState>();
	FleeState = NewObject<UMyGenericEnemyFleeState>();
	AttackState = NewObject<UMyGenericEnemyAttackState>();
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

	if (StateMachine && StateMachine->GetStateList().Num() > 0)
	{
		StateMachine->ChangeState(StateMachine->GetState(Idle));
	}
}

void AMyKoalaEnemyClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//if (FVector::Dist(this->GetActorLocation(), Player->GetActorLocation()) <= RangedAttackRange && FVector::Dist(this->GetActorLocation(), Player->GetActorLocation()) > ChaseRange && !bIsAttackingRanged)
	//{
	//	StateMachine->ChangeState(StateMachine->GetState(RangedAttack));
	//	
	//	bIsAttackingRanged = true;

	//	bIsIdle = true; //remains true to stay in ranged state until timer is done
	//	bIsChasing = true; //remains true to stay in ranged state until timer is done
	//	bIsPatroling = true;

	//	//reset other state bools & clear start flee timer
	//	GetWorldTimerManager().ClearTimer(StartFleeTimerHandle);
	//	GetWorldTimerManager().SetTimer(RangedResetTimerHandle, this, &AMyKoalaEnemyClass::RangedAttackOver, RANGED_RESET_TIMER_AMOUNT, false);
	//}
	////if the enemy is within the chasing distance
	//else if (FVector::Dist(this->GetActorLocation(), Player->GetActorLocation()) <= ChaseRange && !bIsChasing && !bIsIdle)
	//{
	//	StateMachine->ChangeState(StateMachine->GetState(Chase));
	//	bIsChasing = true;

	//	//reset other state bools & clear start flee timer
	//	GetWorldTimerManager().ClearTimer(StartFleeTimerHandle);
	//	bIsIdle = false;
	//	bIsPatroling = false;
	//	bIsAttackingRanged = false;
	//}
	////if the enemy is still, do idle for a bit
	//else 
	if (UKismetMathLibrary::Vector_IsNearlyZero(AMyKoalaEnemyClass::GetVelocity(), IDLE_VELOCITY_TOLERANCE) && !bIsIdle)
	{
		StateMachine->ChangeState(StateMachine->GetState(Idle));
		GetWorldTimerManager().SetTimer(StartFleeTimerHandle, this, &AMyKoalaEnemyClass::StartFleeState, IDLE_TIMER_AMOUNT, false);
	
		bIsIdle = true;
		bIsChasing = false;
		bIsAttackingRanged = false;
	}
	else if (FVector::Dist(this->GetActorLocation(), StartingLocation.GetLocation()) <= PatrolRange && !bIsPatroling)
	{
		StateMachine->ChangeState(StateMachine->GetState(Patrol));

		GetWorldTimerManager().ClearTimer(StartFleeTimerHandle);
		GetWorldTimerManager().SetTimer(IdleResetTimerHandle, this, &AMyKoalaEnemyClass::IdleReset, IDLE_RESET_TIMER_AMOUNT, false);

		bIsPatroling = true;
		bIsChasing = false;
		bIsAttackingRanged = false;
	}

	/*if (CurrentHealth <= 0)
	{
		GetWorldTimerManager().ClearTimer(StartFleeTimerHandle);
	}*/
}

void AMyKoalaEnemyClass::StartFleeState()
{
	//StateMachine->ChangeState(StateMachine->GetState(Patrol));

	//GetWorldTimerManager().SetTimer(IdleResetTimerHandle, this, &AMyKoalaEnemyClass::StartPatrol, IDLE_RESET_TIMER_AMOUNT, false);

	for (int i = 0; i < StateMachine->States.Num(); i++)
	{
		UE_LOG(LogTemp, Log, TEXT("Current State: %s"), *StateMachine->States[i]->GetName());
	}

	bIsPatroling = false;
}

void AMyKoalaEnemyClass::IdleReset()
{
	for (int i = 0; i < StateMachine->States.Num(); i++)
	{
		UE_LOG(LogTemp, Log, TEXT("Current State: %s"), *StateMachine->States[i]->GetName());
	}

	bIsIdle = false;
}

void AMyKoalaEnemyClass::RangedAttackOver()
{
	bIsIdle = false;
	bIsChasing = false;
	bIsPatroling = false;
}

void AMyKoalaEnemyClass::EndPlay(const EEndPlayReason::Type EndPlayReason)
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

void AMyKoalaEnemyClass::StartPatrol()
{
	StateMachine->ChangeState(StateMachine->GetState(Patrol));

	bIsPatroling = true;
	//reset other state bools & clear start flee timer
	GetWorldTimerManager().ClearTimer(StartFleeTimerHandle);
	bIsIdle = false;
	bIsChasing = false;
	bIsAttackingRanged = false;
}