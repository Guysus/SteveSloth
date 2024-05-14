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

	if (PMyself != nullptr && PMySpline != nullptr)
	{
		TotalPathTimeController = 8.0f;
		PMySpline->Duration = TotalPathTimeController;
	}
}

void UMyEnemyPatrolState::ExitState()
{

}

void UMyEnemyPatrolState::UpdateState(float deltaTime)
{
	StartTime = deltaTime;

	if (PMyself != nullptr && PMySpline != nullptr) 
	{
		float CurrentSplineTime = (deltaTime - StartTime) / TotalPathTimeController;

		float Distance = PMySpline->GetSplineLength() * CurrentSplineTime;

		//World Position
		FVector Position = PMySpline->GetLocationAtDistanceAlongSpline(Distance, ESplineCoordinateSpace::World);
		PMyself->SetActorLocation(Position);

		//World Rotation
		FVector Direction = PMySpline->GetDirectionAtDistanceAlongSpline(Distance, ESplineCoordinateSpace::World);
		//Create rotator given a vector director (normalized)
		FRotator Rotator = FRotationMatrix::MakeFromX(Direction).Rotator();
		PMyself->SetActorRotation(Rotator);
	}
	else 
	{
		UE_LOG(LogTemp, Warning, TEXT("Nullcheck failed"));
	}
}

void UMyEnemyPatrolState::SetEnemyBaseClass(AMyEnemyBaseClass* myEnemy)
{
	PMyself = myEnemy;
}

void UMyEnemyPatrolState::SetEnemyMesh(USkeletalMeshComponent* mesh)
{
	PMyMesh = mesh;
}

void UMyEnemyPatrolState::ProcessMovement(float value)
{
	UE_LOG(LogTemp, Warning, TEXT("Processing Movement"));

	const float SplineLength = PMySpline->GetSplineLength();
		
	FVector CurrentSplineLocation = PMySpline->GetLocationAtDistanceAlongSpline(value * SplineLength, ESplineCoordinateSpace::World);
	FRotator CurrentSplineRotation = PMySpline->GetRotationAtDistanceAlongSpline(value * SplineLength, ESplineCoordinateSpace::World);

	UE_LOG(LogTemp, Warning, TEXT("Current Spline Location is: %s"), *CurrentSplineLocation.ToString());
	UE_LOG(LogTemp, Warning, TEXT("Current Spline Rotation is: %s"), *CurrentSplineRotation.ToString());

	/*PMyMesh->SetWorldLocationAndRotation(CurrentSplineLocation, CurrentSplineRotation);*/
}

void UMyEnemyPatrolState::OnEndMovement()
{

}
