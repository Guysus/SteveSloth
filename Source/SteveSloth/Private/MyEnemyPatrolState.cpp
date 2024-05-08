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
	
}

void UMyEnemyPatrolState::ExitState()
{
	//Call this state when enemy notices player(Chase state) or reaches end of spline(Idle state)
}

void UMyEnemyPatrolState::UpdateState(float deltaTime)
{
	ProcessMovement(deltaTime);
}

void UMyEnemyPatrolState::ProcessMovement(float value)
{
	const float SplineLength = PSplineComponent->GetSplineLength();
		
	FVector CurrentSplineLocation = PSplineComponent->GetLocationAtDistanceAlongSpline(value * SplineLength, ESplineCoordinateSpace::World);
	FRotator CurrentSplineRotation = PSplineComponent->GetRotationAtDistanceAlongSpline(value * SplineLength, ESplineCoordinateSpace::World);

	PSkeletalMeshComponent->SetWorldLocationAndRotation(CurrentSplineLocation, CurrentSplineRotation);

	/*if(PSkeletalMeshComponent->GetPosition() = PSplineComponent->)*/
}

void UMyEnemyPatrolState::OnEndMovement()
{

}
