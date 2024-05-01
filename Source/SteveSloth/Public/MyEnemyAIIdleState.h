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
#include "GameFramework/Character.h"
#include "MyEnemyAIIdleState.generated.h"

UCLASS()
class STEVESLOTH_API AMyEnemyAIIdleState : public ACharacter
{
	GENERATED_BODY()
private:
	bool IsIdle;
	bool HasDetectedPlayer;
	float PatrolTime;
	float DetectionRange;
	float IdleResetTime;

public:
	AMyEnemyAIIdleState();

public:
	virtual void Tick(float DeltaTime);


private:
	void DetectPlayer();
	void StartPatrol();
	void ResetToIdle();
	void BeginChase();
	void PlayIdleAnimation();
};
