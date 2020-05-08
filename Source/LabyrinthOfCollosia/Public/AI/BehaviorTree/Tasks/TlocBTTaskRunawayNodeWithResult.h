// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_FinishWithResult.h"
#include "TlocBTTaskRunawayNodeWithResult.generated.h"

/**
 *
 */
UCLASS()
class LABYRINTHOFCOLLOSIA_API UTlocBTTaskRunawayNodeWithResult : public UBTTask_FinishWithResult
{
	GENERATED_BODY()

protected:
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UPROPERTY()
		FName blackBoardKeyName = FName("DetectedPlayer");
};