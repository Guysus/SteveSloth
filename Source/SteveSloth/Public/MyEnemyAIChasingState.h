/****************************************************************************************
 * Copyright: SteveSloth
 * Name: Tammy Boisvert
 * Script: MyEnemyAIChasingState.h
 * Date: April 30. 2024
 * Description: This is the Enemy State for chasing the player when they are in range
 * TODO:
 * Known Bugs:
 ****************************************************************************************/

#pragma once

#include "CoreMinimal.h"
#include "MyPlayer.h"
#include "MyEnemyBaseClass.h"

class STEVESLOTH_API MyEnemyAIChasingState
{
public:
	MyEnemyAIChasingState();
	void PlayChasingAnimation();
	~MyEnemyAIChasingState();
};
