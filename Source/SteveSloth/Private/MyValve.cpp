/****************************************************************************************
 * Copyright: SteveSloth
 * Name: Jeff Moreau
 * Script: MyValve.cpp
 * Date: May 29. 2024
 * Description: Functionality for the Valve for Puzzles
 * TODO:
 * Known Bugs:
 ****************************************************************************************/

#include "MyValve.h"

AMyValve::AMyValve()
{
	PrimaryActorTick.bCanEverTick = true;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base"));
	ValveMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Valve"));
	PlayerHitBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Player Area"));
}

void AMyValve::BeginPlay()
{
	Super::BeginPlay();

	Player = USteveSingleton::GetSteve()->GetPlayerCharacter();

	if (Player)
	{
		Steve = Cast<AMyPlayer>(Player);
	}
}

void AMyValve::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}