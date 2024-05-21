/****************************************************************************************
 * Copyright:
 * Name: Guy Lapensee
 * Script: AMyPermanentHealthPickup
 * Date: May 16, 2024
 * Description:Leaf  pickup for 25 permanent health boost
 * TODO: Permanently add health to the players health bar
 * Known Bugs:
 ****************************************************************************************/

#include "Components/BoxComponent.h"
#include "MyPermanentHealthPickup.h"


AMyPermanentHealthPickup::AMyPermanentHealthPickup()
{
	Player = USteveSingleton::GetSteve()->GetPlayerCharacter();
	Steve = Cast<AMyPlayer>(Player);

	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	RootComponent = BoxComp;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	BaseMesh->SetupAttachment(RootComponent);
}

void AMyPermanentHealthPickup::BeginPlay()
{
	BoxComp->OnComponentBeginOverlap.AddDynamic(this, &AItemBaseClass::OnOverlapStart);
}

void AMyPermanentHealthPickup::IncreaseHealthBar()
{
	//Increase health bar once we have one
}
