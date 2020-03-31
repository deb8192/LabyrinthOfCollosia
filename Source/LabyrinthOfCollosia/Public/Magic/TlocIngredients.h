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
	int GetID();
	TCHAR* GetName();
	int GetQuantity();

	void SetID(int id);
	void SetName(const TCHAR* nm);
	void SetQuantity(int qnty);

private:
	int ID;
	TCHAR* _ingName;
	int quantity;
};
