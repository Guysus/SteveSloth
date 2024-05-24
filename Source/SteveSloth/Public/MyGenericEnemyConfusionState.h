/****************************************************************************************
* Copyright: SteveSloth
 * Name: Brandon Thomas
 * Script: MyGenericEnemyConfusionState.h
 * Date: May 21, 2024
 * Description: What Happens when the Enemy is confused
 * TODO:
 * Known Bugs:
 ****************************************************************************************/

#pragma once

 // INCLUDES HERE
#include "CoreMinimal.h"
#include "MyEnemyBaseClass.h"
#include "MyEnemyBaseState.h"

// MAKE SURE THIS INCLUDE IS LAST
#include "MyGenericEnemyConfusionState.generated.h"

UCLASS()
class STEVESLOTH_API UMyGenericEnemyConfusionState : public UMyEnemyBaseState
{
	GENERATED_BODY()
	
private: // PRIVATE INTERNAL VARIABLES
	AMyEnemyBaseClass* Myself;
	USkeletalMeshComponent* MyMesh;

	float MaxConfusionRange;
	float NegMaxConfusionRange;
	float WaitTime;

	bool IsAnimationRunning;

public: //PUBLIC INHERITED FUNCTIONS
	virtual void EnterState() override;
	virtual void ExitState() override;
	virtual void UpdateState(float deltaTime) override;

	virtual void SetEnemyBaseClass(AMyEnemyBaseClass* myEnemy) override;
	virtual void SetEnemyMesh(USkeletalMeshComponent* mesh) override;
};
