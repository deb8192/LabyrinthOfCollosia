// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TlocObject.h"

/**
 * 
 */
class LABYRINTHOFCOLLOSIA_API TlocWeapon
{
private:
	//Weapon privated functions
	void incLevel();

	int attack;
	int level;
	int experience;
	int nextLevelExp;
	float criticalDamageInc;
	float criticalProbabilityInc;
	bool longRange;

public:
	TlocWeapon();
	~TlocWeapon();

	//Weapon functions
	void IncExperience(int quantity);

	//Getters
	int GetAttack();
	int GetLevel();
	int GetExperience();
	int GetNextLevel();
	float GetCriticalDamageInc();
	float GetCriticalProbabilityInc();
	bool GetLongRange();
};
