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
	MaxConfusionRange = 2.0f;
	IsAnimationRunning = false;
}

void UMyGenericEnemyConfusionState::ExitState() 
{

}

void UMyGenericEnemyConfusionState::UpdateState(float deltaTime) 
{
	FVector currentPoint = Myself->GetStartingLocation().GetLocation();
	ConfusionSpot = currentPoint + UKismetMathLibrary::RandomUnitVector() * FMath::RandRange(0.0f, MaxConfusionRange);
	FVector moveLocation = FMath::VInterpConstantTo(currentPoint, ConfusionSpot, deltaTime, Myself->GetMovementSpeed());

	Myself->SetActorLocation(moveLocation);

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