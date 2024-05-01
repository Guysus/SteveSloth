/****************************************************************************************
 * Copyright: SteveSloth
 * Name: Tammy Jeff Moreau
 * Script: MyEnemyBaseClass.h
 * Date: April 29. 2024
 * Description: Base Class for all enemies to inherit from
 * TODO:
 * Known Bugs:
 ****************************************************************************************/
#pragma once

// INCLUDES HERE
#include "CoreMinimal.h"
#include "GameFramework/Character.h"

// MAKE SURE THIS INCLUDE IS LAST
#include "MyEnemyBaseClass.generated.h"

// ENUMS HERE
enum EState
{
	Idle,
	Patrol,
	Chase,
	Flee,
	Attack,
	Dead
};

UCLASS()
class STEVESLOTH_API AMyEnemyBaseClass : public ACharacter
{
	GENERATED_BODY()

private: // PRIVATE VARIABLES
	EState CurrentState;
	
public:	// CONSTRUCTOR HERE
	AMyEnemyBaseClass();

protected: // SETUP FUNCTIONS
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:	// UPDATE FUNCTIONS
	virtual void Tick(float DeltaTime) override;
	
protected: // PRIVATE INTERNAL FUNCTIONS
	void IdleState();
	void PatrolState();
	void ChaseState();
	void FleeState();
	void AttackState();
	void DeadState();
};