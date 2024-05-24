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
	StartingPoint = Myself->GetActorLocation();
	IsAnimationRunning = false;
}

void UMyGenericEnemyConfusionState::ExitState() 
{

}

void UMyGenericEnemyConfusionState::UpdateState(float deltaTime) 
{
	FVector currentLocation = Myself->GetActorLocation();
	ConfusionSpot.X = currentLocation.X + FMath::RandRange(NegMaxConfusionRange, MaxConfusionRange);
	ConfusionSpot.Y = currentLocation.Y + FMath::RandRange(NegMaxConfusionRange, MaxConfusionRange);;
	ConfusionSpot.Z = currentLocation.Z;
	FVector direction = (StartingPoint - ConfusionSpot).GetSafeNormal();
	FVector moveLocation = FMath::VInterpTo(currentLocation, ConfusionSpot, WaitTime, Myself->GetMovementSpeed());

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