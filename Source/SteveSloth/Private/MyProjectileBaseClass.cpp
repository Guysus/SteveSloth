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

	Player = USteveSingleton::GetSteve()->GetPlayerCharacter();
	Steve = Cast<AMyPlayer>(Player);

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
		DamageOverTimeRate = projectileData->DamageOverTimeRate;
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

	ProjectileHitbox->OnComponentBeginOverlap.AddDynamic(this, &AMyProjectileBaseClass::OnHitboxOverlapBegin);
	AreaOfEffectHitbox->OnComponentBeginOverlap.AddDynamic(this, &AMyProjectileBaseClass::OnAOEHitboxOverlapBegin);
}

void AMyProjectileBaseClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (FVector::Dist(StartingLocation, GetActorLocation()) > ProjectileRange)
	{
		this->Destroy();
	}
}

void AMyProjectileBaseClass::OnHitboxOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (Enemy == OtherActor)
	{
		Enemy = Cast<AMyEnemyBaseClass>(OtherActor);

		Enemy->HitEnemy(Damage);

		switch (ProjectileType)
		{
		case EProjectileType::Physical:
			this->Destroy();

			break;

		case EProjectileType::Fire:
			Mesh->SetVisibility(false);
			ProjectileHitbox->SetActive(false);
			AreaOfEffectHitbox->SetActive(true);

			break;

		case EProjectileType::Water:
			//add confusion here
			this->Destroy();

			break;

		case EProjectileType::Poison:
			Mesh->SetVisibility(false);
			ProjectileHitbox->SetActive(false);

			GetWorldTimerManager().SetTimer(DamageOverTimeTimerHandle, this, &AMyProjectileBaseClass::DamageOverTimeEnemy,
				DamageOverTimeRate, true, DamageOverTimeRate);

			break;

		case EProjectileType::Ice:
			Enemy->SetIsFrozen(true);
			this->Destroy();

			break;
		}
	}
	else if (Steve == OtherActor)
	{
		Steve->HitPlayer(Damage);

		switch (ProjectileType)
		{
		case EProjectileType::Physical:
			this->Destroy();

			break;

		case EProjectileType::Fire:
			Mesh->SetVisibility(false);
			ProjectileHitbox->SetActive(false);
			AreaOfEffectHitbox->SetActive(true);

			break;

		case EProjectileType::Water:
			//add effect here
			this->Destroy();

			break;

		case EProjectileType::Poison:
			Mesh->SetVisibility(false);
			ProjectileHitbox->SetActive(false);

			GetWorldTimerManager().SetTimer(DamageOverTimeTimerHandle, this, &AMyProjectileBaseClass::DamageOverTimePlayer,
				DamageOverTimeRate, true, DamageOverTimeRate);

			break;

		case EProjectileType::Ice:
			//add effect here
			this->Destroy();

			break;
		}
	}
	else
	{
		if (ProjectileType == EProjectileType::Fire)
		{
			Mesh->SetVisibility(false);
			ProjectileHitbox->SetActive(false);
			AreaOfEffectHitbox->SetActive(true);
		}
		else
		{
			this->Destroy();
		}
	}
}

void AMyProjectileBaseClass::OnAOEHitboxOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (Enemy == OtherActor)
	{
		Enemy = Cast<AMyEnemyBaseClass>(OtherActor);

		Enemy->HitEnemy(AreaOfEffectDamage);
		this->Destroy();
	}
	else if (Steve == OtherActor)
	{
		Steve->HitPlayer(AreaOfEffectDamage);
		this->Destroy();
	}
	else
	{
		this->Destroy();
	}
}

void AMyProjectileBaseClass::DamageOverTimeEnemy()
{
	if (DamageOverTimeDuration > 0)
	{
		DamageOverTimeDuration--;
		Enemy->HitEnemy(DamageOverTime);
	}
	else
	{
		GetWorldTimerManager().ClearTimer(DamageOverTimeTimerHandle);
		this->Destroy();
	}
}

void AMyProjectileBaseClass::DamageOverTimePlayer()
{
	if (DamageOverTimeDuration > 0)
	{
		DamageOverTimeDuration--;
		Steve->HitPlayer(DamageOverTime);
	}
	else
	{
		GetWorldTimerManager().ClearTimer(DamageOverTimeTimerHandle);
		this->Destroy();
	}
}
