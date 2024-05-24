/****************************************************************************************
 * Copyright: SteveSloth
 * Name: Elad Saretzky
 * Script: MyPlayerHeadsUpDisplay.cpp
 * Date: May 22, 2024
 * Description: sets up the HUD widgets and allows for the hud blueprint to get values from scripts
 * TODO:
 * Known Bugs:
 *****************************************************************************************/

#include "MyPlayerHeadsUpDisplay.h"

void UMyPlayerHeadsUpDisplay::GrubCountText(int grubAmount)
{
	GrubCountTextBlock->SetText(FText::AsNumber(grubAmount));
}

void UMyPlayerHeadsUpDisplay::EucalyptusCountText(int eucalyptusAmount)
{
	EucalyptusCountTextBlock->SetText(FText::AsNumber(eucalyptusAmount));
}

void UMyPlayerHeadsUpDisplay::AmmoCountText(int ammoAmount)
{
	AmmoCountTextBlock->SetText(FText::AsNumber(ammoAmount));

	if (ammoAmount > 0)
	{
		AmmoCountTextBlock->SetColorAndOpacity(FSlateColor(FLinearColor(1, 1, 1, 1)));
	}
	else
	{
		AmmoCountTextBlock->SetColorAndOpacity(FSlateColor(FLinearColor(1, 0, 0, 1))); 
	}
}

void UMyPlayerHeadsUpDisplay::AmmoIcon(UTexture2D* iconTexture, int ammoAmount)
{
	AmmoIconImageBlock->SetBrushFromTexture(iconTexture);

	if (ammoAmount > 0)
	{
		AmmoIconImageBlock->SetOpacity(100.0f);
	}
	else
	{
		AmmoIconImageBlock->SetOpacity(50.0f);
	}
}