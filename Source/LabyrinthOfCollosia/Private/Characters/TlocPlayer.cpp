// Fill out your copyright notice in the Description page of Project Settings.


#include "../Public/Characters/TlocPlayer.h"
#include "../Public/GlobalConstants.h"

#include <stdlib.h>

// Sets default values
TlocPlayer::TlocPlayer()
{
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

TlocPlayer::TlocPlayer(int idChrctr, int lvl, int lif, int att, int def, int magdef, int exp, int nxtlvl, int crit, int critProb, int lck, int eva)
{
	TlocPlayer();
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

	experience = exp;
	nextLevel = nxtlvl;

}

TlocPlayer::~TlocPlayer()
{
	int size = 0;
	for (size; size < _ingredients.size(); size++)
	{
		delete _ingredients[size];
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

	experience = 0;
	nextLevel = 0;
}

void TlocPlayer::ModifyLife(float quantity)
{
	life += quantity;
	if (life <= 0)
	{
		//Se muere, se acaba la partida
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

int TlocPlayer::Attack()
{
	GlobalConstants constants;

	//If hitProbability random value is bigger than luck, player will miss the attack
	int hitProbability = rand() % constants.KPERCENT;
	if (hitProbability >= luck)
	{
		return constants.KMINUS_ONE;
	}
	return constants.KZERO;
}

/************************** Attack **************************
***	Function that calculates the damage that player will ****
***	cause to the enemies whom the player is attacking to ****
*************************************************************
*				In: 
*					TlocWeapon* wp  -> player's equiped weapon
*
*				Out:
*					int damage -> attack damage
*
*/
int TlocPlayer::Attack(TlocWeapon* _wp)
{
	GlobalConstants constants;

	if(Attack() == constants.KMINUS_ONE)
	{
		return constants.KMINUS_ONE;
	}

	float damage = constants.KBASICDAMAGE * (attack + _wp->GetAttack());

	//If critProbability random value is lower than criticalProb, player hit will be critical
	int critProbability = rand() % constants.KPERCENT;
	if (critProbability < criticalProb * _wp->GetCriticalProbabilityInc())
	{
		damage *= (criticalHit * _wp->GetCriticalDamageInc());
	}

	return int(damage);
}

int TlocPlayer::Magic()
{
	return 0;
}

void TlocPlayer::Transact()
{
}

void TlocPlayer::Talk()
{
}

void TlocPlayer::Move()
{
}

void TlocPlayer::Defend()
{
}

bool TlocPlayer::GetDefend()
{
	return defending;
}


