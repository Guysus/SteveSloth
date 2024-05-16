/****************************************************************************************
* Copyright: SteveSloth
* Name: Tammy, Elad Saretzky, Jeff Moreau
* Script: MyEnemyBaseClass.cpp
* Date: April 29. 2024
* Description: Base Class for all enemies to inherit from
* TODO: Add more Variables (such as animations)
* Known Bugs:
****************************************************************************************/

#include "MyEnemyBaseClass.h"

AMyEnemyBaseClass::AMyEnemyBaseClass()
{
	PrimaryActorTick.bCanEverTick = true;
	StateMachine = CreateDefaultSubobject<UMyEnemyStateComponent>(TEXT("State Machine"));

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
		AmmoType = enemyData->AmmoType;
	}

	CurrentHealth = MaxHealth;
	IsDead = false;
}

void AMyEnemyBaseClass::BeginPlay()
{
	Super::BeginPlay();

	Player = USteveSingleton::GetSteve()->GetPlayerCharacter();
	StartingLocation = GetActorTransform();

	for (int i = 0; i < StateMachine->GetStateList().Num(); i++)
	{
		StateMachine->GetStateList()[i]->GetDefaultObject<UMyEnemyBaseState>()->SetEnemyBaseClass(this);
	}

	StateMachine->ChangeState(StateMachine->GetState(Idle));
}

void AMyEnemyBaseClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (CurrentHealth <= 0 && !IsDead)
	{
		StateMachine->ChangeState(StateMachine->GetState(Die));
		GetWorldTimerManager().SetTimer(DespawnTimerHandle, this, &AMyEnemyBaseClass::Despawn, DESPAWN_TIMER_AMOUNT, false);
		IsDead = true;
	}
}

void AMyEnemyBaseClass::Despawn()
{
	this->Destroy();
}