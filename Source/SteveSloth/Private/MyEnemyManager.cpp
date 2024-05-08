/****************************************************************************************
* Copyright: SteveSloth
 * Name: Jeff Moreau
 * Script: MyEnemyManager.cpp
 * Date: May 8, 2024
 * Description: To take care of all Enemy entities in the game. Easy place to access
 * TODO: 
 * Known Bugs:
 ****************************************************************************************/

#include "MyEnemyManager.h"

AMyEnemyManager::AMyEnemyManager()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AMyEnemyManager::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMyEnemyManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}