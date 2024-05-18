/****************************************************************************************
 * Copyright: 
 * Name: Guy Lapensee
 * Script: ItemBaseClass
 * Date: April 23, 2024
 * Description: Base Class for Items
 * TODO: 
 * Known Bugs: 
 ****************************************************************************************/


#include "ItemBaseClass.h"

// Sets default values
AItemBaseClass::AItemBaseClass()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AItemBaseClass::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AItemBaseClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

