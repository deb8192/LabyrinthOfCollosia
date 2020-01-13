// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "Engine/Scene.h"
#include "CoreMinimal.h"
#include "Object.h"
#include "GameFramework/Character.h"
#include "ConstructorHelpers.h"
#include "TlocMotorFacade.generated.h"

/**
 *
 */

UCLASS()
class LABYRINTHOFCOLLOSIA_API ATlocMotorFacade : public ACharacter
{
	GENERATED_BODY()

public:
	//clase singleton en public
	~ATlocMotorFacade();

	static ATlocMotorFacade* GetInstance() //esto se utiliza para crear el objeto una sola vez
	{
		if (!_unic_instance)
			_unic_instance = NewObject<ATlocMotorFacade>();
		return _unic_instance;
	}
	//fin singleton public

	//Functions
	UStaticMeshComponent* SetMesh(const TCHAR* _name, const TCHAR* _directory, USceneComponent* rootComponent, UObject *obj);

private:
	//clase singleton 
	ATlocMotorFacade();
	static ATlocMotorFacade* _unic_instance;

	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* _mesh;
	//fin clase singleton private

};
