// Fill out your copyright notice in the Description page of Project Settings.


#include "TlocGameMode.h"
#include "TlocGameState.h"
#include "TlocIngameMenu.h"
#include "../Public/GlobalConstants.h"
#include "Misc/FileHelper.h"
#include "FileHelpers.h"
#include "ConstructorHelpers.h"
#include <iostream>
#include <Runtime\Core\Public\Misc\Paths.h>
#include "GameFramework/PlayerController.h"
#include "GameFramework/Controller.h"

ATlocGameMode::ATlocGameMode()
{
	GlobalConstants constants;
	_world = GetWorld();								//Get the world to manage it
	//_defaultLevel = _world->GetPersistentLevel();
	DefaultPawnClass = nullptr;	//Associate player's pawn with player's default class
	HUDClass = UTlocIngameMenu::StaticClass();
	GameStateClass = ATlocGameState::StaticClass();

	_gameLoader = TlocGameLoader::GetInstance();
	_stageLoader = TlocStageLoader::GetInstance();

	//_humanPlayer = DefaultPawnClass->GetDefaultObject<ATlocHumanPlayer>();

	//this->PlayerControllerClass->GetDefaultObject()->
	//APlayerController::Possess(_humanPlayer);
	_dogPlayer = CreateDefaultSubobject<ATlocDogPlayer>("Dog");
	_levels.reserve(constants.KLEVEL_NUM);
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

	if (_world != NULL)
	{
		for (int i = 0; i < _world->GetLevels().Num(); i++)
		{
			_levels.push_back(_world->GetLevel(i));
			_world->GetLevel(i)->GetName();
		}
	}

	spawnPlayers(true);
	SpawnActorsOnStage();
	

	/*
	PlayerControllerClass.GetDefaultObject()->UnPossess();
	PlayerControllerClass.GetDefaultObject()->Possess(_humanPlayer);*/
}

void ATlocGameMode::SpawnLevels(int _lvlNum)
{
	GlobalConstants constants;
	
	//We obtain the full path of the content project
	FString *fileName = new FString();
	//FString fileName = FPaths::GameContentDir();
	//We add json directory, file name and file extension
	//fileName += constants.KDIR_LEVELS;

	switch (_lvlNum)
	{
		case 1:
			*fileName = constants.KNAME_MINITAURUS_STAGE;
			//fileName += constants.KDIR_MINITAURUS_STAGE;
			//fileName += constants.KNAME_MINITAURUS_STAGE;
			break;
			
		default:
			*fileName = constants.KNAME_HALL;
			//fileName += constants.KDIR_HALL;
			//fileName += constants.KNAME_HALL;
			break;
	}



	//_world->GetFirstPlayerController()->ClientTravel(*fileName, TRAVEL_Relative, true);
	//_world->SeamlessTravel(*fileName, false);
	//FEditorFileUtils::LoadMap(fileName, false, true);
	//_levels.push_back(LoadObject<ULevel>(NULL, *fileName));
	//_world->AddLevel(_levels.back());
}

//Function called from stage charger to spawn enemies and objects over the stage
//MAYBE I SHOULD CHANGE THE PLACE WHERE IS THIS FUNCTION PLACED.
void ATlocGameMode::SpawnActorsOnStage()
{
	//TO DO
	GlobalConstants constants;

	const FActorSpawnParameters SpawnParam = FActorSpawnParameters();

	//_world->AddToWorld(;

	//_humanPlayer = DefaultPawnClass.GetDefaultObject();
	_createdObjects.push_back(_stageLoader->ObjectsLoader(constants.KFIRST_LEVEL_NAME));
	_createdEnemies.push_back(_stageLoader->EnemiesLoader(constants.KFIRST_LEVEL_NAME));
	//_world->SpawnActor<TlocWeapon>(TlocWeapon::StaticClass(), FVector(-500, -70, 100), FRotator::ZeroRotator, SpawnParam);

	for (int i = 0; i < 2; i++)
	{
		//_createdObjects[0][i]->RegisterMeshComponent();
		_levelObjects.push_back(_world->SpawnActor<ATlocObject>(SpawnParam));
		_levelObjects[i]->ReplaceObject(_createdObjects[0][i]);
		//UGameplayStatics::FinishSpawningActor(_levelObjects[i], _levelObjects[i]->GetTransform());
		//_levelObjects[i]->ReplaceMesh(_createdObjects[0][i]->GetMeshFileRoot());
	}

	for (int i = 0; i < _createdEnemies[0].size(); i++)
	{
		_levelEnemies.push_back(_world->SpawnActor<ATlocEnemy>(ATlocEnemy::StaticClass(), FVector(-500, -70, 100), FRotator::ZeroRotator, SpawnParam));
		//_levelEnemies[i] = _createdEnemies[0][i];
		_levelEnemies[i]->replaceEnemy(_createdEnemies[0][i]);
	}
}

