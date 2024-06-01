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
	bDidGrapple = false;
	bIsShovelUnlocked = false;
	bIsMagneticUnlocked = false;
	bIsGrapplingUnlocked = false;
	bIsPropellerUnlocked = false;
	bIsClimbingClawUnlocked = true;

	// Health Stuff
	MaxHealth = 0;
	CurrentHealth = 0;

	// Collection Stuff
	LeavesFound = 0;
	
	// Movement Stuff
	WalkSpeed = 250;
	SprintSpeed = 400;
	CrouchSpeed = 250;
	DodgeDistance = -100;

	// IMC Inputs
	IMCInputs = Normal;

	
}

void AMyPlayer::BeginPlay()
{
	Super::BeginPlay();
	
	if (!AmmoDataTable.IsNull())
	{
		AmmoDataTable.DataTable->GetAllRows("", Ammos);

		for (int i = 0; i < Ammos.Num(); i++)
		{
			CurrentAmmos.AddUninitialized();
			AmmoIcons.Add(Ammos[i]->AmmoIcon);
			MaxAmmos.Add(Ammos[i]->MaxAmmo);
			CurrentAmmos[i] = MaxAmmos[i];

			EquippedMaxAmmo = MaxAmmos[Pebble];
			EquippedAmmoIcon = AmmoIcons[Pebble];
			EquippedCurrentAmmo = CurrentAmmos[Pebble];
		}
	}

	if (PlayerHUDClass)
	{
		PlayerHUD = CreateWidget<UMyPlayerHeadsUpDisplay>(UGameplayStatics::GetPlayerController(GetWorld(), 0), PlayerHUDClass);

		if (PlayerHUD)
		{
			PlayerHUD->AddToPlayerScreen();

			PlayerHUD->GrubCountText(GrubCount);
			PlayerHUD->EucalyptusCountText(EucalyptusCount);

			if (!AmmoDataTable.IsNull())
			{
				PlayerHUD->AmmoCountText(EquippedCurrentAmmo);
				PlayerHUD->AmmoIcon(EquippedAmmoIcon, EquippedCurrentAmmo);
			}
		}
	}
}

void AMyPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bDidGrapple)
	{
		SetActorLocation(FMath::VInterpTo(GetActorLocation(), GrappleHitLocation, DeltaTime, InterpSpeed));

		if (GrappleStartLocation == GrappleHitLocation)
		{
			UE_LOG(LogTemp, Warning, TEXT("Grapple Over"));
			//InteractOver();
		}
	}
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

		inputComponent->BindAction(PCamPitch, ETriggerEvent::Triggered, this, &AMyPlayer::CamPitch);
		inputComponent->BindAction(PCamPitch, ETriggerEvent::Completed, this, &AMyPlayer::CamPitch);
		
		inputComponent->BindAction(PJumping, ETriggerEvent::Triggered, this, &AMyPlayer::JumpOne);
		inputComponent->BindAction(PJumping, ETriggerEvent::Completed, this, &AMyPlayer::JumpOne);

		inputComponent->BindAction(PSprint, ETriggerEvent::Triggered, this, &AMyPlayer::IsSprinting);
		inputComponent->BindAction(PSprint, ETriggerEvent::Completed, this, &AMyPlayer::SprintStop);

		inputComponent->BindAction(PInteract, ETriggerEvent::Triggered, this, &AMyPlayer::InteractWith);
		inputComponent->BindAction(PInteract, ETriggerEvent::Completed, this, &AMyPlayer::InteractOver);

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

		inputComponent->BindAction(PSwitchAbilities, ETriggerEvent::Triggered, this, &AMyPlayer::SwitchAbilities);
		inputComponent->BindAction(PSwitchAbilities, ETriggerEvent::Completed, this, &AMyPlayer::SwitchAbilities);
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

void AMyPlayer::SwitchAbilities(const FInputActionValue& Value)
{
}

void AMyPlayer::GrapplingHook()
{
	if (bIsGrapplingUnlocked)
	{
		// FHitResult will hold all data returned by our line collision query
		FHitResult Hit;

		// We set up a line trace from our current location to a point 1000cm ahead of us
		TraceStart = GetActorLocation();
		TraceEnd = GetActorLocation() + GetActorForwardVector() * 1000.0f;

		// You can use FCollisionQueryParams to further configure the query
		// Here we add ourselves to the ignored list so we won't block the trace
		FCollisionQueryParams QueryParams;
		QueryParams.AddIgnoredActor(this);

		// To run the query, you need a pointer to the current level, which you can get from an Actor with GetWorld()
		// UWorld()->LineTraceSingleByChannel runs a line trace and returns the first actor hit over the provided collision channel.
		GetWorld()->LineTraceSingleByChannel(Hit, TraceStart, TraceEnd, TraceChannelProperty, QueryParams);

		// You can use DrawDebug helpers and the log to help visualize and debug your trace queries.
		DrawDebugLine(GetWorld(), TraceStart, TraceEnd, Hit.bBlockingHit ? FColor::Blue : FColor::Red, false, 5.0f, 0, 10.0f);
		UE_LOG(LogTemp, Log, TEXT("Tracing line: %s to %s"), *TraceStart.ToCompactString(), *TraceEnd.ToCompactString());

		bDidGrapple = Hit.bBlockingHit;

		if (bDidGrapple)
		{
			GrappleStartLocation = TraceStart;
			GrappleHitLocation = Hit.GetActor()->GetActorLocation();
		}
	}
}

void AMyPlayer::AddGrapplingHook()
{
	bIsGrapplingUnlocked = true;
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

void AMyPlayer::ClimbingClaw()
{
	if (bIsClimbingClawUnlocked)
	{

	}
}

void AMyPlayer::Shovel()
{
}

void AMyPlayer::Propeller()
{
}

void AMyPlayer::Magnetic()
{
}

void AMyPlayer::GrappleOver()
{
	bDidGrapple = false;
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

void AMyPlayer::InteractOver(const FInputActionValue& Value)
{
	GetWorldTimerManager().SetTimer(GrappleTimerHandle, this,
		&AMyPlayer::GrappleOver, GRAPPLE_TIMER_AMOUNT, false);
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

void AMyPlayer::CamPitch(const FInputActionValue& Value)
{
	float const TurnSpeed = Value.Get<float>();
	AddControllerPitchInput(TurnSpeed * PitchSpeed * GetWorld()->GetDeltaSeconds());
}