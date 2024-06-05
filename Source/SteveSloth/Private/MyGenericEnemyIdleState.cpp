/****************************************************************************************
 * Copyright: SteveSloth
 * Name: Jeff Moreau
 * Script: MyGenericEnemyIdleState.cpp
 * Date: May 8, 2024
 * Description: What Happens when the Enemy is Idle
 * TODO: 
 * Known Bugs:
 ****************************************************************************************/

#include "MyGenericEnemyIdleState.h"

void UMyGenericEnemyIdleState::EnterState()
{
	UE_LOG(LogTemp, Warning, TEXT("Enter Idle"));
	IsAnimationRunning = false;
}

void UMyGenericEnemyIdleState::ExitState()
{
	//UE_LOG(LogTemp, Warning, TEXT("Exit Idle %s"), *Myself->GetName());
}

void UMyGenericEnemyIdleState::UpdateState(float deltaTime)
{
	UE_LOG(LogTemp, Warning, TEXT("Update Idle"));

	// Play the Animation for being Idle
	if (Myself != nullptr && !IsAnimationRunning)
	{
		UE_LOG(LogTemp, Warning, TEXT("Animation %s"), *Myself->GetName());
		Myself->GetMesh()->PlayAnimation(Myself->IdleAnim, true);
		IsAnimationRunning = true;
	}
}

void UMyGenericEnemyIdleState::SetEnemyBaseClass(AMyEnemyBaseClass* myEnemy)
{
	//UE_LOG(LogTemp, Warning, TEXT("Set Base Class %s"), *Myself->GetName());
	Myself = myEnemy;
}

void UMyGenericEnemyIdleState::SetEnemyMesh(USkeletalMeshComponent* mesh)
{
	//UE_LOG(LogTemp, Warning, TEXT("Set Mesh %s"), *Myself->GetName());
	MyMesh = mesh;
}