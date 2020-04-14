// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#include "Objects/TlocObject.h"
//#include "Characters/TlocEnemy.h"
#include "Characters/TlocHumanPlayer.h"
#include "Characters/TlocDogPlayer.h"
#include "JsonReader/TlocStageLoader.h"
#include "JsonReader/TlocGameLoader.h"
#include "Magic/TlocProjectile.h"
#include "Motor/TlocMotorSpatialCalculus.h"

#include "Engine/World.h"
#include "Engine/Level.h"
#include "Engine/Scene.h"


#include "TlocPlayerController.h"


//#include "CoreMinimal.h"
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
	void SetPlayersFeatures(int &plyr, std::vector<TlocPlayer*> &players);

	void Update(float deltaTime);
	void Render(float deltaTime);
	void Tick(float DeltaTime);

private:

	void spawnPlayers(bool newGame);
	float getSeconds();
	bool searchTargets(TlocSpell &_castingSpell, AActor &_activeActor);
	AActor* pointTarget();
	bool checkEnemyTargets(int kindOfTarget, ATlocEnemy &enemy);
	bool checkPlayerTargets(int kindOfTarget);
	bool checkThereAreTargets(AActor& _actor);
	bool isBiggerThan(int num, int comparation);

	void setHumanPlayerViewTarget(float deltaTime);
	//void setDogPlayerViewTarget(float deltaTime);

	void getSpellEffect(TlocSpell& _castingSpell, AActor &_activeActor);
	void spawnProjectiles(TlocSpell& _castingSpell, AActor& _activeActor, const int &selector);

	//World playable characters and levels
	ATlocHumanPlayer* _humanPlayer;
	ATlocDogPlayer* _dogPlayer;
	UWorld* _world;
	std::vector<ULevel*> _levels;

	//Level loaders
	TlocGameLoader* _gameLoader;
	TlocStageLoader* _stageLoader;
	//UScene* _scene;

	//Level Objects and Enemies
	std::vector<ATlocEnemy*> _levelEnemies;
	std::vector<ATlocObject*> _levelObjects;
	std::vector<std::vector<ATlocEnemy*>> _createdEnemies;
	std::vector<std::vector<ATlocObject*>> _createdObjects;
	AActor* _target;

	//Controllers
	ATlocPlayerController* _humanPlayerController;

	//Game logic tools
	float renderTime;
	float updateTime;
	float lastRenderTime;
	float lastUpdateTime;
	bool choosingTarget;
	bool changingLevel; 
	std::vector<ATlocProjectile*> _projectiles;


	//Motors
	TlocMotorSpatialCalculus* _spatialCalculusMotor;
	ATlocMotorFacade* _motor;
};
