/****************************************************************************************
 * Copyright: SteveSloth
 * Name: Guy Lapensee, Edited by Jeff Moreau
 * Script: ItemBaseClass.cpp
 * Date: April 23, 2024
 * Description: Base Class for Items
 * TODO: 
 * Known Bugs: 
 ****************************************************************************************/

#include "ItemBaseClass.h"

AItemBaseClass::AItemBaseClass()
{
	PrimaryActorTick.bCanEverTick = true;

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement Component"));
	ProjectileMovement->bAutoActivate = false;

	ProjectileMovement->bShouldBounce = true;
	ProjectileMovement->Friction = ProjectileMovement->Friction * FRICTION_MODIFIER;
	ProjectileMovement->InitialSpeed = VELOCITY;
	ProjectileMovement->MaxSpeed = VELOCITY;
	ProjectileMovement->Velocity.Z = 1;
	ProjectileMovement->Velocity.X = 1;
	ProjectileMovement->ProjectileGravityScale = 0.2;

	ProjectileMovement->Deactivate();

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(Mesh);
	Mesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	ItemHitBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Hit Box"));
	ItemHitBox->SetupAttachment(Mesh);
}

void AItemBaseClass::BeginPlay()
{
	Super::BeginPlay();

	Player = USteveSingleton::GetSteve()->GetPlayerCharacter();

	if (Player)
	{
		Steve = Cast<AMyPlayer>(Player);
	}

	if (!ItemDataTable.IsNull())
	{
		// Initialize Variables to the Item Data Table
		const auto itemData = ItemDataTable.GetRow<FUMyItemData>("");

		if (itemData)
		{
			Name = itemData->Name;
			Health = itemData->Health;
			ItemType = itemData->ItemType;
			DropChance = itemData->DropChance;
			StackAmount = itemData->StackAmount;
			bIsCurrency = itemData->bIsCurrency;
			bIsAmmo = itemData->bIsAmmo;
			AddHealthAmount = itemData->AddHealthAmount;
			AddHealthPercentage = itemData->AddHealthPercentage;
		}

		if (bIsAmmo || bIsCurrency)
		{
			ProjectileMovement->Activate();
		}

		Mesh->SetStaticMesh(itemData->Mesh);
	}

	ItemHitBox->OnComponentBeginOverlap.AddDynamic(this, &AItemBaseClass::OnHitboxOverlapBegin);
}

void AItemBaseClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AItemBaseClass::OnHitboxOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
										  UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
										  bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor == Player)
	{
		switch (ItemType)
		{
			case EItemType::Leaf:
				Steve->SetMaxHealth(AddHealthAmount);
			break;

			case EItemType::Grub:
				Steve->AddGrubs(1);
			break;

			case EItemType::Eucalyptus:
				Steve->AddEucalyptus(1);
			break;

			case EItemType::GreenBud:
				Steve->SetCurrentHealth(Steve->GetMaxHealth() * AddHealthPercentage);
			break;

			case EItemType::BlueBud:
				Steve->SetCurrentHealth(Steve->GetMaxHealth() * AddHealthPercentage);
			break;

			case EItemType::RedBud:
				Steve->SetCurrentHealth(Steve->GetMaxHealth() * AddHealthPercentage);
			break;

			case EItemType::GrapplingHook:
				Steve->AddGrapplingHook();
			break;

		}
	}

	Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	this->Destroy();
}