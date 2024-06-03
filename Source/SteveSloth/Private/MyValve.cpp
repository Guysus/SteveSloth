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

	isInArea = false;
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
	
	if (isInArea)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player in Area"));
	}
}

void AMyValve::OnHitboxOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
									int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor == Player)
	{
		isInArea = true;
	}
}