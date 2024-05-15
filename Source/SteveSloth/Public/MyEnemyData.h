/****************************************************************************************
* Copyright: SteveSloth
 * Name: Elad Saretzky
 * Script: MyEnemyData.h
 * Date: May 14, 2024
 * Description: data table that holds all the enemy variables
 * TODO:
 * Known Bugs:
 ****************************************************************************************/

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "MyEnemyData.generated.h"


USTRUCT(BlueprintType)
struct STEVESLOTH_API FMyEnemyData : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Name")
	FString Name;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Stats")
	float MeleeAttackRange;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Stats")
	float RangedAttackRange;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Stats")
	float ChaseRange;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Stats")
	float PatrolRange;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Stats")
	float MeleeDamage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Stats")
	float MovementSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Stats")
	float MaxHealth;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Mesh")
	TSoftObjectPtr<USkeletalMesh> Mesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Animations")
	TSoftObjectPtr<UAnimationAsset> IdleAnim;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Animations")
	TSoftObjectPtr<UAnimationAsset> MoveAnim;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Animations")
	TSoftObjectPtr<UAnimationAsset> MeleeAttackAnim;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Animations")
	TSoftObjectPtr<UAnimationAsset> RangedAttackAnim;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Animations")
	TSoftObjectPtr<UAnimationAsset> HitAnim;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Animations")
	TSoftObjectPtr<UAnimationAsset> DeathAnim;
};