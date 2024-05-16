/****************************************************************************************
 * Copyright: SteveSloth
 * Name: Jeff Moreau
 * Script: MyEnemyProjectile.cpp
 * Date: May 15, 2024
 * Description: Where all Enemy Projectiles are made from and all functionality
 * TODO: 
 * Known Bugs: 
 *****************************************************************************************/

#include "MyEnemyProjectile.h"

AMyEnemyProjectile::AMyEnemyProjectile()
{
	PrimaryActorTick.bCanEverTick = true;

	// Initialize Variables to the Projectile Data Table
	const auto projectileData = ProjectileDataTable.GetRow<FMyProjectileData>("");

	if (projectileData)
	{
		ProjectileType = projectileData->ProjectileType;

		Damage = projectileData->Damage;
		ProjectileSpeed = projectileData->ProjectileSpeed;
		ProjectileRange = projectileData->ProjectileRange;
		ProjectileGravity = projectileData->ProjectileGravity;
		InitialLaunchAngle = projectileData->InitialLaunchAngle;
		AreaOfEffectDamage = projectileData->AreaOfEffectDamage;
		AreaOfEffectRadius = projectileData->AreaOfEffectRadius;
		DamageOverTime = projectileData->DamageOverTime;
		DamageOverTimeDuration = projectileData->DamageOverTimeDuration;
	}
}

void AMyEnemyProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMyEnemyProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}