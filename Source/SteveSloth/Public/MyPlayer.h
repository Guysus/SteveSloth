/****************************************************************************************
 * Copyright: SteveSloth
 * Name: Tammy Boisvert edited by Jeff
 * Script: MyPlayer.h
 * Date: April 23. 2024
 * Description: This is the Player Base Class Script
 * TODO:
 * Known Bugs:
 ****************************************************************************************/

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/Character.h"
#include "MyPlayer.generated.h"

enum class EAmmoTypes
{
	Pebble,
	FireCracker,
	WaterBalloon,
	PoisonSac,
	ChristmasBeetle,
	BigRock
};

UCLASS()
class STEVESLOTH_API AMyPlayer : public ACharacter
{
	GENERATED_BODY()
	
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float CurrentHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CurrentSlingshotAmmo;

	UPROPERTY(EditAnywhere, Category = "Input|IMC")
	UInputMappingContext* InputMapping;

	UPROPERTY(EditAnywhere, Category = "Input|Actions")
	UInputAction* ForwardBack;

	UPROPERTY(EditAnywhere, Category = "Input|Actions")
	UInputAction* Turn;

	UPROPERTY(EditAnywhere, Category = "Input|Actions")
	UInputAction* Jumping;
	
private:
	int LeavesFound;
    int GrubsCollected;
	
public:
	AMyPlayer();

protected:
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:	
	virtual void Tick(float DeltaTime) override; 

private:
	void MoveForwardBack(const FInputActionValue& Value);
	void TurnLeftRight(const FInputActionValue& Value);
};