/****************************************************************************************
* Copyright: SteveSloth
 * Name: Jeff Moreau
 * Script: MyGenericEnemyPatrolState.h
 * Date: May 8, 2024
 * Description: What Happens when the Enemy is Patroling around
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
#include "MyGenericEnemyPatrolState.generated.h"

UCLASS()
class STEVESLOTH_API UMyGenericEnemyPatrolState : public UMyEnemyBaseState
{
	GENERATED_BODY()
	
private:
	AMyPlayer* Steve;
	ACharacter* Player;
	AMyEnemyBaseClass* Myself;
	USkeletalMeshComponent* MyMesh;

	FVector StartingSpot;
	FVector PatrolSpot;
	bool IsAnimationRunning;

public: //PUBLIC FUNCTIONS
	virtual void EnterState() override;
	virtual void ExitState() override;
	virtual void UpdateState(float deltaTime) override;

	virtual void SetEnemyBaseClass(AMyEnemyBaseClass* myEnemy) override;
	virtual void SetEnemyMesh(USkeletalMeshComponent* mesh) override;
};
