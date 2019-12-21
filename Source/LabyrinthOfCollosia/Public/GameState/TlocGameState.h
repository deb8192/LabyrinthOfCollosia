// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include <vector>

#include "Characters/TlocEnemy.h"
#include "Characters/TlocHumanPlayer.h"

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "TlocGameState.generated.h"

/**
 * 
 */
UCLASS()
class LABYRINTHOFCOLLOSIA_API ATlocGameState : public AGameState
{
	GENERATED_BODY()

public:

	ATlocGameState();
	~ATlocGameState();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void Tick(float DeltaTime);

private:

};
