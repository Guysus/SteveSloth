/****************************************************************************************
 * Copyright: SteveSloth
 * Name: Ken Ferris
 * Script: MyEnemyAttackingState.h
 * Date: May 3, 2024
 * Description: 
 * TODO:
 * Known Bugs:
 ****************************************************************************************/

#pragma once

#include "CoreMinimal.h"
#include "MyEnemyBaseState.h"
#include "MyEnemyAttackingState.generated.h"

/**
 * 
 */
UCLASS()
class STEVESLOTH_API UMyEnemyAttackingState : public UMyEnemyBaseState
{
	GENERATED_BODY()
	
public:
	virtual void EnterState() override;
	virtual void ExitState() override;
	virtual void UpdateState(float deltaTime) override;
};
