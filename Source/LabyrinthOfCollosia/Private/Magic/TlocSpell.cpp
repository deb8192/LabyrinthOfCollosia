// Fill out your copyright notice in the Description page of Project Settings.


#include "..\Public\Magic\TlocSpell.h"
#include "..\Public\GlobalConstants.h"

TlocSpell::TlocSpell()
{
	level = 1;
	numUses = 0;
	active = false;
}

TlocSpell::TlocSpell(int idSpll, float pwr, std::vector<TlocIngredients*> ingrdnts)
{
	TlocSpell();
	ID = idSpll;
	basicPower = pwr;
	ingredients = ingrdnts;
}

TlocSpell::~TlocSpell()
{
	int size = ingredients.size();
	ID = 0;
	basicPower = 0;
	level = 0;
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
	numUses++;
}

int TlocSpell::GetId()
{
	return ID;
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
	return (level + constants.KUNITY) * constants.KMAXUSES - numUses;
}

float TlocSpell::GetBasicPower()
{
	return basicPower;
}

std::vector<TlocIngredients*> TlocSpell::GetIngredients()
{
	return ingredients;
}
