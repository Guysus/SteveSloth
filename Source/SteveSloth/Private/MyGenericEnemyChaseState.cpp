/****************************************************************************************
 * Copyright: SteveSloth
 * Name: Jeff Moreau
 * Script: MyGenericEnemyChaseState.cpp
 * Date: May 8, 2024
 * Description: What Happens when the Enemy is Chasing the Player
 * TODO:
 * Known Bugs:
 ****************************************************************************************/

#include "MyGenericEnemyChaseState.h"

void UMyGenericEnemyChaseState::EnterState()
{
	Player = USteveSingleton::GetSteve()->GetPlayerCharacter();
	Steve = Cast<AMyPlayer>(Player);

	IsAnimationRunning = false;
	IsChasing = false;
}

void UMyGenericEnemyChaseState::ExitState()
{

}

void UMyGenericEnemyChaseState::UpdateState(float deltaTime)
{
	// GetsDirection for Enemy to move in
	FVector myLocation = Myself->GetActorLocation();
	FVector steveLocation = Player->GetActorLocation();
	FVector directionToTravel = (steveLocation - myLocation).GetSafeNormal();
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

	if (FVector::Dist(Myself->GetActorLocation(), Player->GetActorLocation()) > Myself->GetChaseRange())
	{
		MovementComponent->Velocity = FVector(0, 0, 0);
	}
}

void UMyGenericEnemyChaseState::SetEnemyBaseClass(AMyEnemyBaseClass* myEnemy)
{
	Myself = myEnemy;
}

void UMyGenericEnemyChaseState::SetEnemyMesh(USkeletalMeshComponent* mesh)
{
	MyMesh = mesh;
}