/****************************************************************************************
* Copyright: SteveSloth
 * Name: Jeff Moreau
 * Script: MyEnemyManager.cpp
 * Date: May 8, 2024
 * Description: To take care of all Enemy entities in the game. Easy place to access
 * TODO: 
 * Known Bugs:
 ****************************************************************************************/

#include "MyEnemyManager.h"

AMyEnemyManager::AMyEnemyManager()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AMyEnemyManager::BeginPlay()
{
	Super::BeginPlay();

	ULevel* currentLevel = GetWorld()->GetCurrentLevel();
	FString levelName = currentLevel->GetOutermost()->GetName();

	static ConstructorHelpers::FObjectFinder<UClass> Koala(TEXT("Blueprint'/Game/Blueprints/Enemies/EnemyProjectiles/BP_KoalaStickAmmo.BP_KoalaStickAmmo_C'"));
	UClass* theKoala = Koala.Object;
	FActorSpawnParameters spawnParams;

	if (levelName == "LevelOne")
	{
		for (int i = 0; i < SpawnPoints.Num(); i++)
		{
			FVector SpawnLocation = SpawnPoints[i]->GetTransform().GetLocation();
			FRotator SpawnRotation = SpawnPoints[i]->GetTransform().GetRotation().Rotator();

			// Leaving for reference
			//AActor* tryThis = GetWorld()->SpawnActor<AActor>(theKoala, SpawnLocation, SpawnRotation, spawnParams);
		}
	}
}

void AMyEnemyManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}