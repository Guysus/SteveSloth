/****************************************************************************************
 * Copyright:
 * Name: Guy Lapensee
 * Script: Enemy AI dead state
 * Date: April 29, 2024
 * Description: Enemy AI dead state for enemy base class
 * TODO:
 * Known Bugs:
 ****************************************************************************************/

#pragma once

#include "CoreMinimal.h"
//#include "MyEnemyAIDeadState.generated.h"

UCLASS()
class STEVESLOTH_API MyEnemyAIDeadState
{

private: // PRIVATE VARIABLES
	float TimeDead;
	bool IsDead;

public: // CONSTRUCTOR HERE
	MyEnemyAIDeadState();
	~MyEnemyAIDeadState();

private: // PRIVATE INTERNAL FUNCTIONS
	void DeadAnimation();
	void DropItem();
};
