/****************************************************************************************
 * Copyright: SteveSloth
 * Name: Tammy, Edited by Elad Saretzky, Jeff Moreau
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
	const float THAW_TIMER_AMOUNT = 1.5f;
	const float CONFUSION_TIMER_AMOUNT = 1.5f;
	const float DESPAWN_TIMER_AMOUNT = 2.0f;

protected: // PROTECTED DETAILS PANEL VARIABLES 
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UMyEnemyStateComponent* StateMachine;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (RowType = "MyEnemyData"), Category = "Data")
	FDataTableRowHandle EnemyDataTable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile")
	TSubclassOf<AActor> Projectile;

protected: // PROTECTED INHERITABLE VARIABLES
	ACharacter* Player;

	float Damage;
	float MaxHealth;
	float ChaseRange;
	float PatrolRange;
	float MovementSpeed;
	float CurrentHealth;
	float MeleeAttackSpeed;
	float MeleeAttackRange;
	float RangedAttackSpeed;
	float RangedAttackRange;
	float MaxConfusionRange;

	bool bIsFrozen;
	bool bIsCurrentlyFrozen;
	bool bIsConfused;
	bool bIsCurrentlyConfused;
	bool bIsDead;
	bool bIsIdle;
	bool bIsChasing;
	bool bIsPatroling;
	bool bIsAttackingMelee;
	bool bIsAttackingRanged;

	FTransform StartingLocation;

	FTimerHandle DespawnTimerHandle;
	FTimerHandle ThawTimerHandle;
	FTimerHandle ConfusionTimerHandle;

	UWorld* MyWorld;

public: // PUBLIC ACCESS ANYWHERE VARIABLES
	AActor* AmmoType;

	UAnimationAsset* HitAnim;
	UAnimationAsset* IdleAnim;
	UAnimationAsset* MoveAnim;
	UAnimationAsset* DeathAnim;
	UAnimationAsset* AttackAnim;
	UAnimationAsset* RangedAttackAnim;
	UAnimationAsset* FrozenAnim;
	UAnimationAsset* ConfusionAnim;

public: // GETTERS/ACCESSORS
	float GetDamage() const { return Damage; }
	UWorld* GetMyWorld() { return MyWorld; }
	float GetChaseRange() const { return ChaseRange; }
	float GetPatrolRange() const { return PatrolRange; }
	float GetMovementSpeed() const { return MovementSpeed; }
	float GetAttackRange() const { return MeleeAttackRange; }
	float GetMeleeAttackSpeed() const { return MeleeAttackSpeed; }
	float GetRangedAttackSpeed() const { return RangedAttackSpeed; }
	float GetMaxConfusionRange() const { return MaxConfusionRange; }
	TSubclassOf<AActor> GetProjectile() const { return Projectile; }
	FTransform GetStartingLocation() const { return StartingLocation; }
	float GetMaxConfusionRangeInverse() const { return -MaxConfusionRange; }

public: // SETTER/MUTATOR
	void SetIsFrozen(bool isFrozen) { bIsFrozen = isFrozen; }
	void SetIsConfused(bool isConfused) { bIsConfused = isConfused; }

public:	// CONSTRUCTOR HERE
	AMyEnemyBaseClass();

protected: // INITIALIZE INHERITABLE FUNCTIONS
	virtual void BeginPlay() override;

public:	// UPDATE ACCESS ANYWHERE FUNCTIONS
	virtual void Tick(float DeltaTime) override;

public: // PUBLIC FUNCTIONS
	void HitEnemy(float damageAmount);

protected: // PRIVATE INTERNAL FUNCTIONS
	void Despawn();
	void Thaw();
	void SnapOutOfConfusion();
};