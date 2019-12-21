// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class LABYRINTHOFCOLLOSIA_API TlocState
{
public:
	virtual ~TlocState() = default;
	virtual void Update() = 0;
};
