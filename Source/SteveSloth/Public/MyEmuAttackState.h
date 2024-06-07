/****************************************************************************************
* Copyright: SteveSloth
 * Name: Brandon Thomas
 * Script: MyEmuAttackState.h
 * Date: June. 06, 2024
 * Description: What Happens when the Emu is Attacking the Player
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
#include "MyEmuAttackState.generated.h"

UCLASS()
class STEVESLOTH_API UMyEmuAttackState : public UMyEnemyBaseState
{
	GENERATED_BODY()

private: // PRIVATE INTERNAL VARIABLES
	AMyPlayer* Steve;
	ACharacter* Player;
	AMyEnemyBaseClass* Myself;
	USkeletalMeshComponent* MyMesh;

	int AttackToPerform;

	bool IsAttacking;
	bool IsAnimationRunning;
	FTimerHandle AttackSpeed;

public: //PUBLIC INHERITED FUNCTIONS
	virtual void EnterState() override;
	virtual void ExitState() override;
	virtual void UpdateState(float deltaTime) override;

	virtual void SetEnemyBaseClass(AMyEnemyBaseClass* myEnemy) override;
	virtual void SetEnemyMesh(USkeletalMeshComponent* mesh) override;

private: // PRIVATE INTERNAL FUNCTIONS
	void PerformAttack();
};
