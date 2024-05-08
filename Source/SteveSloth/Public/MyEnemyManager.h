/****************************************************************************************
* Copyright: SteveSloth
 * Name: Jeff Moreau
 * Script: MyEnemyManager.h
 * Date: May 8, 2024
 * Description: To take care of all Enemy entities in the game. Easy place to access
 * TODO: 
 * Known Bugs:
 ****************************************************************************************/

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyEnemyManager.generated.h"

UCLASS()
class STEVESLOTH_API AMyEnemyManager : public AActor
{
	GENERATED_BODY()
	
public:	
	AMyEnemyManager();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};