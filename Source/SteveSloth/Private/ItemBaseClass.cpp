/****************************************************************************************
 * Copyright: 
 * Name: Guy Lapensee
 * Script: ItemBaseClass
 * Date: April 23, 2024
 * Description: 
 * 
				Explain what is in this script and what it is used for
 *              yes you can use multiple lines for more information.
 * TODO: write comments here
 * Known Bugs: anything needs to be fixed
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

