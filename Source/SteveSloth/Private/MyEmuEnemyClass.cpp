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
	Super::Tick(DeltaTime);

	//Switching States:
	//if the enemy is in melee distance
	if (FVector::Dist(this->GetActorLocation(), Player->GetActorLocation()) <= MeleeAttackRange && !IsAttackingMelee)
	{
		// ---- change to melee attack state here ----
		IsAttackingMelee = true;

		//reset other state bools & clear start flee timer
		GetWorldTimerManager().ClearTimer(StartFleeTimerHandle);
		IsIdle = false;
		IsPatroling = false;
		IsChasing = false;
	}
	//if the enemy is within the chasing distance
	else if (FVector::Dist(this->GetActorLocation(), Player->GetActorLocation()) <= ChaseRange && !IsChasing)
	{
		// ---- change to chasing state here ----
		IsChasing = true;

		//reset other state bools & clear start flee timer
		GetWorldTimerManager().ClearTimer(StartFleeTimerHandle);
		IsIdle = false;
		IsPatroling = false;
		IsAttackingMelee = false;
	}
	//if the enemy is still, do idle for a bit
	else if (UKismetMathLibrary::Vector_IsNearlyZero(AMyEmuEnemyClass::GetVelocity(), IDLE_VELOCITY_TOLERANCE) && !IsIdle)
	{
		// ---- change to idle state here ----
		GetWorldTimerManager().SetTimer(StartFleeTimerHandle, this, &AMyEmuEnemyClass::StartFleeState, IDLE_TIMER_AMOUNT, false);
		IsIdle = true;

		//reset other state bools
		IsChasing = false;
		IsPatroling = false;
		IsAttackingMelee = false;
	}
	else if (FVector::Dist(this->GetActorLocation(), StartingLocation.GetLocation()) <= PatrolRange && !IsPatroling)
	{
		// ---- change to patrol state here ----
		IsPatroling = true;

		//reset other state bools & clear start flee timer
		GetWorldTimerManager().ClearTimer(StartFleeTimerHandle);
		IsIdle = false;
		IsChasing = false;
		IsAttackingMelee = false;
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
	IsIdle = false;
}