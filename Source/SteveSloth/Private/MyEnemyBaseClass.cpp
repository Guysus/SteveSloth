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
		enemyData->MeleeDamage = Damage;
		enemyData->MovementSpeed = MovementSpeed;
		enemyData->MaxHealth = MaxHealth;
		enemyData->PatrolRange = PatrolRange;
		enemyData->ChaseRange = ChaseRange;
		enemyData->MeleeAttackRange = MeleeAttackRange;
		enemyData->RangedAttackRange = RangedAttackRange;

		enemyData->IdleAnim = IdleAnim;
		enemyData->MoveAnim = MoveAnim;
		enemyData->MeleeAttackAnim = AttackAnim;
		enemyData->RangedAttackAnim = RangedAttackAnim;
		enemyData->HitAnim = HitAnim;
		enemyData->DeathAnim = DeathAnim;
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