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

    // Singleton
    static UMyAudioManager* GetInstance();

    // Play sound
    void PlaySound(USoundBase* Sound, FVector Location = FVector::ZeroVector, float VolumeMultiplier = 1.f, float PitchMultiplier = 1.f);

    // Stop sound
    void StopAllSounds();

private:
    // Singleton
    static UMyAudioManager* Instance;
};