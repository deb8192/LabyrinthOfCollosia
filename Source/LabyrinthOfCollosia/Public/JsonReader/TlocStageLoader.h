// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../Public/Objects/TlocObject.h"
#include "../Public/Characters/TlocEnemy.h"
#include "UObject/UObjectGlobals.h"
#include "CoreMinimal.h"

#include <vector>

/**
 * 
 */
class LABYRINTHOFCOLLOSIA_API TlocStageLoader
{
public:
	//clase singleton
	~TlocStageLoader();
	static TlocStageLoader* GetInstance()
	{
		if (!_unic_instance)
		{
			//We can call the default "new" constructor because this is not an Unreal object
			_unic_instance = new TlocStageLoader();
		}
		return _unic_instance;
	}
	//fin clase singleton
	std::vector<ATlocObject*> ObjectsLoader(const char* _name);
	std::vector<ATlocEnemy*> EnemiesLoader(const char* _name);

private:
	//clase sigleton
	TlocStageLoader();
	static TlocStageLoader* _unic_instance;
	//fin clase singleton
};
