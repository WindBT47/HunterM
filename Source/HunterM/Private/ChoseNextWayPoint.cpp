// Fill out your copyright notice in the Description page of Project Settings.


#include "ChoseNextWayPoint.h"
#include "AIController.h"
#include "PatrollingGuard.h"
#include "..\Public\ChoseNextWayPoint.h"
#include "BehaviorTree\BlackboardComponent.h"

EBTNodeResult::Type UChoseNextWayPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	auto BlackboardCom = OwnerComp.GetBlackboardComponent();
	
	auto PatrolPoints = GetPatrolPoints(OwnerComp);

	int32 Index = SetPatrolPoint(BlackboardCom, PatrolPoints);
	
	CycleIndex(Index, BlackboardCom, PatrolPoints);
	//UE_LOG(LogTemp,Warning,TEXT("%i"),Index)
	return EBTNodeResult::Succeeded;
}

TArray<AActor*> UChoseNextWayPoint::GetPatrolPoints(UBehaviorTreeComponent& OwnerComp)
{
	auto AIController = OwnerComp.GetAIOwner();
	auto ControlledPawn = AIController->GetPawn();
	auto PatrollingGuard = Cast<APatrollingGuard>(ControlledPawn);
	auto PatrolPoints = PatrollingGuard->PatrolPointsCPP;
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
