/****************************************************************************************
* Copyright: SteveSloth
 * Name:Guy Lapensee
 * Script: MyEnemyDeadState.cpp
 * Date:May 3, 2024
 * Description:Enemy Dead State
 * TODO:
 * Known Bugs:
 ****************************************************************************************/


#include "MyEnemyDeadState.h"

void UMyEnemyDeadState::EnterState()
{
	
	IsTimerStarted = false;
	DeathDelayTime = 3.0f;
}

void UMyEnemyDeadState::ExitState()
{
	Enemy->Destroy();
}

void UMyEnemyDeadState::UpdateState(float deltaTime)
{
	if (!IsTimerStarted)
	{
		GetWorld()->GetTimerManager().SetTimer(
			DeathTimerHandle, // handle to cancel timer at a later time
			this, // the owning object
			&UMyEnemyDeadState::ExitState, // function to call on elapsed
			DeathDelayTime, // float delay until elapsed
			false); // looping?

		//Death animation
		//Death sound FX

		//Drop Item
		IsTimerStarted = true;
	}
}
