/****************************************************************************************
 * Copyright: SteveSloth
 * Name: Elad Saretzky, Jeff Moreau
 * Script: MyEnemyStateComponent.h
 * Date: May 2, 2024
 * Description: Component that is the state machine for the enemy to use
 * TODO: 
 * Known Bugs:
 ****************************************************************************************/

#pragma once

// INCLUDES HERE
#include "CoreMinimal.h"
#include "MyEnemyBaseState.h"
#include "Components/ActorComponent.h"

// MAKE SURE THIS INCLUDE IS LAST
#include "MyEnemyStateComponent.generated.h"

// ENUMS HERE
enum EStates
{
	Idle,
	Patrol,
	Chase,
	Flee,
	Attack,
	RangedAttack,
	Die
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class STEVESLOTH_API UMyEnemyStateComponent : public UActorComponent
{
	GENERATED_BODY()

protected: // PROTECTED DETAILS PANEL VARIABLES 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "States")
	TArray<TSubclassOf<UMyEnemyBaseState>> States;

private: // PRIVATE INTERNAL VARIABLES
	TSubclassOf<UMyEnemyBaseState> CurrentState;

public: // GETTERS/ACCESSORS
	TArray<TSubclassOf<UMyEnemyBaseState>> GetStateList() const {return States; }
	TSubclassOf<UMyEnemyBaseState> GetCurrentState() const { return CurrentState; }
	TSubclassOf<UMyEnemyBaseState> GetState(EStates wantedState) const { return States[wantedState]; }

public:	// CONSTRUCTOR HERE
	UMyEnemyStateComponent();

protected: // INITIALIZE INHERITABLE FUNCTIONS
	virtual void BeginPlay() override;

public:	// UPDATE ACCESS ANYWHERE FUNCTIONS
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void ChangeState(TSubclassOf<UMyEnemyBaseState> newState);
};