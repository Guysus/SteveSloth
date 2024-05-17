/****************************************************************************************
* Copyright: SteveSloth
 * Name: Jeff Moreau
 * Script: MyGenericEnemyAttackState.cpp
 * Date: May 8, 2024
 * Description: What Happens when the Enemy is Attacking the Player
 * TODO:
 * Known Bugs:
 ****************************************************************************************/

#include "MyGenericEnemyAttackState.h"

void UMyGenericEnemyAttackState::EnterState()
{
	Player = USteveSingleton::GetSteve()->GetPlayerCharacter();
	Steve = Cast<AMyPlayer>(Player);

	IsAttacking = false;
	IsAnimationRunning = false;

	// Interval for attack the Main Player
	GetWorld()->GetTimerManager().SetTimer(AttackSpeed, this, &UMyGenericEnemyAttackState::PerformAttack, Myself->GetMeleeAttackSpeed(), true);
}

void UMyGenericEnemyAttackState::ExitState()
{
	// Clear the attack timer on exit from State
	GetWorld()->GetTimerManager().ClearTimer(AttackSpeed);
}

void UMyGenericEnemyAttackState::UpdateState(float deltaTime)
{
	// Play the Animation for the Attack
	if (Myself != nullptr && !IsAnimationRunning && IsAttacking)
	{
		Myself->GetMesh()->PlayAnimation(Myself->AttackAnim, true);
		IsAnimationRunning = true;
		IsAttacking = false;
	}
}

void UMyGenericEnemyAttackState::SetEnemyBaseClass(AMyEnemyBaseClass* myEnemy)
{
	Myself = myEnemy;
}

void UMyGenericEnemyAttackState::SetEnemyMesh(USkeletalMeshComponent* mesh)
{
	MyMesh = mesh;
}

void UMyGenericEnemyAttackState::PerformAttack()
{
	IsAttacking = true;
	// Hit the Main Player for X Damage
	Steve->HitPlayer(Myself->GetDamage());
}