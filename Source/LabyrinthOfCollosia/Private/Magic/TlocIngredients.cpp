// Fill out your copyright notice in the Description page of Project Settings.


#include "..\Public\Magic\TlocIngredients.h"

TlocIngredients::TlocIngredients()
{
	ID = 0;
	_ingName = nullptr;
	quantity = 0;
}

TlocIngredients::TlocIngredients(int id, const TCHAR* _nm, int qnty)
{
	ID = id;
	_ingName = (TCHAR*) _nm;
	quantity = qnty;
}

TlocIngredients::~TlocIngredients()
{
	ID = 0;
	_ingName = nullptr;
	quantity = 0;
}
int TlocIngredients::GetID()
{
	return ID;
}

TCHAR* TlocIngredients::GetName()
{
	return _ingName;
}

int TlocIngredients::GetQuantity()
{
	return quantity;
}

void TlocIngredients::SetID(int id)
{
	ID = id;
}

void TlocIngredients::SetName(const TCHAR* _nm)
{
	_ingName = (TCHAR*) _nm;
}

void TlocIngredients::SetQuantity(int qnty)
{
	quantity = qnty;
}
