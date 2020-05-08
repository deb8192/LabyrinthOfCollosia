// Fill out your copyright notice in the Description page of Project Settings.


#include "../Public/Characters/TlocPlayer.h"
#include "../Public/Characters/TlocHumanPlayer.h"
#include "../Public/GlobalConstants.h"

#include <cstdlib>

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
	life = defaultLife = 250;
	master = defaultMaster = 100;
	attack = 25;
	defense = 15;
	magicDef = 13;
	criticalHit = 2;
	criticalProb = 16;
	luck = 75;
	evasion = 25;
	speed = 400.0f;
	
	jewels = 0;
	_attackingSpell = nullptr;
	_attackingSpellIngredients.reserve(3);

	experience = 0;
	nextLevel = 200;
	player = 0;
	_targetEnemies.reserve(constants.KMAX_NUM_TARGETS);
	_targetPlayers.reserve(2);
	_targetObjects.reserve(constants.KMAX_NUM_TARGETS);

	_className = nullptr;


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
			_ingredients[size] = nullptr;
		}
	}

	size = 0;
	if (!_learnedSpells.empty())
	{
		for (size; size < _learnedSpells.size(); size++)
		{
			_learnedSpells[size] = nullptr;
		}
	}

	size = 0;
	if (!_memorizedSpells.empty())
	{
		for (size; size < _memorizedSpells.size(); size++)
		{
			_memorizedSpells[size] = nullptr;
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
					_items[size][j] = nullptr;
				}
			}
		}
	}

	size = 0;
	if (!_weapon.empty())
	{
		for (size; size < _weapon.size(); size++)
		{
			_weapon[size] = nullptr;
		}
	}

	size = 0;
	if (!_armor.empty())
	{
		for (size; size < _armor.size(); size++)
		{
			_armor[size] = nullptr;
		}
	}

	size = 0;
	if (!_gauntlet.empty())
	{
		for (size; size < _gauntlet.size(); size++)
		{
			_gauntlet[size] = nullptr;
		}
	}

	defending = false;

	ID = 0;
	level = 0;
	life = defaultLife = 0;
	master = defaultMaster = 0;
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

void TlocPlayer::Update(float DeltaTime)
{
	//If actor is invulnerable, we substract deltatime to invulnerableTime
	if (invulnerable)
	{
		invulnerableTime -= DeltaTime;
		if (invulnerableTime <= 0.0)
		{
			invulnerable = false;
			invulnerableTime = 0.0;
		}
	}
}

void TlocPlayer::Render(float DeltaTime)
{
	GlobalConstants constants;
	moveEntity(constants.KUPDATE_TIME);
	rotateEntity(constants.KUPDATE_TIME);
	updateTimeMove(DeltaTime);
}

