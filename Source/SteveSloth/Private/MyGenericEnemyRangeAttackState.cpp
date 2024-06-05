/****************************************************************************************
* Copyright: SteveSloth
* Name : Jeff Moreau
* Script : MyGenericEnemyRangeAttackState.cpp
* Date : May 8, 2024
* Description : What Happens when the Enemy attacking the player from far
* TODO :
* Known Bugs :
****************************************************************************************/

#include "MyGenericEnemyRangeAttackState.h"

void UMyGenericEnemyRangeAttackState::EnterState()
{
	Player = USteveSingleton::GetSteve()->GetPlayerCharacter();
	Steve = Cast<AMyPlayer>(Player);
	IsAnimationRunning = false;

	LaunchProjectile();
	//GetWorld()->GetTimerManager().SetTimer(AttackSpeed, this, &UMyGenericEnemyRangeAttackState::LaunchProjectile, Myself->GetRangedAttackSpeed(), true);
}

void UMyGenericEnemyRangeAttackState::ExitState()
{

}

void UMyGenericEnemyRangeAttackState::UpdateState(float deltaTime)
{
	if (Myself != nullptr && !IsAnimationRunning)
	{
		Myself->GetMesh()->PlayAnimation(Myself->RangedAttackAnim, true);
		IsAnimationRunning = true;
	}
}

void UMyGenericEnemyRangeAttackState::SetEnemyBaseClass(AMyEnemyBaseClass* myEnemy)
{
	Myself = myEnemy;
}

void UMyGenericEnemyRangeAttackState::SetEnemyMesh(USkeletalMeshComponent* mesh)
{
	MyMesh = mesh;
}

void UMyGenericEnemyRangeAttackState::LaunchProjectile()
{
	UWorld* myWorld = Myself->GetMyWorld();
	FTransform myTransform = FTransform(Myself->GetActorTransform());
	TSubclassOf<AActor> projectileSpawn = Myself->GetProjectile();

	UE_LOG(LogTemp, Warning, TEXT("Throw"));
	
	if (myWorld && projectileSpawn)
	{
		UE_LOG(LogTemp, Warning, TEXT("Not Null"));
		myWorld->SpawnActor(projectileSpawn, &myTransform);
	}
}