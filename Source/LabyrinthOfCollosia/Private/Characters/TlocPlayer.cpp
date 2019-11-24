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
}

void TlocPlayer::ModifyLife(float quantity)
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

/*int TlocPlayer::Attack()
{
	return 0;
}*/

/************************** Attack **************************
***	Function that calculates the damage that player will ****
***	cause to the enemies whom the player is attacking to ****
*************************************************************
*				In: 
*					TlocWeapon* wp  -> player's equiped weapon
*					ATlocEnemy* enm -> attacked enemy
*
*				Out:
*					int damage -> attack damage
*
*/
int TlocPlayer::Attack(TlocWeapon* _wp)
{
	GlobalConstants constants;
	float damage = constants.KBASICDAMAGE * (attack + _wp->GetAttack());

	//If hitProbability random value is bigger than luck, player will miss the attack
	int hitProbability = rand() % constants.KPERCENT;
	if (hitProbability >= luck)
	{
		return -1;
	}

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