void TlocPlayer::ModifyLife(float quantity)
{
	GlobalConstants constants;
	if(quantity > 0)
		life += quantity;
	else if (quantity < 0 && !invulnerable)
	{
		life += (quantity - defense * constants.KTEN_PERCENT);
		invulnerable = true;
		invulnerableTime = constants.KINVULNERABLE_TIME;
	}
	if (life <= 0)
	{
		//Se muere, se acaba la partida
		life = 0;
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
		damage += (attack + _wp->GetAttack());
		//If critProbability random value is lower than criticalProb, player hit will be critical
		if (critProbability < criticalProb * _wp->GetCriticalProbabilityInc())
		{
			damage *= (criticalHit + _wp->GetCriticalDamageInc() + constants.KONE_F);
		}
	}


	//If player don't posses any weapon
	else
	{
		damage += attack;
		//If critProbability random value is lower than criticalProb, player hit will be critical
		if (critProbability < criticalProb)
		{
			damage *= (criticalHit + constants.KONE_F);
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

void TlocPlayer::AddWeapon(TlocWeapon& wpn)
{
	_weapon.push_back(&wpn);
}

void TlocPlayer::SelectTarget(AActor &_target, float blendTime)
{
	//_motor->SetViewTarget(this, _target, blendTime);
}


void TlocPlayer::InitMemorizedSpells()
{
	GlobalConstants constants;
	if (_memorizedSpells.size() == constants.KZERO)
	{
		for (int i = 0; i < _learnedSpells.size(); i++)
		{
			if (_learnedSpells[i]->GetActive() && _memorizedSpells.size() < constants.KMAXMEMORIZED_SPELLS)
			{
				_memorizedSpells.push_back(_learnedSpells[i]);
			}
		}
	}
}

int TlocPlayer::GetID()
{
	return ID;
}

int TlocPlayer::GetLevel()
{
	return level;
}

int TlocPlayer::GetLife()
{
	return life;
}

float TlocPlayer::GetDefaultLife()
{
	return defaultLife;
}

float TlocPlayer::GetMaster()
{
	return master;
}

float TlocPlayer::GetDefaultMaster()
{
	return defaultMaster;
}

int TlocPlayer::GetAttack()
{
	return attack;
}

int TlocPlayer::GetDefense()
{
	return defense;
}

int TlocPlayer::GetMagicDefense()
{
	return magicDef;
}

float TlocPlayer::GetCriticalHit()
{
	return criticalHit;
}

float TlocPlayer::GetCriticalProb()
{
	return criticalProb;
}

int TlocPlayer::GetEvasion()
{
	return evasion;
}

int TlocPlayer::GetLuck()
{
	return luck;
}

bool TlocPlayer::GetDefend()
{
	return defending;
}

int TlocPlayer::GetAttacking()
{
	return attacking;
}

int TlocPlayer::GetJewels()
{
	return jewels;
}

bool TlocPlayer::GetInvulnerable()
{
	return invulnerable;
}

float TlocPlayer::GetInvulnerableTime()
{
	return invulnerableTime;
}

UStaticMeshComponent* TlocPlayer::GetMesh()
{
	return _charMesh;
}

FVector TlocPlayer::GetPosition()
{
	return position;
}

FVector TlocPlayer::GetRenderPosition()
{
	return renderPosition;
}

FRotator TlocPlayer::GetRotation()
{
	return rotation;
}

FRotator TlocPlayer::GetRenderRotation()
{
	return renderRotation;
}

std::vector<TlocIngredients*> TlocPlayer::GetIngredients()
{
	return _ingredients;
}

std::vector<TlocSpell*> TlocPlayer::GetSpells()
{
	return _learnedSpells;
}

TlocSpell* TlocPlayer::GetAttackingSpell()
{
	return _attackingSpell;
}

std::vector<TlocSpell*> TlocPlayer::GetMemorizedSpells()
{
	return _memorizedSpells;
}

std::vector<std::vector<TlocItem*>> TlocPlayer::GetItems()
{
	return _items;
}

std::vector<TlocWeapon*> TlocPlayer::GetWeapons()
{
	return _weapon;
}

std::vector<TlocArmor*> TlocPlayer::GetArmors()
{
	return _armor;
}

std::vector<TlocGauntlet*> TlocPlayer::GetGauntlets()
{
	return _gauntlet;
}

std::queue<int> TlocPlayer::GetBuffAilments()
{
	return _buffsAilments;
}

std::queue<float> TlocPlayer::GetBuffAilmentsTime()
{
	return buffsAilmentsTime;
}

TCHAR* TlocPlayer::GetName()
{
	return _name;
}

TCHAR* TlocPlayer::GetClassName()
{
	return _className;
}

int TlocPlayer::GetNextLevel()
{
	return nextLevel;
}

int TlocPlayer::GetExperience()
{
	return experience;
}

int TlocPlayer::GetPlayer()
{
	return player;
}

int TlocPlayer::GetMode()
{
	return mode;
}

std::vector<AActor*> TlocPlayer::GetTargetEnemies()
{
	return _targetEnemies;
}

std::vector<AActor*> TlocPlayer::GetTargetPlayers()
{
	return _targetPlayers;
}

std::vector<AActor*> TlocPlayer::GetTargetObjects()
{
	return _targetObjects;
}

int TlocPlayer::GetTargetSelector()
{
	return targetSelector;
}

void TlocPlayer::SetInitialLife(float lif)
{
	SetLife(lif);
	SetDefaultLife(lif);
}

void TlocPlayer::SetInitialMaster(float mstr)
{
	SetMaster(mstr);
	SetDefaultMaster(mstr);
}

void TlocPlayer::SetID(int id)
{
	ID = id;
}

void TlocPlayer::SetLevel(int lvl)
{
	level = lvl;
}

void TlocPlayer::SetLife(float lif)
{
	life = lif;
}

void TlocPlayer::SetDefaultLife(float dfltLif)
{
	defaultLife = dfltLif;
}

void TlocPlayer::SetMaster(float mstr)
{
	master = mstr;
}

void TlocPlayer::SetDefaultMaster(float dfltMstr)
{
	defaultMaster = dfltMstr;
}

void TlocPlayer::SetAttack(int att)
{
	attack = att;
}

void TlocPlayer::SetDefense(int def)
{
	defense = def;
}

void TlocPlayer::SetMagicDefense(int magDef)
{
	magicDef = magDef;
}

void TlocPlayer::SetCriticalHit(float critHit)
{
	GlobalConstants constants;
	criticalHit = critHit / constants.KPERCENT;
}

void TlocPlayer::SetCriticalProb(float critProb)
{
	GlobalConstants constants;
	criticalProb = critProb / constants.KPERCENT;
}

void TlocPlayer::SetEvasion(int ev)
{
	evasion = ev;
}

void TlocPlayer::SetLuck(int lck)
{
	luck = lck;
}

void TlocPlayer::SetDefend(bool dfnd)
{
	defending = dfnd;
}

void TlocPlayer::SetAttacking(bool attckng)
{
	attacking = attckng;
}

void TlocPlayer::SetJewels(int jwls)
{
	jewels = jwls;
}

void TlocPlayer::SetInvulnerable(bool inv)
{
	invulnerable = inv;
}

void TlocPlayer::SetInvulnerableTime(float invTime)
{
	invulnerableTime = invTime;
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

void TlocPlayer::SetIngredients(std::vector<TlocIngredients*>& _ing)
{
	_ingredients = _ing;
}

void TlocPlayer::SetSpells(std::vector<TlocSpell*>& splls)
{
	_learnedSpells = splls;
}

void TlocPlayer::SetMemorizedSpells(std::vector<TlocSpell*>& _memSplls)
{
	_memorizedSpells = _memSplls;
}

void TlocPlayer::SetItems(std::vector<std::vector<TlocItem*>>& _itms)
{
	_items = _itms;
}

void TlocPlayer::SetWeapons(std::vector<TlocWeapon*>& _wpns)
{
	_weapon = _wpns;
}

void TlocPlayer::SetArmors(std::vector<TlocArmor*>& _armrs)
{
	_armor = _armrs;
}

void TlocPlayer::SetGauntlets(std::vector<TlocGauntlet*>& _gntlt)
{
	_gauntlet = _gntlt;
}

void TlocPlayer::SetBuffAilments(std::queue<int>& _bffsAil)
{
	_buffsAilments = _bffsAil;
}

void TlocPlayer::SetBuffAilmentsTime(std::queue<float>& _bffsAilTime)
{
	buffsAilmentsTime = _bffsAilTime;
}

void TlocPlayer::SetName(TCHAR* _nm)
{
	_name = _nm;
}

void TlocPlayer::SetClassName(TCHAR* _clssNm)
{
	_className = _clssNm;
}

void TlocPlayer::SetNextLevel(int nLevel)
{
	nextLevel = nLevel;
}

void TlocPlayer::SetExperience(int exp)
{
	experience = exp;
}

void TlocPlayer::SetPlayer(int plyr)
{
	player = plyr;
}

void TlocPlayer::SetMode(int mod)
{
	switch (mod)
	{
		case 1:
			mode = PlayingMode::TARGET_SELECTION;
			break;

		default:
			mode = PlayingMode::NORMAL;
	}
}

void TlocPlayer::SetTargetEnemies(std::vector<AActor*>& _enm)
{
	_targetEnemies = _enm;
}

void TlocPlayer::SetTargetPlayers(std::vector<AActor*>& _all)
{
	_targetPlayers = _all;
}

void TlocPlayer::SetTargetObjects(std::vector<AActor*>& _obj)
{
	_targetObjects = _obj;
}

void TlocPlayer::moveEntity(float updTime)
{
	GlobalConstants constants;
	if (position.X != lastPosition.X || position.Y != lastPosition.Y)
	{

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
	}
	if (position.X == lastPosition.X)
	{
		renderPosition.X = constants.KZERO_F;
	}
	if (position.Y == lastPosition.Y)
	{
		renderPosition.Y = constants.KZERO_F;
	}

}

void TlocPlayer::rotateEntity(float updTime)
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
	renderRotation.Roll = lastRotation.Roll * (constants.KONE_F - pt) + rotation.Roll * pt;
	renderRotation.Pitch = lastRotation.Pitch * (constants.KONE_F - pt) + rotation.Pitch * pt;
	renderRotation.Yaw = lastRotation.Yaw * (constants.KONE_F - pt) + rotation.Yaw * pt;
}

void TlocPlayer::updateTimeMove(float rendTime)
{
	moveTime += rendTime;
}

void TlocPlayer::selectTargetLeft()
{
	if (mode == PlayingMode::TARGET_SELECTION)
	{
		GlobalConstants constants;
		targetSelector--;
		if (targetSelector < constants.KZERO)
		{
			switch (_attackingSpell->GetKindTarget())
			{
			case 0:
				targetSelector = _targetEnemies.size();
				break;
			case 1:
				targetSelector = _targetPlayers.size();
				break;
			case 2:
				targetSelector = _targetPlayers.size() - 1;
				break;
			case 3:
				targetSelector = _targetPlayers.size() - 1;
				break;
			case 4:
				targetSelector = _targetObjects.size();
				break;
			}
		}
	}
}

void TlocPlayer::selectTargetRight()
{
	if (mode == PlayingMode::TARGET_SELECTION)
	{
		GlobalConstants constants;
		targetSelector++;
		switch (_attackingSpell->GetKindTarget())
		{
		case 0:
			if(targetSelector > _targetEnemies.size())
				targetSelector = constants.KZERO;
			break;
		case 1:
			if (targetSelector > _targetPlayers.size())
				targetSelector = constants.KZERO;
			break;
		case 2:
			if (targetSelector > _targetPlayers.size() - 1)
				targetSelector = constants.KZERO;
			break;
		case 3:
			if (targetSelector > _targetPlayers.size() - 1)
				targetSelector = constants.KZERO;
			break;
		case 4:
			if (targetSelector > _targetObjects.size() - 1)
				targetSelector = constants.KZERO;
			break;
		}
	}
}



