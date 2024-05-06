/****************************************************************************************
* Copyright: SteveSloth
 * Name: Jeff Moreau
 * Script: MyGameManager.cpp
 * Date: May 3, 2024
 * Description: This is the Game Manager that will direct the flow of the game
 * TODO: 
 * Known Bugs: 
 ****************************************************************************************/

#include "MyGameManager.h"

AMyGameManager* AMyGameManager::pInstance = nullptr;

AMyGameManager* AMyGameManager::Instance()
{
	if (pInstance == nullptr)
	{
		pInstance = this;
	}

	return pInstance;
}

AMyGameManager* AMyGameManager::GetInstance()
{
	return pInstance;
}

AMyGameManager::AMyGameManager()
{

}