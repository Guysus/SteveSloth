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
#include "MyProjectileData.h"

// MAKE SURE THIS INCLUDE IS LAST
#include "MyEnemyProjectile.generated.h"

UCLASS()
class STEVESLOTH_API AMyEnemyProjectile : public AActor
{
	GENERATED_BODY()
	
protected: // PROTECTED DETAILS PANEL VARIABLES 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (RowType = "MyProjectileData"), Category = "Data")
	FDataTableRowHandle ProjectileDataTable;

private: //PRIVATE VARIABLES
	TEnumAsByte<EProjectileType> ProjectileType;

	float Damage;
	float ProjectileSpeed;
	float ProjectileRange;
	float ProjectileGravity;
	float InitialLaunchAngle;
	float AreaOfEffectDamage;
	float AreaOfEffectRadius;
	float DamageOverTime;
	float DamageOverTimeDuration;

public: // CONSTRUCTOR HERE
	AMyEnemyProjectile();

protected: // INITIALIZE INHERITABLE FUNCTIONS
	virtual void BeginPlay() override;

public:	// UPDATE ACCESS ANYWHERE FUNCTIONS
	virtual void Tick(float DeltaTime) override;
};