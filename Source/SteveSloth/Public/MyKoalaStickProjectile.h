/****************************************************************************************
 * Copyright: SteveSloth
 * Name: Brandon T
 * Script: MyLoalaStickProjectile.h
 * Date: May 17. 2024
 * Description: Header file for the koala's stick projectile
 * TODO:
 * Known Bugs:
 ****************************************************************************************/

#pragma once

#include "CoreMinimal.h"
#include "MyProjectileBaseClass.h"

// MAKE SURE THIS INCLUDE IS LAST
#include "MyKoalaStickProjectile.generated.h"

UCLASS()
class STEVESLOTH_API AMyKoalaStickProjectile : public AMyProjectileBaseClass
{
	GENERATED_BODY()

public: // CONSTRUCTOR HERE
	AMyKoalaStickProjectile();

protected: // INITIALIZE INHERITABLE FUNCTIONS
	virtual void BeginPlay() override;

public:	// UPDATE ACCESS ANYWHERE FUNCTIONS
	virtual void Tick(float DeltaTime) override;
};
