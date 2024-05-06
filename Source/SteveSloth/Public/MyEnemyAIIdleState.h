/****************************************************************************************
* Copyright: SteveSloth
* Name: Aidan MacLeod
* Script: MyEnemyAIIdleState.h
* Date: May 6. 2024
* Description: Idle State Class for all enemies to inherit from
* TODO:
* Known Bugs:
****************************************************************************************/

#pragma once

#include "CoreMinimal.h"
#include "MyEnemyBaseState.h"
#include "MyEnemyBaseClass.h"
#include <MyPlayer.h>
#include "MyEnemyAIIdleState.generated.h"


/**
 * 
 */
UCLASS()
class STEVESLOTH_API UMyEnemyAIIdleState : public UMyEnemyBaseState
{
	GENERATED_BODY()

public:
	virtual void EnterState() override;
	virtual void ExitState() override;
	virtual void UpdateState(float deltaTime) override;


private:
	AMyPlayer* Player;
	AMyEnemyBaseClass* Enemy;

};
