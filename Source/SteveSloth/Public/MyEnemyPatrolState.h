/****************************************************************************************
* Copyright: SteveSloth
 * Name:
 * Script: MyEnemyPatrolState.h
 * Date: May.03/2024
 * Description: this is the header file for the enemy patrol state that handles what enemies do when in the patrol state
 * TODO:
 * Known Bugs:
 ****************************************************************************************/
//#pragma once
//
// // INCLUDES HERE
//#include "CoreMinimal.h"
//#include "MyEnemyBaseClass.h"
//#include "MyEnemyBaseState.h"
//#include "Components/SplineComponent.h"
//#include "Components/SkeletalMeshComponent.h"
//
//// MAKE SURE THIS INCLUDE IS LAST
//#include "MyEnemyPatrolState.generated.h"
//
//UCLASS(Blueprintable)
//class STEVESLOTH_API UMyEnemyPatrolState : public UMyEnemyBaseState
//{
//	GENERATED_BODY()
//
//private:
//	AMyEnemyBaseClass* PMyself;
//	USkeletalMeshComponent* PMyMesh;
//	USplineComponent* PMySpline;
//	float Speed;
//	bool IsAnimationRunning;
//	
//public: // PUBLIC FUNCTIONS 
//	virtual void EnterState() override;
//	virtual void ExitState() override;
//	virtual void UpdateState(float deltaTime) override;
//	virtual void SetEnemyBaseClass(AMyEnemyBaseClass* myEnemy) override;
//	virtual void SetEnemyMesh(USkeletalMeshComponent* mesh) override;
//
//	void SetEnemySpline(USplineComponent* spline) { PMySpline = spline; }
//};
