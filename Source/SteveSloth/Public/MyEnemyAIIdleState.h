/****************************************************************************************
* Copyright: SteveSloth
 * Name: Aidan MacLeod
 * Script: MyEnemyIdleState.h
 * Date: April 29. 2024
 * Description: Idle State Class for all enemies to inherit from
 * TODO:
 * Known Bugs:
 ****************************************************************************************/

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyEnemyAIIdleState.generated.h"

/**
 * 
 */
class STEVESLOTH_API MyEnemyAIIdleState
{

protected:

	virtual void BeginPlay() override;

public:

	bool IsDetected;

	virtual void Tick(float DeltaTime) override;
	virtual void DetectPlayer() override;
	MyEnemyAIIdleState();
	~MyEnemyAIIdleState();
	
};
