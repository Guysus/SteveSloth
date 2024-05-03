/****************************************************************************************
 * Copyright: SteveSloth
 * Name: Elad Saretzky
 * Script: MyEnemyStateComponent.h
 * Date: May 2, 2024
 * Description: Component that is the state machine for the enemy to use
 * TODO: 
 * Known Bugs:
 ****************************************************************************************/
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MyEnemyBaseState.h"

// MAKE SURE THIS INCLUDE IS LAST
#include "MyEnemyStateComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class STEVESLOTH_API UMyEnemyStateComponent : public UActorComponent
{
	GENERATED_BODY()

protected: // PROTECTED VARIABLES
	////more states will go here as new TArrays
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "States")
	TArray<UMyEnemyBaseState*> AttackStates;

	UMyEnemyBaseState* CurrentState;

public:	// CONSTRUCTOR HERE
	// Sets default values for this component's properties
	UMyEnemyStateComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	// PUBLIC INTERNAL FUNCTIONS
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void ChangeState(UMyEnemyBaseState* newState);

};
