// Fill out your copyright notice in the Description page of Project Settings.


#include "TlocMotorLoader.h"

#include "Templates/SharedPointer.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"
#include "Misc/Paths.h"
#include "Misc/FileHelper.h"

#include "../Public/GlobalConstants.h"

#include <cstdlib>

//Singleton classes must have an indicator that means it's been created a single object
TlocMotorLoader* TlocMotorLoader::_unic_instance = 0;
//End singleton class indicator

TSharedPtr<FJsonObject> TlocMotorLoader::ParsingJson(FString fileName)
{
	//Json content file it's saved inside jsonStr
	FString jsonStr;
	FFileHelper::LoadFileToString(jsonStr, *fileName);

	TSharedPtr<FJsonObject> jsonParser = MakeShareable(new FJsonObject());
	TSharedRef<TJsonReader<TCHAR>> jsonReader = TJsonReaderFactory<TCHAR>::Create(jsonStr);
	if (FJsonSerializer::Deserialize(jsonReader, jsonParser) && jsonParser.IsValid())
	{
		return jsonParser;
	}
	else return nullptr;
}

FString TlocMotorLoader::GetJsonRoute(char* _name, char* _dir, char* _ext)
{
	GlobalConstants constants;

	//It's obtained the full path of the content project
	FString fileName = FPaths::ProjectContentDir();
	//It's added json directory, file name and file extension into fileName
	fileName += _dir;
	fileName += _name;
	fileName += _ext;
	return fileName;
}

TlocMotorLoader::TlocMotorLoader()
{
}

TlocMotorLoader::~TlocMotorLoader()
{
}
