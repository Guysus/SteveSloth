// Fill out your copyright notice in the Description page of Project Settings.


#include "MyEnemyStateComponent.h"

// Sets default values for this component's properties
UMyEnemyStateComponent::UMyEnemyStateComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UMyEnemyStateComponent::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
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

