// Fill out your copyright notice in the Description page of Project Settings.


#include "../AI/BehaviorTree/BlackBoard/TlocBTTask_BlackboardBase.h"
#include "../AI/TlocAIEnemiesController.h"
#include "../Public/Characters/TlocHumanPlayer.h"

EBTNodeResult::Type UTlocBTTask_BlackboardBase::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    ATlocAIEnemiesController* _enemyController = Cast<ATlocAIEnemiesController>(OwnerComp.GetAIOwner());

    /*If the Controller is valid:
    1)Get the Blackboard Component and the Current Point of the bot
    2)Search for the next point, which will be different from the Current Point*/
    if (_enemyController)
    {

        UBlackboardComponent* BlackboardComp = _enemyController->GetBlackboardComp();
        ATlocHumanPlayer* _player = Cast<ATlocHumanPlayer>(BlackboardComp->GetValueAsObject("detectedPlayer"));

        if (_player)
        {

        }

        //Update the next location in the Blackboard so the bot can move to the next Blackboard value
        BlackboardComp->SetValueAsObject("detectedPlayer", _player);

        //At this point, the task has been successfully completed
        return EBTNodeResult::Succeeded;
    }
    return EBTNodeResult::Failed;
}
