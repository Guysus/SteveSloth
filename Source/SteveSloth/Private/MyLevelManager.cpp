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

// SINGLETON STUFF
AMyLevelManager* AMyLevelManager::pInstance = nullptr;

AMyLevelManager* AMyLevelManager::Instance()
{
	if (pInstance == nullptr)
	{
		pInstance = this;
	}
	return pInstance;
}

AMyLevelManager* AMyLevelManager::GetInstance()
{
	return pInstance;
}

// SINGLETON END

AMyLevelManager::AMyLevelManager()
{
	PrimaryActorTick.bCanEverTick = true;
	InitializeVariables();
}

void AMyLevelManager::InitializeVariables()
{
	//TotalLevels = GameLevels.Num();

	/*FString levelName = GetWorld()->GetMapName();
	levelName.RemoveFromStart(GetWorld()->StreamingLevelsPrefix);
	CurrentLevelName = levelName;*/
}

void AMyLevelManager::BeginPlay()
{
	Super::BeginPlay();
}

void AMyLevelManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMyLevelManager::ChangeLevel(ELevels level)
{
	/*if (level == Hub)
	{
		CurrentLevelName = "Hub";
	}
	else if (level == LevelOne)
	{
		CurrentLevelName = "LevelOne";
	}
	UGameplayStatics::OpenLevel(GetWorld(), FName(CurrentLevelName));*/
}