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
	LevelsCompleted = 0;
	BossesKilled = 0;
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

	if (APlayerController* playerController = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(playerController->GetLocalPlayer()))
		{
			subsystem->ClearAllMappings();
			subsystem->AddMappingContext(InputMapping, 0);
		}
	}

	if (UEnhancedInputComponent* inputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		inputComponent->BindAction(pGasPedal, ETriggerEvent::Triggered, this, &AMyPlayerCarPawn::GasPedal);
		inputComponent->BindAction(pGasPedal, ETriggerEvent::Completed, this, &AMyPlayerCarPawn::GasPedal);
	}
       
}

