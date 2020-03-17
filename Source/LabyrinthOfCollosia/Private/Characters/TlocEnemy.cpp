// Fill out your copyright notice in the Description page of Project Settings.


#include "TlocEnemy.h"
#include "../Public/GlobalConstants.h"
#include "ConstructorHelpers.h"


// Sets default values
ATlocEnemy::ATlocEnemy()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GlobalConstants constants;
	_ingredients.reserve(constants.KMAXINGREDIENTS);
	_learnedSpells.reserve(constants.KMAXSPELLS);
	_memorizedSpells.reserve(constants.KMAXMEMORIZED_SPELLS);
	_items.reserve(constants.KMAXITEMS);
	_weapon.reserve(constants.KMAXWEAPONS);
	_armor.reserve(constants.KMAXARMORS);
	_gauntlet.reserve(constants.KMAXGAUNTLETS);

	attacking = false;
	defending = false;

	//ID = idChrctr;
	level = 1;
	life = defaultLife = 150;
	master = defaultMaster = 100;
	attack = 25;
	defense = 15;
	magicDef = 13;
	criticalHit = 2;
	criticalProb = 16;
	luck = 75;
	evasion = 25;
	
	_motor = ATlocMotorFacade::GetInstance(this);

	position.X = position.Y = position.Z = 0.0;

	_fileRoot = TEXT("/Game/Models/Characters/GuideMonk_Cube_000.GuideMonk_Cube_000");
	_auxFilePath = TEXT("/Game/Models/Characters/GuideMonk_Cube_001.GuideMonk_Cube_001");
	_auxFilePath2 = TEXT("");
	_name = TEXT("Enemy");


	//USceneComponent* _rootComponent = CreateDefaultSubobject<USceneComponent>("RootEnemy");

	_charMesh = _motor->SetMesh(TEXT("enemyMesh"), (const TCHAR*)_fileRoot, GetRootComponent(), this);

	//_wpnMesh->SetupAttachment(_interactionCollision);
	_charMesh->SetupAttachment(GetRootComponent());
	_auxCharMesh = _motor->SetMesh(TEXT("coatEnemy"), (const TCHAR*) _auxFilePath, GetRootComponent(), this);
	_auxCharMesh->SetupAttachment(GetRootComponent());
	//_auxCharMesh2->SetupAttachment(GetRootComponent());


	/*
	_charMesh->SetRelativeLocation(FVector(GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z - 90));
	_charMesh->SetRelativeRotation(FRotator(GetActorRotation().Pitch, GetActorRotation().Yaw, GetActorRotation().Roll));
	_auxCharMesh->SetRelativeLocation(FVector(GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z - 90));
	_auxCharMesh->SetRelativeRotation(FRotator(GetActorRotation().Pitch, GetActorRotation().Yaw, GetActorRotation().Roll));
	*/
}

ATlocEnemy::ATlocEnemy(int idChrctr, int lvl, int lif, int att, int def, int magdef, int crit, int critProb, int lck, int eva)
{
	ATlocEnemy();
	ID = idChrctr;
	level = lvl;
	life = defaultLife = lif;
	attack = att;
	defense = def;
	magicDef = magdef;
	criticalHit = crit;
	criticalProb = critProb;
	luck = lck;
	evasion = eva;

}

ATlocEnemy::~ATlocEnemy()
{
	int size = 0;
	for (size; size < _ingredients.size(); size++)
	{
		for (int j = 0; j < _ingredients[size].size(); j++)
		{
			_ingredients[size][j] = NULL;
		}
	}

	size = 0;
	for (size; size < _learnedSpells.size(); size++)
	{
		delete _learnedSpells[size];
	}

	size = 0;
	for (size; size < _memorizedSpells.size(); size++)
	{
		delete _memorizedSpells[size];
	}

	size = 0;
	for (size; size < _items.size(); size++)
	{
		for (int j = 0; j < _items[size].size(); j++)
		{
			_items[size][j] = NULL;
		}
	}

	size = 0;
	for (size; size < _weapon.size(); size++)
	{
		_weapon[size] = NULL;
	}

	size = 0;
	for (size; size < _armor.size(); size++)
	{
		_armor[size] = NULL;
	}

	size = 0;
	for (size; size < _armor.size(); size++)
	{
		_gauntlet[size] = NULL;
	}

	defending = false;

	ID = 0;
	level = 0;
	life = defaultLife = 0;
	attack = 0;
	defense = 0;
	magicDef = 0;
	criticalHit = 0;
	criticalProb = 0;
	luck = 0;
	evasion = 0;
}

// Called when the game starts or when spawned
void ATlocEnemy::BeginPlay()
{
	Super::BeginPlay();

	//_motor->RegisterMeshComponent(_charMesh);
	//_motor->RegisterMeshComponent(_auxCharMesh);
	//AddActorLocalOffset(FVector(0.0f, 0.0f, 0.0f), true);
}

// Called every frame
void ATlocEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

