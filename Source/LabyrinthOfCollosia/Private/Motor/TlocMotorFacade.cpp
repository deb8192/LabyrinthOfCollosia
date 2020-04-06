// Fill out your copyright notice in the Description page of Project Settings.


#include "TlocMotorFacade.h"
#include "Kismet/GameplayStatics.h"
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

void ATlocMotorFacade::SetViewTarget(AActor &target, float blendTime, EViewTargetBlendFunction blendFunc, float blendExp, bool blockOutgoing)
{
	APlayerController* _pController = UGameplayStatics::GetPlayerController(this, 0);
	_pController->SetViewTargetWithBlend(&target, blendTime, blendFunc, blendExp, blockOutgoing);
}

UStaticMeshComponent* ATlocMotorFacade::SetMesh(const TCHAR* _name, const TCHAR* _directory, USceneComponent* rootComponent, UObject* obj)
{
	_mesh = NewObject<UStaticMeshComponent>(obj, _name);
	UStaticMesh* _meshAsset = LoadObject<UStaticMesh>(NULL, _directory);
	
	//static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(_directory);

	if (_meshAsset)
	{
		_mesh->SetStaticMesh(_meshAsset);
		_mesh->SetWorldScale3D(FVector(1.f));
	}
	return _mesh;
}

void ATlocMotorFacade::RegisterMeshComponent(UStaticMeshComponent* _mesh)
{
	_mesh->RegisterComponent();
}

void ATlocMotorFacade::DestroyMeshComponent(UStaticMeshComponent* _mesh)
{
	_mesh->DestroyComponent();
}

void ATlocMotorFacade::SetMeshPosition(AActor& actor, FVector& position)
{
	actor.SetActorLocation(position);
}

void ATlocMotorFacade::SetMeshRotation(AActor& actor, FRotator& rotation)
{
	actor.SetActorRotation(rotation);
}

// Called when the game starts or when spawned
void ATlocMotorFacade::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATlocMotorFacade::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}



