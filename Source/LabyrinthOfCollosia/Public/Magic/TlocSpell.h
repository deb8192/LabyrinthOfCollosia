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
	TlocSpell(int idSpll, const TCHAR* nm, const TCHAR* desc, const TCHAR* icon, float pwr, bool act, std::vector<TlocIngredients*> ingrdnts);
	~TlocSpell();
	void IncNumUses();

	//Getters && setters
	int GetId();
	int GetMenuId();
	TCHAR* GetName();
	TCHAR* GetDescription();
	TCHAR* GetIconFilePath();
	int GetLevel();
	int GetNumUses();
	int GetNextLevel();
	float GetBasicPower();
	std::vector <TlocIngredients*> GetIngredients();
	bool GetActive();

	void SetId(int id);
	void SetMenuId(int menId);
	void SetName(const TCHAR* nm);
	void SetDescription(const TCHAR* desc);
	void SetIconFilePath(const TCHAR* icon);
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
	int menuID;
	TCHAR *_spellName;
	TCHAR *_description;
	TCHAR* _iconFilePath;
	int level;
	int numUses;
	float basicPower;
	bool active;
	std::vector<TlocIngredients*> ingredients;
};
