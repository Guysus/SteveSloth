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
	//EnemyLocation = (0, 0, 0);
   // PlayerLocation = (0, 0, 0);
	//DistanceToPlayer = 0.0f;

	Super::BeginPlay();
}

void AMyEnemyBaseClass::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AMyEnemyBaseClass::GetPlayerDistance() 
{
	 EnemyLocation = EnemyCharacter->GetActorLocation();
	 PlayerLocation = PlayerCharacter->GetActorLocation();

	 DistanceToPlayer = FVector::Distance(EnemyLocation, PlayerLocation);
}

void AMyEnemyBaseClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	void GetPlayerDistance();
	
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
	// Play Idle Animation
	// Standing Still
	// Check if player is in chase range
}

void AMyEnemyBaseClass::PatrolState()
{
	//Play Walking Animation
	// Moving around a controlled pattern or area
	// Check if Player is in chase range
}

void AMyEnemyBaseClass::ChaseState()
{
	// Play Walking or Running Animation
	// Chase player
	// Check if Player is in attack range
}

void AMyEnemyBaseClass::FleeState()
{
	// Play Running Animation
	// Head back to start location
	// Check if Player is in chase range
}

void AMyEnemyBaseClass::AttackState()
{
	// Go through Attacks and timers and run animations
	// attack player
	// check if player is withing attack range
}

void AMyEnemyBaseClass::DeadState()
{
	// Play Dying Animation
	// decay over time
	// drop loot
}