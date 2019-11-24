// Fill out your copyright notice in the Description page of Project Settings.


#include "../Public/Objects/TlocWeapon.h"
#include "../Public/GlobalConstants.h"

TlocWeapon::TlocWeapon()
{
}

TlocWeapon::~TlocWeapon()
{
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
