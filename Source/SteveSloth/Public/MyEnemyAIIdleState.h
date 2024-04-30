/****************************************************************************************
* Copyright: SteveSloth
 * Name: Aidan MacLeod
 * Script: MyEnemyAIIdleState.h
 * Date: April 29. 2024
 * Description: Idle State Class for all enemies to inherit from
 * TODO:
 * Known Bugs:
 ****************************************************************************************/

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */

UCLASS()
class STEVESLOTH_API MyEnemyAIIdleState
{

private:

	bool IsIdle;
	bool HasDetectedPlayer;

public:
	
	MyEnemyAIIdleState();
	~MyEnemyAIIdleState();
	
private:

	void DetectPlayer();
};
