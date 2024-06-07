/****************************************************************************************
 * Copyright: SteveSloth
 * Name: Elad Saretzky
 * Script: MyRespawnPoint.cpp
 * Date: June 7, 2024
 * Description: Updates the respawn point for the player
 * TODO:
 * Known Bugs:
 ****************************************************************************************/

#include "MyRespawnPoint.h"

// Sets default values
AMyRespawnPoint::AMyRespawnPoint()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AMyRespawnPoint::BeginPlay()
{
	Super::BeginPlay();

	Player = USteveSingleton::GetSteve()->GetPlayerCharacter();

	if (Player)
	{
		Steve = Cast<AMyPlayer>(Player);
	}

}

void AMyRespawnPoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyRespawnPoint::OnHitboxOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor == Player)
	{
		Steve->SetRespawnPoint(Steve->GetActorLocation());
	}
}

