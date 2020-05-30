// Fill out your copyright notice in the Description page of Project Settings.


#include "TlocGameMode.h"
#include "TlocGameState.h"
#include "TlocIngameMenu.h"
#include "../Public/AI/TlocAIEnemiesController.h"
#include "../Public/GlobalConstants.h"
#include "Misc/FileHelper.h"
#include "FileHelpers.h"
#include "ConstructorHelpers.h"
#include <iostream>
#include <Runtime\Core\Public\Misc\Paths.h>
#include "GameFramework/Controller.h"
#include <ctime>

ATlocGameMode::ATlocGameMode()
{
	GlobalConstants constants;
	_world = GetWorld();								//Get the world to manage it
	//_defaultLevel = _world->GetPersistentLevel();
	DefaultPawnClass = nullptr;	//Associate player's pawn with player's default class
	PlayerControllerClass = ATlocPlayerController::StaticClass();
	_humanPlayerController = (ATlocPlayerController*) PlayerControllerClass->GetDefaultObject();
	HUDClass = UTlocIngameMenu::StaticClass();
	GameStateClass = ATlocGameState::StaticClass();

	_gameLoader = TlocGameLoader::GetInstance();
	_stageLoader = TlocStageLoader::GetInstance();



	//_humanPlayer = DefaultPawnClass->GetDefaultObject<ATlocHumanPlayer>();

	//this->PlayerControllerClass->GetDefaultObject()->
	//APlayerController::Possess(_humanPlayer);
	_dogPlayer = CreateDefaultSubobject<ATlocDogPlayer>("Dog");
	_levelEnemies.reserve(30);
	_levelObjects.reserve(30);
	_levelDoors.reserve(30);
	_levelLevers.reserve(30);
	_createdEnemies.reserve(30);
	_createdObjects.reserve(30);
	_projectiles.reserve(constants.KPERCENT);

	renderTime = constants.KRENDER_TIME;
	updateTime = constants.KUPDATE_TIME;
	lastRenderTime = constants.KZERO_F;
	lastUpdateTime = constants.KZERO_F;

	changingLevel = constants.KTRUE;
	choosingTarget = constants.KFALSE;

	PrimaryActorTick.bCanEverTick = constants.KTRUE;
	_spatialCalculusMotor = TlocMotorSpatialCalculus::GetInstance();
	cameraChangeTime = constants.KZERO_F;
	interruptorPushed = false;
	pushingInterruptor = constants.KZERO_F;
}

ATlocGameMode::~ATlocGameMode()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ATlocGameMode::BeginPlay()
{
	Super::BeginPlay();
	SetActorTickInterval(renderTime);

	spawnPlayers(true);
	SpawnActorsOnStage();
	_humanPlayer->InitLocationRotation();
	

	/*
	PlayerControllerClass.GetDefaultObject()->UnPossess();
	PlayerControllerClass.GetDefaultObject()->Possess(_humanPlayer);*/
}

