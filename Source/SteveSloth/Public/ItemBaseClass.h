// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemBaseClass.generated.h"

//All of the different ammo types in an enum
enum AmmoType
{
	Pebble,
	Firecracker,
	WaterBalloon,
	PoisonSac,
	ChristmasBeetle,
	BigRock
};

//Different types of health the player can pick up
enum HealthType
{
	RedFlower,
	BlueFlower,
	GreenFlower
};

UCLASS()
class STEVESLOTH_API AItemBaseClass : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItemBaseClass();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ammo")
	//Amount of ammo picked up
	int AmmoAmount;
	//Chance of what kind of ammo is going to drop
	float ChanceOfAmmo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Currency")
	//Amount of grubs picked up
	int Grubs;
	//Amount of eucalyptus picked up
	int Eucalyptus;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health Type")
	//Counts amount of health to add
	int FlowerBud;
	//Chance in percentage of what kind of health drop
	float ChanceOfHealth;
};
