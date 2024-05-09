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

	FHitResult outHit;

	FVector start = this->GetActorLocation(); //this should change to a specific location we want to shoot from (arm maybe)
	FVector end = (start + (this->GetActorForwardVector() * RangedAttackRange));

	FCollisionQueryParams collisionParams;

	bool isHit = GetWorld()->LineTraceSingleByChannel(outHit, start, end, ECC_Visibility, collisionParams);

	//if the enemy is in melee distance
	if (FVector::Dist(this->GetActorLocation(), Player->GetActorLocation()) <= MeleeAttackRange && !IsAttackingMelee)
	{
		// ---- change to melee attack state here ----
		IsAttackingMelee = true;
	}
	//if the enemy is in ranged distance
	else if (isHit && outHit.bBlockingHit && outHit.GetActor() == Player && !IsAttackingRanged)
	{
		// ----change to ranged attack state here----
		IsAttackingRanged = true;
	}
	//if the enemy is within the chasing distance
	else if (FVector::Dist(this->GetActorLocation(), Player->GetActorLocation()) <= ChaseRange && !IsChasing)
	{
		// ---- change to chasing state here ----
		IsChasing = true;
	}
	//if the enemy is still, do idle for a bit
	else if (UKismetMathLibrary::Vector_IsNearlyZero(AMyPossumEnemyClass::GetVelocity(), IDLE_VELOCITY_TOLERANCE) && !IsIdle)
	{
		// ---- change to idle state here ----
		GetWorldTimerManager().SetTimer(IdleTimerHandle, this, &AMyPossumEnemyClass::IdleOver, IDLE_TIMER_AMOUNT, false);
		IsIdle = true;
	}
}

void AMyPossumEnemyClass::IdleOver()
{
	// ---- change to patrol state here ----
	GetWorldTimerManager().SetTimer(IdleTimerHandle, this, &AMyPossumEnemyClass::IdleReset, IDLE_RESET_TIMER_AMOUNT, false);
}

void AMyPossumEnemyClass::IdleReset()
{
	IsIdle = false;
}

void AMyPossumEnemyClass::RangedAttackOver()
{

}
