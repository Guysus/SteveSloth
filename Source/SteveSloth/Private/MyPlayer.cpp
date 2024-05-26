/****************************************************************************************
* Copyright: SteveSloth
 * Name: Tammy Boisvert, Edited by Jeff Moreau, Elad Saretzky, Ken Ferris
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

	CameraArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Camera Arm"));
	PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Player Camera"));
	
	CameraArm->SetupAttachment((RootComponent));
	CameraArm->bUsePawnControlRotation = true;
	CameraArm->TargetArmLength = 200;

	PlayerCamera->SetupAttachment(CameraArm, USpringArmComponent::SocketName);
	PlayerCamera->bUsePawnControlRotation = false;
	
	// Bools
	bIsMoving = false;
	bDidDodge = false;
	bIsAimMode = false;
	bIsGrapplingHookUnlocked = false;
	bIsClimbingClawUnlocked = false;
	bIsShovelUnlocked = false;
	bIsPropellerUnlocked = false;
	bIsMagneticUnlocked = false;

	// Health Stuff
	MaxHealth = 0;
	CurrentHealth = 0;

	// Collection Stuff
	LeavesFound = 0;
	
	// Movement Stuff
	WalkSpeed = 600;
	SprintSpeed = 1200;
	CrouchSpeed = 300;
	DodgeDistance = -100;

	// IMC Inputs
	IMCInputs = Normal;
}

void AMyPlayer::BeginPlay()
{
	Super::BeginPlay();

	AmmoDataTable.DataTable->GetAllRows("", Ammos);

	for (int i = 0; i < Ammos.Num(); i++)
	{
		CurrentAmmos.AddUninitialized();
		AmmoIcons.Add(Ammos[i]->AmmoIcon);
		MaxAmmos.Add(Ammos[i]->MaxAmmo);
		CurrentAmmos[i] = MaxAmmos[i];
	}

	EquippedMaxAmmo = MaxAmmos[Pebble];
	EquippedAmmoIcon = AmmoIcons[Pebble];
	EquippedCurrentAmmo = CurrentAmmos[Pebble];

	if (PlayerHUDClass)
	{
		PlayerHUD = CreateWidget<UMyPlayerHeadsUpDisplay>(UGameplayStatics::GetPlayerController(GetWorld(), 0), PlayerHUDClass);

		if (PlayerHUD)
		{
			PlayerHUD->AddToPlayerScreen();

			PlayerHUD->GrubCountText(GrubCount);
			PlayerHUD->EucalyptusCountText(EucalyptusCount);
			PlayerHUD->AmmoCountText(EquippedCurrentAmmo);
			PlayerHUD->AmmoIcon(EquippedAmmoIcon, EquippedCurrentAmmo);
		}
	}
}

void AMyPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMyPlayer::HitPlayer(float damageAmount)
{
	CurrentHealth = CurrentHealth - damageAmount;
}

void AMyPlayer::AddGrubs(int grubAmount)
{
	GrubCount += grubAmount;
	PlayerHUD->GrubCountText(GrubCount);
}

void AMyPlayer::RemoveGrubs(int grubAmount)
{
	if (GrubCount - grubAmount >= 0)
	{
		GrubCount -= grubAmount;
	}
	else
	{
		GrubCount = 0;
	}

	PlayerHUD->GrubCountText(GrubCount);
}

void AMyPlayer::AddEucalyptus(int eucalyptusAmount)
{
	EucalyptusCount += eucalyptusAmount;
	PlayerHUD->EucalyptusCountText(EucalyptusCount);
}

void AMyPlayer::RemoveEucalyptus(int eucalyptusAmount)
{
	if (EucalyptusCount - eucalyptusAmount >= 0)
	{
		EucalyptusCount -= eucalyptusAmount;
	}
	else
	{
		EucalyptusCount = 0;
	}

	PlayerHUD->EucalyptusCountText(EucalyptusCount);
}

void AMyPlayer::AddGrapplingHook()
{
	bIsGrapplingHookUnlocked = true;
}

void AMyPlayer::AddClimbingClaw()
{
	bIsClimbingClawUnlocked = true;
}

void AMyPlayer::AddShovel()
{
	bIsShovelUnlocked = true;
}

void AMyPlayer::AddPropeller()
{
	bIsPropellerUnlocked = true;
}

void AMyPlayer::AddMagnetic()
{
	bIsMagneticUnlocked = true;
}

void AMyPlayer::UseAmmo(int ammoAmount)
{
	if (EquippedCurrentAmmo > 0)
	{
		EquippedCurrentAmmo -= ammoAmount;
	}
	else
	{
		EquippedCurrentAmmo = 0;
	}

	PlayerHUD->AmmoCountText(EquippedCurrentAmmo);
	PlayerHUD->AmmoIcon(EquippedAmmoIcon, EquippedCurrentAmmo);
}

void AMyPlayer::PickUpAmmo(int ammoAmount)
{
	if (EquippedCurrentAmmo < EquippedMaxAmmo)
	{
		EquippedCurrentAmmo += ammoAmount;
	}
	else
	{
		EquippedCurrentAmmo = EquippedMaxAmmo;
	}

	PlayerHUD->AmmoCountText(EquippedCurrentAmmo);
	PlayerHUD->AmmoIcon(EquippedAmmoIcon, EquippedCurrentAmmo);
}

void AMyPlayer::EquipAmmo(EAmmoType ammoType)
{
	EquippedAmmoIcon = AmmoIcons[ammoType];
	EquippedMaxAmmo = MaxAmmos[ammoType];
	EquippedCurrentAmmo = CurrentAmmos[ammoType];

	PlayerHUD->AmmoCountText(EquippedCurrentAmmo);
	PlayerHUD->AmmoIcon(EquippedAmmoIcon, EquippedCurrentAmmo);
}

void AMyPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			CurrentIMC = Subsystem;
			Subsystem->ClearAllMappings();
			Subsystem->AddMappingContext(PMainInputMapping, 0);
			Subsystem->AddMappingContext(PAimingInputMapping, 1);
		}
	}

	if (UEnhancedInputComponent* inputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		inputComponent->BindAction(PForwardBack, ETriggerEvent::Triggered, this, &AMyPlayer::MoveForwardBack);
		inputComponent->BindAction(PForwardBack, ETriggerEvent::Completed, this, &AMyPlayer::MoveForwardBack);

		inputComponent->BindAction(PLeftRight, ETriggerEvent::Triggered, this, &AMyPlayer::MoveLeftRight);
		inputComponent->BindAction(PLeftRight, ETriggerEvent::Completed, this, &AMyPlayer::MoveLeftRight);

		inputComponent->BindAction(PTurning, ETriggerEvent::Triggered, this, &AMyPlayer::CamTurn);
		inputComponent->BindAction(PTurning, ETriggerEvent::Completed, this, &AMyPlayer::CamTurn);
		
		inputComponent->BindAction(PJumping, ETriggerEvent::Triggered, this, &AMyPlayer::JumpOne);
		inputComponent->BindAction(PJumping, ETriggerEvent::Completed, this, &AMyPlayer::JumpOne);

		inputComponent->BindAction(PSprint, ETriggerEvent::Triggered, this, &AMyPlayer::IsSprinting);
		inputComponent->BindAction(PSprint, ETriggerEvent::Completed, this, &AMyPlayer::SprintStop);

		inputComponent->BindAction(PInteract, ETriggerEvent::Triggered, this, &AMyPlayer::InteractWith);
		inputComponent->BindAction(PInteract, ETriggerEvent::Completed, this, &AMyPlayer::InteractWith);

		inputComponent->BindAction(PCrouch, ETriggerEvent::Triggered, this, &AMyPlayer::IsCrouching);
		inputComponent->BindAction(PCrouch, ETriggerEvent::Completed, this, &AMyPlayer::CrouchStop);
		
		inputComponent->BindAction(PDodge, ETriggerEvent::Triggered, this, &AMyPlayer::Dodge);
		inputComponent->BindAction(PDodge, ETriggerEvent::Completed, this, &AMyPlayer::Dodge);

		inputComponent->BindAction(PSwim, ETriggerEvent::Triggered, this, &AMyPlayer::Swim);
		inputComponent->BindAction(PSwim, ETriggerEvent::Completed, this, &AMyPlayer::Swim);

		inputComponent->BindAction(PLockTarget, ETriggerEvent::Triggered, this, &AMyPlayer::LockOn);
		inputComponent->BindAction(PLockTarget, ETriggerEvent::Completed, this, &AMyPlayer::LockOn);

		inputComponent->BindAction(PAiming, ETriggerEvent::Triggered, this, &AMyPlayer::Aiming);
		inputComponent->BindAction(PAiming, ETriggerEvent::Completed, this, &AMyPlayer::AimingStop);

		inputComponent->BindAction(PGrappplingHook, ETriggerEvent::Triggered, this, &AMyPlayer::GrapplingHook);
		inputComponent->BindAction(PGrappplingHook, ETriggerEvent::Completed, this, &AMyPlayer::GrapplingHook);

		inputComponent->BindAction(PClimbingClaw, ETriggerEvent::Triggered, this, &AMyPlayer::ClimbingClaw);
		inputComponent->BindAction(PClimbingClaw, ETriggerEvent::Completed, this, &AMyPlayer::ClimbingClaw);

		inputComponent->BindAction(PShovel, ETriggerEvent::Triggered, this, &AMyPlayer::Shovel);
		inputComponent->BindAction(PShovel, ETriggerEvent::Completed, this, &AMyPlayer::Shovel);

		inputComponent->BindAction(PPropeller, ETriggerEvent::Triggered, this, &AMyPlayer::Propeller);
		inputComponent->BindAction(PPropeller, ETriggerEvent::Completed, this, &AMyPlayer::Propeller);

		inputComponent->BindAction(PMagnetic, ETriggerEvent::Triggered, this, &AMyPlayer::Magnetic);
		inputComponent->BindAction(PMagnetic, ETriggerEvent::Completed, this, &AMyPlayer::Magnetic);

	}
}

void AMyPlayer::MoveForwardBack(const FInputActionValue& Value)
{
	if (!bIsAimMode)
	{
		float const Amount = Value.Get<float>();
		FRotator const Rotation = Controller->GetControlRotation();
		FRotator const YawRotation(0, Rotation.Yaw, 0);
		FVector const Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Amount);
		//SetActorRotation(Direction.Rotation());
		//const FRotator NewRotation = FRotationMatrix::MakeFromX(Direction).Rotator();
		//SetActorRotation(NewRotation);
		//FVector const Forward = GetActorForwardVector();

		// Add Animations here with changing of mesh direction 
	}
}

void AMyPlayer::GrapplingHook(const FInputActionValue& Value)
{
}

void AMyPlayer::ClimbingClaw(const FInputActionValue& Value)
{
}

void AMyPlayer::Shovel(const FInputActionValue& Value)
{
}

void AMyPlayer::Propeller(const FInputActionValue& Value)
{
}

void AMyPlayer::Magnetic(const FInputActionValue& Value)
{
}

void AMyPlayer::MoveLeftRight(const FInputActionValue& Value)
{
	float const TurnAmount = Value.Get<float>();
	FRotator const Rotation = Controller->GetControlRotation();
	FRotator const YawRotation(0, Rotation.Yaw, 0);
	FVector const Sideways = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	AddMovementInput(Sideways, TurnAmount);
	//SetActorRotation(Sideways.Rotation());
	//const FRotator NewRotation = FRotationMatrix::MakeFromX(Sideways).Rotator();
	//SetActorRotation(NewRotation);
	// Add Animations here with changing of mesh direction
}

void AMyPlayer::JumpOne(const FInputActionValue& Value)
{
	if (!bIsAimMode)
	{
		Jump();
		// Add Animations here 
	}
}

void AMyPlayer::IsSprinting(const FInputActionValue& Value)
{
	if (!bIsAimMode)
	{
		GetCharacterMovement()->MaxWalkSpeed = SprintSpeed;
		// Reduce Stamina while Sprint held down
		// Change Animation? 
	}
}

void AMyPlayer::SprintStop(const FInputActionValue& Value)
{
	if (!bIsAimMode)
	{
		GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
		// Change Animation  
	}
}

void AMyPlayer::InteractWith(const FInputActionValue& Value)
{
	if (!bIsAimMode)
	{
		// Play Interact Animation.
		// Should use Interfaces or Delegates here
		// Check whether the object we are trying to interact with can be interacted with 
	}
}

void AMyPlayer::IsCrouching(const FInputActionValue& Value)
{
	if (!bIsAimMode)
	{
		GetCharacterMovement()->MaxWalkSpeed = CrouchSpeed;
		// Change Animation

		// For testing Purposes
		CurrentIMC->ClearAllMappings();
		CurrentIMC->AddMappingContext(PWaterInputMapping, 0);
	}
}

void AMyPlayer::CrouchStop(const FInputActionValue& Value)
{
	if (!bIsAimMode)
	{
		GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
		// Change Animation 
	}
}

void AMyPlayer::Dodge(const FInputActionValue& Value)
{
	if (!bIsAimMode)
	{
		if (bDidDodge == false)
		{
			FVector const Forward = GetActorForwardVector();
			//AddMovementInput(Forward, DodgeDistance);
			SetActorLocation(FVector(GetActorLocation().X + DodgeDistance, GetActorLocation().Y, GetActorLocation().Z));
			// Dodge Animation.
		}

		bDidDodge = true;
		// Reset with a timer to be able to activate again 
	}
}

void AMyPlayer::Swim(const FInputActionValue& Value)
{
	if (!bIsAimMode)
	{
		float const SwimDirection = Value.Get<float>();
		FVector const SwimDirectionVector = FVector(0, 0, 1);
		AddMovementInput(SwimDirectionVector, SwimDirection);
		// Add swimming animation here 
	}
}

void AMyPlayer::LockOn(const FInputActionValue& Value)
{
	//Get Closest Target and lock on.
}

void AMyPlayer::Aiming(const FInputActionValue& Value)
{
	//if statement to prevent offset to be applied with each tick
	if (!bIsAimMode) 
	{
		FVector ZoomOffset = FVector(0, 10, 0);
		CameraArm->TargetArmLength = 100;
		CameraArm->AddLocalOffset(ZoomOffset);
		bIsAimMode = true;
	}
}

void AMyPlayer::AimingStop(const FInputActionValue& Value)
{
	FVector ZoomOutOffset = FVector(0, -10, 0);
	CameraArm->AddLocalOffset(ZoomOutOffset);
	CameraArm->TargetArmLength = 200;
	bIsAimMode = false;
}

void AMyPlayer::CamTurn(const FInputActionValue& Value)
{
	float const TurnSpeed = Value.Get<float>();
	AddControllerYawInput(TurnSpeed * RotationSpeed * GetWorld()->GetDeltaSeconds());
}