/****************************************************************************************
* Copyright: SteveSloth
 * Name: Jeff Moreau
 * Script: MyGenericEnemyAttackState.cpp
 * Date: May 8, 2024
 * Description: What Happens when the Enemy is Attacking the Player
 * TODO:
 * Known Bugs:
 ****************************************************************************************/

#include "MyGenericEnemyAttackState.h"

void UMyGenericEnemyAttackState::EnterState()
{
	Player = USteveSingleton::GetSteve()->GetPlayerCharacter();
	Steve = Cast<AMyPlayer>(Player);
	IsAnimationRunning = false;
}

void UMyGenericEnemyAttackState::ExitState()
{

}

void UMyGenericEnemyAttackState::UpdateState(float deltaTime)
{
	if (Myself != nullptr && !IsAnimationRunning)
	{
		Myself->GetMesh()->PlayAnimation(Myself->AttackAnim, true);
		IsAnimationRunning = true;
	}
}

void UMyGenericEnemyAttackState::SetEnemyBaseClass(AMyEnemyBaseClass* myEnemy)
{
	Myself = myEnemy;
}

void UMyGenericEnemyAttackState::SetEnemyMesh(USkeletalMeshComponent* mesh)
{
	MyMesh = mesh;
}
