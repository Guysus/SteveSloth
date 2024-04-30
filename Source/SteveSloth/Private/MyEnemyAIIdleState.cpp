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





MyEnemyAIIdleState::MyEnemyAIIdleState()
{
	IsIdle = false;
	HasDetectedPlayer = false;
}

MyEnemyAIIdleState::~MyEnemyAIIdleState()
{

}

void MyEnemyAIIdleState::DetectPlayer()
{
	//Detect Player within certain range
	//Go into chase or flee state from there
}


