/****************************************************************************************
 * Copyright: SteveSloth
 * Name: Ken Ferris
 * Script: MyEnemyAttackingState.cpp
 * Date: May 3, 2024
 * Description: This is the logic for the enemy attack and handles actions within that state
 * TODO:
 * Known Bugs:
 ****************************************************************************************/


#include "MyEnemyAttackingState.h"

void UMyEnemyAttackingState::EnterState()
{
    Player = USteveSingleton::GetSteve()->GetPlayerCharacter();

    Enemy = Cast<AMyEnemyBaseClass>(GetOuter());
}

void UMyEnemyAttackingState::ExitState()
{

}

void UMyEnemyAttackingState::UpdateState(float deltaTime)
{
    if (Player)
    {
        // Select and perform attack based on distance
        SelectAttack();
    }
}

void UMyEnemyAttackingState::SelectAttack()
{
    
}

void UMyEnemyAttackingState::PerformMeleeAttack()
{
    // Check if melee attack montage is valid
    if (MeleeAttackMontage)
    {
       
    }

    // Apply melee attack damage to the player
    if (Player)
    {
       
    }
}

void UMyEnemyAttackingState::PerformRangedAttack()
{
    // Check if ranged attack montage is valid
    if (RangedAttackMontage)
    {
        
    }

    // Apply ranged attack damage to the player
    if (Player)
    {
        
    }
}