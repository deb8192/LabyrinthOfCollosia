// Fill out your copyright notice in the Description page of Project Settings.


#include "TlocEnemy.h"
#include "../Public/GlobalConstants.h"


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

	defending = false;

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
}

// Called when the game starts or when spawned
void ATlocEnemy::BeginPlay()
{
	Super::BeginPlay();
	
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

void ATlocEnemy::ModifyLife(float quantity)
{
	life += quantity;
	if (life < 0)
	{
		life = 0;
	}
	else if (life > defaultLife)
	{
		life = defaultLife;
	}
}

/************************** Attack **************************
***	Function that calculates the damage the player will  ****
***	cause to the enemies whom the player is attacking to ****
*************************************************************
*				In:
*					TlocWeapon* wp  -> player's equiped weapon
*					ATlocEnemy* enm -> attacked enemy
*
*				Out:
*					int damage
*
*/
int ATlocEnemy::Attack()
{
	GlobalConstants constants;
	float damage = constants.KBASICDAMAGE * attack;

	int hitProbability = rand() % constants.KPERCENT;
	if (hitProbability >= luck)
	{
		return -1;
	}
	int critProbability = rand() % constants.KPERCENT;
	if (critProbability < criticalProb)
	{
		damage *= criticalHit;
	}
	//_ply->ModifyLife(int(damage));

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

