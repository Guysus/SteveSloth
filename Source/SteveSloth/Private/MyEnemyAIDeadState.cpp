/****************************************************************************************
 * Copyright:
 * Name: Guy Lapensee
 * Script: ItemBaseClass
 * Date: April 29, 2024
 * Description: Enemy AI dead state for enemy base class
 * TODO:
 * Known Bugs:
 ****************************************************************************************/


#include "MyEnemyAIDeadState.h"

MyEnemyAIDeadState::MyEnemyAIDeadState()
{
	isDead = false;
}

MyEnemyAIDeadState::~MyEnemyAIDeadState()
{
}

void MyEnemyAIDeadState::DeadAnimation()
{
	// PLAY DEATH ANIMATION
	// WAIT X TIME FOR DESTUCT ACTOR
	// DROP ITEM()
}

void MyEnemyAIDeadState::DropItem()
{
	// DROP RANDOM ITEM
	// DESTROY ACTOR
}
