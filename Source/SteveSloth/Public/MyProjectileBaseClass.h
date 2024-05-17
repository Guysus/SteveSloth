/****************************************************************************************
 * Copyright: SteveSloth
 * Name: Jeff Moreau, Elad Saretzky
 * Script: MyProjectileBaseClass.h
 * Date: May 15, 2024
 * Description: Where all Projectiles are made from and all functionality
 * TODO:
 * Known Bugs:
 *****************************************************************************************/

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyProjectileData.h"
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

private: //PRIVATE VARIABLES
	TEnumAsByte<EProjectileType> ProjectileType;

	float Damage;
	float ProjectileSpeed;
	float ProjectileRange;
	float ProjectileGravity;
	float InitialLaunchAngle;
	float AreaOfEffectDamage;
	float AreaOfEffectRadius;
	float DamageOverTime;
	float DamageOverTimeDuration;

public: // CONSTRUCTOR HERE
	AMyProjectileBaseClass();

protected: // INITIALIZE INHERITABLE FUNCTIONS
	virtual void BeginPlay() override;

public:	// UPDATE ACCESS ANYWHERE FUNCTIONS
	virtual void Tick(float DeltaTime) override;
};
