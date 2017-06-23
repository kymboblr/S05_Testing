// Fill out your copyright notice in the Description page of Project Settings.

#include "ChooseNextWaypoint.h"
#include "PatrollingGuard.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) {
	
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	int32_t Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);

	//Get the next waypoint
	auto PatrollingGuard = Cast<APatrollingGuard>(OwnerComp.GetAIOwner()->GetControlledPawn());
	auto NextWaypoint = PatrollingGuard->getPatrolPoint(Index);

	//Set the next waypoint in Blackboard
	BlackboardComp->SetValueAsObject(NextWaypointKey.SelectedKeyName, NextWaypoint);

	//Cycle the waypoint index
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, (Index + 1) % PatrollingGuard->getPatrolPointLength());

	return EBTNodeResult::Succeeded;
}


