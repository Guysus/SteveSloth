/****************************************************************************************
* Copyright: SteveSloth
 * Name:Guy Lapensee
 * Script: MyTemplate.h
 * Date:May 3, 2024
 * Description:Enemy Dead State
 * TODO:
 * Known Bugs:
 ****************************************************************************************/


#include "MyEnemyDeadState.h"

void UMyEnemyDeadState::EnterState()
{
	TimerStarted = true;
	DeathDelayTime = 3.0f;
}

void UMyEnemyDeadState::ExitState()
{
	AActor::Destroy;
}

void UMyEnemyDeadState::UpdateState(float deltaTime)
{
	if (TimerStarted == true)
	{
		GetWorld()->GetTimerManager().SetTimer(
			DeathTimerHandle, // handle to cancel timer at a later time
			this, // the owning object
			&UMyEnemyDeadState::ExitState, // function to call on elapsed
			DeathDelayTime, // float delay until elapsed
			false); // looping?

		//Death animation
		//Death sound FX


	}
}
