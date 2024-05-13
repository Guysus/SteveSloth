/****************************************************************************************
* Copyright: SteveSloth
 * Name: Jeff Moreau
 * Script: MyGenericEnemyDieState.cpp
 * Date: May 8, 2024
 * Description: What Happens when the Enemy Dies
 * TODO:
 * Known Bugs:
 ****************************************************************************************/

#include "MyGenericEnemyDieState.h"

void UMyGenericEnemyDieState::EnterState()
{
	Player = USteveSingleton::GetSteve()->GetPlayerCharacter();
	Steve = Cast<AMyPlayer>(Player);
	IsAnimationRunning = false;
}

void UMyGenericEnemyDieState::ExitState()
{

}

void UMyGenericEnemyDieState::UpdateState(float deltaTime)
{
	if (Myself != nullptr && !IsAnimationRunning)
	{
		Myself->GetMesh()->PlayAnimation(Myself->DeathAnim, true);
		IsAnimationRunning = true;
	}
}