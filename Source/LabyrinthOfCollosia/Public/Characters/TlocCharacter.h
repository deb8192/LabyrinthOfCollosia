// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <vector>
#include <queue>
#include "..\Public\Magic\TlocSpell.h"
#include "..\Public\Magic\TlocIngredients.h"
#include "..\Public\Objects\TlocItem.h"
#include "..\Public\Objects\TlocWeapon.h"
#include "..\Public\Objects\TlocArmor.h"
#include "..\Public\Objects\TlocGauntlet.h"
//#include "TlocEnemy.h"

#include "CoreMinimal.h"


/**
 * TlocCharacters is an interface that will contain the expresion of character's main function 
 */
class LABYRINTHOFCOLLOSIA_API TlocCharacter
{
public:

	// Called when the game starts or when spawned

	virtual void ModifyLife(float quantity) = 0;				//Adds or substracts as many as quantity value is
	//virtual int Attack() = 0;	//Calculates hit damage
	virtual int Magic() = 0;									//Calculates magic damage
	virtual void Transact() = 0;								//Function for buying or selling objects
	virtual void Talk() = 0;									//Function to talk with anyone
	virtual void Move() = 0;									//Function to move the character
	virtual void Defend() = 0;									//Function to activate or desactivate defense state

	// Getters
	virtual bool GetDefend() = 0;


protected:
	// Variables
	int ID;											//Character ID
	int level;										//Character level
	int life;										//Character life
	int defaultLife;								//Character whole life
	int attack;										//Character attack
	int defense;									//Character defense
	int magicDef;									//Character magic defense
	int criticalHit;								//Character critical hit damage
	int criticalProb;								//Character critical hit probability
	int evasion;									//Character hit evade probability
	int luck;										//Character hit probability
	bool defending;									//Character defending state
	std::vector<TlocIngredients*> _ingredients;		//Character ingredient list
	std::vector<TlocSpell*> _learnedSpells;			//Character learned spell list
	std::vector<TlocSpell*> _memorizedSpells;		//Character memorized spell list from the learned spell list
	std::vector<std::vector<TlocItem*>> _items;		//Character menu items
	std::vector<TlocWeapon*> _weapon;				//Character weapons
	std::vector<TlocArmor*> _armor;					//Character armors
	std::vector<TlocGauntlet*> _gauntlet;			//Character gauntlets
	std::queue<int> _buffsAilments;					//Character active buffs or ailments
	std::queue<float> buffsAilmentsTime;			//Character active buffs or ailments' time
};