//Function called from stage charger to spawn enemies and objects over the stage
//MAYBE I SHOULD CHANGE THE PLACE WHERE IS THIS FUNCTION PLACED.
void ATlocGameMode::SpawnActorsOnStage()
{
	//TO DO
	GlobalConstants constants;

	const FActorSpawnParameters SpawnParam = FActorSpawnParameters();

	_createdObjects.push_back(_stageLoader->ObjectsLoader(constants.KFIRST_LEVEL_NAME));
	_createdEnemies.push_back(_stageLoader->EnemiesLoader(constants.KFIRST_LEVEL_NAME));
	_createdInterruptors.push_back(_stageLoader->InterruptorsLoader(constants.KFIRST_LEVEL_NAME));

	for (int i = 0; i < _createdObjects[0].size(); i++)
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
		_levelEnemies[i]->AIControllerClass = ATlocAIEnemiesController::StaticClass();
		_levelEnemies[i]->AutoPossessAI = EAutoPossessAI::Spawned;
		//_levelEnemies[i]->Controller = NewObject<ATlocAIEnemiesController>();
		_levelEnemies[i]->SpawnDefaultController();
		((ATlocAIEnemiesController*)_levelEnemies[i]->Controller)->OnPosses(_levelEnemies[i]);
	}
	for (int i = 0; i < _createdInterruptors[0].size(); i++)
	{
		char* _objName = (char*)malloc(constants.KCHAR_SIZE);
		TCHAR* _gotObjName = _createdInterruptors[0][i]->GetClassName();
		size_t   x;
		wcstombs_s(&x, _objName, constants.KCHAR_SIZE, _gotObjName, constants.KCHAR_SIZE);

		//It obtains _obj's child class and identifies which one is it's child class
		//WEAPONS
		if (strcmp(_objName, constants.KLEVER) == 0)
		{
			_levelLevers.push_back(_world->SpawnActor<TlocLever>(TlocLever::StaticClass(), FVector(100, -150, 150), FRotator::ZeroRotator, SpawnParam));
			_levelLevers[i]->InitLever();
			TlocLever * _leverActor = dynamic_cast<TlocLever*>(_createdInterruptors[0][i]);
			_levelLevers[i]->ReplaceLever(*_leverActor);
			_leverActor = nullptr;
		}
		else if (strcmp(_objName, constants.KDOOR) == 0)
		{
			int j = i - _createdInterruptors[0].size() / constants.KTWO;
			_levelDoors.push_back(_world->SpawnActor<TlocDoor>(TlocDoor::StaticClass(), FVector(-400, 70, 200), FRotator::ZeroRotator, SpawnParam));
			//_levelDoors[j]->InitDoor();
			TlocDoor* _doorActor = dynamic_cast<TlocDoor*>(_createdInterruptors[0][i]);
			_levelDoors[j]->ReplaceDoor(*_doorActor);
			_doorActor = nullptr;
		}
		
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
		_dogPlayer->SetInitialMaster(players[constants.KZERO]->GetDefaultMaster());
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
		_humanPlayer->SetWeaponMesh();
		_humanPlayer->AddWeapon(*((ATlocHumanPlayer*)players[constants.KZERO])->GetWeapon());
		std::vector<TlocIngredients*> ing = players[constants.KZERO]->GetIngredients();
		_humanPlayer->SetIngredients(ing);
		std::vector<TlocSpell*> spl = players[constants.KZERO]->GetSpells();
		_humanPlayer->SetSpells(spl);
		_humanPlayer->InitMemorizedSpells();
		_humanPlayer->CreateInGameUI();
		_humanPlayerController = (ATlocPlayerController*) _humanPlayer->Controller;
		_humanPlayer->AutoPossessPlayer = EAutoReceiveInput::Player0;
		break;
	}
}

