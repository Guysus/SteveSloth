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

// INCLUDES HERE
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

// MAKE SURE THIS INCLUDE IS LAST
#include "MyEnemyProjectile.generated.h"

UCLASS()
class STEVESLOTH_API AMyEnemyProjectile : public AActor
{
	GENERATED_BODY()
	
public: // CONSTRUCTOR HERE
	AMyEnemyProjectile();

protected: // INITIALIZE INHERITABLE FUNCTIONS
	virtual void BeginPlay() override;

public:	// UPDATE ACCESS ANYWHERE FUNCTIONS
	virtual void Tick(float DeltaTime) override;
};