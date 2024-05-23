/****************************************************************************************
 * Copyright: 
 * Name: Guy Lapensee, Jeff Moreau
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
	}

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
			//Steve->Set
			break;
			case EItemType::Grub:

			break;
			case EItemType::Eucalyptus:
	
			break;
			case EItemType::GreenBud:

			break;
			case EItemType::BlueBud:

			break;
			case EItemType::RedBud:

			break;
		}
	}
}