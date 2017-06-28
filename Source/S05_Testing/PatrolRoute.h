// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PatrolRoute.generated.h"


/**
* A Route Card to create paths for AI
*/
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class S05_TESTING_API UPatrolRoute : public UActorComponent
{
	GENERATED_BODY()

public:	
	AActor* GetPatrolPoint(int32_t index) const;

	int32_t GetPatrolLength() const;

protected:

	UPROPERTY(EditInstanceOnly, Category = "Patrol Route")
	TArray<AActor *> PatrolPoints;
	
};
