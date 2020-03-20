// Fill out your copyright notice in the Description page of Project Settings.


#include "TlocGameLoader.h"

//#include "Dom/JsonObject.h"
#include "Templates/SharedPointer.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"
#include "Misc/FileHelper.h"

#include "UObject/UObjectGlobals.h"
#include "../Public/Objects/Weapons/TlocSword.h"
#include "Characters/TlocHumanPlayer.h"
#include "Characters/TlocDogPlayer.h"

#include "../Public/GlobalConstants.h"

#include <cstdlib>


//Singleton classes must have an indicator that means it's been created a single object
TlocGameLoader* TlocGameLoader::_unic_instance = 0;
//End singleton class indicator

TlocGameLoader::TlocGameLoader()
{
	_motorLoader = TlocMotorLoader::GetInstance();
}

TlocGameLoader::~TlocGameLoader()
{
	delete _motorLoader;
}

std::vector<TlocPlayer*> TlocGameLoader::NewGameLoader()
{
	GlobalConstants constants;
	std::vector<TlocPlayer*> players;
	players.reserve(2);

	//It's called motor loader to get JSON's route to load new game
	FString fileName = _motorLoader->GetJsonRoute((char*) constants.KVOID, (char*) constants.KDIR_JSON_NEW_GAME, (char*)constants.KEXTENSION_JSON);

	//It's called motor loader to parsing the target JSON file pointed by fileName
	TSharedPtr<FJsonObject> jsonParser = _motorLoader->ParsingJson(fileName);
	
	if (jsonParser != nullptr)
	{
		if (jsonParser->Values.Contains(constants.KPLAYER))
		{
			TArray<TSharedPtr<FJsonValue>> playersArray = jsonParser->GetArrayField(constants.KPLAYER);
			ATlocHumanPlayer* _hPlayer;
			ATlocDogPlayer* _dPlayer;
			TlocSword* _swrd;
			FString* _filePath = nullptr;
			FString _objName = "";
			char* _clsNm = (char*)malloc(constants.KCHAR_SIZE);
			size_t   x;
			for (short i = 0; i < playersArray.Num(); i++)
			{

				TSharedPtr<FJsonObject> jsonObject = playersArray[i]->AsObject();

				if (jsonObject->TryGetStringField(constants.KCLASS_NAME, _objName))
				{
					wcstombs_s(&x, _clsNm, constants.KCHAR_SIZE, *_objName, constants.KCHAR_SIZE);

					//The objetct is the human player
					if (strcmp(_clsNm, constants.KHUMAN_PLAYER) == 0)
					{
						_hPlayer = NewObject<ATlocHumanPlayer>();
						//_hPlayer->SetClassName(*jsonObject->GetStringField(constants.KCLASS_NAME));
						_hPlayer->SetID(jsonObject->GetNumberField(constants.KID));
						_hPlayer->SetLevel(jsonObject->GetNumberField(constants.KLEVEL));
						_hPlayer->SetInitialLife(jsonObject->GetNumberField(constants.KLIFE));
						_hPlayer->SetInitialMaster(jsonObject->GetNumberField(constants.KMASTER));
						_hPlayer->SetAttack(jsonObject->GetNumberField(constants.KATTACK));
						_hPlayer->SetDefense(jsonObject->GetNumberField(constants.KDEFENSE));
						_hPlayer->SetMagicDefense(jsonObject->GetNumberField(constants.KMAGIC_DEFENSE));
						_hPlayer->SetEvasion(jsonObject->GetNumberField(constants.KEVASION));
						_hPlayer->SetCriticalHit(jsonObject->GetNumberField(constants.KCRITICAL_HIT));
						_hPlayer->SetCriticalProb(jsonObject->GetNumberField(constants.KCRITICAL_PROB));
						_hPlayer->SetExperience(jsonObject->GetNumberField(constants.KEXPERIENCE));
						_hPlayer->SetNextLevel(jsonObject->GetNumberField(constants.KNEXT_LEVEL));
						jsonObject = jsonObject->GetObjectField(constants.KWEAPON);
						_swrd = NewObject<TlocSword>();
						_swrd->SetClassName(*jsonObject->GetStringField(constants.KCLASS_NAME));
						_swrd->SetName(*jsonObject->GetStringField(constants.KNAME));
						_swrd->SetMeshFileRoot(*jsonObject->GetStringField(constants.KFILE_DIRECTORY));
						_swrd->SetPrice(jsonObject->GetNumberField(constants.KPRICE));
						_swrd->SetAttack(jsonObject->GetNumberField(constants.KATTACK));
						_swrd->SetCriticalDamageInc(jsonObject->GetNumberField(constants.KCRITICAL_DAMAGE_INC));
						_swrd->SetCriticalProbabilityInc(jsonObject->GetNumberField(constants.KCRITICAL_PROBABILITY_INC));
						_filePath = new FString();
						_hPlayer->SetWeapon(_swrd);
						players.push_back(_hPlayer);
					}
					//The objetct is the dog player
					else if (strcmp(_clsNm, constants.KDOG_PLAYER) == 0)
					{
						_dPlayer = NewObject<ATlocDogPlayer>();
						//_dPlayer->SetClassName(*jsonObject->GetStringField(constants.KCLASS_NAME));
						_dPlayer->SetID(jsonObject->GetNumberField(constants.KID));
						_dPlayer->SetLevel(jsonObject->GetNumberField(constants.KLEVEL));
						_dPlayer->SetInitialLife(jsonObject->GetNumberField(constants.KLIFE));
						_dPlayer->SetInitialMaster(jsonObject->GetNumberField(constants.KMASTER));
						_dPlayer->SetAttack(jsonObject->GetNumberField(constants.KATTACK));
						_dPlayer->SetDefense(jsonObject->GetNumberField(constants.KDEFENSE));
						_dPlayer->SetMagicDefense(jsonObject->GetNumberField(constants.KMAGIC_DEFENSE));
						_dPlayer->SetEvasion(jsonObject->GetNumberField(constants.KEVASION));
						_dPlayer->SetCriticalHit(jsonObject->GetNumberField(constants.KCRITICAL_HIT));
						_dPlayer->SetCriticalProb(jsonObject->GetNumberField(constants.KCRITICAL_PROB));
						_dPlayer->SetExperience(jsonObject->GetNumberField(constants.KEXPERIENCE));
						_dPlayer->SetNextLevel(jsonObject->GetNumberField(constants.KNEXT_LEVEL));
						players.push_back(_dPlayer);
					}
				}
			}
		}
	}
	return players;
}