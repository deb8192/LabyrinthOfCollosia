// Fill out your copyright notice in the Description page of Project Settings.


#include "TlocObject.h"
#include "ConstructorHelpers.h"

#include "Engine/Scene.h"
#include "./GlobalConstants.h"

// Sets default values
ATlocObject::ATlocObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	_motor = ATlocMotorFacade::GetInstance(this);

	_interactionCollision = CreateDefaultSubobject<USphereComponent>(TEXT("InteractionCollision"));
	_interactionCollision->SetSphereRadius(50.f, true);
	_interactionCollision->SetupAttachment(GetRootComponent());

	_fileRoot = TEXT("/Game/Models/Equipment/Weapons/Gladius.Gladius");
	_name = TEXT("object");

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

void ATlocObject::replaceObject(FVector pos, FRotator rot, TCHAR* _path, UStaticMeshComponent* _mesh)
{
	position = pos;
	rotation = rot;
	SetActorLocationAndRotation(pos, rot);
	_fileRoot = _path;
	_wpnMesh = NULL;
	_wpnMesh = _motor->SetMesh((const TCHAR*)_name, (const TCHAR*)_fileRoot, GetRootComponent(), this);
	_motor->RegisterMeshComponent(_wpnMesh);
	//_wpnMesh->SetRelativeLocationAndRotation(pos, rot);
}

void ATlocObject::SetMesh(const TCHAR* fileRoot)
{
	_fileRoot = (TCHAR*) fileRoot;
	fileRoot = NULL;
	_wpnMesh = _motor->SetMesh((const TCHAR*) _name, (const TCHAR*) _fileRoot, GetRootComponent(), this);
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

UStaticMeshComponent* ATlocObject::GetMesh()
{
	return _wpnMesh;
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


