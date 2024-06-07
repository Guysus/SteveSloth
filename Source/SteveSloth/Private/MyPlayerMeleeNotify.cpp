/****************************************************************************************
 * Copyright: SteveSloth
 * Name: Elad Saretzky
 * Script: MyPlayerMeleeNotify.cpp
 * Date: June 5, 2024
 * Description: Custom Anim Notify for the player melee attack
 * TODO:
 * Known Bugs:
 *****************************************************************************************/

#include "MyPlayerMeleeNotify.h"
#include "MyPlayer.h"

void UMyPlayerMeleeNotify::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	if (MeshComp != NULL && MeshComp->GetOwner() != NULL)
	{
		AMyPlayer* player = Cast<AMyPlayer>(MeshComp->GetOwner());
		if (player != NULL)
		{
			player->StartMeleeAttack();
		}
	}
}

void UMyPlayerMeleeNotify::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	if (MeshComp != NULL && MeshComp->GetOwner() != NULL)
	{
		AMyPlayer* player = Cast<AMyPlayer>(MeshComp->GetOwner());
		if (player != NULL)
		{
			player->EndMeleeAttack();
		}
	}
}
