// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TP_ThirdPerson/TP_ThirdPersonCharacter.h"
#include "PatrollingGuard.generated.h"

/**
 * 
 */
UCLASS()
class S05_TESTING_API APatrollingGuard : public ATP_ThirdPersonCharacter
{
	GENERATED_BODY()

public:
	AActor* getPatrolPoint(int32_t index);

	int32_t getPatrolPointLength();
	
protected:

	UPROPERTY(EditInstanceOnly, Category = "Patrol Route")
	TArray<AActor*> PatrolPointsCPP;
	
	
};
