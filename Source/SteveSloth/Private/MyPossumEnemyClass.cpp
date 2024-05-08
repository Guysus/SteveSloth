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
}

void AMyPossumEnemyClass::BeginPlay()
{
	Super::BeginPlay();
}

void AMyPossumEnemyClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (UKismetMathLibrary::Vector_IsNearlyZero(AMyPossumEnemyClass::GetVelocity(), IDLE_VELOCITY_TOLERANCE) && !IsIdle)
	{
		//change to idle state here
		GetWorldTimerManager().SetTimer(IdleTimerHandle, this, &AMyPossumEnemyClass::IdleOver, IDLE_TIMER_AMOUNT, false);
	}
}

void AMyPossumEnemyClass::IdleOver()
{
	//change to patrol state
	GetWorldTimerManager().SetTimer(IdleTimerHandle, this, &AMyPossumEnemyClass::IdleReset, IDLE_RESET_TIMER_AMOUNT, false);
}

void AMyPossumEnemyClass::IdleReset()
{
	IsIdle = false;
}
