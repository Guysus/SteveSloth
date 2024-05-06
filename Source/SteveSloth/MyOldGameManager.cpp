/****************************************************************************************
* Copyright: SteveSloth
 * Name: Jeff Moreau
 * Script: MyGameManager.cpp
 * Date: April 23. 2024
 * Description: This is the Game Manager that will direct the flow of the game
 * TODO: 
 * Known Bugs: 
 ****************************************************************************************/

#include "MyOldGameManager.h"

// SINGLETON STUFF
UMyOldGameManager* UMyOldGameManager::pInstance = nullptr;

UMyOldGameManager* UMyOldGameManager::Instance()
{
	if (pInstance == nullptr)
	{
		pInstance = this;
	}
	return pInstance;
}

UMyOldGameManager* UMyOldGameManager::GetInstance()
{
	return pInstance;
}

// SINGLETON END

UMyOldGameManager::UMyOldGameManager()
{
	InitializeVariables();
}

void UMyOldGameManager::InitializeVariables()
{
	
}