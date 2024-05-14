/****************************************************************************************
 * Copyright: SteveSloth
 * Name: Ken Ferris
 * Script: MyEnemyAttackingState.cpp
 * Date: May 3, 2024
 * Description: This is the logic for the enemy melee attack state
 * TODO:
 * Known Bugs:
 ****************************************************************************************/


#include "MyEnemyAttackingState.h"

void UMyEnemyAttackingState::EnterState()
{
	Player = USteveSingleton::GetSteve()->GetPlayerCharacter();
	Steve = Cast<AMyPlayer>(Player);
	IsAnimationRunning = false;
}

void UMyEnemyAttackingState::ExitState()
{

}

void UMyEnemyAttackingState::UpdateState(float deltaTime)
{
	if (Myself != nullptr && !IsAnimationRunning)
	{
		SelectAttack();
	}
}

void UMyEnemyAttackingState::SetEnemyBaseClass(AMyEnemyBaseClass* myEnemy)
{
	Myself = myEnemy;
	AttackRange = Myself->GetAttackRange();
	MeleeAttackDamage = Myself->GetDamage();
}

void UMyEnemyAttackingState::SetEnemyMesh(USkeletalMeshComponent* mesh)
{
	MyMesh = mesh;
}

void UMyEnemyAttackingState::PerformMeleeAttack()
{
	if (MyMesh && Myself)
	{
		// Play melee attack animation montage
		MyMesh->PlayAnimation(Myself->AttackAnim, false);
	}

	
	if (Steve)
	{
		// Apply melee attack damage to the player
	}
}

void UMyEnemyAttackingState::SelectAttack()
{
	if (Player && Myself)
	{
		FVector EnemyLocation = Myself->GetActorLocation();
		FVector PlayerLocation = Player->GetActorLocation();
		float Distance = FVector::Distance(EnemyLocation, PlayerLocation);

		// Check if the player is within attack range
		if (Distance <= AttackRange)
		{
			// Perform melee attack
			PerformMeleeAttack();
		}
	}
}