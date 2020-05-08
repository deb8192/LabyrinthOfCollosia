// Fill out your copyright notice in the Description page of Project Settings.


#include "../Public/AI/BehaviorTree/Tasks/TlocBBTaskRunawayNode.h"
#include "../Public/Characters/TlocEnemy.h"
#include "../Public/Characters/TlocHumanPlayer.h"
#include "../Public/GlobalConstants.h"
#include "BehaviorTree/BlackBoardComponent.h"

EBTNodeResult::Type UTlocBBTaskRunawayNode::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);
	ATlocEnemy* _enemy = dynamic_cast<ATlocEnemy*>(OwnerComp.GetOwner()->GetInstigator());
	GlobalConstants constants;

	UBlackboardComponent* blackboardComponent = OwnerComp.GetBlackboardComponent();
	ATlocHumanPlayer* _target = dynamic_cast<ATlocHumanPlayer*>(blackboardComponent->GetValueAsObject(blackBoardKeyName));
	if (_target)
	{
		FVector posTarget = _target->GetActorLocation();
		if (_enemy)
		{
			float runAwayRemaining = _enemy->RunAway(posTarget);
			if (runAwayRemaining > constants.KZERO_F)
			{
				return EBTNodeResult::InProgress;
			}
			else
			{
				blackboardComponent->SetValueAsObject(blackBoardKeyName, nullptr);
				return EBTNodeResult::Succeeded;
			}
		}
		else return EBTNodeResult::Failed;
	}
	else return EBTNodeResult::Failed;
	

}