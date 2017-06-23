// Fill out your copyright notice in the Description page of Project Settings.

#include "PatrollingGuard.h"


AActor* APatrollingGuard::getPatrolPoint(int32_t index) {
	return PatrolPointsCPP.IsValidIndex(index) ? PatrolPointsCPP[index] : nullptr;
}

int32_t APatrollingGuard::getPatrolPointLength() {
	return PatrolPointsCPP.Num();
}
