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
#include "MyEnemyAIChaseState.h"
#include "MyGenericEnemyIdleState.h"

AMyEnemyBaseClass::AMyEnemyBaseClass()
{
	PrimaryActorTick.bCanEverTick = true;
	StateMachine = CreateDefaultSubobject<UMyEnemyStateComponent>(TEXT("State Machine"));

	Player = USteveSingleton::GetSteve()->GetPlayerCharacter(); 

	CurrentHealth = MaxHealth;

	IsDead = false;
}

void AMyEnemyBaseClass::BeginPlay()
{
	Super::BeginPlay();

	StateMachine->GetIdleState()->GetDefaultObject<UMyGenericEnemyIdleState>()->SetEnemyBaseClass(this);
    StateMachine->GetChaseState()->GetDefaultObject<UMyEnemyAIChaseState>()->SetEnemyBaseClass(this);
	StateMachine->ChangeState(StateMachine->GetChaseState());
    
}

void AMyEnemyBaseClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (CurrentHealth <= 0 && !IsDead)
	{
		// ---- change to dead state here ----
		GetWorldTimerManager().SetTimer(DespawnTimerHandle, this, &AMyEnemyBaseClass::Despawn, DESPAWN_TIMER_AMOUNT, false);
		IsDead = true;
	}
}

void AMyEnemyBaseClass::Despawn()
{
	//this->Destroy();
}
