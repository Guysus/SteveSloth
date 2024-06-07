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
#include "MyLevelManager.h"
#include "EnhancedInputComponent.h"
#include "Camera/CameraComponent.h"
#include "MyPlayerHeadsUpDisplay.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "EnhancedInputSubsystems.h"
#include "Kismet/KismetMathLibrary.h"
#include "Components/BoxComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/SkeletalMeshComponent.h"
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

UENUM(BlueprintType)
enum EAbility
{
	GrapplingHook,
	ClimbingClaw,
	Shovel,
	Propeller,
	Magnetic
};

UCLASS()
class STEVESLOTH_API AMyPlayer : public ACharacter
{
	GENERATED_BODY()

private: //PRIVATE CONST VARIABLES
	const float RESPAWN_TIMER = 5.0f;

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
	UInputAction* PPitch;

	UPROPERTY(EditAnywhere, Category = "Input|Actions")
	UInputAction* PJumping;

	UPROPERTY(EditAnywhere, Category = "Input|Actions")
	UInputAction* PSprint;

	UPROPERTY(EditAnywhere, Category = "Input|Actions")
	UInputAction* PInteract;

	UPROPERTY(EditAnywhere, Category = "Input|Actions")
	UInputAction* PMeleeAttack;

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
	UInputAction* PSwitchAbilities;

	UPROPERTY(EditAnywhere, Category = "Input|Actions")
	UInputAction* PCamPitch;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Animations")
	UAnimSequence* GrapplingHookSequence;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Animation")
	UAnimationAsset* MeleeAttackAnim;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Animation")
	UAnimationAsset* DeathAnim;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USkeletalMeshComponent* WrenchMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UBoxComponent* WrenchHitbox;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USpringArmComponent* CameraArm;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UCameraComponent* PlayerCamera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (RowType = "MyAmmoData"), Category = "Data")
	FDataTableRowHandle AmmoDataTable;

protected: // PROTECTED INHERITABLE VARIABLES
	FTimerHandle GrappleTimerHandle;
	FTimerHandle DeathTimerHandle;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UMyPlayerHeadsUpDisplay> PlayerHUDClass;

	UPROPERTY()
	UMyPlayerHeadsUpDisplay* PlayerHUD;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bIsDead;

private: // PRIVATE VARIABLES
	TArray<FMyAmmoData*> Ammos;
	TArray<EAbility*> Abilities;
	UTexture2D* EquippedAmmoIcon;
	TArray<UTexture2D*> AmmoIcons;
	//USpringArmComponent* CameraArm;
	//UCameraComponent* PlayerCamera;
	UEnhancedInputLocalPlayerSubsystem* CurrentIMC;

	AMyLevelManager* LevelManager;

	EMappingInputs IMCInputs;
	EAbility Ability;

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
	bool bIsClimbing;
	bool bIsShovelUnlocked;
	bool bIsMagneticUnlocked;
	bool bIsGrapplingUnlocked;
	bool bIsPropellerUnlocked;
	bool bIsClimbingClawUnlocked;
	bool bIsMeleeAnimationPlaying;

	TArray<int> MaxAmmos;
	TArray<int> CurrentAmmos;

	FVector RespawnPoint;

public: // GETTERS/ACCESSORS
	FVector GetRespawnPoint() const { return RespawnPoint; };
	float GetMaxHealth() const { return MaxHealth; }
	float GetCurrentHealth() const { return CurrentHealth; }
	float GetNeededAmmoIndex();

public: // SETTERS/MUTATORS
	void SetRespawnPoint(FVector respawnPoint) { RespawnPoint = respawnPoint; }
	void SetMaxHealth(float amount);
	void SetCurrentHealth(float amount);

public:	// CONSTRUCTOR HERE
	AMyPlayer();

protected: // INITIALIZE INHERITABLE FUNCTIONS
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

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

	UFUNCTION(BlueprintCallable)
	void HitPlayer(float damageAmount);

	void AddEucalyptus(int eucalyptusAmount);
	void RemoveEucalyptus(int eucalyptusAmount);

	void StartMeleeAttack();
	void EndMeleeAttack();

	void Death();
	void Respawn();

private: // PRIVATE INTERNAL FUNCTIONS
	void EquipAmmo(EAmmoType ammoType);
	void Swim(const FInputActionValue& Value);
	void Dodge(const FInputActionValue& Value);
	void LockOn(const FInputActionValue& Value);
	void Aiming(const FInputActionValue& Value);
	void CamTurn(const FInputActionValue& Value);
	void JumpOne(const FInputActionValue& Value);
	void CamPitch(const FInputActionValue& Value);
	void SprintStop(const FInputActionValue& Value);
	void CrouchStop(const FInputActionValue& Value);
	void AimingStop(const FInputActionValue& Value);
	void IsSprinting(const FInputActionValue& Value);
	void IsCrouching(const FInputActionValue& Value);
	void InteractOver(const FInputActionValue& Value);
	void InteractWith(const FInputActionValue& Value);
	void MeleeAttack(const FInputActionValue& Value);
	void MeleeAttackStop(const FInputActionValue& Value);
	void MoveLeftRight(const FInputActionValue& Value);
	void MoveForwardBack(const FInputActionValue& Value);
	void SwitchAbilities(const FInputActionValue& Value);
};