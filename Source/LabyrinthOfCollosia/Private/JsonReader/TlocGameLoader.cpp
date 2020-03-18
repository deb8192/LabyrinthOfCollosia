// Fill out your copyright notice in the Description page of Project Settings.


#include "TlocGameLoader.h"

#include "Dom/JsonObject.h"
#include "Templates/SharedPointer.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"
#include "Misc/FileHelper.h"

#include "UObject/UObjectGlobals.h"
#include "../Public/Objects/Weapons/TlocSword.h"
#include "../Public/GlobalConstants.h"


//Singleton classes must have an indicator that means it's been created a single object
TlocGameLoader* TlocGameLoader::_unic_instance = 0;
//End singleton class indicator

TlocGameLoader::TlocGameLoader()
{
}

TlocGameLoader::~TlocGameLoader()
{
}

std::vector<TlocPlayer*> TlocGameLoader::NewGameLoader()
{
	GlobalConstants constants;
	std::vector<TlocPlayer*> players;
	players.reserve(2);

	//We obtain the full path of the content project
	FString fileName = FPaths::ProjectContentDir();
	//We add json directory, file name and file extension
	fileName += constants.KDIR_JSON_NEW_GAME;
	fileName += constants.KEXTENSION_JSON;

	//We save json content file inside jsonStr
	FString jsonStr;
	FFileHelper::LoadFileToString(jsonStr, *fileName);

	TSharedPtr<FJsonObject> jsonParser = MakeShareable(new FJsonObject());
	TSharedRef<TJsonReader<TCHAR>> jsonReader = TJsonReaderFactory<TCHAR>::Create(jsonStr);
	if (FJsonSerializer::Deserialize(jsonReader, jsonParser) && jsonParser.IsValid())
	{
		if (jsonParser->Values.Contains(constants.KPLAYER))
		{
			TArray<TSharedPtr<FJsonValue>> playersArray = jsonParser->GetArrayField(constants.KPLAYER);
			ATlocHumanPlayer* _hPlayer;
			//ATlocDogPlayer* _dPlayer;
			TlocSword* _swrd;
			FString* _filePath;
			FString* _clsNm;
			for (short i = 0; i < playersArray.Num(); i++)
			{
				if (jsonParser->Values.Contains(constants.KPLAYER))
				{
					_hPlayer = NewObject<ATlocHumanPlayer>();
					_swrd = NewObject<TlocSword>();
					_filePath = new FString();
					_clsNm = new FString();
					players.push_back(_hPlayer);
				}
				/*else
				{
					_hPlayer = NewObject<ATlocHumanPlayer>();
					_wpn = NewObject<TlocWeapon>();
					_filePath = new FString();
					_clsNm = new FString();
					TSharedPtr<FJsonObject> jsonObject = playersArray[i]->AsObject();
				}*/
			}
		}
	}
	return players;
}