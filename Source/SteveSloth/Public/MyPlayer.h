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
#include "GameFramework/Character.h"

// MAKE SURE THIS INCLUDE IS LAST
#include "MyPlayer.generated.h"

// ENUMS HERE
enum EMappingInputs
{
	Normal,
	Water,
	Aiming
};

UCLASS()
class STEVESLOTH_API AMyPlayer : public ACharacter
{
	GENERATED_BODY()
	
public: // DETAILS PANEL VARIABLES (UPROPERTY) NEED TO BE PUBLIC
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxHealth;

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
	
private: // PRIVATE VARIABLES
	float CurrentHealth;

	EMappingInputs IMCInputs;
	
	int LeavesFound;
    int GrubsCollected;
	int CurrentSlingshotAmmo;
	int SprintSpeed;
	int CrouchSpeed;
	int WalkSpeed;
	int DodgeDistance;
	
	bool IsMoving;
	bool DidDodge;
	
public:	// CONSTRUCTOR HERE
	AMyPlayer();

protected: // SETUP FUNCTIONS
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:	// UPDATE FUNCTIONS
	virtual void Tick(float DeltaTime) override;

private: // PRIVATE INTERNAL FUNCTIONS
	void MoveForwardBack(const FInputActionValue& Value);
	void MoveLeftRight(const FInputActionValue& Value);
	void JumpOne(const FInputActionValue& Value);
	void Sprint(const FInputActionValue& Value);
	void SprintStop(const FInputActionValue& Value);
	void InteractWith(const FInputActionValue& Value);
	void Crouch(const FInputActionValue& Value);
	void CrouchStop(const FInputActionValue& Value);
	void Dodge(const FInputActionValue& Value);
	void Swim(const FInputActionValue& Value);
};