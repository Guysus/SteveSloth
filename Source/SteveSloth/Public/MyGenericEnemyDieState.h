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
#include "MyPlayer.h"

// MAKE SURE THIS INCLUDE IS LAST
#include "MyGenericEnemyDieState.generated.h"

UCLASS()
class STEVESLOTH_API UMyGenericEnemyDieState : public UMyEnemyBaseState
{
	GENERATED_BODY()

private:
	ACharacter* Player;
	AMyPlayer* Steve;
	AMyEnemyBaseClass* Myself;
	USkeletalMeshComponent* MyMesh;
	bool IsAnimationRunning;

public: //PUBLIC FUNCTIONS
	virtual void EnterState() override;
	virtual void ExitState() override;
	virtual void UpdateState(float deltaTime) override;

	void SetEnemyBaseClass(AMyEnemyBaseClass* myEnemy) { Myself = myEnemy; }
	void SetEnemyMesh(USkeletalMeshComponent* mesh) { MyMesh = mesh; }
};
