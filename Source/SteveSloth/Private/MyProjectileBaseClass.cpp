/****************************************************************************************
 * Copyright: SteveSloth
 * Name: Jeff Moreau, Edited by Elad Saretzky
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
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
}

void AMyProjectileBaseClass::BeginPlay()
{
	Super::BeginPlay();

	Player = USteveSingleton::GetSteve()->GetPlayerCharacter();

	if (IsValid(Player))
	{
		Steve = Cast<AMyPlayer>(Player);
	}

	// Initialize Variables to the Projectile Data Table
	const auto projectileData = ProjectileDataTable.GetRow<FMyProjectileData>("");

	if (projectileData)
	{
		ProjectileType = projectileData->ProjectileType;

		Name = projectileData->Name;
		Damage = projectileData->Damage;
		ProjectileType = projectileData->ProjectileType;
		DamageOverTime = projectileData->DamageOverTime;
		ProjectileRange = projectileData->ProjectileRange;
		ProjectileSpeed = projectileData->ProjectileSpeed;
		ProjectileGravity = projectileData->ProjectileGravity;
		InitialLaunchAngle = projectileData->InitialLaunchAngle;
		AreaOfEffectDamage = projectileData->AreaOfEffectDamage;
		AreaOfEffectRadius = projectileData->AreaOfEffectRadius;
		DamageOverTimeRate = projectileData->DamageOverTimeRate;
		ProjectileMaxSpeed = projectileData->ProjectileMaxSpeed;
		DamageOverTimeDuration = projectileData->DamageOverTimeDuration;
	}

	Mesh->SetStaticMesh(projectileData->Mesh);

	AreaOfEffectHitbox->SetSphereRadius(AreaOfEffectRadius);
	AreaOfEffectHitbox->SetActive(false);

	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->InitialSpeed = ProjectileSpeed;
	ProjectileMovement->MaxSpeed = ProjectileMaxSpeed;
	ProjectileMovement->ProjectileGravityScale = ProjectileGravity;
	ProjectileMovement->Velocity.Z = InitialLaunchAngle;

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
	if (OtherActor == Enemy)
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
			Enemy->SetIsConfused(true);
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
	else if (OtherActor == Steve)
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
	if (OtherActor == Enemy)
	{
		Enemy = Cast<AMyEnemyBaseClass>(OtherActor);

		Enemy->HitEnemy(AreaOfEffectDamage);
		this->Destroy();
	}
	else if (OtherActor == Steve)
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