/****************************************************************************************
 * Copyright: SteveSloth
 * Name: Jeff Moreau, Guy Lapensee
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
}

void AItemBaseClass::BeginPlay()
{
	Super::BeginPlay();

	Player = USteveSingleton::GetSteve()->GetPlayerCharacter();

	if (Player)
	{
		Steve = Cast<AMyPlayer>(Player);
	}

	// Initialize Variables to the Item Data Table
	const auto itemData = ItemDataTable.GetRow<FUMyItemData>("");

	if (itemData)
	{
		Name = itemData->Name;
		Mesh = itemData->Mesh;
		Health = itemData->Health;
		ItemType = itemData->ItemType;
		DropChance = itemData->DropChance;
		StackAmount = itemData->StackAmount;
		bIsCurrency = itemData->bIsCurrency;
		AddHealthAmount = itemData->AddHealthAmount;
		AddHealthPercentage = itemData->AddHealthPercentage;
	}
}

void AItemBaseClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AItemBaseClass::OnHitboxOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
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
}