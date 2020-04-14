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
	TlocSpell(int idSpll, const TCHAR* nm, const TCHAR* desc, const TCHAR* icon, int trgt, float pwr, bool act, std::vector<TlocIngredients*> ingrdnts);
	~TlocSpell();
	int CastSpell(AActor &_target);
	int CastSpell(std::vector<AActor*> &_target);

	//Getters && setters
	int GetId();
	int GetMenuId();
	TCHAR* GetName();
	TCHAR* GetDescription();
	TCHAR* GetIconFilePath();
	int GetLevel();
	int GetNumUses();
	int GetNextLevel();
	int GetKindTarget();
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
	void SetKindTarget(int trgt);
	void SetBasicPower(float pwr);
	void SetIngredients(std::vector <TlocIngredients*> &ing);
	void SetActive(bool act);

	//---- Spell's target ----//	

	enum Target : int
	{
		ENEMY = 0,
		PLAYERS,
		HUMAN_PLAYER,
		DOG_PLAYER,
		STAGE
	};

private:

	//Functions
	void incNumUses();
	void incLevel();
	void incBasicPower();
	void incBasicPowerOne();
	void incBasicPowerAHalf();
	void incBasicPowerAQuarter();
	void getEffect();

	//Variables
	int ID;										//Spell's ID
	int menuID;									//Spell's menu ID
	TCHAR *_spellName;							//Spell's name
	TCHAR *_description;						//Spell's description
	TCHAR* _iconFilePath;						//Spell's icon directory path
	int level;									//Spell's level
	int numUses;								//Number of times that the spell is been used	
	int target;									//Spell's kind of target: 0-Enemies, 1-Players, 2-HumanPlayer, 3-DogPlayer, 4-StageObject
	float basicPower;							//Spell's minimum power
	bool active;								//Variable that sais if the spell is memorized by de player if true or not if false
	std::vector<TlocIngredients*> ingredients;	//Spell's needed ingredients to cast it

};
