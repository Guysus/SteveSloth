// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAudioManager.h"
#include "Kismet/GameplayStatics.h"

UMyAudioManager* UMyAudioManager::Instance = nullptr;

UMyAudioManager::UMyAudioManager()
{
    // Initialize the instance
    Instance = this;
}

UMyAudioManager* UMyAudioManager::GetInstance()
{
    return Instance;
}

void UMyAudioManager::PlaySound(USoundBase* Sound, FVector Location, float VolumeMultiplier, float PitchMultiplier)
{
    if (Sound)
    {
        UGameplayStatics::PlaySoundAtLocation(GetWorld(), Sound, Location, VolumeMultiplier, PitchMultiplier);
    }
}

void UMyAudioManager::StopAllSounds()
{
    
}