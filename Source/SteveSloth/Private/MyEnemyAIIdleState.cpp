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
}

void AMyEnemyAIIdleState::DetectPlayer()
{
	//Detect Player within certain range
	//Go into chase or flee state from there
}


