// Fill out your copyright notice in the Description page of Project Settings.


#include "../Public/AI/BehaviorTree/Services/TlocServiceCheckCoward.h"
#include "../Public/Characters/TlocEnemy.h"
#include "BehaviorTree/BlackboardComponent.h"

void UTlocServiceCheckCoward::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	UBlackboardComponent* blackboardComponent = OwnerComp.GetBlackboardComponent();
	ATlocEnemy* _enemy = dynamic_cast<ATlocEnemy*>(OwnerComp.GetOwner()->GetInstigator());

	if (_enemy)
	{
		if (_enemy->GetCoward())
		{
			blackboardComponent->SetValueAsBool(bbCheckCoward.SelectedKeyName, true);
			blackboardComponent->SetValueAsBool(bbCheckNotCoward.SelectedKeyName, false);
		}
		
		else if (!_enemy->GetCoward())
		{
			blackboardComponent->SetValueAsBool(bbCheckCoward.SelectedKeyName, false);
			blackboardComponent->SetValueAsBool(bbCheckNotCoward.SelectedKeyName, true);
		}
	}
	else
	{
		blackboardComponent->SetValueAsBool(bbCheckCoward.SelectedKeyName, false);
		blackboardComponent->SetValueAsBool(bbCheckNotCoward.SelectedKeyName, false);
	}
}
