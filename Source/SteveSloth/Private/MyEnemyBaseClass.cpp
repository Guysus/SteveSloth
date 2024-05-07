/****************************************************************************************
* Copyright: SteveSloth
 * Name: Tammy, Elad Saretzky 
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

	Player = USteveSingleton::GetSteve()->GetPlayerCharacter(); 
}

void AMyEnemyBaseClass::BeginPlay()
{
	Super::BeginPlay();
}

void AMyEnemyBaseClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (UKismetMathLibrary::Vector_IsNearlyZero(AMyEnemyBaseClass::GetVelocity(), IDLE_VELOCITY_TOLERANCE))
	{

	}
}