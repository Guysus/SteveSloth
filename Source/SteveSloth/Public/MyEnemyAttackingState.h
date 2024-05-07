/****************************************************************************************
 * Copyright: SteveSloth
 * Name: Ken Ferris
 * Script: MyEnemyAttackingState.h
 * Date: May 3, 2024
 * Description: Enemy Attack State
 * TODO:
 * Known Bugs:
 ****************************************************************************************/

#pragma once

#include "CoreMinimal.h"
#include "MyEnemyBaseState.h"
#include "Kismet/GameplayStatics.h"
#include "SteveSingleton.h"
#include "Animation/AnimMontage.h"
#include "MyEnemyAttackingState.generated.h"

UCLASS(Blueprintable)
class STEVESLOTH_API UMyEnemyAttackingState : public UMyEnemyBaseState
{
	GENERATED_BODY()
	
public:
	virtual void EnterState() override;
	virtual void ExitState() override;
	virtual void UpdateState(float deltaTime) override;

protected:
	ACharacter* Player;

	// Combat parameters
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Combat")
	float AttackDamage;

	// Animation parameters
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Animation")
	UAnimMontage* AttackMontage;

	// Function to perform attack
	void PerformAttack();
};
