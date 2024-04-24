/****************************************************************************************
* Copyright: SteveSloth
 * Name: Brandon Thomas
 * Script: SlingshotAmmoBaseClass.cpp
 * Date: April 23. 2024
 * Description: This is the base cpp class for all ammo types
 * TODO:
 * Known Bugs:
 ****************************************************************************************/



#include "SlingshotAmmoBaseClass.h"

// Sets default values for this component's properties
USlingshotAmmoBaseClass::USlingshotAmmoBaseClass()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	Damage = 0;
	AreaOfEffect = false;
	AOEDamage = 0;
	AOERadius = 0;
	DamageOverTime = false;
	DOTDamage = 0;
	DOTDuration = 0;
	MaxAmmoCapacity = false;
	DropRate = 0;
	FireRate = 0;
	CanBeUsedInPuzzle = false;
}


// Called when the game starts
void USlingshotAmmoBaseClass::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void USlingshotAmmoBaseClass::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

