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
	if (OtherActor == Player)
	{
		int randomSFX = FMath::RandRange(0, BreakingSFXs.Num() - 1);

		Mesh->SetVisibility(false);
		Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

		VFXComponent = UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), DestroyedVFX, Mesh->GetComponentLocation(), Mesh->GetComponentRotation());
		VFXComponent->Activate();
		GetWorldTimerManager().SetTimer(VFXStopTimerHandle, this, &AMyBaseDestructibleObject::StopVFX, VFX_TIMER_AMOUNT, false);

		UGameplayStatics::PlaySoundAtLocation(this, BreakingSFXs[randomSFX], GetActorLocation());
		GetWorldTimerManager().SetTimer(DespawnTimerHandle, this, &AMyBaseDestructibleObject::DespawnObject, BreakingSFXs[randomSFX]->Duration, false);
	}
}

void AMyBaseDestructibleObject::SpawnLoot()
{

}

void AMyBaseDestructibleObject::StopVFX()
{
	VFXComponent->Deactivate();
}

void AMyBaseDestructibleObject::DespawnObject()
{
	this->Destroy();
}

