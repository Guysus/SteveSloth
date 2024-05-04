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
	//Enemy->PlayAnimMontage(ChaseMontage,1.0f,);
}

void UMyEnemyAIChaseState::UpdateState(float deltaTime)
{
	//Get The Players Location
	FVector PlayerLocation = Player->GetActorLocation();
	//Get The Enemies Location
	FVector EnemyLocation = Enemy->GetActorLocation();
	//Move Enemy Towards Player
	FVector Direction = EnemyLocation - PlayerLocation;
    Direction.Normalize();
    // FVector NewLocation = PlayerLocation + Direction * MovementSpeed * deltaTime;
    // EnemyLocation = NewLocation;
	
	//Rotate Enemy to face The player
    FRotator TargetRotation = Direction.Rotation();
}

void UMyEnemyAIChaseState::ExitState()
{
}

