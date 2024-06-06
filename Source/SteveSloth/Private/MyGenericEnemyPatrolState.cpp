/****************************************************************************************
 * Copyright: SteveSloth
 * Name: Jeff Moreau
 * Script: MyGenericEnemyPatrolState.cpp
 * Date: May 8, 2024
 * Description: What Happens when the Enemy is Patroling around
 * TODO:
 * Known Bugs:
 ****************************************************************************************/

#include "MyGenericEnemyPatrolState.h"

void UMyGenericEnemyPatrolState::EnterState()
{
	Player = USteveSingleton::GetSteve()->GetPlayerCharacter();
	if (Player)
	{
		Steve = Cast<AMyPlayer>(Player);
	}

	// Get Enemy Starting Location
	StartingSpot = Myself->GetStartingLocation().GetLocation();
	PatrolSpot = StartingSpot + UKismetMathLibrary::RandomUnitVector() * FMath::FRandRange(0.f, Myself->GetPatrolRange());

	IsAnimationRunning = false;
}

void UMyGenericEnemyPatrolState::ExitState()
{
	
}

void UMyGenericEnemyPatrolState::UpdateState(float deltaTime)
{
	FVector currentSpot = Myself->GetActorLocation();
	
	FVector directionToTravel = (PatrolSpot - currentSpot).GetSafeNormal();
	directionToTravel.Normalize();

	UCharacterMovementComponent* MovementComponent = Myself->GetCharacterMovement();
	MovementComponent->Velocity = directionToTravel * Myself->GetMovementSpeed();

	FRotator myRotation = directionToTravel.Rotation();
	myRotation.Pitch = 0.0f;
	Myself->SetActorRotation(myRotation);

	// Play the Animation for Walking
	if (Myself != nullptr && !IsAnimationRunning)
	{
		Myself->GetMesh()->PlayAnimation(Myself->MoveAnim, true);
		IsAnimationRunning = true;
	}
}

void UMyGenericEnemyPatrolState::SetEnemyBaseClass(AMyEnemyBaseClass* myEnemy)
{
	Myself = myEnemy;
}

void UMyGenericEnemyPatrolState::SetEnemyMesh(USkeletalMeshComponent* mesh)
{
	MyMesh = mesh;
}