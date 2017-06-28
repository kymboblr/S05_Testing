// Fill out your copyright notice in the Description page of Project Settings.

#include "ChooseNextWaypoint.h"
#include "PatrolRoute.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) {
	
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	int32_t Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);

	//Get the next waypoint
	auto PatrolRoute = OwnerComp.GetAIOwner()->GetPawn()->FindComponentByClass<UPatrolRoute>();

	if(!ensure(PatrolRoute)){
		return EBTNodeResult::Failed;
	}
	if(PatrolRoute->GetPatrolLength() == 0){
		UE_LOG(LogTemp, Warning, TEXT("A guard is missing patrolpoints"));
		return EBTNodeResult::Failed;
	}

	auto NextWaypoint = PatrolRoute->GetPatrolPoint(Index);

	//Set the next waypoint in Blackboard
	BlackboardComp->SetValueAsObject(NextWaypointKey.SelectedKeyName, NextWaypoint);

	//Cycle the waypoint index
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, (Index + 1) % PatrolRoute->GetPatrolLength());

	return EBTNodeResult::Succeeded;
}


