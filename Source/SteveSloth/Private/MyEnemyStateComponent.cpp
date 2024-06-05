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

	if (CurrentState != nullptr)
	{
		CurrentState->UpdateState(DeltaTime);
	}
}

void UMyEnemyStateComponent::ChangeState(UMyEnemyBaseState* newState)
{
	// Exit the Previously Selected State
	if (CurrentState != nullptr) 
	{
		CurrentState->ExitState();
	}
	
	// Change previous state to new State
	CurrentState = newState;

	// Enter New State
	if (CurrentState != nullptr)
	{
		CurrentState->EnterState();
	}
}