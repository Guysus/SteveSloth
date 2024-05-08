/****************************************************************************************
* Copyright: SteveSloth
 * Name: Jeff Moreau
 * Script: MyGenericEnemyIdleState.cpp
 * Date: May 8, 2024
 * Description: What Happens when the Enemy is Idle
 * TODO: 
 * Known Bugs:
 ****************************************************************************************/

#include "MyGenericEnemyIdleState.h"

void UMyGenericEnemyIdleState::EnterState()
{
	FVector testing = Player->GetActorLocation();
	FString newTesting = testing.ToString();

	UE_LOG(LogTemp, Warning, TEXT("%s"), *newTesting);
}

void UMyGenericEnemyIdleState::ExitState()
{
	
}

void UMyGenericEnemyIdleState::UpdateState(float deltaTime)
{
	
}