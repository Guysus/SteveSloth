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
	GrubCount->SetText(FText::AsNumber(grubAmount));
}

void UMyPlayerHeadsUpDisplay::EucalyptusCountText(int eucalyptusAmount)
{
	EucalyptusCount->SetText(FText::AsNumber(eucalyptusAmount));
}