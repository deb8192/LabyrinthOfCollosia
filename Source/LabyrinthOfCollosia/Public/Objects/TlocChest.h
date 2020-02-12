// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TlocObject.h"

/**
 * 
 */
class LABYRINTHOFCOLLOSIA_API TlocChest : public ATlocObject
{
public:
	TlocChest();
	~TlocChest();

	//Setters & Getters

	void SetOpened(bool open);
	void SetObject(ATlocObject* _obj);
	bool GetOpened();
	ATlocObject* GetObject();

private:
	bool opened;
	ATlocObject* _object;
};
