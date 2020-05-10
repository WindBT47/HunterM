// Fill out your copyright notice in the Description page of Project Settings.


#include "ChoseNextWayPoint.h"
#include "AIController.h"
#include "PatrolRoute.h"
#include "..\Public\ChoseNextWayPoint.h"
#include "BehaviorTree\BlackboardComponent.h"

EBTNodeResult::Type UChoseNextWayPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	auto BlackboardCom = OwnerComp.GetBlackboardComponent();
	
	auto PatrolPoints = GetPatrolPoints(OwnerComp);

	if (PatrolPoints.Num() == 0) { return EBTNodeResult::Failed; }

	int32 Index = SetPatrolPoint(BlackboardCom, PatrolPoints);
	
	CycleIndex(Index, BlackboardCom, PatrolPoints);

	return EBTNodeResult::Succeeded;
}

TArray<AActor*> UChoseNextWayPoint::GetPatrolPoints(UBehaviorTreeComponent& OwnerComp)
{
	auto ControlledPawn = OwnerComp.GetAIOwner()->GetPawn();
	auto PatrolRoute = ControlledPawn->FindComponentByClass<UPatrolRoute>();
	TArray<AActor*> PatrolPoints;
	if (!ensure(PatrolRoute)) { return PatrolPoints; }

	PatrolPoints = PatrolRoute->GetPatrolPoints();

	return PatrolPoints;
}

int32 UChoseNextWayPoint::SetPatrolPoint(UBlackboardComponent* BlackboardCom, TArray<AActor*> PatrolPoints)
{
	int32 Index = BlackboardCom->GetValueAsInt(IndexKey.SelectedKeyName);
	BlackboardCom->SetValueAsObject(WayPointKey.SelectedKeyName, PatrolPoints[Index]);
	return Index;
}

void UChoseNextWayPoint::CycleIndex(int32 Index, UBlackboardComponent* BlackboardCom, TArray<AActor*> PatrolPoints)
{
	Index = (Index + 1) % PatrolPoints.Num();
	BlackboardCom->SetValueAsInt(IndexKey.SelectedKeyName, Index);
}
