/****************************************************************************************
* Copyright: SteveSloth
 * Name: Jeff Moreau
 * Script: MyGameManager.cpp
 * Date: April 23. 2024
 * Description: This is the Game Manager that will direct the flow of the game
 * TODO: 
 * Known Bugs: 
 ****************************************************************************************/

#include "MyGameManager.h"

// SINGLETON STUFF
UMyGameManager* UMyGameManager::pInstance = nullptr;

UMyGameManager* UMyGameManager::Instance()
{
	if (pInstance == nullptr)
	{
		pInstance = this;
	}
	return pInstance;
}

UMyGameManager* UMyGameManager::GetInstance()
{
	return pInstance;
}

// SINGLETON END

UMyGameManager::UMyGameManager()
{
	InitializeVariables();
}

void UMyGameManager::InitializeVariables()
{
	
}