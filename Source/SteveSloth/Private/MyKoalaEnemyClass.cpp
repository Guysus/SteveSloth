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

}

void AMyKoalaEnemyClass::BeginPlay()
{
	Super::BeginPlay();

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
	if (isHit && outHit.bBlockingHit && outHit.GetActor() == Player && !bIsAttackingRanged)
	{
		StateMachine->ChangeState(StateMachine->GetState(RangedAttack));
		bIsAttackingRanged = true;

		bIsIdle = true; //remains true to stay in ranged state until timer is done
		bIsChasing = true; //remains true to stay in ranged state until timer is done
		bIsPatroling = true;

		//reset other state bools & clear start flee timer
		GetWorldTimerManager().ClearTimer(StartFleeTimerHandle);
		GetWorldTimerManager().SetTimer(RangedResetTimerHandle, this, &AMyKoalaEnemyClass::RangedAttackOver, RANGED_RESET_TIMER_AMOUNT, false);
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
		bIsAttackingRanged = false;
	}
	//if the enemy is still, do idle for a bit
	else if (UKismetMathLibrary::Vector_IsNearlyZero(AMyKoalaEnemyClass::GetVelocity(), IDLE_VELOCITY_TOLERANCE) && !bIsIdle)
	{
		StateMachine->ChangeState(StateMachine->GetState(Idle));
		GetWorldTimerManager().SetTimer(StartFleeTimerHandle, this, &AMyKoalaEnemyClass::StartFleeState, IDLE_TIMER_AMOUNT, false);
		bIsIdle = true;

		//reset other state bools
		bIsChasing = false;
		bIsPatroling = false;
		bIsAttackingRanged = false;
	}
	else if (FVector::Dist(this->GetActorLocation(), StartingLocation.GetLocation()) <= PatrolRange && !bIsPatroling)
	{
		StateMachine->ChangeState(StateMachine->GetState(Patrol));
		bIsPatroling = true;

		//reset other state bools & clear start flee timer
		GetWorldTimerManager().ClearTimer(StartFleeTimerHandle);
		bIsIdle = false;
		bIsChasing = false;
		bIsAttackingRanged = false;
	}

	if (CurrentHealth <= 0)
	{
		GetWorldTimerManager().ClearTimer(StartFleeTimerHandle);
	}
}

void AMyKoalaEnemyClass::StartFleeState()
{
	StateMachine->ChangeState(StateMachine->GetState(Flee));
	GetWorldTimerManager().SetTimer(IdleResetTimerHandle, this, &AMyKoalaEnemyClass::IdleReset, IDLE_RESET_TIMER_AMOUNT, false);
}

void AMyKoalaEnemyClass::IdleReset()
{
	bIsIdle = false;
}

void AMyKoalaEnemyClass::RangedAttackOver()
{
	bIsIdle = false;
	bIsChasing = false;
	bIsPatroling = false;
}