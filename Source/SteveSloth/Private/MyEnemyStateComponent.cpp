/****************************************************************************************
* Copyright: SteveSloth
 * Name: Elad Saretzky, edited:Guy Lapensee
 * Script: MyEnemyStateComponent.cpp
 * Date: May 2, 2024
 * Description: Component that is the state machine for the enemy to use
 * TODO: 
 * Known Bugs:
 ****************************************************************************************/

#include "MyEnemyStateComponent.h"

UMyEnemyStateComponent::UMyEnemyStateComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UMyEnemyStateComponent::BeginPlay()
{
	Super::BeginPlay();
	ActiveState = Cast<UMyEnemyBaseState>(CurrentState);
	ChangeState(DeathState);
	
}

void UMyEnemyStateComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	//UE_LOG(LogTemp, Warning, TEXT("Current State"));

	if (ActiveState != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Current State IF"));
		ActiveState->UpdateState(DeltaTime);
		//CurrentState->UpdateState(DeltaTime);
	}
}

void UMyEnemyStateComponent::ChangeState(TSubclassOf<UMyEnemyBaseState> newState)
{
	UE_LOG(LogTemp, Warning, TEXT("Change State "));
	//if (ActiveState != Cast<UMyEnemyBaseState>(newState))
	//{
		
		if (ActiveState != nullptr) 
		{
			ActiveState->ExitState();
		}
		
		ActiveState = Cast<UMyEnemyBaseState>(newState);
		if (ActiveState != nullptr)
		{
			ActiveState->EnterState();
		}
	//}
}
