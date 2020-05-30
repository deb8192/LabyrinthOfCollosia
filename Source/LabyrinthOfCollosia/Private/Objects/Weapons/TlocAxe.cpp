// Fill out your copyright notice in the Description page of Project Settings.



#include "../Public/Objects/Weapons/TlocAxe.h"
#include "../Public/GlobalConstants.h"

TlocAxe::TlocAxe()
{
	axeID = "axe-";
	breakWalls = false;
	defenseInc = 0.0f;
}

TlocAxe::~TlocAxe()
{
	axeID = nullptr;
	breakWalls = false;
	defenseInc = 0.0f;
}

void TlocAxe::SetBreakWalls(bool brkWll)
{
	breakWalls = brkWll;
}

void TlocAxe::SetDefenseInc(float defInc)
{
	defenseInc;
}

bool TlocAxe::GetBreakWalls()
{
	return breakWalls;
}

float TlocAxe::GetDefInc()
{
	return defenseInc;
}

