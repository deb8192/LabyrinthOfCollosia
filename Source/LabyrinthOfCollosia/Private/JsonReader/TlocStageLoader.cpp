// Fill out your copyright notice in the Description page of Project Settings.

#include "../Public/JsonReader/TlocStageLoader.h"

#include "Dom/JsonObject.h"
#include "Templates/SharedPointer.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"
#include "Misc/FileHelper.h"

#include "UObject/UObjectGlobals.h"

#include "../Public/Objects/TlocArmor.h"
#include "../Public/Objects/TlocGauntlet.h"
#include "../Public/Objects/TlocWeapon.h"
#include "../Public/Objects/TlocItem.h"
#include "../Public/Magic/TlocIngredients.h"
#include "../Public/GlobalConstants.h"

#include <string>

//para clases singleton deben tener un indicador de que se ha creado el unico objeto
TlocStageLoader* TlocStageLoader::_unic_instance = 0;
//fin indicador clase singleton

TlocStageLoader::TlocStageLoader()
{
}

TlocStageLoader::~TlocStageLoader()
{
}

std::vector<ATlocObject*> TlocStageLoader::ObjectsLoader(const char* _name)
{
	GlobalConstants constants;
	std::vector<ATlocObject*> levelObjects; 
	levelObjects.reserve(100);

	//We obtain the full path of the content project
	FString fileName = FPaths::ProjectContentDir();
	//We add json directory, file name and file extension
	fileName += constants.KDIR_JSON_OBJ;
	fileName += _name;
	fileName += constants.KEXTENSION_JSON;

	//We save json content file inside jsonStr
	FString jsonStr;
	FFileHelper::LoadFileToString(jsonStr, *fileName);

	TSharedPtr<FJsonObject> jsonParser = MakeShareable(new FJsonObject());
	TSharedRef<TJsonReader<TCHAR>> jsonReader = TJsonReaderFactory<TCHAR>::Create(jsonStr);

	if (FJsonSerializer::Deserialize(jsonReader, jsonParser) && jsonParser.IsValid())
	{
		if (jsonParser->Values.Contains(constants.KSWORD))
		{
			TArray<TSharedPtr<FJsonValue>> objectsArray = jsonParser->GetArrayField(constants.KSWORD);
			TlocWeapon* _wpn;
			FString *_filePath;
			FVector *_pos;
			FRotator *_rot;
			for (short i = 0; i < objectsArray.Num(); i++)
			{
				_filePath = new FString();
				_wpn = NewObject<TlocWeapon>();
				TSharedPtr<FJsonObject> jsonObject = objectsArray[i]->AsObject();
				TArray<FString> posRot;
				jsonObject->TryGetStringArrayField(constants.KPOSITION, posRot);
				_pos = new FVector{  FCString::Atof(*posRot[0]), 
								  FCString::Atof(*posRot[1]), 
								  FCString::Atof(*posRot[2]), };;
				jsonObject->TryGetStringArrayField(constants.KROTATION, posRot);
				_rot = new FRotator{ FCString::Atof(*posRot[3]),
								  FCString::Atof(*posRot[4]),
								  FCString::Atof(*posRot[5]), };
				jsonObject->TryGetStringField(constants.KFILE_DIRECTORY, *_filePath);
				_wpn->SetMesh(**_filePath);
				_wpn->SetPosition(*_pos);
				_wpn->SetRotation(*_rot);
				levelObjects.push_back(_wpn);
			}
		}
		if (jsonParser->Values.Contains(constants.KARMOR))
		{
			TArray<TSharedPtr<FJsonValue>> objectsArray = jsonParser->GetArrayField(constants.KARMOR);
			for (short i = 0; i < objectsArray.Num(); i++)
			{
				TlocArmor* _arm = NewObject<TlocArmor>();
				levelObjects.push_back(_arm);
			}
		}
		if (jsonParser->Values.Contains(constants.KINGREDIENT))
		{
			TArray<TSharedPtr<FJsonValue>> objectsArray = jsonParser->GetArrayField(constants.KINGREDIENT);
			for (short i = 0; i < objectsArray.Num(); i++)
			{
				TlocIngredients* _ing = NewObject<TlocIngredients>();
				levelObjects.push_back(_ing);
			}
		}
		if (jsonParser->Values.Contains(constants.KHEALT_ITEM))
		{
			TArray<TSharedPtr<FJsonValue>> objectsArray = jsonParser->GetArrayField(constants.KHEALT_ITEM);
			for (short i = 0; i < objectsArray.Num(); i++)
			{
				TlocItem* _item = NewObject<TlocItem>();
				levelObjects.push_back(_item);
			}
		}
	}

	return levelObjects;
}

std::vector<ATlocEnemy*> TlocStageLoader::EnemiesLoader(const char* _name)
{
	GlobalConstants constants;
	std::vector<ATlocEnemy*> levelEnemies;
	levelEnemies.reserve(100);

	//We obtain the full path of the content project
	FString fileName = FPaths::ProjectContentDir();
	//We add json directory, file name and file extension
	fileName += constants.KDIR_JSON_ENM;
	fileName += _name;
	fileName += constants.KEXTENSION_JSON;

	//We save json content file inside jsonStr
	FString jsonStr;
	FFileHelper::LoadFileToString(jsonStr, *fileName);

	TSharedPtr<FJsonObject> jsonParser = MakeShareable(new FJsonObject());
	TSharedRef<TJsonReader<TCHAR>> jsonReader = TJsonReaderFactory<TCHAR>::Create(jsonStr);

	if (FJsonSerializer::Deserialize(jsonReader, jsonParser) && jsonParser.IsValid())
	{
		TArray<TSharedPtr<FJsonValue>> enemiesArray = jsonParser->GetArrayField(constants.KENEMY);
		ATlocEnemy* _enm;
		FString* _filePath, _auxFilePath;
		FVector* _pos;
		for (short i = 0; i < enemiesArray.Num(); i++)
		{
			_enm = NewObject<ATlocEnemy>();
			TSharedPtr<FJsonObject> jsonObject = enemiesArray[i]->AsObject();
			TArray<FString> posRot;
			jsonObject->TryGetStringArrayField(constants.KPOSITION, posRot);
			_pos = new FVector{ FCString::Atof(*posRot[0]),
							  FCString::Atof(*posRot[1]),
							  FCString::Atof(*posRot[2]), };
			int j = 1;
			while (j < constants.KMAX_NUM_DIRECTORIES)
			{
				_filePath = new FString();
				_auxFilePath = constants.KFILE_DIRECTORY;
				_auxFilePath.AppendInt(j);
				jsonObject->TryGetStringField(_auxFilePath, *_filePath);
				_enm->SetMesh(**_filePath, j);
				j++;
			}
			_enm->SetPosition(*_pos);
			levelEnemies.push_back(_enm);
		}
	}

	return levelEnemies;
}
