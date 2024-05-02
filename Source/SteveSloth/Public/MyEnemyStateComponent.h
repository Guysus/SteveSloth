/****************************************************************************************
 * Copyright: SteveSloth
 * Name: Elad Saretzky
 * Script: MyEnemyStateComponent.h
 * Date: May 2, 2024
 * Description: Component that is the state machine for the enemy to use
 * TODO: Hold the current state and switch between states
 * Known Bugs:
 ****************************************************************************************/
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MyEnemyBaseState.h"
#include "MyEnemyStateComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class STEVESLOTH_API UMyEnemyStateComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMyEnemyStateComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	//more states will go here as new TArrays
	UPROPERTY (EditAnywhere, Category = "States")
	TArray<UMyEnemyBaseState*> AttackStates;

	UMyEnemyBaseState* CurrentState;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void ChangeState(UMyEnemyBaseState* newState);

};
