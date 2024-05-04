/****************************************************************************************
 * Copyright: SteveSloth
 * Name: Ken Ferris
 * Script: MyEnemyAttackingState.cpp
 * Date: May 3, 2024
 * Description: 
 * TODO:
 * Known Bugs:
 ****************************************************************************************/


#include "MyEnemyAttackingState.h"
#include "MyEnemyBaseClass.h"
#include "Kismet/GameplayStatics.h"

void UMyEnemyAttackingState::EnterState()
{

}

void UMyEnemyAttackingState::ExitState()
{

}

void UMyEnemyAttackingState::UpdateState(float deltaTime)
{
	if (IsPlayerInRange())
	{
		AttackPlayer();
	}
}

bool UMyEnemyAttackingState::IsPlayerInRange() const
{
	AMyEnemyBaseClass* Owner = Cast<AMyEnemyBaseClass>(GetOwner());
	if (!Owner)
	{
		UE_LOG(LogTemp, Error, TEXT("MyEnemyAttackingState::IsPlayerInRange - Owner is not valid"));
		return false;
	}

	ACharacter* PlayerCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	if (!PlayerCharacter)
	{
		UE_LOG(LogTemp, Error, TEXT("MyEnemyAttackingState::IsPlayerInRange - Player character not found"));
		return false;
	}

	float Distance = FVector::Distance(Owner->GetActorLocation(), PlayerCharacter->GetActorLocation());
	return Distance <= Owner->GetAttackRange();
}

void UMyEnemyAttackingState::AttackPlayer()
{
	AMyEnemyBaseClass* Owner = Cast<AMyEnemyBaseClass>(GetOwner());
	if (!Owner)
	{
		UE_LOG(LogTemp, Error, TEXT("MyEnemyAttackingState::AttackPlayer - Owner is not valid"));
		return;
	}

	ACharacter* PlayerCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	if (!PlayerCharacter)
	{
		UE_LOG(LogTemp, Error, TEXT("MyEnemyAttackingState::AttackPlayer - Player character not found"));
		return;
	}
}
