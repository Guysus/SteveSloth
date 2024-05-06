/****************************************************************************************
* Copyright: SteveSloth
 * Name: Elad Saretzky
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
	if (CurrentState != newState)
	{
		CurrentState->ExitState();
		CurrentState = newState;
		CurrentState->EnterState();
	}
}
