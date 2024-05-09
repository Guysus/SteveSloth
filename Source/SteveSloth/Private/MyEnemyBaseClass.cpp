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
#include "MyEnemyDeadState.h"
#include "MyGenericEnemyIdleState.h"

AMyEnemyBaseClass::AMyEnemyBaseClass()
{
	PrimaryActorTick.bCanEverTick = true;
	StateMachine = CreateDefaultSubobject<UMyEnemyStateComponent>(TEXT("State Machine"));

	CurrentHealth = MaxHealth;
}

void AMyEnemyBaseClass::BeginPlay()
{
	Super::BeginPlay();

	//StateMachine->GetIdleState()->GetDefaultObject<UMyGenericEnemyIdleState>()->SetEnemyBaseClass(this);
	//StateMachine->ChangeState(StateMachine->GetIdleState());
	StateMachine->GetDeadState()->GetDefaultObject<UMyEnemyDeadState>()->SetEnemyBaseClassDeadState(this);
	StateMachine->ChangeState(StateMachine->GetDeadState());
}

void AMyEnemyBaseClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}