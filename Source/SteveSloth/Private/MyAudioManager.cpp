// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAudioManager.h"
#include "Kismet/GameplayStatics.h"
#include "Components/AudioComponent.h"

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
    // Get all audio components by tag in the level
    TArray<AActor*> AllActors;
    UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName(TEXT("AudioComponent")), AllActors);

    // Loop through and stop each tagged audio component
    for (AActor* Actor : AllActors)
    {
        TArray<UAudioComponent*> AudioComponents;
        Actor->GetComponents<UAudioComponent>(AudioComponents);

        for (UAudioComponent* AudioComp : AudioComponents)
        {
            if (AudioComp && AudioComp->IsPlaying())
            {
                AudioComp->Stop();
            }
        }
    }
}