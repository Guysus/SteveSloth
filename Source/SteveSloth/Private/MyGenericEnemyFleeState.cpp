/****************************************************************************************
* Copyright: SteveSloth
 * Name: Jeff Moreau
 * Script: MyGenericEnemyFleeState.cpp
 * Date: May 8, 2024
 * Description: What Happens when the Enemy is running away from the player
 * TODO:
 * Known Bugs:
 ****************************************************************************************/

#include "MyGenericEnemyFleeState.h"

void UMyGenericEnemyFleeState::EnterState()
{
	Player = USteveSingleton::GetSteve()->GetPlayerCharacter();
	Steve = Cast<AMyPlayer>(Player);
	IsAnimationRunning = false;
}

void UMyGenericEnemyFleeState::ExitState()
{

}

void UMyGenericEnemyFleeState::UpdateState(float deltaTime)
{
	if (Myself != nullptr && !IsAnimationRunning)
	{
		Myself->GetMesh()->PlayAnimation(Myself->MoveAnim, true);
		IsAnimationRunning = true;
	}
}

void UMyGenericEnemyFleeState::SetEnemyBaseClass(AMyEnemyBaseClass* myEnemy)
{
	Myself = myEnemy;
}

void UMyGenericEnemyFleeState::SetEnemyMesh(USkeletalMeshComponent* mesh)
{
	MyMesh = mesh;
}
