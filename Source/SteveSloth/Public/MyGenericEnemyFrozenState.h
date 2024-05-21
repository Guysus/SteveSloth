/****************************************************************************************
* Copyright: SteveSloth
 * Name: Elad Saretzky
 * Script: MyGenericEnemyFrozenState.h
 * Date: May 21, 2024
 * Description: What Happens when the Enemy is Frozen
 * TODO:
 * Known Bugs:
 ****************************************************************************************/

#pragma once

 // INCLUDES HERE
#include "CoreMinimal.h"
#include "MyEnemyBaseClass.h"
#include "MyEnemyBaseState.h"

// MAKE SURE THIS INCLUDE IS LAST
#include "MyGenericEnemyFrozenState.generated.h"

UCLASS()
class STEVESLOTH_API UMyGenericEnemyFrozenState : public UMyEnemyBaseState
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
