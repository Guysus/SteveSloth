// Fill out your copyright notice in the Description page of Project Settings.

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

    // Singleton pattern
    static UMyAudioManager* GetInstance();

    // Play a sound
    void PlaySound(USoundBase* Sound, FVector Location = FVector::ZeroVector, float VolumeMultiplier = 1.f, float PitchMultiplier = 1.f);

    // Stop all sounds
    void StopAllSounds();

private:
    // Singleton instance
    static UMyAudioManager* Instance;
};