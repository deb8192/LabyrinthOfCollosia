// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TlocWeapon.h"

/**
 * 
 */
class LABYRINTHOFCOLLOSIA_API TlocSword : public TlocWeapon
{
public:
	TlocSword();
	~TlocSword();

	void SetSwordID();
	void SetBuffAillment(int bffAill);
	void SetProbAillment(float probAill);


	char* GetSwordID();
	int GetBuffAillment();
	float GetProbAillment();

private:
	char* swordID;
	int buffAillment;
	float probAillment;
};
