// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TlocWeapon.h"

/**
 * 
 */
class LABYRINTHOFCOLLOSIA_API TlocAxe : public TlocWeapon
{
	TlocAxe();
	~TlocAxe();

	void SetBreakWalls(bool brkWll);
	void SetDefenseInc(float defInc);
	bool GetBreakWalls();
	float GetDefInc();

private:
	char* axeID;
	bool breakWalls;
	float defenseInc;
};

