/****************************************************************************************
* Copyright: SteveSloth
 * Name: Ken Ferris, Edited by Jeff Moreau
 * Script: MyAudioManager.cpp
 * Date: April 24. 2024
 * Description: This is the Audio Manager class
 * TODO:
 * Known Bugs:
 ****************************************************************************************/

#include "MyAudioManager.h"

UMyAudioManager* UMyAudioManager::pInstance = nullptr;

UMyAudioManager* UMyAudioManager::Instance()
{
    if (pInstance == nullptr)
    {
        pInstance = this;
    }

    return pInstance;
}

UMyAudioManager* UMyAudioManager::GetInstance()
{
    return pInstance;
}

UMyAudioManager::UMyAudioManager()
{

}

void UMyAudioManager::PlaySound(USoundBase* Sound, FVector Location, float VolumeMultiplier, float PitchMultiplier)
{
    if (Sound != nullptr)
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
            if (AudioComp != nullptr && AudioComp->IsPlaying())
            {
                AudioComp->Stop();
            }
        }
    }
}