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
	range.X = currentLocation.X + FMath::RandRange(Myself->GetMaxConfusionRangeInverse(), Myself->GetMaxConfusionRange());
	range.Y = currentLocation.Y + FMath::RandRange(Myself->GetMaxConfusionRangeInverse(), Myself->GetMaxConfusionRange());;
	range.Z = currentLocation.Z;
	FVector moveLocation = FMath::VInterpTo(currentLocation, range, deltaTime, Myself->GetMovementSpeed());

	if (WaitTime > 0) 
	{
		if (Myself != nullptr && !IsAnimationRunning)
		{
			Myself->GetMesh()->PlayAnimation(Myself->ConfusionAnim, true);
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