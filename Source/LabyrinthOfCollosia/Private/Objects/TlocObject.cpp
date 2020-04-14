// Fill out your copyright notice in the Description page of Project Settings.


#include "TlocObject.h"
#include "ConstructorHelpers.h"

#include "Engine/Scene.h"
#include "./GlobalConstants.h"

#include "..\Public\Magic\TlocIngredients.h"
#include "..\Public\Objects\TlocItem.h"
#include "..\Public\Objects\Weapons\TlocWeapon.h"
#include "..\Public\Objects\TlocArmor.h"
#include "..\Public\Objects\TlocGauntlet.h"
#include "..\Public\Objects\TlocChest.h"

// Sets default values
ATlocObject::ATlocObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	_motor = ATlocMotorFacade::GetInstance(this);

	_interactionCollision = CreateDefaultSubobject<USphereComponent>(TEXT("InteractionCollision"));
	_interactionCollision->SetSphereRadius(75.f, true);
	SetRootComponent(_interactionCollision);

	_fileRoot = TEXT("/Game/Models/Equipment/Weapons/Gladius.Gladius");
	_spriteFileRoot = TEXT("/Game/Sprites/Equipment/Weapons/Icons-128/Gladius-128px.Gladius128px");
	_name = TEXT("object");
	_className = TEXT("ATlocObject");

	_wpnMesh = _motor->SetMesh(_name, (const TCHAR*)_fileRoot, GetRootComponent(), this);
	_wpnMesh->SetupAttachment(_interactionCollision);

	_interactionCollision->SetRelativeLocation(FVector(GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z + 45.0f));
	_wpnMesh->SetRelativeLocation(FVector(GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z - 45.0f));
}


// Called when the game starts or when spawned
void ATlocObject::BeginPlay()
{
	Super::BeginPlay();

	//_motor->RegisterMeshComponent(_wpnMesh);
	//_wpnMesh->SetRelativeRotation(FRotator(GetActorRotation().Pitch, GetActorRotation().Yaw, GetActorRotation().Roll -90));
	
}

// Called every frame
void ATlocObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATlocObject::ReplaceObject(ATlocObject* _obj)
{
	GlobalConstants constants;
	
	_wpnMesh = _motor->SetMesh((const TCHAR*)_name, (const TCHAR*)_fileRoot, GetRootComponent(), this);
	//_wpnMesh->SetupAttachment(_interactionCollision);
	_motor->RegisterMeshComponent(_wpnMesh);

	char* _objName = (char*)malloc(constants.KCHAR_SIZE);
	TCHAR* _gotObjName = _obj->GetClassName();
	size_t   x;
	wcstombs_s(&x, _objName, constants.KCHAR_SIZE, _gotObjName, constants.KCHAR_SIZE);

	//Object features
	IDObject = _obj->GetIDObject();
	_name = _obj->GetName();
	price = _obj->GetPrice();
	_className = _gotObjName;
	position = _obj->GetPosition();
	rotation = _obj->GetRotation();
	SetActorLocationAndRotation(position, rotation);
	_fileRoot = _obj->GetMeshFileRoot();
	_wpnMesh = _motor->SetMesh(_name, (const TCHAR*)_fileRoot, GetRootComponent(), this);

	//Child features
	
	//WEAPONS
	if (strcmp(_objName, constants.KWEAPON) == 0)
	{
		TlocWeapon* _wpn = (TlocWeapon*)_obj;
		TlocWeapon* _wpnThis = (TlocWeapon*)this;

		_wpnThis->SetAttack(_wpn->GetAttack());
		_wpnThis->SetLevel(_wpn->GetLevel());
		_wpnThis->SetExperience(_wpn->GetExperience());
		_wpnThis->SetNextLevel(_wpn->GetNextLevel());
		_wpnThis->SetCriticalDamageInc(_wpn->GetCriticalDamageInc());
		_wpnThis->SetCriticalProbabilityInc(_wpn->GetCriticalProbabilityInc());
		_wpnThis->SetLongRange(_wpn->GetLongRange());

	}

	else if (strcmp(_objName, constants.KCHEST_CLASS) == 0)
	{
		TlocChest* _chst = (TlocChest*)_obj;
		TlocChest* _chstThis = (TlocChest*)this;


		_chstThis->SetOpened(_chst->GetOpened());
		_chstThis->SetObject(_chst->GetObject());


	}
	//GAUNTLETS
	else if (strcmp(_objName, constants.KGAUNTLET) == 0)
	{
		TlocGauntlet* _glt = (TlocGauntlet*)_obj;
		TlocGauntlet* _gntltThis = (TlocGauntlet*)this;
		//_gntltThis->SetDefense(_glt->GetDefense());
	}
	//ARMORS
	/*else if (strcmp(_objName, constants.KARMOR) == 0)
	{
		TlocArmor* _arm = (TlocArmor*)_obj;
		_armor.push_back(_arm);
	}
	//INGREDIENTS
	else if (strcmp(_objName, constants.KINGREDIENT) == 0)
	{
		TlocIngredients* _ing = (TlocIngredients*)_obj;
		GlobalConstants constants;
		int i = 0;
		while (i < _ingredients.size())
		{
			if (_ingredients[i].front() != nullptr && _ingredients[i].front()->GetID() == _ing->GetID())
			{
				_ingredients[i].push_back(_ing);
				i = _ingredients.size();
			}
			else
			{
				i++;
			}
		}
	}
	//ITEMS
	else if (dynamic_cast<TlocItem*>(_obj))
	{
		TlocItem* _itm = (TlocItem*)_obj;
		GlobalConstants constants;
		int i = 0;
		while (i < _items.size())
		{
			if (_items[i].front() != nullptr && _items[i].front() == _itm)
			{
				_items[i].push_back(_itm);
				i = _items.size();
			}
			else
			{
				i++;
			}
		}
	}
	*/
	
}
void ATlocObject::ReplaceMesh(const TCHAR* fileRoot)
{
	if (_wpnMesh != NULL)
	{
		_motor->DestroyMeshComponent(_wpnMesh);
		_wpnMesh = NULL;
	}
	_wpnMesh = _motor->SetMesh((const TCHAR*)_name, (const TCHAR*)_fileRoot, GetRootComponent(), this);
	_motor->RegisterMeshComponent(_wpnMesh);
}
void ATlocObject::RegisterMeshComponent()
{
	if (_wpnMesh)
	{
		_motor->RegisterMeshComponent(_wpnMesh);
	}
}

