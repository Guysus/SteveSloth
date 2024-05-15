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
#include "MyEnemyPatrolState.h"
//#include "MyEnemyDeadState.h"
//#include "MyGenericEnemyIdleState.h"
//#include <MyGenericEnemyAttackState.h>
//#include <MyGenericEnemyPatrolState.h>
//#include <MyGenericEnemyChaseState.h>
//#include <MyGenericEnemyFleeState.h>
//#include <MyGenericEnemyRangeAttackState.h>
//#include <MyGenericEnemyDieState.h>

AMyEnemyBaseClass::AMyEnemyBaseClass()
{
	PrimaryActorTick.bCanEverTick = true;
	StateMachine = CreateDefaultSubobject<UMyEnemyStateComponent>(TEXT("State Machine"));
	MySpline = CreateDefaultSubobject<USplineComponent>(TEXT("My Patrol Spline"));
	MySpline->SetupAttachment(RootComponent);

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

	}

	CurrentHealth = MaxHealth;

	IsDead = false;
}

void AMyEnemyBaseClass::BeginPlay()
{
	Super::BeginPlay();
	Player = USteveSingleton::GetSteve()->GetPlayerCharacter(); 

	for (int i = 0; i < StateMachine->GetStateList().Num(); i++)
	{
		StateMachine->GetStateList()[i]->GetDefaultObject<UMyEnemyBaseState>()->SetEnemyBaseClass(this);
	}

	/*StateMachine->GetState(Idle)->GetDefaultObject<UMyGenericEnemyIdleState>()->SetEnemyBaseClass(this);
	StateMachine->GetState(Patrol)->GetDefaultObject<UMyGenericEnemyIdleState>()->SetEnemyBaseClass(this);
	StateMachine->GetState(Chase)->GetDefaultObject<UMyGenericEnemyIdleState>()->SetEnemyBaseClass(this);
	StateMachine->GetState(Flee)->GetDefaultObject<UMyGenericEnemyIdleState>()->SetEnemyBaseClass(this);
	StateMachine->GetState(Attack)->GetDefaultObject<UMyGenericEnemyIdleState>()->SetEnemyBaseClass(this);
	StateMachine->GetState(RangedAttack)->GetDefaultObject<UMyGenericEnemyIdleState>()->SetEnemyBaseClass(this);
	StateMachine->GetState(Die)->GetDefaultObject<UMyGenericEnemyIdleState>()->SetEnemyBaseClass(this);*/
	//StateMachine->GetState(Idle)->GetDefaultObject<UMyGenericEnemyIdleState>()->SetEnemyBaseClass(this);
	/*StateMachine->ChangeState(StateMachine->GetState(Idle));*/
	StateMachine->ChangeState(StateMachine->GetState(Patrol));
	StateMachine->GetState(Patrol)->GetDefaultObject<UMyEnemyPatrolState>()->SetEnemySpline(MySpline);
}

void AMyEnemyBaseClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (CurrentHealth <= 0 && !IsDead)
	{
		/*StateMachine->ChangeState(StateMachine->GetState(Idle));*/
		//GetWorldTimerManager().SetTimer(DespawnTimerHandle, this, &AMyEnemyBaseClass::Despawn, DESPAWN_TIMER_AMOUNT, false);
		IsDead = true;
	}
}

void AMyEnemyBaseClass::Despawn()
{
	this->Destroy();
}
