/****************************************************************************************
 * Copyright: SteveSloth
 * Name: Elad Saretzky
 * Script: MyBaseDestructibleObject.cpp
 * Date: May 30, 2024
 * Description: Handles the logic for destructible objects such as crates
 * TODO:
 * Known Bugs:
 ****************************************************************************************/

#include "MyBaseDestructibleObject.h"

// Sets default values
AMyBaseDestructibleObject::AMyBaseDestructibleObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyBaseDestructibleObject::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyBaseDestructibleObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

