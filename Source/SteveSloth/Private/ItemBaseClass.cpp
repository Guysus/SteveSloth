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
}

void AItemBaseClass::BeginPlay()
{
	Super::BeginPlay();
}

void AItemBaseClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}