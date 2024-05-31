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

AMyBaseDestructibleObject::AMyBaseDestructibleObject()
{
	PrimaryActorTick.bCanEverTick = true;

	ObjectHitBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Hit Box"));

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(Mesh);
	Mesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}

void AMyBaseDestructibleObject::BeginPlay()
{
	Super::BeginPlay();
	
	Player = USteveSingleton::GetSteve()->GetPlayerCharacter();

	if (IsValid(Player))
	{
		Steve = Cast<AMyPlayer>(Player);
	}
}

void AMyBaseDestructibleObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyBaseDestructibleObject::OnHitboxOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

}

