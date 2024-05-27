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

	ItemHitBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Hit Box"));

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(Mesh);
	Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
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
			AddHealthAmount = itemData->AddHealthAmount;
			AddHealthPercentage = itemData->AddHealthPercentage;
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
				bIsItemUnlocked = true;
				Steve->AddUpgradeAbility();
			break;

			case EItemType::ClimbingClaw:
				bIsItemUnlocked = true;
				Steve->AddUpgradeAbility();
			break;

			case EItemType::Shovel:
				bIsItemUnlocked = true;
				Steve->AddUpgradeAbility();
			break;

			case EItemType::Propeller:
				bIsItemUnlocked = true;
				Steve->AddUpgradeAbility();
			break;

			case EItemType::Magnetic:
				bIsItemUnlocked = true;
				Steve->AddUpgradeAbility();
			break;
		}
	}
}