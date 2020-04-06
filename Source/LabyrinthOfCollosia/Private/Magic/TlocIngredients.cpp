// Fill out your copyright notice in the Description page of Project Settings.


#include "..\Public\Magic\TlocIngredients.h"

TlocIngredients::TlocIngredients()
{
	ingredientID = 0;
	_ingName = nullptr;
	quantity = 0;
}

TlocIngredients::TlocIngredients(int id, const TCHAR* _nm, int qnty)
{
	ingredientID = id;
	_ingName = (TCHAR*) _nm;
	quantity = qnty;
}

TlocIngredients::~TlocIngredients()
{
	ingredientID = 0;
	_ingName = nullptr;
	quantity = 0;
}
void TlocIngredients::AddQuantity(int qnty)
{
	quantity += qnty;
}
void TlocIngredients::DescendQuantity(int qnty)
{
	quantity -= qnty;
}
int TlocIngredients::GetIngredientID()
{
	return ingredientID;
}

TCHAR* TlocIngredients::GetName()
{
	return _ingName;
}

int TlocIngredients::GetQuantity()
{
	return quantity;
}

void TlocIngredients::SetIngredientID(int id)
{
	ingredientID = id;
}

void TlocIngredients::SetName(const TCHAR* _nm)
{
	_ingName = (TCHAR*) _nm;
}

void TlocIngredients::SetQuantity(int qnty)
{
	quantity = qnty;
}
