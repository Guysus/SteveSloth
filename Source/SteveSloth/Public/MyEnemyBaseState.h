/****************************************************************************************
 * Copyright: SteveSloth
 * Name: Elad Saretzky
 * Script: MyEnemyBaseState.h
 * Date: May 2, 2024
 * Description: Houses the abstract functions (enter, update, exit) for the state machine
 * TODO: 
 * Known Bugs:
 ****************************************************************************************/
#pragma once

// INCLUDES HERE
#include "CoreMinimal.h"
#include "SteveSingleton.h"
#include "UObject/NoExportTypes.h"

 // MAKE SURE THIS INCLUDE IS LAST
#include "MyEnemyBaseState.generated.h"

UCLASS(Abstract)
class STEVESLOTH_API UMyEnemyBaseState : public UObject
{
	GENERATED_BODY()

public: // PUBLIC ABSTRACT FUNCTIONS
	virtual void EnterState() PURE_VIRTUAL(MyEnemyBaseState::EnterState, );
	virtual void ExitState() PURE_VIRTUAL(MyEnemyBaseState::ExitState, );
	virtual void UpdateState(float deltaTime) PURE_VIRTUAL(MyEnemyBaseState::UpdateState, );
};