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
}

void AMyEnemyProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMyEnemyProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}