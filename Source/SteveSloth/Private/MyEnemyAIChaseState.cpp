/****************************************************************************************
 * Copyright: SteveSloth
 * Name: Tammy Boisvert
 * Script: MyEnemyAIChaseState.cpp
 * Date: May 3. 2024
 * Description: This is the Enemy State for chasing the player when they are in range
 * TODO:
 * Known Bugs:
 ****************************************************************************************/


#include "MyEnemyAIChaseState.h"
#include <GameFramework/CharacterMovementComponent.h>


void UMyEnemyAIChaseState::EnterState()
{
	 Player = USteveSingleton::GetSteve()->GetPlayerCharacter();
	 IsAnimationRunning = false;
}

void UMyEnemyAIChaseState::UpdateState(float deltaTime)
{
	if (Myself != nullptr && Player != nullptr) 
	{
		//Get The Players Location(will be handled in enemy base class)
		PlayerLocation = Player->GetActorLocation();
		//Get The Enemies Location(will be handled in enemy base class)
		EnemyLocation = Myself->GetActorLocation();
		//Rotate Enemy to face The player
		FRotator EnemyRotation = UKismetMathLibrary::FindLookAtRotation(EnemyLocation, PlayerLocation);
		
		if (PlayerLocation != FVector::ZeroVector) 
		{
			 //Have Enemy Face Players Direction(will be handled in enemybase class)
			 Direction = PlayerLocation - EnemyLocation;
			 Direction.Normalize();
			 //Update Enemy Location 
			 Myself->SetActorLocation(EnemyLocation + Direction * Myself->GetMovementSpeed() * deltaTime);

			 if (Myself != nullptr && !IsAnimationRunning) 
			 {
				Myself->GetMesh()->PlayAnimation(Myself->MoveAnim, true);
				IsAnimationRunning = true;
			 }
		} 
		if (MyMesh != nullptr)
		{
			MyMesh->SetWorldRotation(EnemyRotation);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("set world rotation issue"));
		}
	} 
}
void UMyEnemyAIChaseState::ExitState()
{
}

