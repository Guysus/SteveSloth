/****************************************************************************************
* Copyright: SteveSloth
 * Name: Tammy Boisvert edited by Jeff
 * Script: MyPlayer.cpp
 * Date: April 23. 2024
 * Description: This is the Player Base Class Script
 * TODO:
 * Known Bugs:
 ****************************************************************************************/

#include "MyPlayer.h"

AMyPlayer::AMyPlayer()
{
	PrimaryActorTick.bCanEverTick = true;
	
	MaxHealth = 0;
	CurrentHealth = 0;
	GrubsCollected = 0;
	CurrentSlingshotAmmo = 0;
	LeavesFound = 0;
}

void AMyPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMyPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->ClearAllMappings();
			Subsystem->AddMappingContext(PInputMapping, 0);
		}
	}

	if (UEnhancedInputComponent* inputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		inputComponent->BindAction(PForwardBack, ETriggerEvent::Triggered, this, &AMyPlayer::MoveForwardBack);
		inputComponent->BindAction(PForwardBack, ETriggerEvent::Completed, this, &AMyPlayer::MoveForwardBack);

		inputComponent->BindAction(PTurn, ETriggerEvent::Triggered, this, &AMyPlayer::MoveLeftRight);
		inputComponent->BindAction(PTurn, ETriggerEvent::Completed, this, &AMyPlayer::MoveLeftRight);

		inputComponent->BindAction(PJumping, ETriggerEvent::Triggered, this, &AMyPlayer::JumpOne);
		inputComponent->BindAction(PJumping, ETriggerEvent::Completed, this, &AMyPlayer::JumpOne);
	}
}

void AMyPlayer::MoveForwardBack(const FInputActionValue& Value)
{
	float const Direction = Value.Get<float>();
	FVector const Forward = GetActorForwardVector();
	AddMovementInput(Forward, Direction);
}

void AMyPlayer::MoveLeftRight(const FInputActionValue& Value)
{
	// Will Move left and right but also turn to face that direction as well
	float const TurnDirection = Value.Get<float>();
	FRotator const Rotation = Controller->GetControlRotation();
	FRotator const RotationAxis(0, Rotation.Yaw, 0);
	FVector const Turning = FRotationMatrix(RotationAxis).GetUnitAxis(EAxis::Y);
	AddMovementInput(Turning, TurnDirection);
}

void AMyPlayer::JumpOne(const FInputActionValue& Value)
{
	float const IsJumping = Value.Get<bool>();
	Jump();
}
