// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyEnemyBaseState.h"
#include "MyEnemyBaseClass.h"

#include "MyCrococdileOpeningState.generated.h"

/**
 * 
 */
UCLASS()
class STEVESLOTH_API UMyCrococdileOpeningState : public UMyEnemyBaseState
{
	GENERATED_BODY()
	
private: // PRIVATE INTERNAL VARIABLES
	AMyEnemyBaseClass* Myself;
	USkeletalMeshComponent* MyMesh;

	bool IsMoveAnimationRunning;
	bool IsRoarAnimationRunning;
	float WaitTime;
	float Distance;

public: //PUBLIC INHERITED FUNCTIONS
	virtual void EnterState() override;
	virtual void ExitState() override;
	virtual void UpdateState(float deltaTime) override;

	virtual void SetEnemyBaseClass(AMyEnemyBaseClass* myEnemy) override;
	virtual void SetEnemyMesh(USkeletalMeshComponent* mesh) override;
};
