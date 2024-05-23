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

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "MyPlayerHeadsUpDisplay.generated.h"

UCLASS(Abstract)
class STEVESLOTH_API UMyPlayerHeadsUpDisplay : public UUserWidget
{
	GENERATED_BODY()
	
protected: //WIDGET VARIABLES
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UTextBlock* GrubCount;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UTextBlock* EucalyptusCount;

public: //PUBLIC FUNCTIONS
	void GrubCountText(int grubAmount);
	void EucalyptusCountText(int eucalyptusAmount);
};
