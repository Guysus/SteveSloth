/****************************************************************************************
 * Copyright: SteveSloth
 * Name: Elad Saretzky, Jeff Moreau
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
}

void UMyEnemyStateComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Update the Currently Selected State
	if (CurrentState != nullptr)
	{
		CurrentState->GetDefaultObject<UMyEnemyBaseState>()->UpdateState(DeltaTime);
	}
}

void UMyEnemyStateComponent::ChangeState(TSubclassOf<UMyEnemyBaseState> newState)
{
	// Exit the Previously Selected State
	if (CurrentState != nullptr) 
	{
		CurrentState->GetDefaultObject<UMyEnemyBaseState>()->ExitState();
	}
	
	// Change previous state to new State
	CurrentState = newState;

	// Enter New State
	if (CurrentState != nullptr)
	{
		CurrentState->GetDefaultObject<UMyEnemyBaseState>()->EnterState();
	}
}