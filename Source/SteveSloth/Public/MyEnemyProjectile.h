/****************************************************************************************
* Copyright: SteveSloth
* Name: Jeff Moreau
* Script: MyEnemyProjectile.h
* Date: May 15, 2024
* Description: Where all Enemy Projectiles are made from and all functionality
* TODO:
* Known Bugs:
*****************************************************************************************/

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyEnemyProjectile.generated.h"

UCLASS()
class STEVESLOTH_API AMyEnemyProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	AMyEnemyProjectile();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
