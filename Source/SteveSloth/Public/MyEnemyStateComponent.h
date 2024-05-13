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

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class STEVESLOTH_API UMyEnemyStateComponent : public UActorComponent
{
	GENERATED_BODY()

protected: // PROTECTED VARIABLES
	////more states will go here as new TArrays
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "States")
	TArray<UMyEnemyBaseState*> AttackStates;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "States")
	TSubclassOf<UMyEnemyBaseState> IdleState;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "States")
	TSubclassOf<UMyEnemyBaseState> DeadState;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "States")
	USkeletalMeshComponent* MyMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "States")
	USkeletalMeshComponent* EnemyMesh;

	TSubclassOf<UMyEnemyBaseState> CurrentState;

public:	// CONSTRUCTOR HERE
	UMyEnemyStateComponent();

protected:
	virtual void BeginPlay() override;

public:	// PUBLIC INTERNAL FUNCTIONS
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void ChangeState(TSubclassOf<UMyEnemyBaseState> newState);

	TSubclassOf<UMyEnemyBaseState> GetIdleState() { return IdleState; }
	TSubclassOf<UMyEnemyBaseState> GetDeadState() { return DeadState; }
};