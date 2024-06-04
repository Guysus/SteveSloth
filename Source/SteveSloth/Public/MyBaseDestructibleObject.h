/****************************************************************************************
 * Copyright: SteveSloth
 * Name: Elad Saretzky
 * Script: MyBaseDestructibleObject.h
 * Date: May 30, 2024
 * Description: Handles the logic for destructible objects such as crates
 * TODO:
 * Known Bugs:
 ****************************************************************************************/

#pragma once

 // INCLUDES HERE

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyPlayer.h"
#include "SteveSingleton.h"
#include "MyProjectileBaseClass.h"
#include "ItemBaseClass.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"

// MAKE SURE THIS INCLUDE IS LAST
#include "MyBaseDestructibleObject.generated.h"

UCLASS()
class STEVESLOTH_API AMyBaseDestructibleObject : public AActor
{
	GENERATED_BODY()

private: //PRIVATE CONST VARIABLES
	const float VFX_TIMER_AMOUNT = 0.1f;

protected: // PROTECTED DETAILS PANEL VARIABLES 
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UBoxComponent* ObjectHitBox;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VFX")
	UNiagaraComponent* VFXComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VFX")
	UNiagaraSystem* DestroyedVFX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SFX")
	TArray<USoundBase*> BreakingSFXs;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Loot (Ammo crate must be in the same order as EAmmoType in MyPlayer)")
	TArray<TSubclassOf<AActor>> Loots;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ammo Crate")
	bool bIsAmmoCrate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Drops")
	int MinAmountDropped;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Drops")
	int MaxAmountDropped;

private: // PRIVATE INTERNAL VARIABLES
	AMyPlayer* Steve;
	ACharacter* Player;

	AMyProjectileBaseClass* Projectile;

	FTimerHandle DespawnTimerHandle;
	FTimerHandle VFXStopTimerHandle;

public:	// CONSTRUCTOR HERE
	AMyBaseDestructibleObject();

protected: // INITIALIZE INHERITABLE FUNCTIONS
	virtual void BeginPlay() override;

public:	// UPDATE ACCESS ANYWHERE FUNCTIONS
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnHitboxOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

private: // PRIVATE INTERNAL FUNCTIONS
	void SpawnLoot();
	void StopVFX();
	void DespawnObject();
};
