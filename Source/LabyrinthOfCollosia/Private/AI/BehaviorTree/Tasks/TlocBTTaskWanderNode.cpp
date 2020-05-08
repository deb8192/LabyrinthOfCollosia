// Fill out your copyright notice in the Description page of Project Settings.


#include "../Public/AI/BehaviorTree/Tasks/TlocBTTaskWanderNode.h"
#include "BehaviorTree/BlackBoardComponent.h"
#include "../Public/Characters/TlocEnemy.h"
#include "../Public/GlobalConstants.h"


EBTNodeResult::Type UTlocBTTaskWanderNode::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);
	ATlocEnemy* _enemy = dynamic_cast<ATlocEnemy*>(OwnerComp.GetOwner()->GetInstigator());
	GlobalConstants constants;

	if (_enemy)
	{
		_enemy->Wander();
		return EBTNodeResult::Succeeded;
	}
	else return EBTNodeResult::Aborted;
}
