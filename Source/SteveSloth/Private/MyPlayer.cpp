/****************************************************************************************
* Copyright: SteveSloth
 * Name: Tammy Boisvert edited by Jeff and Ken
 * Script: MyPlayer.cpp
 * Date: April 23. 2024
 * Description: This is the Player Base Class Script
 * TODO:
 * Known Bugs:
 ****************************************************************************************/

#include "MyPlayer.h"
#include "GameFramework/CharacterMovementComponent.h"

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
	IsMoving = false;
	DidDodge = false;

	// Health Stuff
	MaxHealth = 0;
	CurrentHealth = 0;

	// Collection Stuff
	GrubsCollected = 0;
	CurrentSlingshotAmmo = 0;
	LeavesFound = 0;
	
	// Movement Stuff
	SprintSpeed = 1200;
	CrouchSpeed = 300;
	WalkSpeed = 600;
	DodgeDistance = -100;

	// IMC Inputs
	IMCInputs = Normal;
}

void AMyPlayer::BeginPlay()
{
	Super::BeginPlay();
}

void AMyPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMyPlayer::HitPlayer(float damageAmount)
{
	CurrentHealth = CurrentHealth - damageAmount;
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

		inputComponent->BindAction(PSprint, ETriggerEvent::Triggered, this, &AMyPlayer::Sprint);
		inputComponent->BindAction(PSprint, ETriggerEvent::Completed, this, &AMyPlayer::SprintStop);

		inputComponent->BindAction(PInteract, ETriggerEvent::Triggered, this, &AMyPlayer::InteractWith);
		inputComponent->BindAction(PInteract, ETriggerEvent::Completed, this, &AMyPlayer::InteractWith);

		inputComponent->BindAction(PCrouch, ETriggerEvent::Triggered, this, &AMyPlayer::Crouch);
		inputComponent->BindAction(PCrouch, ETriggerEvent::Completed, this, &AMyPlayer::CrouchStop);
		
		inputComponent->BindAction(PDodge, ETriggerEvent::Triggered, this, &AMyPlayer::Dodge);
		inputComponent->BindAction(PDodge, ETriggerEvent::Completed, this, &AMyPlayer::Dodge);

		inputComponent->BindAction(PSwim, ETriggerEvent::Triggered, this, &AMyPlayer::Swim);
		inputComponent->BindAction(PSwim, ETriggerEvent::Completed, this, &AMyPlayer::Swim);

		inputComponent->BindAction(PLockTarget, ETriggerEvent::Triggered, this, &AMyPlayer::LockOn);
		inputComponent->BindAction(PLockTarget, ETriggerEvent::Completed, this, &AMyPlayer::LockOn);
	}
}

void AMyPlayer::MoveForwardBack(const FInputActionValue& Value)
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
	Jump();
	// Add Animations here
}

void AMyPlayer::Sprint(const FInputActionValue& Value)
{
	GetCharacterMovement()->MaxWalkSpeed = SprintSpeed;
	// Reduce Stamina while Sprint held down
	// Change Animation?
}

void AMyPlayer::SprintStop(const FInputActionValue& Value)
{
	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
	// Change Animation
}

void AMyPlayer::InteractWith(const FInputActionValue& Value)
{
	// Play Interact Animation.
	// Should use Interfaces or Delegates here
	// Check whether the object we are trying to interact with can be interacted with
}

void AMyPlayer::Crouch(const FInputActionValue& Value)
{
	GetCharacterMovement()->MaxWalkSpeed = CrouchSpeed;
	// Change Animation

	// For testing Purposes
	CurrentIMC->ClearAllMappings();
	CurrentIMC->AddMappingContext(PWaterInputMapping, 0);
}

void AMyPlayer::CrouchStop(const FInputActionValue& Value)
{
	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
	// Change Animation
}

void AMyPlayer::Dodge(const FInputActionValue& Value)
{
	if (DidDodge == false)
	{
		FVector const Forward = GetActorForwardVector();
		//AddMovementInput(Forward, DodgeDistance);
		SetActorLocation(FVector(GetActorLocation().X + DodgeDistance, GetActorLocation().Y,GetActorLocation().Z));
		// Dodge Animation.
	}
	
	DidDodge = true;
	// Reset with a timer to be able to activate again
}

void AMyPlayer::Swim(const FInputActionValue& Value)
{
	float const SwimDirection = Value.Get<float>();
	FVector const SwimDirectionVector = FVector(0, 0, 1);
	AddMovementInput(SwimDirectionVector, SwimDirection);
	// Add swimming animation here
}

void AMyPlayer::LockOn(const FInputActionValue& Value)
{
	//Get Closest Target and lock on.
}

void AMyPlayer::CamTurn(const FInputActionValue& Value)
{
	float const TurnSpeed = Value.Get<float>();
	AddControllerYawInput(TurnSpeed * RotationSpeed * GetWorld()->GetDeltaSeconds());
}