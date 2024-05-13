/****************************************************************************************
* Copyright: SteveSloth
 * Name: Jeff Moreau
 * Script: MyGenericEnemyChaseState.cpp
 * Date: May 8, 2024
 * Description: What Happens when the Enemy is Chasing the Player
 * TODO:
 * Known Bugs:
 ****************************************************************************************/

#include "MyGenericEnemyChaseState.h"

void UMyGenericEnemyChaseState::EnterState()
{
	Player = USteveSingleton::GetSteve()->GetPlayerCharacter();
	Steve = Cast<AMyPlayer>(Player);
	IsAnimationRunning = false;
}

void UMyGenericEnemyChaseState::ExitState()
{

}

void UMyGenericEnemyChaseState::UpdateState(float deltaTime)
{
	if (Myself != nullptr && !IsAnimationRunning)
	{
		Myself->GetMesh()->PlayAnimation(Myself->MoveAnim, true);
		IsAnimationRunning = true;
	}
}