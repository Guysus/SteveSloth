/****************************************************************************************
 * Copyright: SteveSloth
 * Name: Tammy, Elad Saretzky, Jeff Moreau
 * Script: MyEnemyBaseClass.h
 * Date: April 29. 2024
 * Description: Base Class for all enemies to inherit from
 * TODO: Add more Variables (such as animations)
 * Known Bugs:
 ****************************************************************************************/
#pragma once

// INCLUDES HERE
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/SplineComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "SteveSingleton.h"
#include "MyEnemyData.h"
#include "MyEnemyStateComponent.h"

// MAKE SURE THIS INCLUDE IS LAST
#include "MyEnemyBaseClass.generated.h"

UCLASS()
class STEVESLOTH_API AMyEnemyBaseClass : public ACharacter
{
	GENERATED_BODY()
private: //PRIVATE CONST VARIABLES
	const float DESPAWN_TIMER_AMOUNT = 2.0f;

protected: // PROTECTED VARIABLES 
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UMyEnemyStateComponent* StateMachine;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (RowType = "MyEnemyData"), Category = "Data")
	FDataTableRowHandle EnemyDataTable;

	FTransform StartingLocation;
	float Damage;
	float MovementSpeed;
	float MaxHealth;
	float PatrolRange;
	float ChaseRange;
	float MeleeAttackRange;
	float RangedAttackRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spline")
	USplineComponent* MySpline;

	ACharacter* Player; 

	bool IsDead;

	FTimerHandle DespawnTimerHandle;

public: // PUBLIC VARIABLES
	UAnimationAsset* IdleAnim;
	UAnimationAsset* MoveAnim;
	UAnimationAsset* AttackAnim;
	UAnimationAsset* RangedAttackAnim;
	UAnimationAsset* HitAnim;
	UAnimationAsset* DeathAnim;

	float CurrentHealth;

public: // GETTERS/ACCESSORS
	float GetMovementSpeed() const { return MovementSpeed; }
	float GetAttackRange() const { return MeleeAttackRange; }
	float GetDamage() const { return Damage; }

public:	// CONSTRUCTOR HERE
	AMyEnemyBaseClass();

protected: // SETUP FUNCTIONS
	virtual void BeginPlay() override;

public:	// UPDATE FUNCTIONS
	virtual void Tick(float DeltaTime) override;

private: // PRIVATE INTERNAL FUNCTIONS
	void Despawn();
};