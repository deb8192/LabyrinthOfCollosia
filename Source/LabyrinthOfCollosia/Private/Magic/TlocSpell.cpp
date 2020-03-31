// Fill out your copyright notice in the _description page of Project Settings.


#include "..\Public\Magic\TlocSpell.h"
#include "..\Public\GlobalConstants.h"

TlocSpell::TlocSpell()
{
	GlobalConstants constants;
	ID = -1;
	_spellName = _description = nullptr;
	level = 1; 
	numUses = 0;
	basicPower = 0;
	ingredients.reserve(constants.KTHREE);
	active = false;
}

TlocSpell::TlocSpell(int idSpll, const TCHAR* nm, const TCHAR* desc, float pwr, bool act, std::vector<TlocIngredients*> ingrdnts)
{
	TlocSpell();
	ID = idSpll;
	_spellName = (TCHAR*) nm;
	_description = (TCHAR*)desc;
	basicPower = pwr;
	active = act;
	ingredients = ingrdnts;
}

TlocSpell::~TlocSpell()
{
	int size = ingredients.size();
	ID = 0;
	basicPower = 0;
	level = 0;
	_spellName = _description = nullptr;
	numUses = 0;
	active = false;

	while (size > 0)
	{
		size--;
		delete ingredients[size];
	}
	
}

void TlocSpell::IncNumUses()
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

int TlocSpell::GetId()
{
	return ID;
}

TCHAR* TlocSpell::GetName()
{
	return _spellName;
}

TCHAR* TlocSpell::GetDescription()
{
	return _description;
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

void TlocSpell::SetName(const TCHAR* nm)
{
	_spellName = (TCHAR*) nm;
}

void TlocSpell::SetDescription(const TCHAR* desc)
{
	_description = (TCHAR*) desc;
}

void TlocSpell::SetLevel(int lvl)
{
	level = lvl;
}

void TlocSpell::SetNumUses(int uses)
{
	numUses = uses;
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

