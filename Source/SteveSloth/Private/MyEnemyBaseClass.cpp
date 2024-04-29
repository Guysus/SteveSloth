/****************************************************************************************
* Copyright: SteveSloth
 * Name: Tammy Jeff Moreau
 * Script: MyEnemyBaseClass.cpp
 * Date: April 29. 2024
 * Description: Base Class for all enemies to inherit from
 * TODO:
 * Known Bugs:
 ****************************************************************************************/

#include "MyEnemyBaseClass.h"

AMyEnemyBaseClass::AMyEnemyBaseClass()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AMyEnemyBaseClass::BeginPlay()
{
	Super::BeginPlay();
}

void AMyEnemyBaseClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMyEnemyBaseClass::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}