/****************************************************************************************
* Copyright: SteveSloth
 * Name: Jeff Moreau
 * Script: MyPlayerCamera.cpp
 * Date: April 29. 2024
 * Description: The Main Camera that follows the player around
 * TODO:
 * Known Bugs:
 ****************************************************************************************/

#include "MyPlayerCamera.h"

#include "K2Node_SpawnActorFromClass.h"
#include "Kismet/GameplayStatics.h"

AMyPlayerCamera::AMyPlayerCamera()
{
	PrimaryActorTick.bCanEverTick = true;
	PCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Player Camera"));
	
}

void AMyPlayerCamera::BeginPlay()
{
	Super::BeginPlay();
}

void AMyPlayerCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}