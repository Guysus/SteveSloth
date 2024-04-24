/****************************************************************************************
* Copyright: SteveSloth
 * Name: Jeff Moreau
 * Script: MyLevelManager.cpp
 * Date: April 24. 2024
 * Description: This is where we can manage all levels and get information for levels
 * TODO: 
 * Known Bugs: 
 ****************************************************************************************/

#include "MyLevelManager.h"

AMyLevelManager::AMyLevelManager()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AMyLevelManager::BeginPlay()
{
	Super::BeginPlay();
}

void AMyLevelManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}