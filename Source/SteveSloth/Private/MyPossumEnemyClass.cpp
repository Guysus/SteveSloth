/****************************************************************************************
 * Copyright: SteveSloth
 * Name: Elad Saretzky
 * Script: MyPossumEnemyClass.cpp
 * Date: May 6, 2024
 * Description: Does all of the specific to possum things
 * TODO:
 * Known Bugs:
 ****************************************************************************************/


#include "MyPossumEnemyClass.h"

AMyPossumEnemyClass::AMyPossumEnemyClass()
{
	IsIdle = false;
	IsChasing = false;
	IsAttackingMelee = false;
	IsAttackingRanged = false;
}

void AMyPossumEnemyClass::BeginPlay()
{
	Super::BeginPlay();
}

void AMyPossumEnemyClass::Tick(float DeltaTime)
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
	//if the enemy is in melee distance
	if (FVector::Dist(this->GetActorLocation(), Player->GetActorLocation()) <= MeleeAttackRange && !IsAttackingMelee)
	{
		// ---- change to melee attack state here ----
		IsAttackingMelee = true;

		//reset other state bools & clear start patrol timer
		GetWorldTimerManager().ClearTimer(StartPatrolTimerHandle);
		IsIdle = false;
		IsChasing = false;
		IsAttackingRanged = false;
	}
	//if the enemy is in ranged distance
	else if (isHit && outHit.bBlockingHit && outHit.GetActor() == Player && !IsAttackingRanged)
	{
		// ----change to ranged attack state here----
		IsAttackingRanged = true;

		IsIdle = true; //remains true to stay in ranged state until timer is done
		IsChasing = true; //remains true to stay in ranged state until timer is done

		//reset other state bools & clear start patrol timer
		GetWorldTimerManager().ClearTimer(StartPatrolTimerHandle);
		GetWorldTimerManager().SetTimer(RangedResetTimerHandle, this, &AMyPossumEnemyClass::RangedAttackOver, RANGED_RESET_TIMER_AMOUNT, false);
		IsAttackingMelee = false;
	}
	//if the enemy is within the chasing distance
	else if (FVector::Dist(this->GetActorLocation(), Player->GetActorLocation()) <= ChaseRange && !IsChasing)
	{
		// ---- change to chasing state here ----
		IsChasing = true;

		//reset other state bools & clear start patrol timer
		GetWorldTimerManager().ClearTimer(StartPatrolTimerHandle);
		IsIdle = false;
		IsAttackingMelee = false;
		IsAttackingRanged = false;
	}
	//if the enemy is still, do idle for a bit
	else if (UKismetMathLibrary::Vector_IsNearlyZero(AMyPossumEnemyClass::GetVelocity(), IDLE_VELOCITY_TOLERANCE) && !IsIdle)
	{
		// ---- change to idle state here ----
		GetWorldTimerManager().SetTimer(StartPatrolTimerHandle, this, &AMyPossumEnemyClass::StartPatrolState, IDLE_TIMER_AMOUNT, false);
		IsIdle = true;

		//reset other state bools & clear start patrol timer
		IsChasing = false;
		IsAttackingMelee = false;
		IsAttackingRanged = false;
	}

	if (CurrentHealth <= 0)
	{
		GetWorldTimerManager().ClearTimer(StartPatrolTimerHandle);
	}
}

void AMyPossumEnemyClass::StartPatrolState()
{
	// ---- change to patrol state here ----
	GetWorldTimerManager().SetTimer(IdleResetTimerHandle, this, &AMyPossumEnemyClass::IdleReset, IDLE_RESET_TIMER_AMOUNT, false);
}

void AMyPossumEnemyClass::IdleReset()
{
	IsIdle = false;
}

void AMyPossumEnemyClass::RangedAttackOver()
{
	IsIdle = false;
	IsChasing = false;
}