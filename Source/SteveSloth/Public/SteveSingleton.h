/****************************************************************************************
* Copyright: SteveSloth
 * Name: Jeff Moreau
 * Script: SteveSingleton.h
 * Date: May 6. 2024
 * Description: The way to access Steve in every class. Singleton Global
 * TODO: 
 * Known Bugs: 
 ****************************************************************************************/

#pragma once

// INCLUDES HERE
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Character.h"

// MAKE SURE THIS INCLUDE IS LAST
#include "SteveSingleton.generated.h"

UCLASS()
class STEVESLOTH_API USteveSingleton : public UObject
{
	GENERATED_BODY()

public: // SINGLETON STUFF
	static USteveSingleton* SteveInstance;
	static USteveSingleton* GetSteve();

	ACharacter* GetPlayerCharacter() { return Steve; }

private:
	ACharacter* Steve = nullptr;
	
public:
	void SetSteve(ACharacter* NewSteve);
};