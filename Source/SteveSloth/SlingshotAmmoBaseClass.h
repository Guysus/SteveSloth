/****************************************************************************************
* Copyright: SteveSloth
 * Name: Brandon Thomas
 * Script: SlingshotAmmoBaseClass.h
 * Date: April 23. 2024
 * Description: This is the base header class for all ammo types
 * TODO:
 * Known Bugs:
 ****************************************************************************************/

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SlingshotAmmoBaseClass.generated.h"


enum DamageType
{
	Physical,
	Fire,
	Water,
	Poison,
	Ice
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class STEVESLOTH_API USlingshotAmmoBaseClass : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USlingshotAmmoBaseClass();
	

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Name")
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
	float Damage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
	bool AreaOfEffect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
	float AOEDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
	float AOERadius;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
	bool DamageOverTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
	float DOTDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
	float DOTDuration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Capacity")
	int MaxAmmoCapacity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Drop Rate")
	float DropRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fire Rate")
	float FireRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Puzzles")
	bool CanBeUsedInPuzzle;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
