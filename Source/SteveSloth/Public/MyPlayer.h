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

	UPROPERTY(EditAnywhere, Category = "Input|IMC")
	UInputMappingContext* PInputMapping;

	UPROPERTY(EditAnywhere, Category = "Input|Actions")
	UInputAction* PForwardBack;

	UPROPERTY(EditAnywhere, Category = "Input|Actions")
	UInputAction* PLeftRight;

	UPROPERTY(EditAnywhere, Category = "Input|Actions")
	UInputAction* PJumping;
	
private:
	float CurrentHealth;
	
	int LeavesFound;
    int GrubsCollected;
	int CurrentSlingshotAmmo;

	bool IsMoving;
	
public:
	AMyPlayer();

protected:
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:	
	virtual void Tick(float DeltaTime) override; 

private:
	void MoveForwardBack(const FInputActionValue& Value);
	void MoveLeftRight(const FInputActionValue& Value);
	void JumpOne(const FInputActionValue& Value);
};