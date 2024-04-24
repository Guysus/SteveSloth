// Fill out your copyright notice in the Description page of Project Settings.


#include "MyEnemy.h"

MyEnemy::MyEnemy(float MaxHealth, float CurrentHealth, int Damage, enum MovementState, enum AttackType, enum Level, float MoveSpeed, bool IsDead)
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
