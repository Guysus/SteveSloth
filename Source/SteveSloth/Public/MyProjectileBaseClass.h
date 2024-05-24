/****************************************************************************************
 * Copyright: SteveSloth
 * Name: Jeff Moreau, Edited by Elad Saretzky
 * Script: MyProjectileBaseClass.h
 * Date: May 15, 2024
 * Description: Where all Projectiles are made from and all functionality
 * TODO:
 * Known Bugs:
 *****************************************************************************************/

#pragma once

// INCLUDES HERE
#include "MyPlayer.h"
#include "CoreMinimal.h"
#include "SteveSingleton.h"
#include "MyEnemyBaseClass.h"
#include "MyProjectileData.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

 // MAKE SURE THIS INCLUDE IS LAST
#include "MyProjectileBaseClass.generated.h"

UCLASS()
class STEVESLOTH_API AMyProjectileBaseClass : public AActor
{
	GENERATED_BODY()

protected: // PROTECTED DETAILS PANEL VARIABLES 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (RowType = "MyProjectileData"), Category = "Data")
	FDataTableRowHandle ProjectileDataTable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UProjectileMovementComponent* ProjectileMovement;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UBoxComponent* ProjectileHitbox;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USphereComponent* AreaOfEffectHitbox;

private: // PRIVATE INTERNAL VARIABLES
	AMyPlayer* Steve;
	ACharacter* Player;
	AMyEnemyBaseClass* Enemy;

	FString Name;

	float Damage;
	float DamageOverTime;
	float ProjectileSpeed;
	float ProjectileRange;
	float ProjectileGravity;
	float InitialLaunchAngle;
	float AreaOfEffectDamage;
	float AreaOfEffectRadius;
	float ProjectileMaxSpeed;
	float DamageOverTimeRate;

	int DamageOverTimeDuration;

	FVector StartingLocation;

	FTimerHandle DamageOverTimeTimerHandle;

	TEnumAsByte<EProjectileType> ProjectileType;

public: // CONSTRUCTOR HERE
	AMyProjectileBaseClass();

protected: // INITIALIZE INHERITABLE FUNCTIONS
	virtual void BeginPlay() override;

public:	// UPDATE ACCESS ANYWHERE FUNCTIONS
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnHitboxOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnAOEHitboxOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

private: // PRIVATE INTERNAL FUNCTIONS
	void DamageOverTimeEnemy();
	void DamageOverTimePlayer();
};