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
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "MyEnemyBaseState.h"
#include "MyEnemyBaseClass.h"
#include "MyLevelManager.h"
#include "MyEnemyAIIdleState.generated.h"

UCLASS(Blueprintable)
class STEVESLOTH_API UMyEnemyAIIdleState : public UMyEnemyBaseState
{
	GENERATED_BODY()

public:
	AMyEnemyBaseClass* Enemy;
	ACharacter* Player;

private:
	bool IsIdle = false;
	float IdleTimer = 5.0f;

public:
	virtual void EnterState() override;
	virtual void ExitState() override;
	virtual void UpdateState(float deltaTime) override;
};
