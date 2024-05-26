/****************************************************************************************
 * Copyright: SteveSloth
 * Name: Tammy Boisvert, Edited by Jeff Moreau, Elad Saretzky, Ken Ferris
 * Script: MyPlayer.h
 * Date: April 23. 2024
 * Description: This is the Player Base Class Script
 * TODO:
 * Known Bugs:
 ****************************************************************************************/

#pragma once

// INCLUDES HERE
#include "MyAmmoData.h"
#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "Camera/CameraComponent.h"
#include "MyPlayerHeadsUpDisplay.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// MAKE SURE THIS INCLUDE IS LAST
#include "MyPlayer.generated.h"

// ENUMS HERE
enum EMappingInputs
{
	Normal,
	Swimming,
	EAiming
};

enum EAmmoType
{
	Pebble,
	Firecracker,
	WaterBalloon,
	PoisonSac,
	ChristmasBeetle,
	BigRock
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

	UPROPERTY(EditAnywhere, Category = "Input|Actions")
	UInputAction* PGrappplingHook;

	UPROPERTY(EditAnywhere, Category = "Input|Actions")
	UInputAction* PClimbingClaw;

	UPROPERTY(EditAnywhere, Category = "Input|Actions")
	UInputAction* PShovel;

	UPROPERTY(EditAnywhere, Category = "Input|Actions")
	UInputAction* PPropeller;

	UPROPERTY(EditAnywhere, Category = "Input|Actions")
	UInputAction* PMagnetic;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (RowType = "MyAmmoData"), Category = "Data")
	FDataTableRowHandle AmmoDataTable;

public: // GETTERS/ACCESSORS
	float GetMaxHealth() { return MaxHealth; }
	float GetCurrentHealth() { return CurrentHealth; }

public: // SETTERS/MUTATORS
	void SetMaxHealth(float amount) { MaxHealth = MaxHealth + amount; }
	void SetCurrentHealth(float amount) { CurrentHealth = CurrentHealth + amount; }

	UPROPERTY(EditAnywhere)
	TSubclassOf<UMyPlayerHeadsUpDisplay> PlayerHUDClass;

	UPROPERTY()
	UMyPlayerHeadsUpDisplay* PlayerHUD;
	
private: // PRIVATE VARIABLES
	TArray<FMyAmmoData*> Ammos;
	UTexture2D* EquippedAmmoIcon;
	TArray<UTexture2D*> AmmoIcons;
	USpringArmComponent* CameraArm;
	UCameraComponent* PlayerCamera;
	UEnhancedInputLocalPlayerSubsystem* CurrentIMC;
	
	EMappingInputs IMCInputs;
	
	float CurrentHealth;
	
	int GrubCount;
	int LeavesFound;
	int EucalyptusCount;
	int EquippedMaxAmmo;
	int EquippedCurrentAmmo;
	
	bool bIsMoving;
	bool bDidDodge;
	bool bIsAimMode;
	bool bDidGrapple;
	bool bIsShovelUnlocked;
	bool bIsMagneticUnlocked;
	bool bIsPropellerUnlocked;
	bool bIsClimbingClawUnlocked;
	bool bIsGrapplingHookUnlocked;

	TArray<int> MaxAmmos;
	TArray<int> CurrentAmmos;
	
public:	// CONSTRUCTOR HERE
	AMyPlayer();

protected: // INITIALIZE INHERITABLE FUNCTIONS
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:	// UPDATE ACCESS ANYWHERE FUNCTIONS
	virtual void Tick(float DeltaTime) override;

public:	// PUBLIC ACCESS ANYWHERE FUNCTIONS
	void AddShovel();
	void AddMagnetic();
	void AddPropeller();
	void AddClimbingClaw();
	void AddGrapplingHook();
	void UseAmmo(int ammoAmount);
	void AddGrubs(int grubAmount);
	void PickUpAmmo(int ammoAmount);
	void RemoveGrubs(int grubAmount);
	void HitPlayer(float damageAmount);
	void AddEucalyptus(int eucalyptusAmount);
	void RemoveEucalyptus(int eucalyptusAmount);

private: // PRIVATE INTERNAL FUNCTIONS
	void EquipAmmo(EAmmoType ammoType);
	void Swim(const FInputActionValue& Value);
	void Dodge(const FInputActionValue& Value);
	void LockOn(const FInputActionValue& Value);
	void Aiming(const FInputActionValue& Value);
	void Shovel(const FInputActionValue& Value);
	void CamTurn(const FInputActionValue& Value);
	void JumpOne(const FInputActionValue& Value);
	void Magnetic(const FInputActionValue& Value);
	void Propeller(const FInputActionValue& Value);
	void SprintStop(const FInputActionValue& Value);
	void CrouchStop(const FInputActionValue& Value);
	void AimingStop(const FInputActionValue& Value);
	void IsSprinting(const FInputActionValue& Value);
	void IsCrouching(const FInputActionValue& Value);
	void ClimbingClaw(const FInputActionValue& Value);
	void InteractWith(const FInputActionValue& Value);
	void MoveLeftRight(const FInputActionValue& Value);
	void GrapplingHook(const FInputActionValue& Value);
	void MoveForwardBack(const FInputActionValue& Value);
};