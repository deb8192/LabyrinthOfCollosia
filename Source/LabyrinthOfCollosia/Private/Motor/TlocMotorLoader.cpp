// Fill out your copyright notice in the Description page of Project Settings.


#include "TlocMotorLoader.h"

#include "Templates/SharedPointer.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"
#include "Misc/Paths.h"
#include "Misc/FileHelper.h"

#include "../Public/GlobalConstants.h"
#include "../Objects/Weapons/TlocSword.h"
#include "../Objects/Weapons/TlocSpear.h"
#include "../Objects/Weapons/TlocAxe.h"

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

TlocWeapon* TlocMotorLoader::IdentifyWeapon(TSharedPtr<FJsonObject> obj)
{
	GlobalConstants constants;
	TlocWeapon* _wpn = NewObject<TlocWeapon>();
	//TSharedPtr<FJsonObject> jsonObject = obj->GetObjectField(constants.KWEAPON);
	FString _objName = "";
	char* _clsNm = (char*)malloc(constants.KCHAR_SIZE);
	size_t   x;
		
	if (obj->TryGetStringField(constants.KCLASS_NAME, _objName))
	{
		wcstombs_s(&x, _clsNm, constants.KCHAR_SIZE, *_objName, constants.KCHAR_SIZE);

		//The objetct is a sword
		if (strcmp(_clsNm, constants.KSWORD) == 0)
		{
			createSword(obj, *_wpn);
		}
		else if (strcmp(_clsNm, constants.KSPEAR) == 0)
		{
			createSpear(obj, *_wpn);
		}
		else if (strcmp(_clsNm, constants.KAXE) == 0)
		{
			createAxe(obj, *_wpn);
		}
	}
	return _wpn;
}

std::vector<TlocIngredients*> TlocMotorLoader::IdentifyIngredients(TArray<TSharedPtr<FJsonValue>> arr)
{
	GlobalConstants constants;
	std::vector<TlocIngredients*> playerIngredients;
	playerIngredients.reserve(constants.KMAXINGREDIENTS);
	if (arr.Num() > constants.KZERO)
	{
		for (short i = 0; i < arr.Num(); i++)
		{
			TSharedPtr<FJsonObject> jsonObject = arr[i]->AsObject();
			TlocIngredients* _ingredient = obtainIngredientsFeatures(jsonObject);
			if (_ingredient != nullptr)
			{
				playerIngredients.push_back(_ingredient);
			}
		}
	}
	return playerIngredients;
}

std::vector<TlocSpell*> TlocMotorLoader::CreateSpells(TArray<TSharedPtr<FJsonValue>> arr)
{
	GlobalConstants constants;
	std::vector<TlocSpell*> playerSpells;
	playerSpells.reserve(constants.KMAXSPELLS);
	if (arr.Num() > constants.KZERO)
	{
		for (short i = 0; i < arr.Num(); i++)
		{
			TSharedPtr<FJsonObject> jsonObject = arr[i]->AsObject();
			TlocSpell* _spell = obtainSpellFeatures(jsonObject);
			if (_spell != nullptr)
			{
				playerSpells.push_back(_spell);
			}
		}
	}
	return playerSpells;
}

FString TlocMotorLoader::GetJsonRoute(char* _name, char* _dir, char* _ext)
{
	

	//It's obtained the full path of the content project
	FString fileName = FPaths::ProjectContentDir();
	//It's added json directory, file name and file extension into fileName
	fileName += _dir;
	fileName += _name;
	fileName += _ext;
	return fileName;
}

TlocIngredients* TlocMotorLoader::obtainIngredientsFeatures(TSharedPtr<FJsonObject> obj)
{
	GlobalConstants constants;
	FString* _name = new FString();
	obj->TryGetStringField(constants.KNAME, *_name);
	TlocIngredients* _newIngredient = NewObject<TlocIngredients>();
	_newIngredient->SetName(**_name);
	_newIngredient->SetIngredientID((int)obj->GetNumberField(constants.KID));
	_newIngredient->SetQuantity((int)obj->GetNumberField(constants.KQUANTITY));
	return _newIngredient;
}

/******************************** Obtain Spell Features ********************************
**** Function that reads the FJsonObject obj to obtain TlocSpell _spll the features ****
****************************		 for setting in it.		****************************
*				In: FJsonObject obj: the JSON object with the spell's features
*					TlocSpel _spll: the new spell in which will be set the features
*
*				Out:
*
*/
TlocSpell* TlocMotorLoader::obtainSpellFeatures(TSharedPtr<FJsonObject> obj)
{
	GlobalConstants constants;
	TArray<TSharedPtr<FJsonValue>> arr = obj->GetArrayField(constants.KINGREDIENT);
	TlocIngredients* _ing = nullptr;
	FString* _name = nullptr;
	std::vector<TlocIngredients*> splIng;
	splIng.reserve(constants.KTHREE);
	if (arr.Num() > constants.KZERO)
	{
		//Bucle for getting the spell ingredients
		for (int i = 0; i < arr.Num(); i++)
		{
			_name = new FString();
			TSharedPtr<FJsonObject> jsonObject = arr[i]->AsObject();
			jsonObject->TryGetStringField(constants.KNAME, *_name);
			_ing = NewObject<TlocIngredients>();
			_ing->SetIngredientID(jsonObject->GetNumberField(constants.KID));
			_ing->SetName((TCHAR*)**_name);
			_ing->SetQuantity(jsonObject->GetNumberField(constants.KQUANTITY));
			splIng.push_back(_ing);
		}
		FString* _desc = new FString();
		FString* _icon = new FString();
		_name = new FString();
		obj->TryGetStringField(constants.KNAME, *_name);
		obj->TryGetStringField(constants.KDESCRIPTION, *_desc);
		obj->TryGetStringField(constants.KFILE_DIRECTORY, *_icon);
		TlocSpell* _newSpell = new TlocSpell((int)obj->GetNumberField(constants.KID), **_name, **_desc, **_icon, (int) obj->GetNumberField(constants.KTARGET), (float) obj->GetNumberField(constants.KBASIC_POWER), obj->GetBoolField(constants.KACTIVE), splIng);
		return _newSpell;
	}
	else return nullptr;

}

