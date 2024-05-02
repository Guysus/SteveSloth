/****************************************************************************************
 * Copyright: SteveSloth
 * Name: Elad Saretzky
 * Script: MyEnemyStateComponent.h
 * Date: May 2, 2024
 * Description: Houses the abstract functions (enter, update, exit) for the state machine
 * TODO: make all the abstract functions
 * Known Bugs:
 ****************************************************************************************/
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MyEnemyBaseState.generated.h"


UCLASS(Abstract)
class STEVESLOTH_API UMyEnemyBaseState : public UObject
{
	GENERATED_BODY()
	
public:
	virtual void EnterState() PURE_VIRTUAL(MyEnemyBaseState::EnterState, );
	virtual void ExitState() PURE_VIRTUAL(MyEnemyBaseState::ExitState, );
	virtual void UpdateState(float deltaTime) PURE_VIRTUAL(MyEnemyBaseState::UpdateState, );
};
