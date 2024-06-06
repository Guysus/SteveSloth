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

}

void AMyEmuEnemyClass::BeginPlay()
{
	Super::BeginPlay();
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
		GetWorldTimerManager().SetTimer(StartFleeTimerHandle, this, &AMyEmuEnemyClass::StartFleeState, IDLE_TIMER_AMOUNT, false);
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