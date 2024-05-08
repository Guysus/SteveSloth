/****************************************************************************************
 * Copyright: SteveSloth
 * Name: Tammy Boisvert
 * Script: MyEnemyAIChaseState.cpp
 * Date: May 3. 2024
 * Description: This is the Enemy State for chasing the player when they are in range
 * TODO:
 * Known Bugs:
 ****************************************************************************************/


#include "MyEnemyAIChaseState.h"
#include <GameFramework/CharacterMovementComponent.h>


void UMyEnemyAIChaseState::EnterState()
{
	//play the walking or running animation montage for the enemy
	 PlayAnimMontage();
}

void UMyEnemyAIChaseState::UpdateState(float deltaTime)
{
	//Get The Players Location(will be handled in enemy base class)
	FVector PlayerLocation = Player->GetActorLocation();

	//Get The Enemies Location(will be handled in enemy base class)
	FVector EnemyLocation = Enemy->GetActorLocation();

	//Have Enemy Face Players Direction(will be handled in enemybase class)
    FVector Direction = EnemyLocation - PlayerLocation;
    Direction.Normalize();

    //Move Enemy Towards Player
    FVector NewLocation = EnemyLocation + Direction * MovementSpeed * deltaTime;
    EnemyLocation = NewLocation;
	
	//Rotate Enemy to face The player
    FRotator TargetRotation = Direction.Rotation();
}

void UMyEnemyAIChaseState::PlayAnimMontage() 
{
	UAnimMontage* WalkMotage;
}

void UMyEnemyAIChaseState::ExitState()
{
}

