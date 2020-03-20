// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include <iostream>
#include "TlocCharacter.h"
#include "..\UserInterfaces\TlocIngameMenu.h"
#include "..\UserInterfaces\TlocHUD.h"
#include "Camera/CameraComponent.h"
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

	//Getters & Setters

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
	FRotator GetRotation();

	// -Getters TlocPlayer
	int GetNextLevel();
	int GetExperience();
	int GetPlayer();
	
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

	// -Setters TlocPlayer
	void SetNextLevel(int nLevel);
	void SetExperience(int exp);
	void SetPlayer(int plyr);
	
protected:

	//Variables
	int nextLevel;				//Necessary experience to reach next level
	int experience;				//Player experience
	int player;					//Int that identifies if player is boy, girls or dog


};