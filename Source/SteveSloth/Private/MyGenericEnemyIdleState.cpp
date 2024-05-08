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
	Player = USteveSingleton::GetSteve()->GetPlayerCharacter();
	UE_LOG(LogTemp, Warning, TEXT("Enter Idle"));
	if (Player != nullptr)
	{
		FVector testing = Player->GetActorLocation();
		FString newTesting = testing.ToString();
	
		UE_LOG(LogTemp, Warning, TEXT("%s"), *newTesting);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Null Idle"));
	}
	UE_LOG(LogTemp, Warning, TEXT("Exit Idle"));
}

void UMyGenericEnemyIdleState::ExitState()
{
	UE_LOG(LogTemp, Warning, TEXT("Exit Idle"));
}

void UMyGenericEnemyIdleState::UpdateState(float deltaTime)
{
	/*FVector testing = Player->GetActorLocation();
	FString newTesting = testing.ToString();

	UE_LOG(LogTemp, Warning, TEXT("%s"), *newTesting);*/
	//UE_LOG(LogTemp, Warning, TEXT("Update Idle"));
}