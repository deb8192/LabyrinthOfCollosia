// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include <iostream>
#include "TlocCharacter.h"
#include "..\UserInterfaces\TlocIngameMenu.h"
#include "..\UserInterfaces\TlocHUD.h"
#include "GameFramework/Actor.h"
//#include "TlocEnemy.h"

/**
 * TlocPlayer is the main class which contains the players main set of functions and variables 
 */
class LABYRINTHOFCOLLOSIA_API TlocPlayer : public TlocCharacter
{

public:

	// Sets default values for this actor's properties
	TlocPlayer();
	//NO ES INCORRECTO, PERO NO ES FUNCIONAL EN UNREAL ENGINE
	//TlocPlayer(int idChrctr, int lvl, int lif, int att, int def, int magdef, int exp, int nxtlvl, int crit, int critProb, int lck, int eva);
	~TlocPlayer();

	//Character's functions
	void ModifyLife(float quantity);
	int  Attack();
	//int  Attack(TlocWeapon* _wp, ATlocEnemy* _enm);
	int  Attack(TlocWeapon* _wp);
	int Magic();
	void Transact();
	void Talk();
	void Move();
	void Defend();
	void AddWeapon(TlocWeapon &wpn);
	void SelectTarget(AActor& _target, float blendTime);

	//Getters & Setters

	void InitMemorizedSpells();

	// -Getters TlocCharacter
	int GetID();
	int GetLevel();
	int GetLife();
	float GetDefaultLife();
	float GetMaster();
	float GetDefaultMaster();
	int GetAttack();
	int GetDefense();
	int GetMagicDefense();
	float GetCriticalHit();
	float GetCriticalProb();
	int GetEvasion();
	int GetLuck();
	bool GetDefend();
	int GetAttacking();
	//int GetTalons();
	int GetJewels();
	//int GetCredits();
	bool GetInvulnerable();
	float GetInvulnerableTime();
	UStaticMeshComponent* GetMesh();
	FVector GetPosition();
	FVector GetRenderPosition();
	FRotator GetRotation();
	FRotator GetRenderRotation();
	std::vector<TlocIngredients*> GetIngredients();
	std::vector<TlocSpell*> GetSpells();
	TlocSpell* GetAttackingSpell();
	std::vector<TlocSpell* > GetMemorizedSpells();
	std::vector<std::vector<TlocItem*>> GetItems();
	std::vector<TlocWeapon* > GetWeapons();
	std::vector<TlocArmor*> GetArmors();
	std::vector<TlocGauntlet*> GetGauntlets();
	std::queue<int> GetBuffAilments();
	std::queue<float> GetBuffAilmentsTime();
	TCHAR* GetName();
	TCHAR* GetClassName();

	// -Getters TlocPlayer
	int GetNextLevel();
	int GetExperience();
	int GetPlayer();
	int GetMode();
	std::vector<AActor*> GetTargetEnemies();
	std::vector<AActor*> GetTargetPlayers();
	std::vector<AActor*> GetTargetObjects();
	int GetTargetSelector();
	
	// -Setters TlocCharacter
	void SetInitialLife(float lif);
	void SetInitialMaster(float mstr);
	void SetID(int id);
	void SetLevel(int lvl);
	void SetLife(float lif);
	void SetDefaultLife(float dfltLif);
	void SetMaster(float mstr);
	void SetDefaultMaster(float dfltMstr);
	void SetAttack(int att);
	void SetDefense(int def);
	void SetMagicDefense(int magDef);
	void SetCriticalHit(float critHit);
	void SetCriticalProb(float critProb);
	void SetEvasion(int ev);
	void SetLuck(int lck);
	void SetDefend(bool dfnd);
	void SetAttacking(bool attckng);
	//void SetTalons(int tlns);
	void SetJewels(int jwls);
	//void SetCredits(int crdts);
	void SetInvulnerable(bool inv);
	void SetInvulnerableTime(float invTime);
	virtual void SetMesh(const TCHAR* fileRoot, int mesh) = 0;
	void SetPosition(FVector newPosition);
	void SetRotation(FRotator newRotation);
	void SetIngredients(std::vector<TlocIngredients*>& _ing);
	void SetSpells(std::vector<TlocSpell*>& _splls);
	void SetMemorizedSpells(std::vector<TlocSpell*>& _memSplls);
	void SetItems(std::vector<std::vector<TlocItem*>>& _itms);
	void SetWeapons(std::vector<TlocWeapon*>& _wpns);
	void SetArmors(std::vector<TlocArmor*>& _armrs);
	void SetGauntlets(std::vector<TlocGauntlet*>& _gntlt);
	void SetBuffAilments(std::queue<int>& _bffsAil);
	void SetBuffAilmentsTime(std::queue<float>& _bffsAilTime);
	void SetName(TCHAR* _nm);
	void SetClassName(TCHAR* _clssNm);

	// -Setters TlocPlayer
	void SetNextLevel(int nLevel);
	void SetExperience(int exp);
	void SetPlayer(int plyr);
	void SetMode(int mod);
	void SetTargetEnemies(std::vector<AActor*> &_enm);
	void SetTargetPlayers(std::vector<AActor*> &_all);
	void SetTargetObjects(std::vector<AActor*> &_obj);

	enum PlayingMode : int
	{
		NORMAL = 0,
		TARGET_SELECTION,
		CASTING_SPELL
	};
	
protected:

	// Functions
	void moveEntity(float updTime);
	void rotateEntity(float updTime);
	void updateTimeMove(float rendTime);
	void selectTargetLeft();
	void selectTargetRight();

	//Variables
	int nextLevel;				//Necessary experience to reach next level
	int experience;				//Player experience
	int player;					//Int that identifies if player is boy, girls or dog
	int mode;					//Int that identifies playing mode: normal or target_selection
	int targetSelector;

};