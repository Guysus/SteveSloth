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
