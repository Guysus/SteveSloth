/****************************************************************************************
* Copyright: SteveSloth
 * Name:
 * Script: MyEnemyPatrolState.cpp
 * Date: May.03/2024
 * Description: this is the cpp file for the enemy patrol state that handles what enemies do when in the patrol state
 * TODO:
 * Known Bugs:
 ****************************************************************************************/

#include "MyEnemyPatrolState.h"

void UMyEnemyPatrolState::EnterState()
{
	UE_LOG(LogTemp, Warning, TEXT("Enter Patrol"));
}

void UMyEnemyPatrolState::ExitState()
{
	
}

void UMyEnemyPatrolState::UpdateState(float deltaTime)
{
	if (PMyself != nullptr) 
	{
		//ProcessMovement(deltaTime);
	}
}

void UMyEnemyPatrolState::ProcessMovement(float value)
{
	const float SplineLength = PMySpline->GetSplineLength();
		
	FVector CurrentSplineLocation = PMySpline->GetLocationAtDistanceAlongSpline(value * SplineLength, ESplineCoordinateSpace::World);
	FRotator CurrentSplineRotation = PMySpline->GetRotationAtDistanceAlongSpline(value * SplineLength, ESplineCoordinateSpace::World);

	PMyMesh->SetWorldLocationAndRotation(CurrentSplineLocation, CurrentSplineRotation);

	/*if(PSkeletalMeshComponent->GetPosition() = PSplineComponent->)*/
}

void UMyEnemyPatrolState::OnEndMovement()
{

}
