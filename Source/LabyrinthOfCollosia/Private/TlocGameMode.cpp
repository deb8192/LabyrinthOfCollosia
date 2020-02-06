// Fill out your copyright notice in the Description page of Project Settings.


#include "TlocGameMode.h"
#include "TlocGameState.h"
#include "../Public/GlobalConstants.h"
#include "ConstructorHelpers.h"
#include <iostream>

ATlocGameMode::ATlocGameMode()
{
	_world = GetWorld();								//Get the world to manage it
	DefaultPawnClass = ATlocHumanPlayer::StaticClass();	//Associate player's pawn with player's default class
	GameStateClass = ATlocGameState::StaticClass();

	//_stageLoader = TlocStageLoader::GetInstance();

	_levelEnemies.reserve(30);
	_levelObjects.reserve(30);
	_createdEnemies.reserve(30);
	_createdObjects.reserve(30);

	changingLevel = true;

	PrimaryActorTick.bCanEverTick = true;
}

ATlocGameMode::~ATlocGameMode()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ATlocGameMode::BeginPlay()
{
	Super::BeginPlay();
	GlobalConstants constants;

	const FActorSpawnParameters SpawnParam = FActorSpawnParameters();
	
	//_humanPlayer = DefaultPawnClass.GetDefaultObject();
	_createdObjects.push_back(_stageLoader->ObjectsLoader(constants.KFIRST_LEVEL_NAME));
	_createdEnemies.push_back(_stageLoader->EnemiesLoader(constants.KFIRST_LEVEL_NAME));
	//_world->SpawnActor<TlocWeapon>(TlocWeapon::StaticClass(), FVector(-500, -70, 100), FRotator::ZeroRotator, SpawnParam);

	for (int i = 0; i < 2; i++)
	{
		_levelObjects.push_back(_world->SpawnActor<ATlocObject>(SpawnParam));
		_levelObjects.back()->replaceObject(_createdObjects[0][i]->GetPosition(), _createdObjects[0][i]->GetRotation(), _createdObjects[0][i]->GetMeshFileRoot(), _createdObjects[0][i]->GetMesh());
	}
	for (int i = 0; i < _createdEnemies[0].size(); i++)
	{
		_levelEnemies.push_back(_world->SpawnActor<ATlocEnemy>(ATlocEnemy::StaticClass(), FVector(-500, -70, 100), FRotator::ZeroRotator, SpawnParam));
		_levelEnemies.back()->replaceEnemy(_createdEnemies[0][i]->GetPosition(), _createdEnemies[0][i]->GetRotation(), _createdEnemies[0][i]->GetMeshesFileRoot(), _createdEnemies[0][i]->GetMesh());
	}


	/*
	PlayerControllerClass.GetDefaultObject()->UnPossess();
	PlayerControllerClass.GetDefaultObject()->Possess(_humanPlayer);*/
}

//Function called from stage charger to spawn enemies and objects over the stage
//MAYBE I SHOULD CHANGE THE PLACE WHERE IS THIS FUNCTION PLACED.
void ATlocGameMode::SpawnActorsOnStage()
{
	//TO DO
}

// Called every frame
void ATlocGameMode::Tick(float DeltaTime)
{
	GlobalConstants constants;
	Super::Tick(DeltaTime);

	for (int i = 0; i < _levelEnemies.size(); i++)
	{
		_levelEnemies[i]->AddActorWorldOffset(FVector(0.0f, 0.0f, 0.0f), true);
	}
	if (!_levelEnemies.empty())
	{
		for (int i = 0; i < _levelEnemies.size(); i++)
		{
			if (_levelEnemies[i]->GetLife() <= constants.KZERO)
			{
				_levelEnemies[i]->Destroy();
				_levelEnemies.erase(_levelEnemies.begin() + i);
				UE_LOG(LogTemp, Warning, TEXT("You killed the enemy."));
			}
		}
	}



}



