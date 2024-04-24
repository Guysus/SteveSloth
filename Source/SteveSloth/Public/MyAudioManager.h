/****************************************************************************************
* Copyright: SteveSloth
 * Name: Ken Ferris
 * Script: MyAudioManager.h
 * Date: April 24. 2024
 * Description: This is the Audio Manager class
 * TODO:
 * Known Bugs:
 ****************************************************************************************/

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Sound/SoundBase.h"
#include "MyAudioManager.generated.h"

UCLASS()
class STEVESLOTH_API UMyAudioManager : public UGameInstance
{
    GENERATED_BODY()

public:
    UMyAudioManager();

    // Singleton
    static UMyAudioManager* GetInstance();

    // Play sound
    void PlaySound(USoundBase* Sound, FVector Location = FVector::ZeroVector, float VolumeMultiplier = 1.f, float PitchMultiplier = 1.f);

    // Stop sound
    void StopAllSounds();

    // Exposed map for sound effects
    UPROPERTY(EditAnywhere, Category = "Audio")
    TMap<FString, USoundBase*> SoundEffectsMap;

    // Exposed map for music
    UPROPERTY(EditAnywhere, Category = "Audio")
    TMap<FString, USoundBase*> MusicMap;

private:
    // Singleton
    static UMyAudioManager* Instance;
};