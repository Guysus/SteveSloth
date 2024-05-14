/****************************************************************************************
 * Copyright: SteveSloth
 * Name: Ken Ferris
 * Script: MyEnemyAttackingState.h
 * Date: May 3, 2024
 * Description: This is the logic for the enemy melee attack state
 * TODO:
 * Known Bugs:
 ****************************************************************************************/

#pragma once

#include "CoreMinimal.h"
#include "MyEnemyBaseClass.h"
#include "MyEnemyBaseState.h"
#include "MyPlayer.h"
#include "MyEnemyAttackingState.generated.h"

UCLASS(Blueprintable)
class STEVESLOTH_API UMyEnemyAttackingState : public UMyEnemyBaseState
{
	GENERATED_BODY()

private:
	ACharacter* Player;
	AMyPlayer* Steve;
	AMyEnemyBaseClass* Myself;
	USkeletalMeshComponent* MyMesh;
	bool IsAnimationRunning;

	// Combat parameter
	float MeleeAttackDamage;
	float AttackRange;

public:
	virtual void EnterState() override;
	virtual void ExitState() override;
	virtual void UpdateState(float deltaTime) override;

	virtual void SetEnemyBaseClass(AMyEnemyBaseClass* myEnemy) override;
	virtual void SetEnemyMesh(USkeletalMeshComponent* mesh) override;

private:
	// Internal functions
	void PerformMeleeAttack();
	void SelectAttack();
};
