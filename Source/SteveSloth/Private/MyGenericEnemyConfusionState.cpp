/****************************************************************************************
* Copyright: SteveSloth
 * Name: Brandon Thomas
 * Script: MyGenericEnemyConfusionState.cpp
 * Date: May 21, 2024
 * Description: What Happens when the Enemy is confused
 * TODO:
 * Known Bugs:
 ****************************************************************************************/


#include "MyGenericEnemyConfusionState.h"

void UMyGenericEnemyConfusionState::EnterState() 
{
	MaxConfusionRange = 5.0f;
	NegMaxConfusionRange = -5.0f;
	WaitTime = 2.0f;
	IsAnimationRunning = false;
}

void UMyGenericEnemyConfusionState::ExitState() 
{

}

void UMyGenericEnemyConfusionState::UpdateState(float deltaTime) 
{
	FVector currentLocation = Myself->GetActorLocation();
	FVector range;
	range.X = currentLocation.X + FMath::RandRange(NegMaxConfusionRange, MaxConfusionRange);
	range.Y = currentLocation.Y + FMath::RandRange(NegMaxConfusionRange, MaxConfusionRange);;
	range.Z = currentLocation.Z;
	FVector moveLocation = FMath::VInterpTo(currentLocation, range, deltaTime, Myself->GetMovementSpeed());

	if (WaitTime > 0) 
	{
		if (Myself != nullptr && !IsAnimationRunning)
		{
			Myself->GetMesh()->PlayAnimation(Myself->MoveAnim, true);
			IsAnimationRunning = true;
		}

		Myself->SetActorLocation(moveLocation);
		WaitTime -= deltaTime;
		return;
	}

	WaitTime = 2.0f;
}

void UMyGenericEnemyConfusionState::SetEnemyBaseClass(AMyEnemyBaseClass* myEnemy)
{
	Myself = myEnemy;
}

void UMyGenericEnemyConfusionState::SetEnemyMesh(USkeletalMeshComponent* mesh)
{
	MyMesh = mesh;
}