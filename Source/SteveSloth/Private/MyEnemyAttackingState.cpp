/****************************************************************************************
 * Copyright: SteveSloth
 * Name: Ken Ferris
 * Script: MyEnemyAttackingState.cpp
 * Date: May 3, 2024
 * Description: Enemy Attack State
 * TODO:
 * Known Bugs:
 ****************************************************************************************/


#include "MyEnemyAttackingState.h"
#include "MySteveSingleton.h"

void UMyEnemyAttackingState::EnterState()
{
	Player = USteveSingleton::GetSteve()->GetPlayerCharacter();
}

void UMyEnemyAttackingState::ExitState()
{

}

void UMyEnemyAttackingState::UpdateState(float deltaTime)
{
	
}

