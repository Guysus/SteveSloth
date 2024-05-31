// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCrococdileOpeningState.h"

void UMyCrococdileOpeningState::EnterState()
{
	IsMoveAnimationRunning = false;
	IsRoarAnimationRunning = false;
	WaitTime = 5.0f;
	Distance = 5.0f;
}

void UMyCrococdileOpeningState::ExitState()
{

}

void UMyCrococdileOpeningState::UpdateState(float deltaTime)
{
	FVector currentLocation = Myself->GetActorLocation();
	FVector range;
	range.Z = currentLocation.Z + Distance;
	range.X = currentLocation.X;
	range.Y = currentLocation.Y;
	FVector moveLocation = FMath::VInterpTo(currentLocation, range, deltaTime, Myself->GetMovementSpeed());

	if (WaitTime > 0)
	{
		// Play the Animation for being Idle
		if (Myself != nullptr && !IsMoveAnimationRunning)
		{
			Myself->GetMesh()->PlayAnimation(Myself->MoveAnim, true);
			IsMoveAnimationRunning = true;
		}

		Myself->SetActorLocation(moveLocation);
		WaitTime -= deltaTime;
		return;
	}

	if (WaitTime <= 0) 
	{
		if (Myself != nullptr && !IsRoarAnimationRunning) 
		{
			Myself->GetMesh()->PlayAnimation(Myself->IdleAnim, false);
			IsMoveAnimationRunning = false;
			IsRoarAnimationRunning = true;
		}
	}
}

void UMyCrococdileOpeningState::SetEnemyBaseClass(AMyEnemyBaseClass* myEnemy)
{
	Myself = myEnemy;
}

void UMyCrococdileOpeningState::SetEnemyMesh(USkeletalMeshComponent* mesh)
{
	MyMesh = mesh;
}