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


#include "MyEnemy.h"

MyEnemy::MyEnemy()
{
	MaxHealth = 0;
	CurrentHealth = 0;
	Damage = 0;
	MovementState = Idle;
	AttackType = Melee;
	Level = One;
	MoveSpeed = 0;
	IsDead = false;
}

MyEnemy::~MyEnemy()
{
}
