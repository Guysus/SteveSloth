/****************************************************************************************
 * Copyright: SteveSloth
 * Name: Tammy, Elad Saretzky, Jeff Moreau
 * Script: MyEnemyBaseClass.h
 * Date: April 29. 2024
 * Description: Base Class for all enemies to inherit from
 * TODO: Add more Variables (such as animations)
 * Known Bugs:
 ****************************************************************************************/
#pragma once

// INCLUDES HERE
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/SplineComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "SteveSingleton.h"
#include "MyEnemyStateComponent.h"

// MAKE SURE THIS INCLUDE IS LAST
#include "MyEnemyBaseClass.generated.h"

// ENUMS HERE

UENUM(BlueprintType)
enum class EAttackType
{
	Melee UMETA(DisplayName = "Melee"),
	Range UMETA(DisplayName = "Range"),
	MeleeAndRange UMETA(DisplayName = "Melee And Range")
};

UCLASS()
class STEVESLOTH_API AMyEnemyBaseClass : public ACharacter
{
	GENERATED_BODY()
private: //PRIVATE CONST VARIABLES
	const float DESPAWN_TIMER_AMOUNT = 2.0f;

protected: // PROTECTED VARIABLES 
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UMyEnemyStateComponent* StateMachine;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack Stats")
	TEnumAsByte<EAttackType> AttackType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack Stats") 
	float AttackRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack Stats")
	float Damage;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")	
	float MovementSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	FTransform StartingLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float MaxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spline")
	USplineComponent* MySpline;

	ACharacter* Player; 

	bool IsDead;

	FTimerHandle DespawnTimerHandle;

public: // PUBLIC VARIABLES
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animations")
	UAnimationAsset* IdleAnim;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animations")
	UAnimationAsset* MoveAnim;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animations")
	UAnimationAsset* AttackAnim;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animations")
	UAnimationAsset* RangedAttackAnim;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animations")
	UAnimationAsset* HitAnim;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animations")
	UAnimationAsset* DeathAnim;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animations")
	UAnimationAsset* Dead;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animations")
	UAnimationAsset* Move;

	float GetMovementSpeed() const { return MovementSpeed; }

	float CurrentHealth;

public:	// CONSTRUCTOR HERE
	AMyEnemyBaseClass();

protected: // SETUP FUNCTIONS
	virtual void BeginPlay() override;

public:	// UPDATE FUNCTIONS
	virtual void Tick(float DeltaTime) override;

private: // PRIVATE INTERNAL FUNCTIONS
	void Despawn();
};