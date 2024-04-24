// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyEnemy.generated.h"

/**
 * 
 */
class STEVESLOTH_API MyEnemy
{
public:
	float MaxHealth;
	float CurrentHealth;
	int Damage;
	enum MovementState {Idle, Patrolling, Chasing, Fleeing, Walking};
	enum AttackType {Melee, Ranged};
	enum Level {One, Two, Three, Four, Five};
	float MoveSpeed;
	bool IsDead;

	MyEnemy(float MaxHealth, float CurrentHealth, int Damage, enum MovementState, enum AttackType, enum Level, float MoveSpeed, bool IsDead);
	~MyEnemy();


};
