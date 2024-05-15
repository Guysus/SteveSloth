/****************************************************************************************
* Copyright: SteveSloth
 * Name:
 * Script: MyEnemyPatrolState.cpp
 * Date: May.03/2024
 * Description: this is the cpp file for the enemy patrol state that handles what enemies do when in the patrol state
 * TODO:
 * Known Bugs:
 ****************************************************************************************/

//#include "MyEnemyPatrolState.h"
//
//void UMyEnemyPatrolState::EnterState()
//{
//	if (PMyself != nullptr && PMySpline != nullptr)
//	{
//		Speed = PMyself->GetMovementSpeed();
//		IsAnimationRunning = false;
//	}
//}
//
//void UMyEnemyPatrolState::ExitState()
//{
//
//}
//
//void UMyEnemyPatrolState::UpdateState(float deltaTime)
//{
//
//	if (PMyself != nullptr && PMySpline != nullptr)
//	{
//		//Member variable to hold the spline length
//		const float SplineLength = PMySpline->GetSplineLength();
//
//		//Member variable for spline location and rotation
//		FVector CurrentSplineLocation = PMySpline->GetLocationAtDistanceAlongSpline(SplineLength * Speed, ESplineCoordinateSpace::World);
//		FRotator CurrentSplineRotation = PMySpline->GetRotationAtDistanceAlongSpline(SplineLength * Speed, ESplineCoordinateSpace::World);
//
//		//Set enemies location and rotation
//		PMyself->SetActorLocation(CurrentSplineLocation);
//		PMyself->SetActorRotation(CurrentSplineRotation);
//
//		IsAnimationRunning = true;
//	}
//
//	if (IsAnimationRunning)
//	{
//		//Run animation
//		PMyself->GetMesh()->PlayAnimation(PMyself->MoveAnim, true);
//	}
//}
//
//void UMyEnemyPatrolState::SetEnemyBaseClass(AMyEnemyBaseClass* myEnemy)
//{
//	PMyself = myEnemy;
//}
//
//void UMyEnemyPatrolState::SetEnemyMesh(USkeletalMeshComponent* mesh)
//{
//	PMyMesh = mesh;
//}
