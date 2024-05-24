/****************************************************************************************
* Copyright: SteveSloth
 * Name: Ken Ferris, Edited by Jeff Moreau
 * Script: MyAudioManager.h
 * Date: April 24. 2024
 * Description: This is the Audio Manager class
 * TODO:
 * Known Bugs:
 ****************************************************************************************/

#pragma once

// INCLUDES HERE
#include "CoreMinimal.h"
#include "Sound/SoundBase.h"
#include "Engine/GameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Components/AudioComponent.h"

// MAKE SURE THIS INCLUDE IS LAST
#include "MyAudioManager.generated.h"

UCLASS()
class STEVESLOTH_API UMyAudioManager : public UGameInstance
{
    GENERATED_BODY()

public:// SINGLETON STUFF
    static UMyAudioManager* pInstance;
    static UMyAudioManager* GetInstance();
    UMyAudioManager* Instance();

protected: // PROTECTED DETAILS PANEL VARIABLES 
    UPROPERTY(EditAnywhere, Category = "Audio")
    TMap<FString, USoundBase*> SoundEffectsMap;

    UPROPERTY(EditAnywhere, Category = "Audio")
    TMap<FString, USoundBase*> MusicMap;

public:	// CONSTRUCTOR HERE
    UMyAudioManager();

public:	// UPDATE ACCESS ANYWHERE FUNCTIONS
    void PlaySound(USoundBase* Sound, FVector Location = FVector::ZeroVector, float VolumeMultiplier = 1.f, float PitchMultiplier = 1.f);
    void StopAllSounds();
};