void ATlocEnemy::replaceEnemy(ATlocEnemy* _enm)
{
	position = _enm->GetPosition();
	rotation = _enm->GetRotation();
	SetActorLocationAndRotation(position, rotation);
	TArray<TCHAR*> paths = _enm->GetMeshesFileRoot();
	_fileRoot = paths[0];
	_auxFilePath = paths[1];
	_auxFilePath2 = paths[2];
	if (_charMesh != NULL)
	{
		_motor->DestroyMeshComponent(_charMesh);
		_charMesh = NULL;
	}
	if (_auxCharMesh != NULL)
	{
		_motor->DestroyMeshComponent(_auxCharMesh);
		_auxCharMesh = NULL;
	}
	if (_auxCharMesh2 != NULL)
	{
		_motor->DestroyMeshComponent(_auxCharMesh2);
		_auxCharMesh2 = NULL;
	}
	_charMesh = _motor->SetMesh((const TCHAR*)_name, (const TCHAR*)_fileRoot, GetRootComponent(), this);
	_charMesh->SetupAttachment(GetRootComponent());
	_motor->RegisterMeshComponent(_charMesh);
	if (*_auxFilePath !=  _T('\0'))
	{
		_auxCharMesh = _motor->SetMesh(TEXT("Auxiliar mesh"), (const TCHAR*)_auxFilePath, GetRootComponent(), this);
		_auxCharMesh->SetupAttachment(GetRootComponent());
		_motor->RegisterMeshComponent(_auxCharMesh);
		if (*_auxFilePath2 != _T('\0'))
		{
			_auxCharMesh2 = _motor->SetMesh(TEXT("Auxiliar mesh 2"), (const TCHAR*)_auxFilePath2, GetRootComponent(), this);
			_motor->RegisterMeshComponent(_auxCharMesh2);
			_auxCharMesh2->SetupAttachment(GetRootComponent());
		}
	}
	//_charMesh->SetRelativeLocationAndRotation(pos, rot);
}

// Called to bind functionality to input
void ATlocEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

/***************************** Modify life **************************
*** 	Function that adds the quantity parameter value to the   ****
***	character's life. Quantity value may be positive or negative ****
*********************************************************************
*		In:
*			float quantity
*
*		Out:
*
*/
void ATlocEnemy::ModifyLife(float quantity)
{
	UE_LOG(LogTemp, Warning, TEXT("You hurt the enemy."));
	life += quantity;
	if (life <= 0)
	{
		//He/she dies
		life = 0;
	}
	else if (quantity < 0)
	{
		GlobalConstants constants;
		invulnerable = true;
		invulnerableTime = constants.KINVULNERABLE_TIME;
	}
	else if (life > defaultLife)
	{
		life = defaultLife;
	}
}

/*************************** Attack ***************************
****  Function that calculates the damage the player will  ****
****  cause to the enemies whom the player is attacking to ****
***************************************************************
*		In:
*			
*		Out:
*			int damage
*
*/
int ATlocEnemy::Attack()
{
	GlobalConstants constants;
	float damage = constants.KBASICDAMAGE * attack;

	int hitProbability = rand() % constants.KPERCENT;
	if (hitProbability >= luck)
	{
		return constants.KMINUS_ONE;
	}
	int critProbability = rand() % constants.KPERCENT;
	if (critProbability < criticalProb)
	{
		damage *= criticalHit;
	}

	return int(damage);
}

int ATlocEnemy::Magic()
{
	return 0;
}

void ATlocEnemy::Transact()
{
}

void ATlocEnemy::Talk()
{
}

void ATlocEnemy::Move()
{
}

void ATlocEnemy::Defend()
{
}

void ATlocEnemy::SetMesh(const TCHAR* fileRoot, int mesh)
{
	switch (mesh)
	{
		case 2:
			_auxFilePath = (TCHAR*)fileRoot;
			fileRoot = NULL;
			_auxCharMesh = _motor->SetMesh(TEXT("Auxiliar mesh"), (const TCHAR*)_auxFilePath, GetRootComponent(), this);
			break;

		case 3:
			_auxFilePath2 = (TCHAR*)fileRoot;
			fileRoot = NULL;
			_auxCharMesh2 = _motor->SetMesh(TEXT("Auxiliar mesh 2"), (const TCHAR*)_auxFilePath2, GetRootComponent(), this);
			break;

		default:
			_fileRoot = (TCHAR*)fileRoot;
			fileRoot = NULL;
			_charMesh = _motor->SetMesh((const TCHAR*)_name, (const TCHAR*)_fileRoot, GetRootComponent(), this);
			break;

	}
}

void ATlocEnemy::SetPosition(FVector newPosition)
{
	position = newPosition;
	SetActorLocation(newPosition);
	_charMesh->SetRelativeLocation(newPosition);
}

void ATlocEnemy::SetRotation(FRotator newRotation)
{
	rotation = newRotation;
	SetActorRotation(newRotation);
	_charMesh->SetRelativeRotation(newRotation);
}

bool ATlocEnemy::GetDefend()
{
	return defending;
}

int ATlocEnemy::GetLife()
{
	return life;
}

UStaticMeshComponent* ATlocEnemy::GetMesh()
{
	return _charMesh;
}

FVector ATlocEnemy::GetPosition()
{
	return position;
}

FRotator ATlocEnemy::GetRotation()
{
	return rotation;
}

TCHAR* ATlocEnemy::GetMeshFileRoot()
{
	return _fileRoot;
}

TArray<TCHAR*> ATlocEnemy::GetMeshesFileRoot()
{
	TArray<TCHAR*> paths;
	paths.Push(_fileRoot);
	paths.Push(_auxFilePath);
	paths.Push(_auxFilePath2);
	return paths;
}

