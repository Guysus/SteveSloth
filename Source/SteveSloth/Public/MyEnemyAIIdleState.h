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

UCLASS()
class STEVESLOTH_API UMyEnemyAIIdleState : public UMyEnemyBaseState
{
	GENERATED_BODY()

public:
	AMyEnemyBaseClass* Enemy;
	ACharacter* Player;

private:
	bool IsIdle = false;
	bool HasDetectedPlayer = false;
	float DetectionRange = 1000.0;
	float DistancetoPlayer = 2000.0f;
	float IdleTimer = 5.0f;

public:
	virtual void EnterState() override;
	virtual void ExitState() override;
	virtual void UpdateState(float deltaTime) override;

private:
	void DetectPlayer();

};
