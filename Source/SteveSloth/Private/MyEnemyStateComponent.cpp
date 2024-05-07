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
	ChangeState(DeathState);
}

void UMyEnemyStateComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (CurrentState != nullptr)
	{
		auto currentState = Cast<UMyEnemyBaseState>(CurrentState);
		currentState->UpdateState(DeltaTime);
		//CurrentState->UpdateState(DeltaTime);
	}
}

void UMyEnemyStateComponent::ChangeState(TSubclassOf<UMyEnemyBaseState> newState)
{
	auto currentState = Cast<UMyEnemyBaseState>(CurrentState);
	
	if (CurrentState != newState)
	{
		currentState->ExitState();
		CurrentState = newState;
		currentState->EnterState();
		//CurrentState->ExitState();
		//CurrentState = newState;
		//CurrentState->EnterState();
	}
}
