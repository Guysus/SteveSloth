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
	if (FVector::Dist(this->GetActorLocation(), Player->GetActorLocation()) <= MeleeAttackRange && !bIsAttackingMelee)
	{
		// ---- change to melee attack state here ----
		bIsAttackingMelee = true;

		//reset other state bools & clear start flee timer
		GetWorldTimerManager().ClearTimer(StartFleeTimerHandle);
		bIsIdle = false;
		bIsPatroling = false;
		bIsChasing = false;
		bIsAttackingRanged = false;
	}
	//if the enemy is in ranged distance
	else if (isHit && outHit.bBlockingHit && outHit.GetActor() == Player && !bIsAttackingRanged)
	{
		// ----change to ranged attack state here----
		bIsAttackingRanged = true;

		bIsIdle = true; //remains true to stay in ranged state until timer is done
		bIsPatroling = true;
		bIsChasing = true; //remains true to stay in ranged state until timer is done

		//reset other state bools & clear start flee timer
		GetWorldTimerManager().ClearTimer(StartFleeTimerHandle);
		GetWorldTimerManager().SetTimer(RangedResetTimerHandle, this, &AMyPossumEnemyClass::RangedAttackOver, RANGED_RESET_TIMER_AMOUNT, false);
		bIsAttackingMelee = false;
	}
	//if the enemy is within the chasing distance
	else if (FVector::Dist(this->GetActorLocation(), Player->GetActorLocation()) <= ChaseRange && !bIsChasing)
	{
		// ---- change to chasing state here ----
		bIsChasing = true;

		//reset other state bools & clear start flee timer
		GetWorldTimerManager().ClearTimer(StartFleeTimerHandle);
		bIsIdle = false;
		bIsPatroling = false;
		bIsAttackingMelee = false;
		bIsAttackingRanged = false;
	}
	//if the enemy is still, do idle for a bit
	else if (UKismetMathLibrary::Vector_IsNearlyZero(AMyPossumEnemyClass::GetVelocity(), IDLE_VELOCITY_TOLERANCE) && !bIsIdle)
	{
		// ---- change to idle state here ----
		GetWorldTimerManager().SetTimer(StartFleeTimerHandle, this, &AMyPossumEnemyClass::StartFleeState, IDLE_TIMER_AMOUNT, false);
		bIsIdle = true;

		//reset other state bools
		bIsChasing = false;
		bIsPatroling = false;
		bIsAttackingMelee = false;
		bIsAttackingRanged = false;
	}
	else if (FVector::Dist(this->GetActorLocation(), StartingLocation.GetLocation()) <= PatrolRange && !bIsPatroling)
	{
		// ---- change to patrol state here ----
		bIsPatroling = true;

		//reset other state bools & clear start flee timer
		GetWorldTimerManager().ClearTimer(StartFleeTimerHandle);
		bIsIdle = false;
		bIsChasing = false;
		bIsAttackingMelee = false;
		bIsAttackingRanged = false;
	}

	if (CurrentHealth <= 0)
	{
		GetWorldTimerManager().ClearTimer(StartFleeTimerHandle);
	}
}

void AMyPossumEnemyClass::StartFleeState()
{
	// ---- change to flee state here ----
	GetWorldTimerManager().SetTimer(IdleResetTimerHandle, this, &AMyPossumEnemyClass::IdleReset, IDLE_RESET_TIMER_AMOUNT, false);
}

void AMyPossumEnemyClass::IdleReset()
{
	bIsIdle = false;
}

void AMyPossumEnemyClass::RangedAttackOver()
{
	bIsIdle = false;
	bIsPatroling = false;
	bIsChasing = false;
}