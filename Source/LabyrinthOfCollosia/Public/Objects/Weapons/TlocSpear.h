// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TlocWeapon.h"

/**
 * 
 */
class LABYRINTHOFCOLLOSIA_API TlocSpear : public TlocWeapon
{
public:
	TlocSpear();
	~TlocSpear();

	void SetThrowingDistance(float dist);

	float GetThrowingDistance();

private:
	float throwingDistance;
};