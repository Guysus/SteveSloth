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
	IsAnimationRunning = false;
}

void UMyEnemyDeadState::ExitState()
{
	UE_LOG(LogTemp, Warning, TEXT("Exit Death State"));
}

void UMyEnemyDeadState::UpdateState(float deltaTime)
{
	UE_LOG(LogTemp, Warning, TEXT("Update State"));
	if (Enemy != nullptr && !IsAnimationRunning)
	{
		Enemy->GetMesh()->PlayAnimation(Enemy->Dead, true);
		IsAnimationRunning = true;
	}
}
