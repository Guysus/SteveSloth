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
#include "Components/ActorComponent.h"
#include "MyEnemyBaseState.h"

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
	Die
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class STEVESLOTH_API UMyEnemyStateComponent : public UActorComponent
{
	GENERATED_BODY()

protected: // PROTECTED VARIABLES
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "States")
	TArray<TSubclassOf<UMyEnemyBaseState>> States;

	TSubclassOf<UMyEnemyBaseState> CurrentState;

public:	// CONSTRUCTOR HERE
	UMyEnemyStateComponent();

protected:
	virtual void BeginPlay() override;

public:	// PUBLIC INTERNAL FUNCTIONS
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void ChangeState(TSubclassOf<UMyEnemyBaseState> newState);

	TSubclassOf<UMyEnemyBaseState> GetIdleState() const { return States[Idle]; }
	TSubclassOf<UMyEnemyBaseState> GetPatrolState() const { return States[Patrol]; }
	TSubclassOf<UMyEnemyBaseState> GetChaseState() const { return States[Chase]; }
	TSubclassOf<UMyEnemyBaseState> GetFleeState() const { return States[Flee]; }
	TSubclassOf<UMyEnemyBaseState> GetAttackState() const { return States[Attack]; }
	TSubclassOf<UMyEnemyBaseState> GetDieState() const { return States[Die]; }
	TSubclassOf<UMyEnemyBaseState> GetCurrentState() const { return CurrentState; }
	TArray<TSubclassOf<UMyEnemyBaseState>> GetState() const { return States; }
};