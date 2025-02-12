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

AMyEmuEnemyClass::AMyEmuEnemyClass()
{
	StateMachine = CreateDefaultSubobject<UMyEnemyStateComponent>(TEXT("State Machine"));
}

void AMyEmuEnemyClass::BeginPlay()
{
	Super::BeginPlay();
}

void AMyEmuEnemyClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Switching States:
	//if the enemy is in melee distance
	if (FVector::Dist(this->GetActorLocation(), Player->GetActorLocation()) <= MeleeAttackRange && !bIsAttackingMelee)
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
	else if (FVector::Dist(this->GetActorLocation(), Player->GetActorLocation()) <= ChaseRange && !bIsChasing)
	{
		StateMachine->ChangeState(StateMachine->GetState(Chase));
		bIsChasing = true;

		//reset other state bools & clear start flee timer
		GetWorldTimerManager().ClearTimer(StartFleeTimerHandle);
		bIsIdle = false;
		bIsPatroling = false;
		bIsAttackingMelee = false;
	}
	//if the enemy is still, do idle for a bit
	else if (UKismetMathLibrary::Vector_IsNearlyZero(AMyEmuEnemyClass::GetVelocity(), IDLE_VELOCITY_TOLERANCE) && !bIsIdle)
	{
		StateMachine->ChangeState(StateMachine->GetState(Idle));
		GetWorldTimerManager().SetTimer(StartFleeTimerHandle, this, &AMyEmuEnemyClass::StartFleeState, IDLE_TIMER_AMOUNT, false);
		bIsIdle = true;

		//reset other state bools
		bIsChasing = false;
		bIsPatroling = false;
		bIsAttackingMelee = false;
	}
	else if (FVector::Dist(this->GetActorLocation(), StartingLocation.GetLocation()) <= PatrolRange && !bIsPatroling)
	{
		StateMachine->ChangeState(StateMachine->GetState(Patrol));
		bIsPatroling = true;

		//reset other state bools & clear start flee timer
		GetWorldTimerManager().ClearTimer(StartFleeTimerHandle);
		bIsIdle = false;
		bIsChasing = false;
		bIsAttackingMelee = false;
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