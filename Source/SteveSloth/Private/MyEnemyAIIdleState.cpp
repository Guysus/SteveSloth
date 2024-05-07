/****************************************************************************************
* Copyright: SteveSloth
* Name: Aidan MacLeod
* Script: MyEnemyAIIdleState.cpp
* Date: May 6. 2024
* Description: Idle State Class for all enemies to inherit from
* TODO:
* Known Bugs:
****************************************************************************************/

#include "MyEnemyAIIdleState.h"

void UMyEnemyAIIdleState::EnterState()
{
	IsIdle = true;
	HasDetectedPlayer = false;
	DetectionRange = 1000.0;
	DistancetoPlayer = 2000.0f;
	IdleTimer = 5.0f;
	Player = USteveSingleton::GetSteve()->GetPlayerCharacter();

	//Enemy->PlayAnimMontage(IdleAnim, 1.0f);
}

void UMyEnemyAIIdleState::ExitState()
{
	//if (IdleTimer <= 0.0f)
	//{
	//	Go to Patrol State
	//}
	//else if (HasDetectedPlayer == true)
	//{
	//	Go to Chase State
	//}
}

void UMyEnemyAIIdleState::UpdateState(float deltaTime)
{
	IdleTimer -= deltaTime;
	DetectPlayer();
}

void UMyEnemyAIIdleState::DetectPlayer()
{
	if (Player && Enemy)
	{
		//Calculates the distance between the player and enemy
		float Distance = FVector::Distance(Player->GetActorLocation(), Enemy->GetActorLocation());

		//Assigns the calculated distance to the DistancetoPlayer variable
		DistancetoPlayer = Distance;

		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FString::Printf(TEXT("Distance to Player: %f"), DistancetoPlayer));
	}

	if (DetectionRange <= DistancetoPlayer)
	{
		HasDetectedPlayer = true;
		ExitState();
	}
}