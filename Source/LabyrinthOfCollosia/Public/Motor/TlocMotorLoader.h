// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Dom/JsonObject.h"

#include "../Objects/Weapons/TlocWeapon.h"
#include "../Magic/TlocSpell.h"

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
	TlocWeapon* IdentifyWeapon(TSharedPtr<FJsonObject> obj);
	std::vector<TlocSpell*> CreateSpells(TArray<TSharedPtr<FJsonValue>> arr);

	//Getters
	FString GetJsonRoute(char* _name, char* _dir, char* _ext);

private:
	//clase sigleton
	TlocMotorLoader();
	static TlocMotorLoader* _unic_instance;
	//fin clase singleton

	TlocSpell* obtainSpellFeatures(TSharedPtr<FJsonObject> obj);
	void createSword(TSharedPtr<FJsonObject> obj, TlocWeapon& _wpn);
	//void createSpear(TSharedPtr<FJsonObject> obj, TlocWeapon* _wpn);
	//void createAxe(TSharedPtr<FJsonObject> obj, TlocWeapon* _wpn);
};
