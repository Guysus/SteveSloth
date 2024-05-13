/****************************************************************************************
 * Copyright: SteveSloth
 * Name: Elad Saretzky
 * Script: MyCrocodileEnemyClass.h
 * Date: May 10, 2024
 * Description: Does all of the specific to Crocodile things
 * TODO:
 * Known Bugs:
 ****************************************************************************************/

#pragma once

#include "CoreMinimal.h"
#include "MyEnemyBaseClass.h"
#include "MyCrocodileEnemyClass.generated.h"


UCLASS()
class STEVESLOTH_API AMyCrocodileEnemyClass : public AMyEnemyBaseClass
{
	GENERATED_BODY()

private: //PRIVATE CONST VARIABLES
	const float IDLE_VELOCITY_TOLERANCE = 0.001f;
	const float IDLE_TIMER_AMOUNT = 1.0f;
	const float IDLE_RESET_TIMER_AMOUNT = 1.0f;
	const float RANGED_RESET_TIMER_AMOUNT = 1.0f;

private: // PRIVATE VARIABLES 
	FTimerHandle StartFleeTimerHandle;
	FTimerHandle IdleResetTimerHandle;

	bool IsIdle;
	bool IsPatroling;
	bool IsChasing;
	bool IsAttackingMelee;

	FVector StartingLocation;

protected: // PROTECTED VARIABLES 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Patrol")
	float PatrolRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Chase")
	float ChaseRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack")
	float MeleeAttackRange;

public:	// CONSTRUCTOR HERE
	AMyCrocodileEnemyClass();

protected: // SETUP FUNCTIONS
	virtual void BeginPlay() override;

public:	// UPDATE FUNCTIONS
	virtual void Tick(float DeltaTime) override;

private: // PRIVATE INTERNAL FUNCTIONS
	void StartFleeState();
	void IdleReset();
};
