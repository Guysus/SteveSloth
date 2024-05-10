/****************************************************************************************
 * Copyright: SteveSloth
 * Name: Elad Saretzky
 * Script: MyPossumEnemyClass.h
 * Date: May 6, 2024
 * Description: Does all of the specific to possum things
 * TODO:
 * Known Bugs:
 ****************************************************************************************/

#pragma once

#include "CoreMinimal.h"
#include "MyEnemyBaseClass.h"
#include "MyPossumEnemyClass.generated.h"


UCLASS()
class STEVESLOTH_API AMyPossumEnemyClass : public AMyEnemyBaseClass
{
	GENERATED_BODY()

private: //PRIVATE CONST VARIABLES
	const float IDLE_VELOCITY_TOLERANCE = 0.001f;
	const float IDLE_TIMER_AMOUNT = 1.0f;
	const float IDLE_RESET_TIMER_AMOUNT = 1.0f;
	const float RANGED_RESET_TIMER_AMOUNT = 1.0f;

private: // PRIVATE VARIABLES 
	FTimerHandle StartPatrolTimerHandle;
	FTimerHandle IdleResetTimerHandle;
	FTimerHandle RangedResetTimerHandle;

	bool IsIdle;
	bool IsChasing;
	bool IsAttackingMelee;
	bool IsAttackingRanged;

protected: // PROTECTED VARIABLES 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Chase")
	float ChaseRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack")
	float MeleeAttackRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack")
	float RangedAttackRange;

public:	// CONSTRUCTOR HERE
	AMyPossumEnemyClass();

protected: // SETUP FUNCTIONS
	virtual void BeginPlay() override;

public:	// UPDATE FUNCTIONS
	virtual void Tick(float DeltaTime) override;

private: // PRIVATE INTERNAL FUNCTIONS
	void StartPatrolState(); 
	void IdleReset();

	void RangedAttackOver();
};
