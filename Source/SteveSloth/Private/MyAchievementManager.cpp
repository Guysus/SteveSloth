/****************************************************************************************
* Copyright: SteveSloth
 * Name: Jeff Moreau
 * Script: MyAchievementManager.cpp
 * Date: April 23. 2024
 * Description: Keep Track of In game Achievements per 
 * TODO: 
 * Known Bugs: 
 ****************************************************************************************/

#include "MyAchievementManager.h"

AMyAchievementManager::AMyAchievementManager()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AMyAchievementManager::BeginPlay()
{
	Super::BeginPlay();
}

void AMyAchievementManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}