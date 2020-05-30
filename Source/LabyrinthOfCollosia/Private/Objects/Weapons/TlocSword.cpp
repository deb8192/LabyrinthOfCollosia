// Fill out your copyright notice in the Description page of Project Settings.


#include "../Public/Objects/Weapons/TlocSword.h"
#include "../Public/GlobalConstants.h"

TlocSword::TlocSword()
{
	GlobalConstants constants;
	swordID = "sword-";
	buffAillment = constants.KPOISON;
	probAillment = 0.1f;
}

TlocSword::~TlocSword()
{
	swordID = "";
	buffAillment = -1;
	probAillment = 0.f;
}

void TlocSword::SetBuffAillment(int bffAill)
{
	buffAillment = bffAill;
}

void TlocSword::SetProbAillment(float probAill)
{
	probAillment = probAill;
}

char* TlocSword::GetSwordID()
{
	return swordID;
}

int TlocSword::GetBuffAillment()
{
	return buffAillment;
}

float TlocSword::GetProbAillment()
{
	return probAillment;
}

