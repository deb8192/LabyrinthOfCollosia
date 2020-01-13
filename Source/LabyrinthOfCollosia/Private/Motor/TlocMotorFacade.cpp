// Fill out your copyright notice in the Description page of Project Settings.


#include "TlocMotorFacade.h"
#include "Engine/World.h"


//para clases singleton deben tener un indicador de que se ha creado el unico objeto
ATlocMotorFacade* ATlocMotorFacade::_unic_instance = 0;
//fin indicador singleton

// Sets default values
ATlocMotorFacade::ATlocMotorFacade()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

ATlocMotorFacade::~ATlocMotorFacade()
{
}

UStaticMeshComponent* ATlocMotorFacade::SetMesh(const TCHAR* _name, const TCHAR* _directory, USceneComponent* rootComponent, UObject* obj)
{
	_mesh = NewObject<UStaticMeshComponent>(obj, _name);
	_mesh->SetupAttachment(rootComponent);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(_directory);

	if (MeshAsset.Succeeded())
	{
		_mesh->SetStaticMesh(MeshAsset.Object);
		_mesh->RegisterComponent();
		_mesh->SetWorldScale3D(FVector(1.f));
	}
	return _mesh;
}



