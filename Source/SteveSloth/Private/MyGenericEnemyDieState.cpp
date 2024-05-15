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
	IsAnimationRunning = false;
}

void UMyGenericEnemyDieState::ExitState()
{

}

void UMyGenericEnemyDieState::UpdateState(float deltaTime)
{
	UE_LOG(LogTemp, Warning, TEXT("im dead"));
	if (Myself != nullptr && !IsAnimationRunning)
	{
		Myself->GetMesh()->PlayAnimation(Myself->DeathAnim, true);
		IsAnimationRunning = true;
	}
}

void UMyGenericEnemyDieState::SetEnemyBaseClass(AMyEnemyBaseClass* myEnemy)
{
	Myself = myEnemy;
}

void UMyGenericEnemyDieState::SetEnemyMesh(USkeletalMeshComponent* mesh)
{
	MyMesh = mesh;
}