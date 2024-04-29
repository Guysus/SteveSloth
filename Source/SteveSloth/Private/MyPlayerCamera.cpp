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

AMyPlayerCamera::AMyPlayerCamera()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AMyPlayerCamera::BeginPlay()
{
	Super::BeginPlay();
}

void AMyPlayerCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}