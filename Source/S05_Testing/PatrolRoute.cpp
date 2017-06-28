// Fill out your copyright notice in the Description page of Project Settings.

#include "PatrolRoute.h"


AActor* UPatrolRoute::GetPatrolPoint(int32_t index) const {
	return PatrolPoints.IsValidIndex(index) ? PatrolPoints[index] : nullptr;
}

int32_t UPatrolRoute::GetPatrolLength() const {
	return PatrolPoints.Num();
}

