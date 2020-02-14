// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Objects/TlocWeapon.h"
#include "Characters/TlocEnemy.h"
#include "Characters/TlocHumanPlayer.h"
#include "Engine/World.h"
#include "Engine/Level.h"
#include "Engine/Scene.h"
#include "JsonReader/TlocStageLoader.h"

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

	void SpawnLevels(int _lvlNum);
	void SpawnActorsOnStage();

	void Tick(float DeltaTime);

private:
	ATlocHumanPlayer* _humanPlayer;
	UWorld* _world;
	//ULevel* _defaultLevel;
	std::vector<ULevel*> _levels;
	TlocStageLoader* _stageLoader;
	//UScene* _scene;

	//Level Objects
	std::vector<ATlocEnemy*> _levelEnemies;
	std::vector<ATlocObject*> _levelObjects;
	std::vector<std::vector<ATlocEnemy*>> _createdEnemies;
	std::vector<std::vector<ATlocObject*>> _createdObjects;
	bool changingLevel; 
};
