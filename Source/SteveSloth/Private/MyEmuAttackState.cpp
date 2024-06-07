/****************************************************************************************
* Copyright: SteveSloth
 * Name: Jeff Moreau
 * Script: MyEmuAttackState.cpp
 * Date: June. 06, 2024
 * Description: What Happens when the Emu is Attacking the Player
 * TODO:
 * Known Bugs:
 ****************************************************************************************/

#include "MyEmuAttackState.h"

void UMyEmuAttackState::EnterState()
{
	Player = USteveSingleton::GetSteve()->GetPlayerCharacter();
	Steve = Cast<AMyPlayer>(Player);

	IsAttacking = false;
	IsAnimationRunning = false;

	AttackToPerform = FMath::RandRange(1, 2);

	// Interval for attack the Main Player
	/*GetWorld()->GetTimerManager().SetTimer(AttackSpeed, this, &UMyGenericEnemyAttackState::PerformAttack, Myself->GetMeleeAttackSpeed(), true);*/
}

void UMyEmuAttackState::ExitState()
{
	// Clear the attack timer on exit from State
	/*GetWorld()->GetTimerManager().ClearTimer(AttackSpeed);*/
}

void UMyEmuAttackState::UpdateState(float deltaTime)
{
	// Play the Animation for the Attack
	if (Myself != nullptr && !IsAnimationRunning)
	{
		FRotator facingDirection = UKismetMathLibrary::FindLookAtRotation(Player->GetActorLocation(), Myself->GetActorLocation());
		FRotator lookAt;
		lookAt.Pitch = Myself->GetActorRotation().Pitch;
		lookAt.Roll = Myself->GetActorRotation().Roll;
		lookAt.Yaw = facingDirection.Yaw;
		Myself->AddActorWorldRotation(lookAt);

		if (AttackToPerform == 1)
		{
			Myself->GetMesh()->PlayAnimation(Myself->AttackAnim, true);
			IsAnimationRunning = true;
			PerformAttack();
		}
		
		if (AttackToPerform == 2) 
		{
			Myself->GetMesh()->PlayAnimation(Myself->RangedAttackAnim, true);
			IsAnimationRunning = true;
			PerformAttack();
		}
	}
}

void UMyEmuAttackState::SetEnemyBaseClass(AMyEnemyBaseClass* myEnemy)
{
	Myself = myEnemy;
}

void UMyEmuAttackState::SetEnemyMesh(USkeletalMeshComponent* mesh)
{
	MyMesh = mesh;
}

void UMyEmuAttackState::PerformAttack()
{
	// Hit the Main Player for X Damage
	Steve->HitPlayer(Myself->GetDamage());
}