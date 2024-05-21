/****************************************************************************************
 * Copyright: 
 * Name: Guy Lapensee
 * Script: ItemBaseClass
 * Date: April 23, 2024
 * Description: Base Class for Items
 * TODO: 
 * Known Bugs: 
 ****************************************************************************************/

#include "Kismet/GameplayStatics.h"
#include "ItemBaseClass.h"
#include "Sound/SoundBase.h"

// Sets default values
AItemBaseClass::AItemBaseClass()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Player = USteveSingleton::GetSteve()->GetPlayerCharacter();
	Steve = Cast<AMyPlayer>(Player);
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

void AItemBaseClass::OnOverlapStart(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (Steve == OtherActor)
	{
		UGameplayStatics::SpawnSoundAtLocation(this, ItemSound, GetActorLocation());
		Steve->MaxHealth += 25;
	}
}



void AItemBaseClass::DespawnItem()
{
	this->Destroy();
}

