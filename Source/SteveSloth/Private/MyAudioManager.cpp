/****************************************************************************************
* Copyright: SteveSloth
 * Name: Ken Ferris
 * Script: MyAudioManager.cpp
 * Date: April 24. 2024
 * Description: This is the Audio Manager class
 * TODO:
 * Known Bugs:
 ****************************************************************************************/

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