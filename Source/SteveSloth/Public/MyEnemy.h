/****************************************************************************************

Copyright: SteveSloth

Name: Aidan

Script: MyEnemy.cpp

Date: April 23. 2024

Description: This is the base class for all Enemies.

TODO:

Known Bugs:

TODO:

Known Bugs:
****************************************************************************************/

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyEnemy.generated.h"

/**
 * 
 */

enum MovementState {Idle, Patrolling, Chasing, Fleeing, Walking};
enum AttackType {Melee, Ranged};
enum Level {One, Two, Three, Four, Five};

class STEVESLOTH_API MyEnemy
{
public:
	float MaxHealth;
	float CurrentHealth;
	int Damage;

	float MoveSpeed;
	bool IsDead;

	MyEnemy();
	~MyEnemy();


};
