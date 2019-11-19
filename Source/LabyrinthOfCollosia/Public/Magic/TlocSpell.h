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
	TlocSpell(int idSpll, float pwr, std::vector<TlocIngredients*> ingrdnts);
	~TlocSpell();
	void IncNumUses();
	int GetId();
	int GetLevel();
	int GetNumUses();
	int GetNextLevel();
	float GetBasicPower();
	std::vector <TlocIngredients*> GetIngredients();

private:

	//Variables
	int ID;
	int level;
	int numUses;
	float basicPower;
	bool active;
	std::vector<TlocIngredients*> ingredients;
};
