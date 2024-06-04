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

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(Mesh);
	Mesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	ObjectHitBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Hit Box"));
	ObjectHitBox->SetupAttachment(Mesh);

	VFXComponent = CreateDefaultSubobject<UNiagaraComponent>(TEXT("VFX"));
	VFXComponent->SetupAttachment(Mesh);
	VFXComponent->bAutoActivate = false;
	VFXComponent->Deactivate();
}

void AMyBaseDestructibleObject::BeginPlay()
{
	Super::BeginPlay();

	ObjectHitBox->OnComponentBeginOverlap.AddDynamic(this, &AMyBaseDestructibleObject::OnHitboxOverlapBegin);

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
	//needs to put the weapon/projectile hitbox here instead of just player
	if (OtherActor == Player) 
	{
		int randomSFX = FMath::RandRange(0, BreakingSFXs.Num() - 1);

		Mesh->SetVisibility(false);
		Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		
		SpawnLoot();

		VFXComponent = UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), DestroyedVFX, Mesh->GetComponentLocation(), Mesh->GetComponentRotation());
		VFXComponent->Activate();
		GetWorldTimerManager().SetTimer(VFXStopTimerHandle, this, &AMyBaseDestructibleObject::StopVFX, VFX_TIMER_AMOUNT, false);

		UGameplayStatics::PlaySoundAtLocation(this, BreakingSFXs[randomSFX], GetActorLocation());
		GetWorldTimerManager().SetTimer(DespawnTimerHandle, this, &AMyBaseDestructibleObject::DespawnObject, BreakingSFXs[randomSFX]->Duration, false);
	}
}

void AMyBaseDestructibleObject::SpawnLoot()
{
	int randomLootAmount = FMath::RandRange(MinAmountDropped, MaxAmountDropped);
	TSubclassOf<AActor> itemToSpawn = (bIsAmmoCrate) ? Loots[Steve->GetNeededAmmoIndex()] : Loots[0];

	if (itemToSpawn)
	{
		for (int i = 0; i < randomLootAmount; i++)
		{
			float randomDirection = FMath::RandRange(0.0f, 360.0f);
			FVector spawnLocation = FVector(GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z + 50.0f);
			FTransform spawnTransform = FTransform(FRotator(0, randomDirection, 0), spawnLocation);

			GetWorld()->SpawnActor(itemToSpawn, &spawnTransform);
		}
	}
}

void AMyBaseDestructibleObject::StopVFX()
{
	VFXComponent->Deactivate();
}

void AMyBaseDestructibleObject::DespawnObject()
{
	this->Destroy();
}

