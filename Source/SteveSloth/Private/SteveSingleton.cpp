/****************************************************************************************
* Copyright: SteveSloth
 * Name: Jeff Moreau
 * Script: SteveSingleton.cpp
 * Date: May 6. 2024
 * Description: The way to access Steve in every class. Singleton Global
 * TODO: 
 * Known Bugs: 
 ****************************************************************************************/


#include "SteveSingleton.h"

USteveSingleton* USteveSingleton::SteveInstance = nullptr;

USteveSingleton* USteveSingleton::GetSteve()
{
	if (!SteveInstance)
	{
			SteveInstance = NewObject<USteveSingleton>();
	}
	return SteveInstance;
}

void USteveSingleton::SetSteve(ACharacter* NewSteve)
{
  Steve = NewSteve;
}