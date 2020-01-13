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
	attack = 25;
	defense = 15;
	magicDef = 13;
	criticalHit = 2;
	criticalProb = 16;
	luck = 75;
	evasion = 25;
	
	for (int i = 0; i < std::size(defaultPosition); i++)
	{
		defaultPosition[i] = 0.0;
	}

	_fileRoot = TEXT("/Game/Models/Characters/Hero-M.Hero-M");

	_motor = ATlocMotorFacade::GetInstance();

	USceneComponent* _rootComponent = CreateDefaultSubobject<USceneComponent>("RootEnemy");

	_charMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("enemyMesh"));
	_charMesh->SetupAttachment(_rootComponent); 
	_auxCharMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("auxEnemyMesh"));
	_auxCharMesh->SetupAttachment(_rootComponent);


	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Models/Characters/GuideMonk_Cube_000.GuideMonk_Cube_000"));

	if (MeshAsset.Succeeded())
	{
		_charMesh->SetStaticMesh(MeshAsset.Object);
		_charMesh->SetWorldScale3D(FVector(1.f));
	}

	static ConstructorHelpers::FObjectFinder<UStaticMesh> auxMeshAsset(TEXT("/Game/Models/Characters/GuideMonk_Cube_001.GuideMonk_Cube_001"));

	if (auxMeshAsset.Succeeded())
	{
		_auxCharMesh->SetStaticMesh(auxMeshAsset.Object);
		_auxCharMesh->SetWorldScale3D(FVector(1.f));
	}

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
			delete _ingredients[size][j];
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
			delete _items[size][j];
		}
	}

	size = 0;
	for (size; size < _weapon.size(); size++)
	{
		delete _weapon[size];
	}

	size = 0;
	for (size; size < _armor.size(); size++)
	{
		delete _armor[size];
	}

	size = 0;
	for (size; size < _armor.size(); size++)
	{
		delete _gauntlet[size];
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

	AddActorLocalOffset(FVector(0.0f, 0.0f, 0.0f), true);

	_charMesh->SetRelativeLocation(FVector(GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z - 90));
	_charMesh->SetRelativeRotation(FRotator(GetActorRotation().Pitch, GetActorRotation().Yaw, GetActorRotation().Roll));
	_auxCharMesh->SetRelativeLocation(FVector(GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z - 90));
	_auxCharMesh->SetRelativeRotation(FRotator(GetActorRotation().Pitch, GetActorRotation().Yaw, GetActorRotation().Roll));
	
}

// Called every frame
void ATlocEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


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
		//Se muere
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

bool ATlocEnemy::GetDefend()
{
	return defending;
}

int ATlocEnemy::GetLife()
{
	return life;
}

