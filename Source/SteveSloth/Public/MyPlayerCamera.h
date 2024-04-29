/****************************************************************************************
* Copyright: SteveSloth
 * Name: Jeff Moreau
 * Script: MyPlayerCamera.h
 * Date: April 29. 2024
 * Description: The Main Camera that follows the player around
 * TODO:
 * Known Bugs:
 ****************************************************************************************/

#pragma once

// INCLUDES HERE
#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Actor.h"

// MAKE SURE THIS INCLUDE IS LAST
#include "MyPlayerCamera.generated.h"

UCLASS()
class STEVESLOTH_API AMyPlayerCamera : public AActor
{
	GENERATED_BODY()

public: // DETAILS PANEL VARIABLES (UPROPERTY) NEED TO BE PUBLIC
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UCameraComponent* PCamera;
	
public:	// CONSTRUCTOR
	AMyPlayerCamera();

protected: // SETUP FUNCTIONS
	virtual void BeginPlay() override;

public:	// UPDATE FUNCTIONS
	virtual void Tick(float DeltaTime) override;
};