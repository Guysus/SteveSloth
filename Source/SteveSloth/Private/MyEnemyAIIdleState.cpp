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
	PatrolTime = 5.0f;
	IdleResetTime = 5.0f;
	DetectionRange = 1000.0f;
	DistancetoPlayer = 2000.0f;
}

void AMyEnemyAIIdleState::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	CalculateDistancetoPlayer();
	DetectPlayer();
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

}

void AMyEnemyAIIdleState::ResetToIdle()
{
	PlayIdleAnimation();
	IsIdle = true;
	HasDetectedPlayer = false;
}

void AMyEnemyAIIdleState::BeginChase()
{

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
		AnimInstance->Montage_Play(IdleAnim, 1.0f);
	}
}

void AMyEnemyAIIdleState::CalculateDistancetoPlayer()
{

}


