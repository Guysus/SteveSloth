/****************************************************************************************
* Copyright: SteveSloth
 * Name: Tammy Jeff Moreau
 * Script: MyEnemyBaseClass.cpp
 * Date: April 29. 2024
 * Description: Base Class for all enemies to inherit from
 * TODO:
 * Known Bugs:
 ****************************************************************************************/

#include "MyEnemyBaseClass.h"

#include "AsyncTreeDifferences.h"

AMyEnemyBaseClass::AMyEnemyBaseClass()
{
	PrimaryActorTick.bCanEverTick = true;
	
	CurrentState = Idle;
}

void AMyEnemyBaseClass::BeginPlay()
{
	Super::BeginPlay();

}

void AMyEnemyBaseClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	switch (CurrentState)
	{
	case Idle:
		IdleState();
		break;
	case Patrol:
		PatrolState();
		break;
	case Chase:
		ChaseState();
		break;
	case Flee:
		FleeState();
		break;
	case Attack:
		AttackState();
		break;
	case Dead:
		DeadState();
		break;
	default:
		break;
	}
}

void AMyEnemyBaseClass::IdleState()
{
	// Standing Still
	// Check if player is in chase range
}

void AMyEnemyBaseClass::PatrolState()
{
	// Moving around a controlled pattern or area
	// Check if Player is in chase range
}

void AMyEnemyBaseClass::ChaseState()
{
	// Chase player
	// Check if Player is in attack range
}

void AMyEnemyBaseClass::FleeState()
{
	// Head back to start location
	// Check if Player is in chase range
}

void AMyEnemyBaseClass::AttackState()
{
	// attack player
	// check if player is withing attack range
}

void AMyEnemyBaseClass::DeadState()
{
	// decay over time
	// drop loot
}