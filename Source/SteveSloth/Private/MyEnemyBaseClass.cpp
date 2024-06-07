/****************************************************************************************
 * Copyright: SteveSloth
 * Name: Tammy, Edited by Elad Saretzky, Jeff Moreau
 * Script: MyEnemyBaseClass.cpp
 * Date: April 29. 2024
 * Description: Base Class for all enemies to Inherit from
 * TODO: Add more Variables (such as animations)
 * Known Bugs:
 ****************************************************************************************/

#include "MyEnemyBaseClass.h"

AMyEnemyBaseClass::AMyEnemyBaseClass()
{
	PrimaryActorTick.bCanEverTick = true;

	// Create the StateMachine Component on the Enemy Base Class
	//StateMachine = CreateDefaultSubobject<UMyEnemyStateComponent>(TEXT("State Machine"));

	// Initialize Variables before use
	bIsDead = false;
	bIsConfused = false;
	bIsIdle = false;
	bIsFrozen = false;
	bIsChasing = false;
	bIsPatroling = false;
	bIsAttackingMelee = false;
	bIsCurrentlyFrozen = false;
	bIsCurrentlyConfused = false;
	bIsAttackingRanged = false;
}

void AMyEnemyBaseClass::BeginPlay()
{
	Super::BeginPlay();

	MyWorld = GetWorld();

	if (!EnemyDataTable.IsNull())
	{
		// Initialize Variables to the Enemy Data Table
		const auto enemyData = EnemyDataTable.GetRow<FMyEnemyData>("");

		if (enemyData)
		{
			Damage = enemyData->MeleeDamage;
			MovementSpeed = enemyData->MovementSpeed;
			MaxHealth = enemyData->MaxHealth;
			PatrolRange = enemyData->PatrolRange;
			ChaseRange = enemyData->ChaseRange;
			MeleeAttackRange = enemyData->MeleeAttackRange;
			RangedAttackRange = enemyData->RangedAttackRange;
			MeleeAttackSpeed = enemyData->MeleeAttackSpeed;
			RangedAttackSpeed = enemyData->RangedAttackSpeed;
			MaxConfusionRange = enemyData->MaxConfusionRange;
			IdleAnim = enemyData->IdleAnim;
			MoveAnim = enemyData->MoveAnim;
			AttackAnim = enemyData->MeleeAttackAnim;
			RangedAttackAnim = enemyData->RangedAttackAnim;
			HitAnim = enemyData->HitAnim;
			DeathAnim = enemyData->DeathAnim;
			FrozenAnim = enemyData->FrozenAnim;
			ConfusionAnim = enemyData->ConfusionAnim;
			AmmoType = enemyData->AmmoType;
		}
	}

	// Initialize Variables before use
	CurrentHealth = MaxHealth;

	// Get a referance to the Main Player
	Player = USteveSingleton::GetSteve()->GetPlayerCharacter();

	// Get the starting location of the Enemy
	StartingLocation = GetActorTransform();
}

void AMyEnemyBaseClass::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Player = nullptr;
	MyWorld = nullptr;
	HitAnim = nullptr;
	AmmoType = nullptr;
	IdleAnim = nullptr;
	MoveAnim = nullptr;
	DeathAnim = nullptr;
	AttackAnim = nullptr;
	FrozenAnim = nullptr;
	//StateMachine = nullptr;
	ConfusionAnim = nullptr;
	RangedAttackAnim = nullptr;
}

void AMyEnemyBaseClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Check if Enemy is Dead
	//if (CurrentHealth <= 0 && !bIsDead)
	//{
	//	StateMachine->ChangeState(StateMachine->GetState(Die));
	//	GetWorldTimerManager().SetTimer(DespawnTimerHandle, this, &AMyEnemyBaseClass::Despawn, DESPAWN_TIMER_AMOUNT, false);
	//	bIsDead = true;
	//}
	////Check if frozen
	//else if (bIsFrozen && !bIsCurrentlyFrozen)
	//{
	//	//set state to idle to frozen
	//	StateMachine->ChangeState(StateMachine->GetState(Frozen));

	//	bIsIdle = true;
	//	bIsFrozen = true;
	//	bIsChasing = true;
	//	bIsPatroling = true;
	//	bIsAttackingMelee = true;
	//	bIsCurrentlyFrozen = true;
	//	bIsAttackingRanged = true;

	//	GetWorldTimerManager().SetTimer(ThawTimerHandle, this, &AMyEnemyBaseClass::Thaw, THAW_TIMER_AMOUNT, false);
	//}
	////Check if confused
	//else if (bIsConfused && !bIsCurrentlyConfused) 
	//{
	//	StateMachine->ChangeState(StateMachine->GetState(Confused));

	//	bIsConfused = true;
	//	bIsCurrentlyConfused = true;
	//	bIsIdle = true;
	//	bIsChasing = true;
	//	bIsPatroling = true;
	//	bIsAttackingMelee = true;
	//	bIsAttackingRanged = true;

	//	GetWorldTimerManager().SetTimer(ConfusionTimerHandle, this,
	//		&AMyEnemyBaseClass::SnapOutOfConfusion, CONFUSION_TIMER_AMOUNT, false);
	//}
}

void AMyEnemyBaseClass::HitEnemy(float damageAmount)
{
	CurrentHealth -= damageAmount;
}

void AMyEnemyBaseClass::Despawn()
{
	/*this->Destroy();*/
}

void AMyEnemyBaseClass::Thaw()
{
	bIsFrozen = false;
	bIsCurrentlyFrozen = false;
	bIsIdle = false;
	bIsChasing = false;
	bIsPatroling = false;
	bIsAttackingMelee = false;
	bIsAttackingRanged = false;
}

void AMyEnemyBaseClass::SnapOutOfConfusion() 
{
	bIsConfused = false;
	bIsCurrentlyConfused = false;
	bIsIdle = false;
	bIsChasing = false;
	bIsPatroling = false;
	bIsAttackingMelee = false;
	bIsAttackingRanged = false;
}