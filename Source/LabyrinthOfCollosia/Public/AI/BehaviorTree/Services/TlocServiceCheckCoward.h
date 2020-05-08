// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "TlocServiceCheckCoward.generated.h"

/**
 * 
 */
UCLASS()
class LABYRINTHOFCOLLOSIA_API UTlocServiceCheckCoward : public UBTService_BlackboardBase
{
    GENERATED_BODY()

protected:
    //It's protected because its base function is protected
    void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
private:

    UPROPERTY(EditAnywhere) FBlackboardKeySelector bbCheckCoward;
    UPROPERTY(EditAnywhere) FBlackboardKeySelector bbCheckNotCoward;
};