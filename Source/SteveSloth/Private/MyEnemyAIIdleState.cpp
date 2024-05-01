/****************************************************************************************
* Copyright: SteveSloth
 * Name: Aidan MacLeod
 * Script: MyEnemyAIIdleState.cpp
 * Date: April 29. 2024
 * Description: Idle State Class for all enemies to inherit from
 * TODO:
 * Known Bugs:
 ****************************************************************************************/

#include "MyEnemyAIIdleState.h"

AMyEnemyAIIdleState::AMyEnemyAIIdleState()
{
	IsIdle = false;
	HasDetectedPlayer = false;
	PatrolTime = 5.0f;
	DetectionRange = 1000.0f;
	IdleResetTime = 5.0f;
}

void AMyEnemyAIIdleState::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	DetectPlayer();
}

void AMyEnemyAIIdleState::DetectPlayer()
{
	if (/*condition to be added*/)
	{
		IsIdle = false;
		HasDetectedPlayer = true;
	}
}

void AMyEnemyAIIdleState::StartPatrol()
{

}

void AMyEnemyAIIdleState::ResetToIdle()
{
	PlayIdleAnimation();
}

void AMyEnemyAIIdleState::BeginChase()
{

}

void AMyEnemyAIIdleState::PlayIdleAnimation()
{

}