void ATlocGameMode::SetPlayersFeatures(int& plyr, std::vector<TlocPlayer*> &players)
{

	const FActorSpawnParameters SpawnParam = FActorSpawnParameters();
	GlobalConstants constants;
	switch (plyr)
	{
	case 1:
		_dogPlayer->SetID(players[constants.KZERO]->GetID());
		_dogPlayer->SetLevel(players[constants.KZERO]->GetLevel());
		_dogPlayer->SetInitialLife(players[constants.KZERO]->GetDefaultLife());
		_dogPlayer->SetAttack(players[constants.KZERO]->GetAttack());
		_dogPlayer->SetMaster(players[constants.KZERO]->GetMaster());
		_dogPlayer->SetMagicDefense(players[constants.KZERO]->GetMagicDefense());
		_dogPlayer->SetEvasion(players[constants.KZERO]->GetEvasion());
		_dogPlayer->SetLuck(players[constants.KZERO]->GetLuck());
		_dogPlayer->SetCriticalHit(players[constants.KZERO]->GetCriticalHit());
		_dogPlayer->SetCriticalProb(players[constants.KZERO]->GetCriticalProb());
		_dogPlayer->SetExperience(players[constants.KZERO]->GetExperience());
		_dogPlayer->SetNextLevel(players[constants.KZERO]->GetNextLevel());
		//_dogPlayer->SetWeapon(Cast<ATlocHumanPlayer>(players[constants.KZERO])->GetWeapon());
		break;

	default:
		_humanPlayer->SetID(players[constants.KZERO]->GetID());
		_humanPlayer->SetLevel(players[constants.KZERO]->GetLevel());
		_humanPlayer->SetInitialLife(players[constants.KZERO]->GetDefaultLife());
		_humanPlayer->SetAttack(players[constants.KZERO]->GetAttack());
		_humanPlayer->SetMaster(players[constants.KZERO]->GetMaster());
		_humanPlayer->SetMagicDefense(players[constants.KZERO]->GetMagicDefense());
		_humanPlayer->SetEvasion(players[constants.KZERO]->GetEvasion());
		_humanPlayer->SetLuck(players[constants.KZERO]->GetLuck());
		_humanPlayer->SetCriticalHit(players[constants.KZERO]->GetCriticalHit());
		_humanPlayer->SetCriticalProb(players[constants.KZERO]->GetCriticalProb());
		_humanPlayer->SetExperience(players[constants.KZERO]->GetExperience());
		_humanPlayer->SetNextLevel(players[constants.KZERO]->GetNextLevel());
		_humanPlayer->SetWeapon(((ATlocHumanPlayer*) players[constants.KZERO])->GetWeapon());
		std::vector<TlocSpell*> spl = players[constants.KZERO]->GetSpells();
		_humanPlayer->SetSpells(spl);
		_humanPlayer->InitMemorizedSpells();
		_humanPlayer->AutoPossessPlayer = EAutoReceiveInput::Player0;
		break;

	}
}

// Called every frame
void ATlocGameMode::Tick(float DeltaTime)
{
	GlobalConstants constants;
	Super::Tick(DeltaTime);

	/*if (changingLevel)
	{
		_world->SetCurrentLevel(_levels[1]);
		changingLevel = false;
	}*/
	if (!_levelEnemies.empty())
	{

		for (int i = 0; i < _levelEnemies.size(); i++)
		{

			if (_levelEnemies[i] != NULL)
			{
				_levelEnemies[i]->AddActorWorldOffset(FVector(0.0f, 0.0f, 0.0f), true);
				if (_levelEnemies[i]->GetLife() <= constants.KZERO)
				{
					_levelEnemies[i]->Destroy();
				_levelEnemies.erase(_levelEnemies.begin() + i);
				UE_LOG(LogTemp, Warning, TEXT("You killed the enemy."));
				}
			}
		}
	}



}

void ATlocGameMode::spawnPlayers(bool newGame)
{

	const FActorSpawnParameters SpawnParam = FActorSpawnParameters();
	GlobalConstants constants;

	//First player hero spawn
	_humanPlayer = _world->SpawnActor<ATlocHumanPlayer>(ATlocHumanPlayer::StaticClass(), FVector(constants.KZERO, constants.KZERO, constants.KPERCENT), FRotator(constants.KZERO, -constants.K1_2PI_RADIAN, constants.KZERO), SpawnParam);
	std::vector<TlocPlayer*> players;
	if (newGame)
	{
		players = _gameLoader->NewGameLoader();
	}
	else
	{
		players = _gameLoader->NewGameLoader();
	}
	for (int i = 0; i < players.size(); i++)
	{
		SetPlayersFeatures(i, players);
	}
}



