/****************************************************************************************
* Copyright: SteveSloth
 * Name: Elad Saretzky
 * Script: MyProjectileData.h
 * Date: May 16, 2024
 * Description: data table that holds all the projectile variables
 * TODO:
 * Known Bugs:
 ****************************************************************************************/

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "MyProjectileData.generated.h"

UENUM(BlueprintType)
enum class EProjectileType
{
	Physical UMETA(DisplayName = "Physical"),
	Fire UMETA(DisplayName = "Fire"),
	Water UMETA(DisplayName = "Water"),
	Poison UMETA(DisplayName = "Poison"),
	Ice UMETA(DisplayName = "Ice")
};

USTRUCT(BlueprintType)
struct STEVESLOTH_API FMyProjectileData : public FTableRowBase
{
	GENERATED_BODY()
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FString Name;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TEnumAsByte<EProjectileType> ProjectileType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float Damage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float ProjectileSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float ProjectileRange;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float ProjectileGravity;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float InitialLaunchAngle;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float AreaOfEffectDamage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float AreaOfEffectRadius;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float DamageOverTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float DamageOverTimeDuration;
};
