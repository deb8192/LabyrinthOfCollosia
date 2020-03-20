// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Dom/JsonObject.h"

/**
 * 
 */
class LABYRINTHOFCOLLOSIA_API TlocMotorLoader
{
public:
	//clase singleton
	~TlocMotorLoader();
	static TlocMotorLoader* GetInstance()
	{
		if (!_unic_instance)
		{
			//We can call the default "new" constructor because this is not an Unreal object
			_unic_instance = new TlocMotorLoader();
		}
		return _unic_instance;
	}
	//fin clase singleton

	TSharedPtr<FJsonObject> ParsingJson(FString fileName);

	//Getters
	FString GetJsonRoute(char* _name, char* _dir, char* _ext);

private:
	//clase sigleton
	TlocMotorLoader();
	static TlocMotorLoader* _unic_instance;
	//fin clase singleton
};
