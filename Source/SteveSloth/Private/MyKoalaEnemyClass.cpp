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

AMyKoalaEnemyClass::AMyKoalaEnemyClass()
{
	IsIdle = false;
	IsPatroling = false;
	IsChasing = false;
	IsAttackingRanged = false;
}

void AMyKoalaEnemyClass::BeginPlay()
{
	Super::BeginPlay();

	//StartingLocation = this->GetActorLocation();
}

void AMyKoalaEnemyClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Linetrace:
	FHitResult outHit;

	FVector start = this->GetActorLocation(); //this should change to a specific location we want to shoot from (arm maybe)
	FVector end = (start + (this->GetActorForwardVector() * RangedAttackRange));

	FCollisionQueryParams collisionParams;
	collisionParams.AddIgnoredActor(this);

	bool isHit = GetWorld()->LineTraceSingleByChannel(outHit, start, end, ECC_Visibility, collisionParams);

	//Switching States:
	//if the enemy is in ranged distance
	if (isHit && outHit.bBlockingHit && outHit.GetActor() == Player && !IsAttackingRanged)
	{
		// ----change to ranged attack state here----
		IsAttackingRanged = true;

		IsIdle = true; //remains true to stay in ranged state until timer is done
		IsPatroling = true;
		IsChasing = true; //remains true to stay in ranged state until timer is done

		//reset other state bools & clear start flee timer
		GetWorldTimerManager().ClearTimer(StartFleeTimerHandle);
		GetWorldTimerManager().SetTimer(RangedResetTimerHandle, this, &AMyKoalaEnemyClass::RangedAttackOver, RANGED_RESET_TIMER_AMOUNT, false);
	}
	//if the enemy is within the chasing distance
	else if (FVector::Dist(this->GetActorLocation(), Player->GetActorLocation()) <= ChaseRange && !IsChasing)
	{
		StateMachine->ChangeState(StateMachine->GetState(Chase));
		IsChasing = true;

		//reset other state bools & clear start flee timer
		GetWorldTimerManager().ClearTimer(StartFleeTimerHandle);
		IsIdle = false;
		IsPatroling = false;
		IsAttackingRanged = false;
	}
	//if the enemy is still, do idle for a bit
	else if (UKismetMathLibrary::Vector_IsNearlyZero(AMyKoalaEnemyClass::GetVelocity(), IDLE_VELOCITY_TOLERANCE) && !IsIdle)
	{
		StateMachine->ChangeState(StateMachine->GetState(Idle));
		GetWorldTimerManager().SetTimer(StartFleeTimerHandle, this, &AMyKoalaEnemyClass::StartFleeState, IDLE_TIMER_AMOUNT, false);
		IsIdle = true;

		//reset other state bools
		IsChasing = false;
		IsPatroling = false;
		IsAttackingRanged = false;
	}
	else if (FVector::Dist(this->GetActorLocation(), StartingLocation) <= PatrolRange && !IsPatroling)
	{
		// ---- change to patrol state here ----
		IsPatroling = true;

		//reset other state bools & clear start flee timer
		GetWorldTimerManager().ClearTimer(StartFleeTimerHandle);
		IsIdle = false;
		IsChasing = false;
		IsAttackingRanged = false;
	}

	if (CurrentHealth <= 0)
	{
		GetWorldTimerManager().ClearTimer(StartFleeTimerHandle);
	}
}

void AMyKoalaEnemyClass::StartFleeState()
{
	// ---- change to flee state here ----
	GetWorldTimerManager().SetTimer(IdleResetTimerHandle, this, &AMyKoalaEnemyClass::IdleReset, IDLE_RESET_TIMER_AMOUNT, false);
}

void AMyKoalaEnemyClass::IdleReset()
{
	IsIdle = false;
}

void AMyKoalaEnemyClass::RangedAttackOver()
{
	IsIdle = false;
	IsPatroling = false;
	IsChasing = false;
}
