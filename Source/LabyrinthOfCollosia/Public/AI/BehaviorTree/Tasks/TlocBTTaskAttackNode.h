// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "TlocBTTaskAttackNode.generated.h"

/**
 * 
 */
UCLASS()
class LABYRINTHOFCOLLOSIA_API UTlocBTTaskAttackNode : public UBTTaskNode
{
	GENERATED_BODY()
	
protected:
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