void ATlocObject::DestroyMeshComponent()
{
	if (_wpnMesh != NULL)
	{
		_motor->DestroyMeshComponent(_wpnMesh);
		_wpnMesh = NULL;
	}
}

void ATlocObject::SetMeshFileRoot(const TCHAR* fileRoot)
{
	_fileRoot = (TCHAR*) fileRoot;
}

void ATlocObject::SetMesh(const TCHAR* fileRoot)
{
	if (fileRoot != nullptr)
	{
		SetMeshFileRoot(fileRoot);
		_wpnMesh = _motor->SetMesh((const TCHAR*)_name, (const TCHAR*)_fileRoot, GetRootComponent(), this);
	}
}

void ATlocObject::SetClassName(const TCHAR* _clsNm)
{
	_className = (TCHAR*)_clsNm;
}

void ATlocObject::SetPrice(float pric)
{
	price = pric;
}

void ATlocObject::SetName(const TCHAR* _nm)
{
	_name = (TCHAR*) _nm;
}

void ATlocObject::SetAttributes()
{
}

void ATlocObject::SetPosition(FVector newPosition)
{
	position = newPosition;
	SetActorLocation(newPosition);
	_wpnMesh->SetRelativeLocation(newPosition);
}

void ATlocObject::SetRotation(FRotator newRotation)
{
	rotation = newRotation;
	SetActorRotation(newRotation);
	_wpnMesh->SetRelativeRotation(newRotation);
}

int ATlocObject::GetIDObject()
{
	return IDObject;
}

TCHAR* ATlocObject::GetName()
{
	return _name;
}

TCHAR* ATlocObject::GetClassName()
{
	return _className;
}

float ATlocObject::GetPrice()
{
	return price;
}

UStaticMeshComponent* ATlocObject::GetMesh()
{
	return _wpnMesh;
}

USphereComponent* ATlocObject::GetInteractionCollision()
{
	return _interactionCollision;
}

FVector ATlocObject::GetPosition()
{
	return position;
}

FRotator ATlocObject::GetRotation()
{
	return rotation;
}

TCHAR* ATlocObject::GetMeshFileRoot()
{
	return _fileRoot;
}


