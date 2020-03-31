// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <vector>
#include "CoreMinimal.h"
#include "TlocIngredients.h"

/**
 * 
 */
class LABYRINTHOFCOLLOSIA_API TlocSpell
{
public:

	//Methods
	TlocSpell();
	TlocSpell(int idSpll, const TCHAR* nm, const TCHAR* desc, float pwr, bool act, std::vector<TlocIngredients*> ingrdnts);
	~TlocSpell();
	void IncNumUses();

	//Getters && setters
	int GetId();
	TCHAR* GetName();
	TCHAR* GetDescription();
	int GetLevel();
	int GetNumUses();
	int GetNextLevel();
	float GetBasicPower();
	std::vector <TlocIngredients*> GetIngredients();
	bool GetActive();

	void SetId(int id);
	void SetName(const TCHAR* nm);
	void SetDescription(const TCHAR* desc);
	void SetLevel(int lvl);
	void SetNumUses(int uses);
	void SetBasicPower(float pwr);
	void SetIngredients(std::vector <TlocIngredients*> &ing);
	void SetActive(bool act);

private:

	//Functions
	void incLevel();
	void incBasicPower();
	void incBasicPowerOne();
	void incBasicPowerAHalf();
	void incBasicPowerAQuarter();

	//Variables
	int ID;
	TCHAR *_spellName;
	TCHAR *_description;
	int level;
	int numUses;
	float basicPower;
	bool active;
	std::vector<TlocIngredients*> ingredients;
};
