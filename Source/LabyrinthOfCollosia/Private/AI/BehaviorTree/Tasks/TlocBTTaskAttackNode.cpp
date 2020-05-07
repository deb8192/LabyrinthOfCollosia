// Fill out your copyright notice in the Description page of Project Settings.


#include "../Public/AI/BehaviorTree/Tasks/TlocBTTaskAttackNode.h"
#include "../Public/Characters/TlocEnemy.h"
#include "../Public/GlobalConstants.h"

EBTNodeResult::Type UTlocBTTaskAttackNode::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) 
{
	GlobalConstants constants;
	Super::ExecuteTask(OwnerComp, NodeMemory);
	ATlocEnemy* _enemy = dynamic_cast<ATlocEnemy*>(OwnerComp.GetOwner()->GetInstigator());
	if (_enemy)
	{
		float attack = _enemy->Attack();
		if (attack > constants.KMINUS_ONE)
		{
			return EBTNodeResult::Succeeded;
		}
		else return EBTNodeResult::Failed;
	}
	else return EBTNodeResult::Failed;
	
}