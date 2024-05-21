/****************************************************************************************
* Copyright: SteveSloth
 * Name: Elad Saretzky
 * Script: MyGenericEnemyFrozenState.cpp
 * Date: May 21, 2024
 * Description: What Happens when the Enemy is Frozen
 * TODO:
 * Known Bugs:
 ****************************************************************************************/

#include "MyGenericEnemyFrozenState.h"

void UMyGenericEnemyFrozenState::EnterState()
{
	IsAnimationRunning = false;
}

void UMyGenericEnemyFrozenState::ExitState()
{

}

void UMyGenericEnemyFrozenState::UpdateState(float deltaTime)
{
	// Play the Animation for being Frozen
	if (Myself != nullptr && !IsAnimationRunning)
	{
		Myself->GetMesh()->PlayAnimation(Myself->FrozenAnim, true);
		IsAnimationRunning = true;
	}
}

void UMyGenericEnemyFrozenState::SetEnemyBaseClass(AMyEnemyBaseClass* myEnemy)
{
	Myself = myEnemy;
}

void UMyGenericEnemyFrozenState::SetEnemyMesh(USkeletalMeshComponent* mesh)
{
	MyMesh = mesh;
}