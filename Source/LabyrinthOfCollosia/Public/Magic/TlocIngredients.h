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
	~TlocIngredients();
	int GetID();

private:
	int ID;
};
