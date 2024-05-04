/****************************************************************************************
* Copyright: SteveSloth
 * Name:
 * Script: MyEnemyPatrolState.cpp
 * Date: May.03/2024
 * Description: this is the cpp file for the enemy patrol state that handles what enemies do when in the patrol state
 * TODO:
 * Known Bugs:
 ****************************************************************************************/

#include "MyEnemyPatrolState.h"

void UMyEnemyPatrolState::EnterState()
{
	//Get enemy movement speed
	//Get patrol spline from enemy
}

void UMyEnemyPatrolState::ExitState()
{
	//Call this state when enemy notices player(Chase state) or reaches end of spline(Idle state)
}

void UMyEnemyPatrolState::UpdateState(float deltaTime)
{
	//Move enemy from start to finish of spline
	//Play walking animation while moving
}
