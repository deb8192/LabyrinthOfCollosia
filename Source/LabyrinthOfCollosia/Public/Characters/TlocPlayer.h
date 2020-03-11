// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include <iostream>
#include "TlocCharacter.h"
#include "..\UserInterfaces\TlocIngameMenu.h"
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

	//Setters & Getters
	void SetPosition(FVector newPosition);
	void SetRotation(FRotator newRotation);

	FVector GetPosition();
	FRotator GetRotation();
	bool GetDefend();
	int GetLife();


private:
	
	//Variables
	int nextLevel;				//Necessary experience to reach next level
	int experience;				//Player experience


};