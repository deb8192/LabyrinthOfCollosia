// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackBoardComponent.h"
#include "TlocAIEnemiesController.generated.h"

/**
 * 
 */
UCLASS()
class LABYRINTHOFCOLLOSIA_API ATlocAIEnemiesController : public AAIController
{
	GENERATED_BODY()

public:

	ATlocAIEnemiesController();
	~ATlocAIEnemiesController();

	virtual void OnPosses(class APawn* _enemy);

	void Update(float DesltaTime);

	// Human player ingame menu
	FORCEINLINE UBlackboardComponent* GetBlackboardComp() const
	{
		return _enemyBlackBoard; 
	}
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "AI")
		UBehaviorTree* _enemyBehaviorTree;
	UPROPERTY(EditAnywhere, Category = "AI")
		UBlackboardComponent* _enemyBlackBoard;
	UPROPERTY(EditDefaultsOnly, Category = "AI")
		FName getPlayerLocation;
	UPROPERTY(VisibleAnywhere)
		UAIPerceptionComponent* AIPerceptionComponent;
	UBehaviorTreeComponent* _behaviorTreeComponent;

private:

	/** The function that fires when the perception of our AI gets updated */
	UFUNCTION()
		void OnPerceptionUpdated(const TArray<AActor*> &UpdatedActors);

	UPROPERTY()
		FName blackBoardKeyName = FName("DetectedPlayer");

	// Ingame menu class
	/*TSubclassOf<class UBehaviorTree> BehaviorTreeClass;

	// Ingame menu object
	UPROPERTY(EditAnywhere, Category = "AI")
		class UTlocBehaviorTreeEnemies* _behaviorTree;
	// !Human player ingame menu*/

};
