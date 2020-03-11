// Fill out your copyright notice in the Description page of Project Settings.


#include "../Public/Characters/TlocPlayer.h"
#include "../Public/Characters/TlocHumanPlayer.h"
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

	attacking = false;
	defending = false;

	//ID = idChrctr;
	level = 1;
	life = defaultLife = 75;
	attack = 25;
	defense = 15;
	magicDef = 13;
	criticalHit = 2;
	criticalProb = 16;
	luck = 75;
	evasion = 25;
	

	position.X = position.Y = position.Z = 0.0;

	experience = 0;
	nextLevel = 200;


}

//COMENTADO PARA EXPORTACIONES DE PROYECTO

/*TlocPlayer::TlocPlayer(int idChrctr, int lvl, int lif, int att, int def, int magdef, int exp, int nxtlvl, int crit, int critProb, int lck, int eva)
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

}*/

TlocPlayer::~TlocPlayer()
{
	int size = 0;

	if (!_ingredients.empty())
	{
		for (size; size < _ingredients.size(); size++)
		{
			if (!_ingredients[size].empty())
			{
				for (int j = 0; j < _ingredients[size].size(); j++)
				{
					_ingredients[size][j] = NULL;
				}
			}
		}
	}

	size = 0;
	if (!_learnedSpells.empty())
	{
		for (size; size < _learnedSpells.size(); size++)
		{
			_learnedSpells[size] = NULL;
		}
	}

	size = 0;
	if (!_memorizedSpells.empty())
	{
		for (size; size < _memorizedSpells.size(); size++)
		{
			_memorizedSpells[size] = NULL;
		}
	}

	size = 0;
	if (!_items.empty())
	{
		for (size; size < _items.size(); size++)
		{
			if (!_items[size].empty())
			{
				for (int j = 0; j < _items[size].size(); j++)
				{
					_items[size][j] = NULL;
				}
			}
		}
	}

	size = 0;
	if (!_weapon.empty())
	{
		for (size; size < _weapon.size(); size++)
		{
			_weapon[size] = NULL;
		}
	}

	size = 0;
	if (!_armor.empty())
	{
		for (size; size < _armor.size(); size++)
		{
			_armor[size] = NULL;
		}
	}

	size = 0;
	if (!_gauntlet.empty())
	{
		for (size; size < _gauntlet.size(); size++)
		{
			_gauntlet[size] = NULL;
		}
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

		UE_LOG(LogTemp, Warning, TEXT("You missed the attack."));
		return constants.KMINUS_ONE;
	}

	float damage = constants.KBASICDAMAGE;
	int critProbability = rand() % constants.KPERCENT;

	//If player posses a weapon
	if (_wp != nullptr)
	{
		damage *= (attack + _wp->GetAttack());
		//If critProbability random value is lower than criticalProb, player hit will be critical
		if (critProbability < criticalProb * _wp->GetCriticalProbabilityInc())
		{
			damage *= (criticalHit * _wp->GetCriticalDamageInc());
		}
	}


	//If player don't posses any weapon
	else
	{
		damage *= attack;
		//If critProbability random value is lower than criticalProb, player hit will be critical
		if (critProbability < criticalProb)
		{
			damage *= criticalHit;
		}
	}

	damage += rand() % constants.KMAX_VARIABLE_DAMAGE + constants.KMIN_VARIABLE_DAMAGE;

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

int TlocPlayer::GetLife()
{
	return life;
}

void TlocPlayer::SetPosition(FVector newPosition)
{
	position = newPosition;
	_wpnMesh->SetRelativeLocation(newPosition);
}

void TlocPlayer::SetRotation(FRotator newRotation)
{
	rotation = newRotation;
	_wpnMesh->SetRelativeRotation(newRotation);
}

FVector TlocPlayer::GetPosition()
{
	return position;
}

FRotator TlocPlayer::GetRotation()
{
	return rotation;
}


