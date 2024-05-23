/****************************************************************************************
 * Copyright: SteveSloth
 * Name: Tammy, Elad Saretzky, Jeff Moreau
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
	StateMachine = CreateDefaultSubobject<UMyEnemyStateComponent>(TEXT("State Machine"));

	//// Initialize Variables to the Enemy Data Table
	//const auto enemyData = EnemyDataTable.GetRow<FMyEnemyData>("");
	
	/*if (enemyData)
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

	 Initialize Variables before use
	CurrentHealth = MaxHealth;*/

	IsFrozen = false;
	IsCurrentlyFrozen = false;
	IsConfused = false;
	IsDead = false;
	IsIdle = false;
	IsChasing = false;
	IsPatroling = false;
	IsAttackingMelee = false;
	IsAttackingRanged = false;
}

void AMyEnemyBaseClass::BeginPlay()
{
	Super::BeginPlay();

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

	// Initialize Variables before use
	CurrentHealth = MaxHealth;

	/*UE_LOG(LogTemp, Warning, TEXT("Current Health: %s"), );*/

	// Get a referance to the Main Player
	Player = USteveSingleton::GetSteve()->GetPlayerCharacter();

	// Get the starting location of the Enemy
	StartingLocation = GetActorTransform();

	// Set this Enemy to all the available States for the Enemy so they have access to it
	for (int i = 0; i < StateMachine->GetStateList().Num(); i++)
	{
		StateMachine->GetStateList()[i]->GetDefaultObject<UMyEnemyBaseState>()->SetEnemyBaseClass(this);
	}

	// Set initial State as Idle
	StateMachine->ChangeState(StateMachine->GetState(Confused));
}

void AMyEnemyBaseClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//// Check if Enemy is Dead
	//if (CurrentHealth <= 0 && !IsDead)
	//{
	//	StateMachine->ChangeState(StateMachine->GetState(Die));
	//	GetWorldTimerManager().SetTimer(DespawnTimerHandle, this, &AMyEnemyBaseClass::Despawn, DESPAWN_TIMER_AMOUNT, false);
	//	IsDead = true;
	//}
	//Check if frozen
	/*else */if (IsFrozen && !IsCurrentlyFrozen)
	{
		//set state to idle to frozen
		StateMachine->ChangeState(StateMachine->GetState(Frozen));

		IsFrozen = true;
		IsCurrentlyFrozen = true;
		IsIdle = true;
		IsChasing = true;
		IsPatroling = true;
		IsAttackingMelee = true;
		IsAttackingRanged = true;

		GetWorldTimerManager().SetTimer(ThawTimerHandle, this, &AMyEnemyBaseClass::Thaw, THAW_TIMER_AMOUNT, false);
	}
	//Check if confused
	else if (IsConfused && !IsCurrentlyConfused) 
	{
		StateMachine->ChangeState(StateMachine->GetState(Confused));

		IsConfused = true;
		IsCurrentlyConfused = true;
		IsIdle = true;
		IsChasing = true;
		IsPatroling = true;
		IsAttackingMelee = true;
		IsAttackingRanged = true;

		GetWorldTimerManager().SetTimer(ConfusionTimerHandle, this,
			&AMyEnemyBaseClass::SnapOutOfConfusion, CONFUSION_TIMER_AMOUNT, false);
	}
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
	IsFrozen = false;
	IsCurrentlyFrozen = false;
	IsIdle = false;
	IsChasing = false;
	IsPatroling = false;
	IsAttackingMelee = false;
	IsAttackingRanged = false;
}

void AMyEnemyBaseClass::SnapOutOfConfusion() 
{
	IsConfused = false;
	IsCurrentlyConfused = false;
	IsIdle = false;
	IsChasing = false;
	IsPatroling = false;
	IsAttackingMelee = false;
	IsAttackingRanged = false;
}
