/****************************************************************************************
* Copyright: SteveSloth
 * Name:
 * Script: MyEnemyPatrolState.h
 * Date: May.03/2024
 * Description: this is the header file for the enemy patrol state that handles what enemies do when in the patrol state
 * TODO:
 * Known Bugs:
 ****************************************************************************************/
#pragma once

 // INCLUDES HERE
#include "CoreMinimal.h"
#include "MyEnemyBaseState.h"
#include "Components/SplineComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/TimelineComponent.h"

// MAKE SURE THIS INCLUDE IS LAST
#include "MyEnemyPatrolState.generated.h"

UCLASS(Blueprintable)
class STEVESLOTH_API UMyEnemyPatrolState : public UMyEnemyBaseState
{
	GENERATED_BODY()
	
public: // INHERITED FUNCTIONS 
	virtual void EnterState() override;
	virtual void ExitState() override;
	virtual void UpdateState(float deltaTime) override;

//private: // PRIVATE VARIABLES
	
public: // DETAILS PANEL VARIABLES

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spline")
	USplineComponent* PSplineComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
	USkeletalMeshComponent* PSkeletalMeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Speed")
	float MovementVelocity;

private: // PRIVATE INTERNAL FUNCTIONS

	void ProcessMovement(float value);

	void OnEndMovement();
};
