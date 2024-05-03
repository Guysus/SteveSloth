/****************************************************************************************
* Copyright: SteveSloth
 * Name:Guy Lapensee
 * Script: MyTemplate.h
 * Date:May 3, 2024
 * Description:Enemy Dead State
 * TODO:
 * Known Bugs:
 ****************************************************************************************/

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyEnemyBaseState.h"
#include "MyEnemyDeadState.generated.h"

/**
 * 
 */
UCLASS()
class STEVESLOTH_API UMyEnemyDeadState : public UMyEnemyBaseState
{
	GENERATED_BODY()

private:
	FTimerHandle DeathTimerHandle;
	float DeathDelayTime;
	bool TimerStarted;

public: //PUBLIC ABSTRACT FUNCTIONS
	virtual void EnterState() override;
	virtual void ExitState() override;
	virtual void UpdateState(float deltaTime) override;
};
