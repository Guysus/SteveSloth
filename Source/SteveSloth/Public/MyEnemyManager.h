/****************************************************************************************
* Copyright:
* Name:
* Script: MyEnemyManager.h
* Date: 
* Description: 
* TODO: 
* Known Bugs: 
*****************************************************************************************/

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