//Function that updates The Labyrinth of Collosia's logic
void ATlocGameMode::Update(float deltaTime)
{
	GlobalConstants constants;
	_humanPlayerController->Update(deltaTime);
	if (pushingInterruptor > constants.KZERO_F)
	{
		pushingInterruptor -= deltaTime;
	}
	if (pushingInterruptor <= constants.KZERO_F && interruptorPushed)
	{
		pushingInterruptor = constants.KZERO_F;
		cameraChangeTime = constants.KCAMERA_CHANGE_TIME;
		interruptorPushed = !interruptorPushed;
		setHumanPlayerViewTarget(0.5f);
	}
	if (cameraChangeTime > constants.KZERO_F)
	{
		cameraChangeTime -= deltaTime;
	}
	else if (cameraChangeTime <= constants.KZERO_F && !interruptorPushed)
	{
		if (_target != _humanPlayer)
		{
			_target = _humanPlayer;
			setHumanPlayerViewTarget(0.5f);
		}
	}
	if (_humanPlayer->GetMode() == _humanPlayer->PlayingMode::TARGET_SELECTION)
	{
		bool goOn = true;
		//If there are not selected targets, we look for them
		if (!checkThereAreTargets(*_humanPlayer))
		{
			//if we cant find targets, we stop the spell casting
			if (!searchTargets(*_humanPlayer->GetAttackingSpell(), *_humanPlayer))
			{
				_humanPlayer->SetMode(_humanPlayer->PlayingMode::NORMAL);
				goOn = false;
			}
		}
		//There are targets selected so the spell casting continues
		if (goOn)
		{
			_target = pointTarget();
			setHumanPlayerViewTarget(deltaTime);
		}
	}
	else if (_humanPlayer->GetMode() == _humanPlayer->PlayingMode::CASTING_SPELL)
	{
		//TO DO: reduce the number of ingredients, delete attackingSpell, attackingSpellIngredients & targetVector
		_motor->SetViewTarget(*_humanPlayer, *_humanPlayer, constants.KUPDATE_TIME);
		getSpellEffect(*_humanPlayer->GetAttackingSpell(), *_humanPlayer);
		_humanPlayer->SetMode(_humanPlayer->PlayingMode::NORMAL);
	}


	//Update _projectiles position & rotation
	for (int i = 0; i < _projectiles.size(); i++)
	{
		_projectiles[i]->Update(deltaTime);
	}
	//Update _levelLevers rotation
	for (int i = 0; i < _levelLevers.size(); i++)
	{
		int id = _levelLevers[i]->GetId();
		int j = 0;
		bool encontrado = false;
		bool active = _levelLevers[i]->GetActive();
		_levelLevers[i]->Update(deltaTime);
		while (!encontrado && j < _levelDoors.size())
		{
			if (_levelDoors[j]->GetId() == id)
			{
				if (_levelDoors[j]->GetActive() != active)
				{
					_levelDoors[j]->ActivateDeactivateInterruptor();
					encontrado = true;
					if (!interruptorPushed)
					{
						interruptorPushed = !interruptorPushed;
						pushingInterruptor = 0.5f;
						_target = _levelDoors[j];
					}
				}
			}
			j++;
		}
	}

	//Update _levelDoors rotation
	if (cameraChangeTime > constants.KZERO_F)
	{
		for (int i = 0; i < _levelDoors.size(); i++)
		{
			_levelDoors[i]->Update(deltaTime);
		}
	}

	//Checks for enemies to update their state them
	if (!choosingTarget && !_levelEnemies.empty())
	{
		for (int i = 0; i < _levelEnemies.size(); i++)
		{
			if (_levelEnemies[i] != NULL)
			{
				((ATlocAIEnemiesController*)_levelEnemies[i]->Controller)->Update(deltaTime);
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

void ATlocGameMode::Render(float DeltaTime)
{
	//Render _humanaPlayer position & rotation
	_humanPlayerController->Render(DeltaTime);
	_motor->MovePlayer(*_humanPlayer, _humanPlayer->GetRenderPosition());
	_motor->RotateActor(*_humanPlayer, _humanPlayer->GetRenderRotation());
	
	//Render _projectiles position & rotation
	for (int i = 0; i < _projectiles.size(); i++)
	{
		_projectiles[i]->Render(DeltaTime);
		_motor->MoveActor(*_projectiles[i], _projectiles[i]->GetRenderPosition());
		_motor->RotateActor(*_projectiles[i], _projectiles[i]->GetRenderRotation());
	}

	//Render _levelLevers rotation
	for (int i = 0; i < _levelLevers.size(); i++)
	{
		_levelLevers[i]->Render(DeltaTime);
		_motor->SetMeshRotation(*_levelLevers[i]->GetMesh(), _levelLevers[i]->GetRenderRotation());
	}

	//Render _levelLevers rotation
	for (int i = 0; i < _levelDoors.size(); i++)
	{
		_levelDoors[i]->Render(DeltaTime);
		_motor->SetMeshRotation(*_levelDoors[i]->GetMesh(), _levelDoors[i]->GetRenderRotation());
	}
	for (int i = 0; i < _levelEnemies.size(); i++)
	{
		if (_levelEnemies[i] != NULL)
		{
			((ATlocAIEnemiesController*)_levelEnemies[i]->Controller)->Render(DeltaTime);
			_motor->MovePlayer(*_levelEnemies[i], _levelEnemies[i]->GetRenderPosition());
			_motor->RotateActor(*_levelEnemies[i], _levelEnemies[i]->GetRenderRotation());
		}
	}
}

// Called every frame
void ATlocGameMode::Tick(float DeltaTime)
{
	GlobalConstants constants;
	Super::Tick(DeltaTime);
	float currentTime = _world->GetTimeSeconds();
	//if (currentTime - lastRenderTime >= renderTime)
	//{
		Render(currentTime - lastRenderTime);
		lastRenderTime = currentTime;
		if (currentTime - lastUpdateTime >= updateTime)
		{
			Update(currentTime - lastUpdateTime);
			lastUpdateTime = currentTime;
		}
	//}


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

float ATlocGameMode::getSeconds()
{
	return ((float)clock()/(CLOCKS_PER_SEC));
}

bool ATlocGameMode::searchTargets(TlocSpell& _castingSpell, AActor &_activeActor)
{
	GlobalConstants constants;
	int kindOfTargetIfEnemyOrPlayer = -1;
	ATlocEnemy* _enemyActor = nullptr;
	std::vector<AActor*> targets;
	bool targetsSelected = constants.KFALSE;;
	bool enemy = constants.KFALSE;
	if (dynamic_cast<ATlocEnemy*>(&_activeActor))
	{
		enemy = constants.KTRUE;
		_enemyActor = (ATlocEnemy*)&_activeActor;
	}
	switch (_castingSpell.GetKindTarget())
	{
		case TlocSpell::Target::PLAYERS:
			if (enemy)
			{
				targets.reserve(_levelEnemies.size());
				for (int i = 0; i < _levelEnemies.size(); i++)
				{
					if (_spatialCalculusMotor->CheckIsInAttackRange(_activeActor.GetActorLocation(), _levelEnemies[i]->GetActorLocation()))
					{
						targets.push_back(_levelEnemies[i]);
					}
				}
				kindOfTargetIfEnemyOrPlayer = 0;
			}
			else
			{
				targets.reserve(constants.KMAX_NUM_PLAYERS);
				if (_spatialCalculusMotor->CheckIsInAttackRange(_activeActor.GetActorLocation(), _humanPlayer->GetActorLocation()))
				{
					targets.push_back(_humanPlayer);
				}
				if (_spatialCalculusMotor->CheckIsInAttackRange(_activeActor.GetActorLocation(), _dogPlayer->GetActorLocation()))
				{
					targets.push_back(_dogPlayer);
				}
				kindOfTargetIfEnemyOrPlayer = 1;
			}
			break;

			//Only for Atlas
		case TlocSpell::Target::HUMAN_PLAYER:
			targets.reserve(constants.KMAX_NUM_PLAYERS);
			targets.push_back(_humanPlayer);
			kindOfTargetIfEnemyOrPlayer = 1;
			break;

			//Only for Revive
		case TlocSpell::Target::DOG_PLAYER:
			targets.reserve(constants.KMAX_NUM_PLAYERS);
			targets.push_back(_dogPlayer);
			kindOfTargetIfEnemyOrPlayer = 1;
			break;
		case TlocSpell::Target::STAGE:
			kindOfTargetIfEnemyOrPlayer = 2;
			break;
		default :
			if (enemy)
			{
				targets.reserve(constants.KMAX_NUM_PLAYERS);
				if (_spatialCalculusMotor->CheckIsInAttackRange(_activeActor.GetActorLocation(), _humanPlayer->GetActorLocation()))
				{
					targets.push_back(_humanPlayer);
				}
				if (_spatialCalculusMotor->CheckIsInAttackRange(_activeActor.GetActorLocation(), _dogPlayer->GetActorLocation()))
				{
					targets.push_back(_dogPlayer);
				}
				kindOfTargetIfEnemyOrPlayer = 1;
			}
			else
			{
				targets.reserve(_levelEnemies.size());
				for (int i = 0; i < _levelEnemies.size(); i++)
				{
					if (_spatialCalculusMotor->CheckIsInAttackRange(_activeActor.GetActorLocation(), _levelEnemies[i]->GetActorLocation()))
					{
						targets.push_back(_levelEnemies[i]);
					}
				}
				kindOfTargetIfEnemyOrPlayer = 0;
			}
			break;
	}

	if (targets.size() > constants.KZERO)
	{
		targetsSelected = true;
		switch (kindOfTargetIfEnemyOrPlayer)
		{
		case 0:
			if (enemy)
			{
				_enemyActor->SetTargetPlayers(targets);
			}
			else
			{
				_humanPlayer->SetTargetEnemies(targets);
			}
			break;
		case 1:
			if (enemy)
			{
				_enemyActor->SetTargetEnemies(targets);
			}
			else
			{
				_humanPlayer->SetTargetPlayers(targets);
			}
			break;
		case 2:
			if (enemy)
			{
				_enemyActor->SetTargetObjects(targets);
			}
			else
			{
				_humanPlayer->SetTargetObjects(targets);
			}
			break;
		}
	}
	return targetsSelected;
}

AActor* ATlocGameMode::pointTarget()
{
	AActor* target = nullptr;
	switch (_humanPlayer->GetAttackingSpell()->GetKindTarget())
	{
		case TlocSpell::Target::PLAYERS:
			if (_humanPlayer->GetTargetSelector() < _humanPlayer->GetTargetPlayers().size())
			{
				target = _humanPlayer->GetTargetPlayers()[_humanPlayer->GetTargetSelector()];
			}
			break;
		case TlocSpell::Target::HUMAN_PLAYER:
			if (_humanPlayer->GetTargetSelector() < _humanPlayer->GetTargetPlayers().size())
			{
				target = _humanPlayer->GetTargetPlayers()[_humanPlayer->GetTargetSelector()];
			}
			break;
		case TlocSpell::Target::DOG_PLAYER:
			if (_humanPlayer->GetTargetSelector() < _humanPlayer->GetTargetPlayers().size())
			{
				target = _humanPlayer->GetTargetPlayers()[_humanPlayer->GetTargetSelector()];
			}
			break;
		case TlocSpell::Target::STAGE:
			if (_humanPlayer->GetTargetSelector() < _humanPlayer->GetTargetObjects().size())
			{
				target = _humanPlayer->GetTargetObjects()[_humanPlayer->GetTargetSelector()];
			}
			break;
		default:
			if (_humanPlayer->GetTargetSelector() < _humanPlayer->GetTargetEnemies().size())
			{
				target = _humanPlayer->GetTargetEnemies()[_humanPlayer->GetTargetSelector()];
			}
			break;
	}
	if (target == nullptr)
	{
		target = _humanPlayer;
	}
	return target;
}

/***************************** Check Player Trgets *********************************
**** Function that return true if player has whaterver kind of selected targets ****
*
*						In: int kindOfTarget (wanted type of target)
*						Out: bool (true if there are targets, false if there aren't.
*/
bool ATlocGameMode::checkPlayerTargets(int kindOfTarget)
{
	GlobalConstants constants;
	int targetsQuantity = 0;
	switch (kindOfTarget)
	{
	case TlocSpell::Target::ENEMY:
		targetsQuantity = _humanPlayer->GetTargetEnemies().size();
		break;
	case TlocSpell::Target::PLAYERS:
		targetsQuantity = _humanPlayer->GetTargetPlayers().size();
		break;
	case TlocSpell::Target::HUMAN_PLAYER:
		targetsQuantity = _humanPlayer->GetTargetPlayers().size();
		break;
	case TlocSpell::Target::DOG_PLAYER:
		targetsQuantity = _humanPlayer->GetTargetPlayers().size();
		break;
	case TlocSpell::Target::STAGE:
		targetsQuantity = _humanPlayer->GetTargetObjects().size();
		break;
	}
	return isBiggerThan(targetsQuantity, constants.KZERO);
}
/***************************** Check Enemy Trgets *********************************
**** Function that return true if enemy has whaterver kind of selected targets ****
*
*						In: int kindOfTarget (wanted type of target)
*						Out: bool (true if there are targets, false if there aren't.
*/
bool ATlocGameMode::checkEnemyTargets(int kindOfTarget, ATlocEnemy& enemy)
{
	GlobalConstants constants;
	int targetsQuantity = 0;
	switch (kindOfTarget)
	{
		case TlocSpell::Target::ENEMY:
			targetsQuantity = enemy.GetTargetEnemies().size();
			break;
		case TlocSpell::Target::PLAYERS:
			targetsQuantity = enemy.GetTargetPlayers().size();
			break;
		case TlocSpell::Target::HUMAN_PLAYER:
			targetsQuantity = enemy.GetTargetPlayers().size();
			break;
		case TlocSpell::Target::DOG_PLAYER:
			targetsQuantity = enemy.GetTargetPlayers().size();
			break;
		case TlocSpell::Target::STAGE:
			targetsQuantity = enemy.GetTargetObjects().size();
			break;
	}
	return isBiggerThan(targetsQuantity, constants.KZERO);
}

/**************************** Check There Are Targets ******************************
**** Function that identifies _actor's class and then calls checkPlayerTargets  ****
**** or checkEnemyTargets keeping in mind _actor's class. Return true if _actor ****
**** has got selected targets and false if it hasn't got.                       ****
*
*								In: AActor &_actor (_actor for checking its targets)
*
*								Out: bool isTargetSeleced (true if targets, false if not targets)
*/
bool ATlocGameMode::checkThereAreTargets(AActor &_actor)
{
	GlobalConstants constants;
	bool isTargetSelected = false;

	if (dynamic_cast<ATlocHumanPlayer*>(&_actor))
	{
		isTargetSelected = checkPlayerTargets(_humanPlayer->GetAttackingSpell()->GetKindTarget());
	}
	else if (dynamic_cast<ATlocEnemy*>(&_actor))
	{
		ATlocEnemy* _attackingEnemy = (ATlocEnemy*) &_actor;
		isTargetSelected = checkEnemyTargets(_attackingEnemy->GetAttackingSpell()->GetKindTarget(), *_attackingEnemy);
	}
	return isTargetSelected;
}

//Function to compare if int num is bigger than int comparation
bool ATlocGameMode::isBiggerThan(int num, int comparation)
{
	if (num > comparation)
	{
		return true;
	}
	else return false;
}

//In this function we switch into target camera to select the spell or element target
void ATlocGameMode::setHumanPlayerViewTarget(float deltaTime)
{
	GlobalConstants constants;
	if(_humanPlayerController->GetViewTarget() != _target)
	{
		_humanPlayerController->SetViewTargetWithBlend(_target, deltaTime);
	}
}

//Function that cast the spell keeping in mind _castingSpell's ID
void ATlocGameMode::getSpellEffect(TlocSpell& _castingSpell, AActor &_activeActor)
{
	GlobalConstants constants;
	bool enemy = constants.KFALSE;
	ATlocEnemy* _enemyActor = nullptr;
	if (dynamic_cast<ATlocEnemy*>(&_activeActor))
	{
		enemy = constants.KTRUE;
		_enemyActor = (ATlocEnemy*)&_activeActor;
	}
	switch (_castingSpell.GetId())
	{
		//Flash
		case 0:
			if (enemy)
			{
				if (/*_enemyActor->GetTargetSelector() == _enemyActor->GetTargetEnemies().size()*/enemy)
				{
					for (int i = 0; i < _enemyActor->GetTargetEnemies().size(); i++)
					{
						spawnProjectiles(_castingSpell, *_enemyActor, i);
					}
				}
				else
				{
					//spawnProjectiles(_castingSpell, *_enemyActor, _enemyActor->GetTargetSelector());
				}
			}
			else
			{
				if (_humanPlayer->GetTargetSelector() == _humanPlayer->GetTargetEnemies().size())
				{
					for (int i = 0; i < _humanPlayer->GetTargetEnemies().size(); i++)
					{
						spawnProjectiles(_castingSpell, *_humanPlayer, i);
					}
				}
				else
				{
					spawnProjectiles(_castingSpell, *_humanPlayer, _humanPlayer->GetTargetSelector());
				}
			}
			break;
		//Hard ball
		case 1:
			if (enemy)
			{
				if (/*_enemyActor->GetTargetSelector() == _enemyActor->GetTargetEnemies().size()*/enemy)
				{
					for (int i = 0; i < _enemyActor->GetTargetEnemies().size(); i++)
					{
						spawnProjectiles(_castingSpell, *_enemyActor, i);
					}
				}
				else
				{
					//spawnProjectiles(_castingSpell, *_enemyActor, _enemyActor->GetTargetSelector());
				}
			}
			else
			{
				if (_humanPlayer->GetTargetSelector() == _humanPlayer->GetTargetEnemies().size())
				{
					for (int i = 0; i < _humanPlayer->GetTargetEnemies().size(); i++)
					{
						spawnProjectiles(_castingSpell, *_humanPlayer, i);
					}
				}
				else
				{
					spawnProjectiles(_castingSpell, *_humanPlayer, _humanPlayer->GetTargetSelector());
				}
			}
			break;
		//Acid rain
		case 2:
			//rainEffect(*_activeActor, _castingSpell);
			break;
		//Defend
		case 3:
			//improve(*_activeActor, _castingSpell);
			break;
		//Cure
		case 4:
			//manageBuffsAillments(*_activeActor, _castingSpell);
			break;
		//Heal
		case 5:
			//manageLife(*_activeActor, _castingSpell);
			break;
		//Levitate
		case 6:
			//levitate(*_activeActor, _castingSpell);
			break;
		//Speed
		case 7:
			//manageBuffsAillments(*_activeActor, _castingSpell);
			break;
		//Crush
		case 8:
			if (enemy)
			{
				if (/*_enemyActor->GetTargetSelector() == _enemyActor->GetTargetEnemies().size()*/enemy)
				{
					for (int i = 0; i < _enemyActor->GetTargetEnemies().size(); i++)
					{
						spawnProjectiles(_castingSpell, *_enemyActor, i);
					}
				}
				else
				{
					//spawnProjectiles(_castingSpell, *_enemyActor, _enemyActor->GetTargetSelector());
				}
			}
			else
			{
				if (_humanPlayer->GetTargetSelector() == _humanPlayer->GetTargetEnemies().size())
				{
					for (int i = 0; i < _humanPlayer->GetTargetEnemies().size(); i++)
					{
						spawnProjectiles(_castingSpell, *_humanPlayer, i);
					}
				}
				else
				{
					spawnProjectiles(_castingSpell, *_humanPlayer, _humanPlayer->GetTargetSelector());
				}
			}
			break;
		//Sting
		case 9:
			//sting(*_activeActor, _castingSpell);
			break;
		//Revive
		case 10:
			//manageLife(*_activeActor, _castingSpell);
			break;
		//Revealer
		case 11:
			//revealer(*_activeActor, _castingSpell);
			break;
		//Atlas
		case 12:
			//manageBuffsAillments(*_activeActor, _castingSpell);
			break;
		//Drain
		case 13:
			if (enemy)
			{
				if (/*_enemyActor->GetTargetSelector() == _enemyActor->GetTargetEnemies().size()*/enemy)
				{
					for (int i = 0; i < _enemyActor->GetTargetEnemies().size(); i++)
					{
						spawnProjectiles(_castingSpell, *_enemyActor, i);
					}
				}
				else
				{
					//spawnProjectiles(_castingSpell, *_enemyActor, _enemyActor->GetTargetSelector());
				}
			}
			else
			{
				if (_humanPlayer->GetTargetSelector() == _humanPlayer->GetTargetEnemies().size())
				{
					for (int i = 0; i < _humanPlayer->GetTargetEnemies().size(); i++)
					{
						spawnProjectiles(_castingSpell, *_humanPlayer, i);
					}
				}
				else
				{
					spawnProjectiles(_castingSpell, *_humanPlayer, _humanPlayer->GetTargetSelector());
				}
			}
			break;
	}
}

void ATlocGameMode::spawnProjectiles(TlocSpell& _castingSpell, AActor& _activeActor, const int& selector)
{
	GlobalConstants constants; 
	bool enemy = constants.KFALSE;
	ATlocEnemy* _enemyActor = nullptr;
	if (dynamic_cast<ATlocEnemy*>(&_activeActor))
	{
		enemy = constants.KTRUE;
		_enemyActor = (ATlocEnemy*)&_activeActor;
	}
	switch (_castingSpell.GetId())
	{
		case 0:
			ATlocProjectile* _projectile = _world->SpawnActor<ATlocProjectile>(_activeActor.GetActorLocation(), _activeActor.GetActorRotation());
			if (enemy)
			{
				_projectile->SetTargetActor(*_enemyActor->GetTargetPlayers()[selector]);
				_projectile->SetTarget(((TlocPlayer*)_enemyActor->GetTargetPlayers()[selector])->GetPosition());
				_projectile->SetOriginActor(*_enemyActor);
				_projectile->SetOrigin(_enemyActor->GetPosition());
				_projectile->SetPosition(_enemyActor->GetPosition());
				_projectile->SetLastPosition(_enemyActor->GetPosition());
				_projectile->SetDirectorVector();
				_projectile->SetPursue(constants.KTRUE);
			}
			else
			{
				_projectile->SetTargetActor(*_humanPlayer->GetTargetEnemies()[selector]);
				_projectile->SetTarget(((ATlocEnemy*) _humanPlayer->GetTargetEnemies()[selector])->GetPosition());
				_projectile->SetOriginActor(*_humanPlayer);
				_projectile->SetOrigin(_humanPlayer->GetPosition());
				_projectile->SetPosition(_projectile->GetActorLocation());
				_projectile->SetLastPosition(_humanPlayer->GetPosition());
				_projectile->SetDirectorVector();
				_projectile->SetPursue(constants.KTRUE);
			}
			_projectiles.push_back(_projectile);
	}
}



