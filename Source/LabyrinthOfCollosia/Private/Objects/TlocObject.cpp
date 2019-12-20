// Fill out your copyright notice in the Description page of Project Settings.


#include "TlocObject.h"
#include "ConstructorHelpers.h"

#include "Engine/Scene.h"

// Sets default values
ATlocObject::ATlocObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	_interactionCollision = CreateDefaultSubobject<USphereComponent>(TEXT("InteractionCollision"));
	_interactionCollision->SetupAttachment(GetRootComponent());

	_wpnMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ObjectMesh"));
	_wpnMesh->SetupAttachment(_interactionCollision);

	fileRoot = TEXT("/Game/Models/Equipment/Weapons/Gladius.Gladius");

	static ConstructorHelpers::FObjectFinder<UStaticMesh> ObjectMeshAsset(fileRoot);

	if (ObjectMeshAsset.Succeeded())
	{
		_wpnMesh->SetStaticMesh(ObjectMeshAsset.Object);
		_wpnMesh->SetWorldScale3D(FVector(1.f));
	}

}


// Called when the game starts or when spawned
void ATlocObject::BeginPlay()
{
	Super::BeginPlay();


	_wpnMesh->SetRelativeRotation(FRotator(0.0, 0.0, -90));
	
}

// Called every frame
void ATlocObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATlocObject::SetMesh(const TCHAR* fileRoot)
{
}

void ATlocObject::SetAttributes()
{
}

void ATlocObject::SetPosition(FVector newPosition)
{
	_wpnMesh->SetRelativeLocation(newPosition);
}

UStaticMeshComponent* ATlocObject::GetMesh()
{
	return _wpnMesh;
}

const TCHAR* ATlocObject::GetMeshFileRoot()
{
	return fileRoot;
}


