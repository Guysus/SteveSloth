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

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FString Name;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float MeleeAttackRange;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float RangedAttackRange;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float ChaseRange;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float PatrolRange;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float MeleeDamage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float MovementSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float MaxHealth;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UAnimationAsset* IdleAnim;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UAnimationAsset* MoveAnim;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UAnimationAsset* MeleeAttackAnim;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UAnimationAsset* RangedAttackAnim;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UAnimationAsset* HitAnim;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UAnimationAsset* DeathAnim;
};