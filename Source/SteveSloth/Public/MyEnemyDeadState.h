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
#include "MyEnemyBaseState.h"
#include "MyEnemyBaseClass.h"
#include "MyEnemyDeadState.generated.h"

//DECLARATIONS
class UAnimMontage;

UCLASS()
class STEVESLOTH_API UMyEnemyDeadState : public UMyEnemyBaseState
{
	GENERATED_BODY()

public:
	AMyEnemyBaseClass* Enemy;

private:
	FTimerHandle DeathTimerHandle;
	bool IsTimerStarted;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Timer")
	float DeathDelayTime;

public: //PUBLIC ABSTRACT FUNCTIONS
	virtual void EnterState() override;
	virtual void ExitState() override;
	virtual void UpdateState(float deltaTime) override;
};
