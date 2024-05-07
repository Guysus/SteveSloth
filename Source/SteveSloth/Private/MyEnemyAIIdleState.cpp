/****************************************************************************************
* Copyright: SteveSloth
* Name: Aidan MacLeod
* Script: MyEnemyAIIdleState.cpp
* Date: May 6. 2024
* Description: Idle State Class for all enemies to inherit from
* TODO:
* Known Bugs:
****************************************************************************************/

#include "MyEnemyAIIdleState.h"

void UMyEnemyAIIdleState::EnterState()
{
	IsIdle = true;
	IdleTimer = 5.0f;
	Player = USteveSingleton::GetSteve()->GetPlayerCharacter();

	//Enemy->PlayAnimMontage(IdleAnim, 1.0f);
}

void UMyEnemyAIIdleState::ExitState()
{

}

void UMyEnemyAIIdleState::UpdateState(float deltaTime)
{
	IdleTimer -= deltaTime;
}