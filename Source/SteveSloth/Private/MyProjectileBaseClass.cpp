/****************************************************************************************
 * Copyright: SteveSloth
 * Name: Jeff Moreau, Elad Saretzky
 * Script: MyProjectileBaseClass.cpp
 * Date: May 15, 2024
 * Description: Where all Projectiles are made from and all functionality
 * TODO:
 * Known Bugs:
 *****************************************************************************************/

#include "MyProjectileBaseClass.h"

AMyProjectileBaseClass::AMyProjectileBaseClass()
{
	PrimaryActorTick.bCanEverTick = true;

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement Component"));
	ProjectileHitbox = CreateDefaultSubobject<UBoxComponent>(TEXT("Hitbox"));
	AreaOfEffectHitbox = CreateDefaultSubobject<USphereComponent>(TEXT("AOEHitbox"));

	// Initialize Variables to the Projectile Data Table
	const auto projectileData = ProjectileDataTable.GetRow<FMyProjectileData>("");

	if (projectileData)
	{
		ProjectileType = projectileData->ProjectileType;

		Damage = projectileData->Damage;
		ProjectileSpeed = projectileData->ProjectileSpeed;
		ProjectileMaxSpeed = projectileData->ProjectileMaxSpeed;
		ProjectileRange = projectileData->ProjectileRange;
		ProjectileGravity = projectileData->ProjectileGravity;
		InitialLaunchAngle = projectileData->InitialLaunchAngle;
		AreaOfEffectDamage = projectileData->AreaOfEffectDamage;
		AreaOfEffectRadius = projectileData->AreaOfEffectRadius;
		DamageOverTime = projectileData->DamageOverTime;
		DamageOverTimeDuration = projectileData->DamageOverTimeDuration;
	}

	AreaOfEffectHitbox->SetSphereRadius(AreaOfEffectRadius);
	AreaOfEffectHitbox->SetActive(false);
	
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->InitialSpeed = ProjectileSpeed;
	ProjectileMovement->MaxSpeed = ProjectileMaxSpeed;
	ProjectileMovement->ProjectileGravityScale = ProjectileGravity;
	ProjectileMovement->Velocity.Z = InitialLaunchAngle;
}

void AMyProjectileBaseClass::BeginPlay()
{
	Super::BeginPlay();

	StartingLocation = GetActorLocation();
}

void AMyProjectileBaseClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (FVector::Dist(StartingLocation, GetActorLocation()) > ProjectileRange)
	{
		this->Destroy();
	}
}