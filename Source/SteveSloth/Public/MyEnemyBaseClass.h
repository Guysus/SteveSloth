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
#include "MyEnemyData.h"
#include "SteveSingleton.h"
#include "MyEnemyStateComponent.h"
#include "GameFramework/Character.h"
#include "Kismet/KismetMathLibrary.h"
#include "Components/SkeletalMeshComponent.h"

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

	ACharacter* Player; 

	float Damage;
	float MaxHealth;
	float ChaseRange;
	float PatrolRange;
	float MovementSpeed;
	float MeleeAttackSpeed;
	float MeleeAttackRange;
	float RangedAttackSpeed;
	float RangedAttackRange;
	FTransform StartingLocation;

	bool IsDead;
	bool IsIdle;
	bool IsChasing;
	bool IsPatroling;
	bool IsAttackingRanged;

	FTimerHandle DespawnTimerHandle;

public: // PUBLIC VARIABLES
	UAnimationAsset* HitAnim;
	UAnimationAsset* IdleAnim;
	UAnimationAsset* MoveAnim;
	UAnimationAsset* DeathAnim;
	UAnimationAsset* AttackAnim;
	UAnimationAsset* RangedAttackAnim;
	AActor* AmmoType;

	float CurrentHealth;

public: // GETTERS/ACCESSORS
	float GetDamage() const { return Damage; }
	float GetPatrolRange() const { return PatrolRange; }
	float GetMovementSpeed() const { return MovementSpeed; }
	float GetAttackRange() const { return MeleeAttackRange; }
	float GetMeleeAttackSpeed() const { return MeleeAttackSpeed; }
	float GetRangedAttackSpeed() const { return RangedAttackSpeed; }
	FTransform GetStartingLocation() const { return StartingLocation; }

public:	// CONSTRUCTOR HERE
	AMyEnemyBaseClass();

protected: // SETUP FUNCTIONS
	virtual void BeginPlay() override;

public:	// UPDATE FUNCTIONS
	virtual void Tick(float DeltaTime) override;

private: // PRIVATE INTERNAL FUNCTIONS
	void Despawn();
};