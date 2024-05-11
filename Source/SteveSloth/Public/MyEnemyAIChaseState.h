/****************************************************************************************
 * Copyright: SteveSloth
 * Name: Tammy Boisvert
 * Script: MyEnemyAIChasingState.h
 * Date: May 3. 2024
 * Description: This is the Enemy State for chasing the player when they are in range
 * TODO:
 * Known Bugs:
 ****************************************************************************************/

#pragma once

#include "CoreMinimal.h"
#include "MyPlayer.h"
#include "Math/Vector.h"
#include "Animation/AnimInstance.h"
#include "MyEnemyBaseState.h"
#include "MyEnemyBaseClass.h"
#include "MyEnemyAIChaseState.generated.h"

UCLASS()
class STEVESLOTH_API UMyEnemyAIChaseState : public UMyEnemyBaseState
{
	GENERATED_BODY()

private:
	ACharacter* Player;
	FVector PlayerLocation;
    AMyEnemyBaseClass* Myself;
	FVector EnemyLocation;
    FVector Direction;	
	USkeletalMeshComponent* MyMesh;
	bool IsAnimationRunning;
public:
	virtual void EnterState()override;
	virtual void ExitState()override;
	virtual void UpdateState(float deltaTime)override;
	void SetEnemyBaseClass(AMyEnemyBaseClass* myEnemy) { Myself = myEnemy; }
	void SetEnemyMesh(USkeletalMeshComponent* mesh) { MyMesh = mesh; }
};
