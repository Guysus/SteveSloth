/****************************************************************************************
 * Copyright:
 * Name: Guy Lapensee
 * Script: AMyPermanentHealthPickup
 * Date: May 16, 2024
 * Description:Leaf  pickup for 25 permanent health boost
 * TODO: Permanently add health to the players health bar
 * Known Bugs:
 ****************************************************************************************/

#include "Kismet/GameplayStatics.h"
#include "Sound/SoundBase.h"
#include "MyPermanentHealthPickup.h"

AMyPermanentHealthPickup::AMyPermanentHealthPickup()
{
	Player = USteveSingleton::GetSteve()->GetPlayerCharacter();
	Steve = Cast<AMyPlayer>(Player);
}

void AMyPermanentHealthPickup::BeginPlay()
{
	BoxComp->OnComponentBeginOverlap.AddDynamic(this, &AItemBaseClass::OnOverlapStart);
}

void AMyPermanentHealthPickup::OnPickUp()
{
	if (Steve != nullptr)
	{
		UGameplayStatics::SpawnSoundAtLocation(this, ItemSound, GetActorLocation());

	}
}

void AMyPermanentHealthPickup::IncreaseHealthBar()
{
}
