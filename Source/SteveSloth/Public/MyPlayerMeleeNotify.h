/****************************************************************************************
 * Copyright: SteveSloth
 * Name: Elad Saretzky
 * Script: MyPlayerMeleeNotify.h
 * Date: June 5, 2024
 * Description: Custom Anim Notify for the player melee attack
 * TODO:
 * Known Bugs:
 *****************************************************************************************/

#pragma once

// INCLUDES HERE
#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"

// MAKE SURE THIS INCLUDE IS LAST
#include "MyPlayerMeleeNotify.generated.h"

UCLASS()
class STEVESLOTH_API UMyPlayerMeleeNotify : public UAnimNotifyState
{
	GENERATED_BODY()
	
public: //PUBLIC ACCESS ANYWHERE FUNCTIONS
	virtual void NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference) override;
	virtual void NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;
};
