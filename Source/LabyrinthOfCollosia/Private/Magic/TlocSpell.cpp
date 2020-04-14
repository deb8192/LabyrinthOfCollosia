// Fill out your copyright notice in the _description page of Project Settings.


#include "..\Public\Magic\TlocSpell.h"
#include "..\Public\GlobalConstants.h"

TlocSpell::TlocSpell()
{
	GlobalConstants constants;
	ID = -1;
	menuID = -1;
	_spellName = _description = _iconFilePath = nullptr;
	level = 1; 
	numUses = 0;
	target = 0;
	basicPower = 0;
	target = Target::ENEMY;
	ingredients.reserve(constants.KTHREE);
	active = false;
}

TlocSpell::TlocSpell(int idSpll, const TCHAR* nm, const TCHAR* desc, const TCHAR* icon, int trgt, float pwr, bool act, std::vector<TlocIngredients*> ingrdnts)
{
	TlocSpell();
	ID = idSpll;
	_spellName = (TCHAR*) nm;
	_description = (TCHAR*) desc;
	_iconFilePath = (TCHAR*) icon;
	target = trgt;
	basicPower = pwr;
	active = act;
	ingredients = ingrdnts;
}

TlocSpell::~TlocSpell()
{
	int size = ingredients.size();
	ID = 0;
	menuID = 0;
	target = 0;
	basicPower = 0;
	level = 0;
	_spellName = _description = _iconFilePath = nullptr;
	numUses = 0;
	active = false;
	target = Target::ENEMY;

	while (size > 0)
	{
		size--;
		delete ingredients[size];
	}
	
}
int TlocSpell::CastSpell(AActor& _target)
{
	return -1;
}

int TlocSpell::CastSpell(std::vector<AActor*>& _target)
{
	return -1;
}

void TlocSpell::incNumUses()
{
	GlobalConstants constants;
	if (numUses < constants.KMAXUSES * constants.KMAXALCHEMY_LEVEL)
	{
		numUses++;
		if (GetNextLevel() == constants.KZERO)
		{
			if (level < constants.KMAXALCHEMY_LEVEL)
			{
				incLevel();
			}
		}
	}
}

void TlocSpell::incLevel()
{
	level++;
	incBasicPower();
}

void TlocSpell::incBasicPower()
{
	GlobalConstants constants;
	switch (ID)
	{
		case 7:
			incBasicPowerAQuarter();
			break;

		case 8:
			incBasicPowerOne();
			break;

		default:
			incBasicPowerAHalf();
			break;
	}
}

void TlocSpell::incBasicPowerOne()
{
	basicPower++;
}

void TlocSpell::incBasicPowerAHalf()
{
	GlobalConstants constants;
	basicPower += (basicPower / constants.KTWO);
}

void TlocSpell::incBasicPowerAQuarter()
{
	GlobalConstants constants;
	basicPower += (basicPower / constants.KFOUR);
}

void TlocSpell::getEffect()
{
	/*switch (ID)
	{
		case
	}*/
}

int TlocSpell::GetId()
{
	return ID;
}

int TlocSpell::GetMenuId()
{
	return menuID;
}

TCHAR* TlocSpell::GetName()
{
	return _spellName;
}

TCHAR* TlocSpell::GetDescription()
{
	return _description;
}

TCHAR* TlocSpell::GetIconFilePath()
{
	return _iconFilePath;
}

int TlocSpell::GetLevel()
{
	return level;
}

int TlocSpell::GetNumUses()
{
	return numUses;
}

int TlocSpell::GetNextLevel()
{
	GlobalConstants constants;
	if (level < constants.KMAXALCHEMY_LEVEL)
	{
		return level * constants.KMAXUSES - numUses;
	}
	else return constants.KMINUS_ONE;
}

int TlocSpell::GetKindTarget()
{
	return target;
}

float TlocSpell::GetBasicPower()
{
	return basicPower;
}

std::vector<TlocIngredients*> TlocSpell::GetIngredients()
{
	return ingredients;
}

bool TlocSpell::GetActive()
{
	return active;
}

void TlocSpell::SetId(int id)
{
	ID = id;
}

void TlocSpell::SetMenuId(int menId)
{
	menuID = menId;
}

void TlocSpell::SetName(const TCHAR* nm)
{
	_spellName = (TCHAR*) nm;
}

void TlocSpell::SetDescription(const TCHAR* desc)
{
	_description = (TCHAR*) desc;
}

void TlocSpell::SetIconFilePath(const TCHAR* icon)
{
	_iconFilePath = (TCHAR*) icon;
}

void TlocSpell::SetLevel(int lvl)
{
	level = lvl;
}

void TlocSpell::SetNumUses(int uses)
{
	numUses = uses;
}

void TlocSpell::SetKindTarget(int trgt)
{
	target = trgt;
}

void TlocSpell::SetBasicPower(float pwr)
{
	basicPower = pwr;
}

void TlocSpell::SetIngredients(std::vector<TlocIngredients*> &ing)
{
	ingredients = ing;
}

void TlocSpell::SetActive(bool act)
{
	active = act;
}

