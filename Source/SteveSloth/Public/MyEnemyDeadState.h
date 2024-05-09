/****************************************************************************************
* Copyright: SteveSloth
 * Name:Guy Lapensee
 * Script: MyEnemyDeadState.h
 * Date:May 3, 2024
 * Description:Enemy Dead State; run timer for death animation montage
 * TODO:
 * Known Bugs:
 ****************************************************************************************/

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyEnemyBaseClass.h"
#include "MyEnemyBaseState.h"
#include "MyEnemyDeadState.generated.h"

//DECLARATIONS
class UAnimMontage;

UCLASS(Blueprintable)
class STEVESLOTH_API UMyEnemyDeadState : public UMyEnemyBaseState
{
	GENERATED_BODY()

private:
	AMyEnemyBaseClass* Enemy;
	USkeletalMeshComponent* EnemyMesh;
	bool IsAnimationRunning;
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Timer")
	float DeathDelayTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Montage")
	UAnimMontage* CallMontage;  

public: //PUBLIC ABSTRACT FUNCTIONS
	virtual void EnterState() override;
	virtual void ExitState() override;
	virtual void UpdateState(float deltaTime) override;

	void SetEnemyBaseClass(AMyEnemyBaseClass* myEnemy) { Enemy = myEnemy; }
	void SetEnemyMesh(USkeletalMeshComponent* mesh) { EnemyMesh = mesh; }
};