// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../Objects/TlocObject.h"

/**
 * 
 */
class LABYRINTHOFCOLLOSIA_API TlocIngredients : public ATlocObject
{
public:
	TlocIngredients();
	TlocIngredients(int id, const TCHAR* nm, int qnty);
	~TlocIngredients();
	
	void AddQuantity(int qnty);
	void DescendQuantity(int qnty);
	
	int GetIngredientID();
	TCHAR* GetName();
	int GetQuantity();

	void SetIngredientID(int id);
	void SetName(const TCHAR* nm);
	void SetQuantity(int qnty);

private:
	int ingredientID;
	TCHAR* _ingName;
	int quantity;
};
