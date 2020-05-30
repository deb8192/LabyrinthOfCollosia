// Fill out your copyright notice in the Description page of Project Settings.


#include "../Public/Objects/Weapons/TlocSpear.h"
#include "../Public/GlobalConstants.h"

TlocSpear::TlocSpear()
{
	throwingDistance = 0.0f;
}

TlocSpear::~TlocSpear()
{
	throwingDistance = 0.0f;
}

void TlocSpear::SetThrowingDistance(float dist)
{
	throwingDistance = dist;
}

float TlocSpear::GetThrowingDistance()
{
	return throwingDistance;
}
