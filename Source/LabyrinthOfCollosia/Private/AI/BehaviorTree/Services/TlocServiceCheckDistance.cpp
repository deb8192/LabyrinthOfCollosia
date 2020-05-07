// Fill out your copyright notice in the Description page of Project Settings.


#include "../Public/AI/BehaviorTree/Services/TlocServiceCheckDistance.h"
#include "../Public/Characters/TlocHumanPlayer.h"
#include "BehaviorTree/BlackboardComponent.h"

void UTlocServiceCheckDistance::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
	
	FVector targetLocation = OwnerComp.GetOwner()->GetActorLocation();

	UBlackboardComponent* blackboardComponent = OwnerComp.GetBlackboardComponent();
	UObject* target = blackboardComponent->GetValueAsObject(bbTarget.SelectedKeyName);
	ATlocHumanPlayer* targetActor = dynamic_cast<ATlocHumanPlayer*>(target);

	if (targetActor)
	{
		FVector enemyLocation = OwnerComp.GetOwner()->GetInstigator()->GetActorLocation();
		FVector targetLocation = targetActor->GetActorLocation();
		FVector distance = enemyLocation - targetLocation;
		float distanceModule = distance.Size();

		if (distanceModule <= closeDistance)
		{
			blackboardComponent->SetValueAsBool(bbCheckClose.SelectedKeyName, true);
			blackboardComponent->SetValueAsBool(bbCheckAway.SelectedKeyName, false);
			blackboardComponent->SetValueAsObject(bbTarget.SelectedKeyName, targetActor);
		}
		else if(distanceModule <= awayDistance)
		{
			blackboardComponent->SetValueAsBool(bbCheckClose.SelectedKeyName, false);
			blackboardComponent->SetValueAsBool(bbCheckAway.SelectedKeyName, true);
			blackboardComponent->SetValueAsObject(bbTarget.SelectedKeyName, targetActor);
		}
		else
		{
			blackboardComponent->SetValueAsBool(bbCheckClose.SelectedKeyName, false);
			blackboardComponent->SetValueAsBool(bbCheckAway.SelectedKeyName, false);
			blackboardComponent->SetValueAsObject(bbTarget.SelectedKeyName, nullptr);
		}
	}
}