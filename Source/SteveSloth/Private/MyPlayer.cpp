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
			Subsystem->AddMappingContext(InputMapping, 0);
		}
	}

	if (UEnhancedInputComponent* inputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		inputComponent->BindAction(ForwardBack, ETriggerEvent::Triggered, this, &AMyPlayer::MoveForwardBack);
		inputComponent->BindAction(ForwardBack, ETriggerEvent::Completed, this, &AMyPlayer::MoveForwardBack);

		inputComponent->BindAction(Turn, ETriggerEvent::Triggered, this, &AMyPlayer::TurnLeftRight);
		inputComponent->BindAction(Turn, ETriggerEvent::Completed, this, &AMyPlayer::TurnLeftRight);
	}
}

void AMyPlayer::MoveForwardBack(const FInputActionValue& Value)
{
	float const Direction = Value.Get<float>();
	FVector const Forward = GetActorForwardVector();
	AddMovementInput(Forward, Direction);
}

void AMyPlayer::TurnLeftRight(const FInputActionValue& Value)
{
	float const TurnDirection = Value.Get<float>();
	FRotator const Rotation = Controller->GetControlRotation();
	FRotator const RotationAxis(0, Rotation.Yaw, 0);
	FVector const Turning = FRotationMatrix(RotationAxis).GetUnitAxis(EAxis::Y);
	AddMovementInput(Turning, TurnDirection);
}