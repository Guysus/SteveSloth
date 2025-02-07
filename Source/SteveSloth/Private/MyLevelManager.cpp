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

	Instance();

	bIsValveOneOpen = false;
	bIsInValveOneArea = false;
	bIsValveOneOperated = false;
	bIsValveTwoOpen = false;
	bIsInValveTwoArea = false;
	bIsValveTwoOperated = false;
	bIsValveThreeOpen = false;
	bIsInValveThreeArea = false;
	bIsValveThreeOperated = false;
}

void AMyLevelManager::BeginPlay()
{
	Super::BeginPlay();

	ACharacter* Steve = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	if (Steve != nullptr)
	{
		USteveSingleton::GetSteve()->SetSteve(Steve);
	}
}

void AMyLevelManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMyLevelManager::ChangeLevel(ELevels level)
{
	for (int i = 0; i < GameLevels.Num(); i++)
	{
		if (level == i)
		UGameplayStatics::OpenLevel(GetWorld(), FName(GameLevels[i]));
		break;
	}
}