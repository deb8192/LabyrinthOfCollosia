// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <vector>

#include "Objects/TlocWeapon.h"
#include "Characters/TlocEnemy.h"
#include "Characters/TlocHumanPlayer.h"
#include "Engine/World.h"
#include "Engine/Scene.h"

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "TlocGameMode.generated.h"

/**
 * 
 */
UCLASS()
class LABYRINTHOFCOLLOSIA_API ATlocGameMode : public AGameMode
{
	GENERATED_BODY()

public:

	ATlocGameMode();
	~ATlocGameMode();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void Tick(float DeltaTime);

private:
	ATlocHumanPlayer* _humanPlayer;
	UWorld* _world;
	//UScene* _scene;

	std::vector<ATlocEnemy*> enemies;
	
};
