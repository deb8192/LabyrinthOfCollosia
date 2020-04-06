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
	speed = 4.0f;

	jewels = 0;
	
	_motor = ATlocMotorFacade::GetInstance(this);

	position.X = position.Y = position.Z = 0.0;
	renderPosition.X = renderPosition.Y = renderPosition.Z = 0.0;
	rotation = renderRotation = FRotator::ZeroRotator;

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
		_ingredients[size] = nullptr;
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
			_items[size][j] = nullptr;
		}
	}

	size = 0;
	for (size; size < _weapon.size(); size++)
	{
		_weapon[size] = nullptr;
	}

	size = 0;
	for (size; size < _armor.size(); size++)
	{
		_armor[size] = nullptr;
	}

	size = 0;
	for (size; size < _armor.size(); size++)
	{
		_gauntlet[size] = nullptr;
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

void ATlocEnemy::moveEntity(float updTime)
{
	GlobalConstants constants;

	//pt es el porcentaje de tiempo pasado desde la posicion
    //de update antigua hasta la nueva
	float pt = moveTime / updTime;

	if (pt > constants.KONE_F)
	{
		pt = constants.KONE_F;
	}

	renderPosition.X = lastPosition.X * (constants.KONE_F - pt) + position.X * pt;
	renderPosition.Y = lastPosition.Y * (constants.KONE_F - pt) + position.Y * pt;

}

void ATlocEnemy::rotateEntity(float updTime)
{
	GlobalConstants constants;

	//pt es el porcentaje de tiempo pasado desde la posicion
	//de update antigua hasta la nueva
	float pt = moveTime / updTime;

	if (pt > constants.KONE_F)
	{
		pt = constants.KONE_F;
	}
	else if (pt < constants.KZERO_F)
	{
		pt = constants.KZERO_F;
	}

	renderPosition.X = lastPosition.X * (constants.KONE_F - pt) + position.X * pt;
	renderPosition.Y = lastPosition.Y * (constants.KONE_F - pt) + position.Y * pt;

	renderRotation.Roll = lastRotation.Roll * (constants.KONE_F - pt) + rotation.Roll * pt;
	renderRotation.Pitch = lastRotation.Pitch * (constants.KONE_F - pt) + rotation.Pitch * pt;
	renderRotation.Yaw = lastRotation.Yaw * (constants.KONE_F - pt) + rotation.Yaw * pt;
}

void ATlocEnemy::updateTimeMove(float rendTime)
{
	moveTime += rendTime;
}

/*void ATlocEnemy::moveVertically(float value)
{
	GlobalConstants constants;
	lastPosition.Y = position.Y;
	position.Y += value* speed* constants.KUPDATE_TIME;
	//AddMovementInput(GetActorForwardVector(), value*speed * GetWorld()->GetDeltaSeconds());
}

void ATlocEnemy::moveHorizontally(float value)
{
	GlobalConstants constants;
	lastPosition.X = position.X;
	position.X += value * speed * constants.KUPDATE_TIME;
	//AddMovementInput(GetActorRightVector(), value * speed * GetWorld()->GetDeltaSeconds());
}

void ATlocEnemy::rotateHorizontally(float value)
{
	GlobalConstants constants;
	lastRotation.Yaw = rotation.Yaw;
	rotation.Yaw = value * constants.KROTATIONSPEED * constants.KUPDATE_TIME;
	//AddControllerYawInput(value * constants.KROTATIONSPEED * GetWorld()->GetDeltaSeconds());
}*/

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
	if (_charMesh != nullptr)
	{
		_motor->DestroyMeshComponent(_charMesh);
		_charMesh = nullptr;
	}
	if (_auxCharMesh != nullptr)
	{
		_motor->DestroyMeshComponent(_auxCharMesh);
		_auxCharMesh = nullptr;
	}
	if (_auxCharMesh2 != nullptr)
	{
		_motor->DestroyMeshComponent(_auxCharMesh2);
		_auxCharMesh2 = nullptr;
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
	GlobalConstants constants;
	UE_LOG(LogTemp, Warning, TEXT("You hurt the enemy."));
	if (quantity < 0)
	{
		life += (quantity - defense * constants.KTEN_PERCENT);
		invulnerable = true;
		invulnerableTime = constants.KINVULNERABLE_TIME;
	}
	else
	{
		life += quantity;
	}
	if (life <= 0)
	{
		//He/she dies
		life = 0;
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

void ATlocEnemy::AddWeapon(TlocWeapon& wpn)
{
	_weapon.push_back(&wpn);
}

int ATlocEnemy::GetID()
{
	return ID;
}

int ATlocEnemy::GetLevel()
{
	return level;
}

int ATlocEnemy::GetLife()
{
	return life;
}

float ATlocEnemy::GetDefaultLife()
{
	return defaultLife;
}

float ATlocEnemy::GetMaster()
{
	return master;
}

float ATlocEnemy::GetDefaultMaster()
{
	return defaultMaster;
}

int ATlocEnemy::GetAttack()
{
	return attack;
}

int ATlocEnemy::GetDefense()
{
	return defense;
}

int ATlocEnemy::GetMagicDefense()
{
	return magicDef;
}

float ATlocEnemy::GetCriticalHit()
{
	return criticalHit;
}

float ATlocEnemy::GetCriticalProb()
{
	return criticalProb;
}

int ATlocEnemy::GetEvasion()
{
	return evasion;
}

int ATlocEnemy::GetLuck()
{
	return luck;
}

bool ATlocEnemy::GetDefend()
{
	return defending;
}

int ATlocEnemy::GetAttacking()
{
	return attacking;
}

int ATlocEnemy::GetJewels()
{
	return jewels;
}

bool ATlocEnemy::GetInvulnerable()
{
	return invulnerable;
}

float ATlocEnemy::GetInvulnerableTime()
{
	return invulnerableTime;
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

std::vector<TlocIngredients*> ATlocEnemy::GetIngredients()
{
	return _ingredients;
}

std::vector<TlocSpell*> ATlocEnemy::GetSpells()
{
	return _learnedSpells;
}

std::vector<TlocSpell*> ATlocEnemy::GetMemorizedSpells()
{
	return _memorizedSpells;
}

std::vector<std::vector<TlocItem*>> ATlocEnemy::GetItems()
{
	return _items;
}

std::vector<TlocWeapon*> ATlocEnemy::GetWeapons()
{
	return _weapon;
}

std::vector<TlocArmor*> ATlocEnemy::GetArmors()
{
	return _armor;
}

std::vector<TlocGauntlet*> ATlocEnemy::GetGauntlets()
{
	return _gauntlet;
}

std::queue<int> ATlocEnemy::GetBuffAilments()
{
	return _buffsAilments;
}

std::queue<float> ATlocEnemy::GetBuffAilmentsTime()
{
	return buffsAilmentsTime;
}

void ATlocEnemy::SetInitialLife(float lif)
{
	SetLife(lif);
	SetDefaultLife(lif);
}

void ATlocEnemy::SetInitialMaster(float mstr)
{
	SetMaster(mstr);
	SetDefaultMaster(mstr);
}

void ATlocEnemy::SetID(int id)
{
	ID = id;
}

void ATlocEnemy::SetLevel(int lvl)
{
	level = lvl;
}

void ATlocEnemy::SetLife(float lif)
{
	life = lif;
}

void ATlocEnemy::SetDefaultLife(float dfltLif)
{
	defaultLife = dfltLif;
}

void ATlocEnemy::SetMaster(float mstr)
{
	master = mstr;
}

void ATlocEnemy::SetDefaultMaster(float dfltMstr)
{
	defaultMaster = dfltMstr;
}

void ATlocEnemy::SetAttack(int att)
{
	attack = att;
}

void ATlocEnemy::SetDefense(int def)
{
	defense = def;
}

void ATlocEnemy::SetMagicDefense(int magDef)
{
	magicDef = magDef;
}

void ATlocEnemy::SetCriticalHit(float critHit)
{
	GlobalConstants constants;
	criticalHit = critHit / constants.KPERCENT;
}

void ATlocEnemy::SetCriticalProb(float critProb)
{
	GlobalConstants constants;
	criticalProb = critProb / constants.KPERCENT;
}

void ATlocEnemy::SetEvasion(int ev)
{
	evasion = ev;
}

void ATlocEnemy::SetLuck(int lck)
{
	luck = lck;
}

void ATlocEnemy::SetDefend(bool dfnd)
{
	defending = dfnd;
}

void ATlocEnemy::SetAttacking(bool attckng)
{
	attacking = attckng;
}

void ATlocEnemy::SetJewels(int jwls)
{
	jewels = jwls;
}

void ATlocEnemy::SetInvulnerable(bool inv)
{
	invulnerable = inv;
}

void ATlocEnemy::SetInvulnerableTime(float invTime)
{
	invulnerableTime = invTime;
}

void ATlocEnemy::SetMesh(const TCHAR* fileRoot, int mesh)
{
	switch (mesh)
	{
	case 2:
		_auxFilePath = (TCHAR*)fileRoot;
		fileRoot = nullptr;
		_auxCharMesh = _motor->SetMesh(TEXT("Auxiliar mesh"), (const TCHAR*)_auxFilePath, GetRootComponent(), this);
		break;

	case 3:
		_auxFilePath2 = (TCHAR*)fileRoot;
		fileRoot = nullptr;
		_auxCharMesh2 = _motor->SetMesh(TEXT("Auxiliar mesh 2"), (const TCHAR*)_auxFilePath2, GetRootComponent(), this);
		break;

	default:
		_fileRoot = (TCHAR*)fileRoot;
		fileRoot = nullptr;
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

void ATlocEnemy::SetIngredients(std::vector<TlocIngredients*>& _ing)
{
	_ingredients = _ing;
}

void ATlocEnemy::SetSpells(std::vector<TlocSpell*>& splls)
{
	_learnedSpells = splls;
}

void ATlocEnemy::SetMemorizedSpells(std::vector<TlocSpell*>& _memSplls)
{
	_memorizedSpells = _memSplls;
}

void ATlocEnemy::SetItems(std::vector<std::vector<TlocItem*>>& _itms)
{
	_items = _itms;
}

void ATlocEnemy::SetWeapons(std::vector<TlocWeapon*>& _wpns)
{
	_weapon = _wpns;
}

void ATlocEnemy::SetArmors(std::vector<TlocArmor*>& _armrs)
{
	_armor = _armrs;
}

void ATlocEnemy::SetGauntlets(std::vector<TlocGauntlet*>& _gntlt)
{
	_gauntlet = _gntlt;
}

void ATlocEnemy::SetBuffAilments(std::queue<int>& _bffsAil)
{
	_buffsAilments = _bffsAil;
}

void ATlocEnemy::SetBuffAilmentsTime(std::queue<float>& _bffsAilTime)
{
	buffsAilmentsTime = _bffsAilTime;
}
