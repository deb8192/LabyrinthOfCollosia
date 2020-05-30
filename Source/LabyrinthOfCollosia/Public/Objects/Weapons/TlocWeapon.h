// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TlocObject.h"

/**
 * 
 */
class LABYRINTHOFCOLLOSIA_API TlocWeapon : public ATlocObject
{
private:
	//Weapon privated functions
	void incLevel();

	int attack;
	int level;
	int experience;
	int nextLevelExp;
	int idWeapon;
	float criticalDamageInc;
	float criticalProbabilityInc;
	bool longRange;

public:
	TlocWeapon();
	~TlocWeapon();

	//Weapon functions
	void IncExperience(int quantity);

	//Setters & Getters

	void SetAttack(int att);
	void SetLevel(int lvl);
	void SetExperience(int exp);
	void SetNextLevel(int nxt);
	void SetWeaponID(int id);
	void SetCriticalDamageInc(float dam);
	void SetCriticalProbabilityInc(float prob);
	void SetLongRange(bool lrang);

	int GetAttack();
	int GetLevel();
	int GetExperience();
	int GetNextLevel();
	int GetWeaponID();
	float GetCriticalDamageInc();
	float GetCriticalProbabilityInc();
	bool GetLongRange();
};
