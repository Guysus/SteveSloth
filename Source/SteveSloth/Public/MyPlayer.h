/****************************************************************************************
 * Copyright: SteveSloth
 * Name: Tammy Boisvert edited by Jeff and Ken
 * Script: MyPlayer.h
 * Date: April 23. 2024
 * Description: This is the Player Base Class Script
 * TODO:
 * Known Bugs:
 ****************************************************************************************/

#pragma once

// INCLUDES HERE
#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"

// MAKE SURE THIS INCLUDE IS LAST
#include "MyPlayer.generated.h"

// ENUMS HERE
enum EMappingInputs
{
	Normal,
	Swimming,
	EAiming
};

UCLASS()
class STEVESLOTH_API AMyPlayer : public ACharacter
{
	GENERATED_BODY()
	
public: // DETAILS PANEL VARIABLES (UPROPERTY) NEED TO BE PUBLIC
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxHealth;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float RotationSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float PitchSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SprintSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CrouchSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int WalkSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int DodgeDistance;

	UPROPERTY(EditAnywhere, Category = "Input|IMC")
	UInputMappingContext* PMainInputMapping;

	UPROPERTY(EditAnywhere, Category = "Input|IMC")
	UInputMappingContext* PWaterInputMapping;

	UPROPERTY(EditAnywhere, Category = "Input|IMC")
	UInputMappingContext* PAimingInputMapping;

	UPROPERTY(EditAnywhere, Category = "Input|Actions")
	UInputAction* PForwardBack;

	UPROPERTY(EditAnywhere, Category = "Input|Actions")
	UInputAction* PLeftRight;

	UPROPERTY(EditAnywhere, Category = "Input|Actions")
	UInputAction* PTurning;

	UPROPERTY(EditAnywhere, Category = "Input|Actions")
	UInputAction* PJumping;

	UPROPERTY(EditAnywhere, Category = "Input|Actions")
	UInputAction* PSprint;

	UPROPERTY(EditAnywhere, Category = "Input|Actions")
	UInputAction* PInteract;

	UPROPERTY(EditAnywhere, Category = "Input|Actions")
	UInputAction* PCrouch;
	
	UPROPERTY(EditAnywhere, Category = "Input|Actions")
	UInputAction* PDodge;

	UPROPERTY(EditAnywhere, Category = "Input|Actions")
	UInputAction* PSwim;

	UPROPERTY(EditAnywhere, Category = "Input|Actions")
	UInputAction* PLockTarget;

	UPROPERTY(EditAnywhere, Category = "Input|Actions")
	UInputAction* PAiming;
	
private: // PRIVATE VARIABLES
	UEnhancedInputLocalPlayerSubsystem* CurrentIMC;
	
	EMappingInputs IMCInputs;
	
	float CurrentHealth;
	
	int LeavesFound;
    int GrubsCollected;
	int CurrentSlingshotAmmo;
	
	bool IsMoving;
	bool DidDodge;

	USpringArmComponent* CameraArm;
	UCameraComponent* PlayerCamera;
	
public:	// CONSTRUCTOR HERE
	AMyPlayer();

protected: // SETUP FUNCTIONS
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:	// UPDATE FUNCTIONS
	virtual void Tick(float DeltaTime) override;

public: // NORMAL FUNCTIONS
	void HitPlayer(float damageAmount);

private: // PRIVATE INTERNAL FUNCTIONS
	void MoveForwardBack(const FInputActionValue& Value);
	void MoveLeftRight(const FInputActionValue& Value);
	void JumpOne(const FInputActionValue& Value);
	void IsSprinting(const FInputActionValue& Value);
	void SprintStop(const FInputActionValue& Value);
	void InteractWith(const FInputActionValue& Value);
	void IsCrouching(const FInputActionValue& Value);
	void CrouchStop(const FInputActionValue& Value);
	void Dodge(const FInputActionValue& Value);
	void Swim(const FInputActionValue& Value);
	void LockOn(const FInputActionValue& Value);
	void Aiming(const FInputActionValue& Value);
	void AimingStop(const FInputActionValue& Value);
	void CamTurn(const FInputActionValue& Value);
};