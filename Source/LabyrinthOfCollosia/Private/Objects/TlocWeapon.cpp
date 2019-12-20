// Fill out your copyright notice in the Description page of Project Settings.


#include "../Public/Objects/TlocWeapon.h"
#include "../Public/GlobalConstants.h"

TlocWeapon::TlocWeapon() : ATlocObject()
{
	attack = 5;
	level = 1;
	experience = 0;
	nextLevelExp = 100;
	criticalDamageInc = 1.25;
	criticalProbabilityInc = 10;
	longRange = false;
}

TlocWeapon::~TlocWeapon()
{
	attack = 0;
	level = 0;
	experience = 0;
	nextLevelExp = 0;
	criticalDamageInc = 0.0;
	criticalProbabilityInc = 0;
	longRange = false;
}
void TlocWeapon::incLevel()
{
	level++;
	GlobalConstants constants;
	if (level == constants.KMAXEQUIPEMENT_LEVEL)
	{
		experience = nextLevelExp;
	}
}
void TlocWeapon::IncExperience(int quantity)
{
	GlobalConstants constants;
	if(level < constants.KMAXEQUIPEMENT_LEVEL)
	{
		if (experience += quantity >= nextLevelExp)
		{
			incLevel();
		}
	}
}
int TlocWeapon::GetAttack()
{
	return attack;
}

int TlocWeapon::GetLevel()
{
	return level;
}

int TlocWeapon::GetExperience()
{
	return experience;
}

int TlocWeapon::GetNextLevel()
{
	return nextLevelExp;
}

float TlocWeapon::GetCriticalDamageInc()
{
	return criticalDamageInc;
}

float TlocWeapon::GetCriticalProbabilityInc()
{
	return criticalProbabilityInc;
}

bool TlocWeapon::GetLongRange()
{
	return longRange;
}
