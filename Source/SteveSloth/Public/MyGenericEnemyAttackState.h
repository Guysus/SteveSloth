/****************************************************************************************
* Copyright: SteveSloth
 * Name: Jeff Moreau
 * Script: MyGenericEnemyAttackState.h
 * Date: May 8, 2024
 * Description: What Happens when the Enemy is Attacking the Player
 * TODO:
 * Known Bugs:
 ****************************************************************************************/

#pragma once

 // INCLUDES HERE
#include "MyPlayer.h"
#include "CoreMinimal.h"
#include "MyEnemyBaseClass.h"
#include "MyEnemyBaseState.h"

// MAKE SURE THIS INCLUDE IS LAST
#include "MyGenericEnemyAttackState.generated.h"

UCLASS()
class STEVESLOTH_API UMyGenericEnemyAttackState : public UMyEnemyBaseState
{
	GENERATED_BODY()
	
private:
	AMyPlayer* Steve;
	ACharacter* Player;
	AMyEnemyBaseClass* Myself;
	USkeletalMeshComponent* MyMesh;

	FTimerHandle AttackSpeed;
	bool IsAnimationRunning;

public: //PUBLIC FUNCTIONS
	virtual void EnterState() override;
	virtual void ExitState() override;
	virtual void UpdateState(float deltaTime) override;

	virtual void SetEnemyBaseClass(AMyEnemyBaseClass* myEnemy) override;
	virtual void SetEnemyMesh(USkeletalMeshComponent* mesh) override;

private:
	void PerformAttack();
};