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
	MaxConfusionRange = 25.0f;
	StartingPoint = Myself->GetStartingLocation().GetLocation();
	
	IsAnimationRunning = false;
}

void UMyGenericEnemyConfusionState::ExitState() 
{

}

void UMyGenericEnemyConfusionState::UpdateState(float deltaTime) 
{
	for (int i = 0; i < 10; i++) 
	{
		i = (float)i;
		ConfusionSpot.X = StartingPoint.X + UKismetMathLibrary::RandomUnitVector().Y * FMath::RandRange(0.0f, MaxConfusionRange);
		FVector moveLocation = FMath::VInterpConstantTo(StartingPoint, ConfusionSpot, i, Myself->GetMovementSpeed());

		Myself->SetActorLocation(moveLocation);
	}

	
	

	if (Myself != nullptr && !IsAnimationRunning) 
	{
		Myself->GetMesh()->PlayAnimation(Myself->MoveAnim, true);
		IsAnimationRunning = true;
	}
}

void UMyGenericEnemyConfusionState::SetEnemyBaseClass(AMyEnemyBaseClass* myEnemy)
{
	Myself = myEnemy;
}

void UMyGenericEnemyConfusionState::SetEnemyMesh(USkeletalMeshComponent* mesh)
{
	MyMesh = mesh;
}