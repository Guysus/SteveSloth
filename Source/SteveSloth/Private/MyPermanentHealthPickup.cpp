/****************************************************************************************
 * Copyright:
 * Name: Guy Lapensee
 * Script: AMyPermanentHealthPickup
 * Date: May 16, 2024
 * Description:Leaf  pickup for 25 permanent health boost
 * TODO: Permanently add health to the players health bar
 * Known Bugs:
 ****************************************************************************************/


#include "MyPermanentHealthPickup.h"

AMyPermanentHealthPickup::AMyPermanentHealthPickup()
{
	ItemClass = CreateDefaultSubobject<AItemBaseClass>(TEXT("Item Class"));
}
