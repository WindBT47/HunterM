// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "ChoseNextWayPoint.generated.h"

/**
 * 
 */
UCLASS()
class HUNTERM_API UChoseNextWayPoint : public UBTTaskNode
{
	GENERATED_BODY()

public:

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

protected:

	UPROPERTY(EditAnywhere, category = "Blackboard")
	struct FBlackboardKeySelector IndexKey;

	UPROPERTY(EditAnywhere, category = "Blackboard")
	struct FBlackboardKeySelector WayPointKey;

	TArray<AActor*> GetPatrolPoints(UBehaviorTreeComponent& OwnerComp);

	int32 SetPatrolPoint(UBlackboardComponent* BlackboardCom, TArray<AActor*> PatrolPoints);

	void CycleIndex(int32 Index, UBlackboardComponent* BlackboardCom, TArray<AActor*> PatrolPoints);

};
