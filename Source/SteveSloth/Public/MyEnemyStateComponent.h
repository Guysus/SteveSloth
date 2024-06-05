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

protected: // PROTECTED DETAILS PANEL VARIABLES 
	TArray<UMyEnemyBaseState*> States;

protected: // PRIVATE INTERNAL VARIABLES
	UMyEnemyBaseState* CurrentState;

public: // GETTERS/ACCESSORS
	TArray<UMyEnemyBaseState*> GetStateList() {return States; }
	UMyEnemyBaseState* GetCurrentState() const { return CurrentState; }
	UMyEnemyBaseState* GetState(EStates wantedState) const { return States[wantedState]; }

public:	// CONSTRUCTOR HERE
	UMyEnemyStateComponent();

	void SetBaseClass(AMyEnemyBaseClass* myEnemy);

protected: // INITIALIZE INHERITABLE FUNCTIONS
	virtual void BeginPlay() override;

public:	// UPDATE ACCESS ANYWHERE FUNCTIONS
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void ChangeState(UMyEnemyBaseState* newState);
};