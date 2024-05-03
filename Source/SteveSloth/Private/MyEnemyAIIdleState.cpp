/****************************************************************************************
* Copyright: SteveSloth
 * Name: Aidan MacLeod
 * Script: MyEnemyAIIdleState.cpp
 * Date: April 29. 2024
 * Description: Idle State Class for all enemies to inherit from
 * TODO:
 * Known Bugs:
 ****************************************************************************************/

#include "MyEnemyAIIdleState.h"

AMyEnemyAIIdleState::AMyEnemyAIIdleState()
{
	IsIdle = false;
	HasDetectedPlayer = false;
	PatrolTime = 10.0f;
	DetectionRange = 1000.0f;
	DistancetoPlayer = 2000.0f;
}

void AMyEnemyAIIdleState::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	CalculateDistancetoPlayer();
	DetectPlayer();

	if (HasDetectedPlayer == true && DetectionRange < DistancetoPlayer)
	{
		PatrolTime -= DeltaTime;
	}
}

void AMyEnemyAIIdleState::DetectPlayer()
{
	if (DetectionRange >= DistancetoPlayer)
	{
		IsIdle = false;
		HasDetectedPlayer = true;
		BeginChase();
	}
}

void AMyEnemyAIIdleState::StartPatrol()
{
	//EState::Patrol;
	if (PatrolTime <= 0.0f)
	{
		ResetToIdle();
	}
}

void AMyEnemyAIIdleState::ResetToIdle()
{
	PlayIdleAnimation();
	IsIdle = true;
	HasDetectedPlayer = false;
	PatrolTime = 10.0f;
	//EState::Idle;
}

void AMyEnemyAIIdleState::BeginChase()
{
	//EState::Chase;
	if (HasDetectedPlayer == true && DetectionRange < DistancetoPlayer)
	{
		StartPatrol();
	}
}

void AMyEnemyAIIdleState::PlayIdleAnimation()
{
	if (UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance())
	{
		//Plays idle animation, IdleAnim is placeholder text
		//AnimInstance->Montage_Play(IdleAnim, 1.0f);
	}
}

/*void AMyEnemyAIIdleState::CalculateDistancetoPlayer()
{
	ACharacter* PlayerCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	ACharacter* EnemyCharacter;

		if (PlayerCharacter && EnemyCharacter)
		{
			//Calculates the distance between the player and enemy
			float Distance = FVector::Distance(PlayerCharacter->GetActorLocation(), EnemyCharacter->GetActorLocation());

			//Assigns the calculated distance to the DistancetoPlayer variable
			DistancetoPlayer = Distance;

			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FString::Printf(TEXT("Distance to Player: %f"), DistancetoPlayer));
		}
}*/



