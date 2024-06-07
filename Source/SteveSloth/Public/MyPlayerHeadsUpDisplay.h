/****************************************************************************************
 * Copyright: SteveSloth
 * Name: Elad Saretzky
 * Script: MyPlayerHeadsUpDisplay.h
 * Date: May 22, 2024
 * Description: sets up the HUD widgets and allows for the hud blueprint to get values from scripts
 * TODO:
 * Known Bugs:
 *****************************************************************************************/

#pragma once

// INCLUDES HERE
#include "CoreMinimal.h"
#include "Components/Image.h"
#include "Styling/SlateColor.h"
#include "Components/TextBlock.h"
#include "Blueprint/UserWidget.h"
#include "Components/ProgressBar.h"

// MAKE SURE THIS INCLUDE IS LAST
#include "MyPlayerHeadsUpDisplay.generated.h"

UCLASS(Abstract)
class STEVESLOTH_API UMyPlayerHeadsUpDisplay : public UUserWidget
{
	GENERATED_BODY()
	
protected: //WIDGET VARIABLES
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UTextBlock* GrubCountTextBlock;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UTextBlock* EucalyptusCountTextBlock;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UTextBlock* AmmoCountTextBlock;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UImage* AmmoIconImageBlock;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UProgressBar* HealthBar;

public:	// PUBLIC ACCESS ANYWHERE FUNCTIONS
	void GrubCountText(int grubAmount);
	void EucalyptusCountText(int eucalyptusAmount);
	void AmmoCountText(int ammoAmount);
	void AmmoIcon(UTexture2D* iconTexture, int ammoAmount);
	void HealthBarAmount(float currentHealth, float maxHealth);
};