/****************************************************************************************
 * Copyright: SteveSloth
 * Name: Jeff Moreau
 * Script: MyGenericEnemyDieState.h
 * Date: May 8, 2024
 * Description: What Happens when the Enemy Dies
 * TODO:
 * Known Bugs:
 ****************************************************************************************/

#pragma once

 // INCLUDES HERE
#include "CoreMinimal.h"
#include "MyEnemyBaseClass.h"
#include "MyEnemyBaseState.h"

// MAKE SURE THIS INCLUDE IS LAST
#include "MyGenericEnemyDieState.generated.h"

UCLASS()
class STEVESLOTH_API UMyGenericEnemyDieState : public UMyEnemyBaseState
{
	GENERATED_BODY()

private: // PRIVATE INTERNAL VARIABLES
	AMyEnemyBaseClass* Myself;
	USkeletalMeshComponent* MyMesh;

	bool IsAnimationRunning;

public: //PUBLIC INHERITED FUNCTIONS
	virtual void EnterState() override;
	virtual void ExitState() override;
	virtual void UpdateState(float deltaTime) override;

	virtual void SetEnemyBaseClass(AMyEnemyBaseClass* myEnemy) override;
	virtual void SetEnemyMesh(USkeletalMeshComponent* mesh) override;
};