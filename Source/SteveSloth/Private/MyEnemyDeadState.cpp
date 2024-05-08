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
	UE_LOG(LogTemp, Warning, TEXT("Death Enter State"));
	/*IsTimerStarted = false;
	DeathDelayTime = 3.0f;

	if (!IsTimerStarted)
	{
		GetWorld()->GetTimerManager().SetTimer(
			DeathTimerHandle, // handle to cancel timer at a later time
			this, // the owning object
			&UMyEnemyDeadState::ExitState, // function to call on elapsed
			DeathDelayTime, // float delay until elapsed
			false); // looping?

		PlayMontage();

		//Drop Item
		IsTimerStarted = true;
	}*/
}

void UMyEnemyDeadState::ExitState()
{

}

void UMyEnemyDeadState::UpdateState(float deltaTime)
{
	UE_LOG(LogTemp, Warning, TEXT("Update State"));
}

void UMyEnemyDeadState::PlayMontage()
{
	
	//UAnimInstance* AnimInstance;
}