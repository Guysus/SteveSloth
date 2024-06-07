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
	Frozen,
	Confused,
	Die
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class STEVESLOTH_API UMyEnemyStateComponent : public UActorComponent
{
	GENERATED_BODY()

public: // PROTECTED DETAILS PANEL VARIABLES 
	TArray<TWeakObjectPtr<UMyEnemyBaseState>> States;

public: // PRIVATE INTERNAL VARIABLES
	TWeakObjectPtr<UMyEnemyBaseState> CurrentState;
	
public: // GETTERS/ACCESSORS
	TArray<TWeakObjectPtr<UMyEnemyBaseState>> GetStateList() {return States; }
	TWeakObjectPtr<UMyEnemyBaseState> GetState(EStates wantedState) { return States[wantedState]; }

public:	// CONSTRUCTOR HERE
	UMyEnemyStateComponent();

protected: // INITIALIZE INHERITABLE FUNCTIONS
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:	// UPDATE ACCESS ANYWHERE FUNCTIONS
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void ChangeState(TWeakObjectPtr<UMyEnemyBaseState> newState);
};