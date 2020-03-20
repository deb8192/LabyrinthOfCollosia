// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "../Motor/TlocMotorLoader.h"

#include "../Public/Characters/TlocPlayer.h"

#include <vector>

/**
 * 
 */
class LABYRINTHOFCOLLOSIA_API TlocGameLoader
{
public:
	//clase singleton
	~TlocGameLoader();
	static TlocGameLoader* GetInstance()
	{
		if (!_unic_instance)
		{
			//We can call the default "new" constructor because this is not an Unreal object
			_unic_instance = new TlocGameLoader();
		}
		return _unic_instance;
	}
	//fin clase singleton

	std::vector<TlocPlayer*> NewGameLoader();
	//std::vector<ATlocObject*> ObjectsLoader(const char* _name);
	//std::vector<ATlocEnemy*> EnemiesLoader(const char* _name);

private:
	//clase sigleton
	TlocGameLoader();
	static TlocGameLoader* _unic_instance;
	TlocMotorLoader* _motorLoader;
	//fin clase singleton
};
