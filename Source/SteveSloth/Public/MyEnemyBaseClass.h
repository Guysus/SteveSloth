/****************************************************************************************
 * Copyright: SteveSloth
 * Name: Tammy Jeff Moreau
 * Script: MyEnemyBaseClass.h
 * Date: April 29. 2024
 * Description: Base Class for all enemies to inherit from
 * TODO:
 * Known Bugs:
 ****************************************************************************************/
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyEnemyBaseClass.generated.h"

UCLASS()
class STEVESLOTH_API AMyEnemyBaseClass : public ACharacter
{
	GENERATED_BODY()

public:
	AMyEnemyBaseClass();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};