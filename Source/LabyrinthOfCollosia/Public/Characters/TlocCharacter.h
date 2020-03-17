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
#include "..\Public\Motor\TlocMotorFacade.h"
//#include "TlocEnemy.h"

#include "CoreMinimal.h"


/**
 * TlocCharacters is an interface that will contain the expresion of character's main function 
 */
class LABYRINTHOFCOLLOSIA_API TlocCharacter
{
public:

	// Called when the game starts or when spawned
	//virtual ~TlocCharacter() = 0;

	virtual void ModifyLife(float quantity) = 0;				//Adds or substracts as many as quantity value is
	virtual int Attack() = 0;									//Calculates hit damage
	virtual int Magic() = 0;									//Calculates magic damage
	virtual void Transact() = 0;								//Function for buying or selling objects
	virtual void Talk() = 0;									//Function to talk with anyone
	virtual void Move() = 0;									//Function to move the character
	virtual void Defend() = 0;									//Function to activate or desactivate defense state

	// Getters
	virtual void SetMesh(const TCHAR* fileRoot, int mesh) = 0;
	virtual void SetPosition(FVector newPosition) = 0;
	virtual void SetRotation(FRotator newRotation) = 0;

	virtual bool GetDefend() = 0;
	virtual int GetLife() = 0;
	virtual UStaticMeshComponent* GetMesh() = 0;
	virtual FVector GetPosition() = 0;
	virtual FRotator GetRotation() = 0;


protected:
	// Variables
	int ID;											//Character's ID
	int level;										//Character's level
	float life;										//Character's life
	float defaultLife;								//Character's whole life
	float master;									//Character's spetial attack points
	float defaultMaster;							//Character's special attack max points
	int attack;										//Character's attack
	int defense;									//Character's defense
	int magicDef;									//Character's magic defense
	int criticalHit;								//Character's critical hit damage
	int criticalProb;								//Character's critical hit probability
	int evasion;									//Character's hit evade probability
	int luck;										//Character's hit probability
	bool defending;									//Character's defending state
	bool attacking;									//Character's attacking state
	bool invulnerable;
	float invulnerableTime;
	std::vector<std::vector<TlocIngredients*>> _ingredients;		//Character's ingredient list
	std::vector<TlocSpell*> _learnedSpells;			//Character's learned spell list
	std::vector<TlocSpell*> _memorizedSpells;		//Character's memorized spell list from the learned spell list
	std::vector<std::vector<TlocItem*>> _items;		//Character's menu items
	std::vector<TlocWeapon*> _weapon;				//Character's weapons
	std::vector<TlocArmor*> _armor;					//Character's armors
	std::vector<TlocGauntlet*> _gauntlet;			//Character's gauntlets
	std::queue<int> _buffsAilments;					//Character's active buffs or ailments
	std::queue<float> buffsAilmentsTime;			//Character's active buffs or ailments' time

	TCHAR* _name;
	FVector position;
	FRotator rotation;

	//Facade variables
	ATlocMotorFacade* _motor;

	//Unreal variables
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent *_charMesh;
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* _wpnMesh;

	TCHAR* _fileRoot;
};