void TlocMotorLoader::createSword(TSharedPtr<FJsonObject> obj, TlocWeapon &_wpn)
{
	GlobalConstants constants;
	TlocSword *_swrd = Cast<TlocSword>(&_wpn); 
	FString *_className = new FString(); 
	FString *_fileDirectory = new FString();
	FString *_name = new FString();
	obj->TryGetStringField(constants.KCLASS_NAME, *_className);
	obj->TryGetStringField(constants.KFILE_DIRECTORY, *_fileDirectory);
	obj->TryGetStringField(constants.KNAME, *_name);

	//_swrd = NewObject<TlocSword>();
	_swrd->SetClassName(**_className);
	_swrd->SetName(**_name);
	_swrd->SetMesh(**_fileDirectory);
	_swrd->SetPrice(obj->GetNumberField(constants.KPRICE));
	_swrd->SetAttack(obj->GetNumberField(constants.KATTACK));
	_swrd->SetWeaponID(obj->GetNumberField(constants.KID));
	_swrd->SetCriticalDamageInc(obj->GetNumberField(constants.KCRITICAL_DAMAGE_INC));
	_swrd->SetCriticalProbabilityInc(obj->GetNumberField(constants.KCRITICAL_PROBABILITY_INC));
}

void TlocMotorLoader::createSpear(TSharedPtr<FJsonObject> obj, TlocWeapon& _wpn)
{
	GlobalConstants constants;
	TlocSpear* _spr = Cast<TlocSpear>(&_wpn);
	FString* _className = new FString();
	FString* _fileDirectory = new FString();
	FString* _name = new FString();
	obj->TryGetStringField(constants.KCLASS_NAME, *_className);
	obj->TryGetStringField(constants.KFILE_DIRECTORY, *_fileDirectory);
	obj->TryGetStringField(constants.KNAME, *_name);

	_spr = NewObject<TlocSpear>();
	_spr->SetClassName(*obj->GetStringField(constants.KCLASS_NAME));
	_spr->SetName(*obj->GetStringField(constants.KNAME));
	_spr->SetMeshFileRoot(*obj->GetStringField(constants.KFILE_DIRECTORY));
	_spr->SetPrice(obj->GetNumberField(constants.KPRICE));
	_spr->SetAttack(obj->GetNumberField(constants.KATTACK));
	_spr->SetWeaponID(obj->GetNumberField(constants.KID));
	_spr->SetCriticalDamageInc(obj->GetNumberField(constants.KCRITICAL_DAMAGE_INC));
	_spr->SetCriticalProbabilityInc(obj->GetNumberField(constants.KCRITICAL_PROBABILITY_INC));

}

void TlocMotorLoader::createAxe(TSharedPtr<FJsonObject> obj, TlocWeapon& _wpn)
{
	GlobalConstants constants;
	TlocAxe* _axe = Cast<TlocAxe>(&_wpn);
	FString* _className = new FString();
	FString* _fileDirectory = new FString();
	FString* _name = new FString();
	obj->TryGetStringField(constants.KCLASS_NAME, *_className);
	obj->TryGetStringField(constants.KFILE_DIRECTORY, *_fileDirectory);
	obj->TryGetStringField(constants.KNAME, *_name);

	_axe = NewObject<TlocAxe>();
	_axe->SetClassName(*obj->GetStringField(constants.KCLASS_NAME));
	_axe->SetName(*obj->GetStringField(constants.KNAME));
	_axe->SetMeshFileRoot(*obj->GetStringField(constants.KFILE_DIRECTORY));
	_axe->SetPrice(obj->GetNumberField(constants.KPRICE));
	_axe->SetAttack(obj->GetNumberField(constants.KATTACK));
	_axe->SetWeaponID(obj->GetNumberField(constants.KID));
	_axe->SetCriticalDamageInc(obj->GetNumberField(constants.KCRITICAL_DAMAGE_INC));
	_axe->SetCriticalProbabilityInc(obj->GetNumberField(constants.KCRITICAL_PROBABILITY_INC));

}

TlocMotorLoader::TlocMotorLoader()
{
}

TlocMotorLoader::~TlocMotorLoader()
{
}
