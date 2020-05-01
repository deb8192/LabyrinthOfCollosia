// Fill out your copyright notice in the Description page of Project Settings.


#include "Interruptor.h"

// Sets default values
AInterruptor::AInterruptor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	_motor = ATlocMotorFacade::GetInstance(this);

	active = false;

	_interactionCollision = CreateDefaultSubobject<USphereComponent>(TEXT("InteractionCollision"));
	_interactionCollision->SetSphereRadius(75.f, true);
	SetRootComponent(_interactionCollision);
	_fileRoot = TEXT("/Game/Models/Stages/Stages-objects/Interruptor.Interruptor");

	_name = TEXT("interruptor");
	_className = TEXT("Interruptor");

	_mesh = _motor->SetMesh(_name, (const TCHAR*)_fileRoot, GetRootComponent(), this);
	_mesh->SetupAttachment(_interactionCollision);

	_interactionCollision->SetRelativeLocation(FVector(GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z + 45.0f));
	_mesh->SetRelativeLocation(FVector(GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z - 45.0f));
}

AInterruptor::~AInterruptor()
{
	_interactionCollision = nullptr;
	_mesh = nullptr;
	FVector position = FVector::ZeroVector;
	FRotator rotation = FRotator::ZeroRotator;

	_motor = nullptr;
	int IDInterruptor = 0;
	_name = nullptr;
	_className = nullptr;
	_fileRoot = nullptr;
	active = false;
}

void AInterruptor::InitLocationRotation(FVector loc, FRotator rot)
{
	position = lastPosition = renderPosition = loc;
	rotation = lastRotation = renderRotation = rot;
}

void AInterruptor::replaceInterruptor(AInterruptor& _int)
{
	GlobalConstants constants;

	_mesh = _motor->SetMesh((const TCHAR*)_name, (const TCHAR*)_fileRoot, GetRootComponent(), this);
	_motor->RegisterMeshComponent(_mesh);

	char* _intName = (char*)malloc(constants.KCHAR_SIZE);
	TCHAR* _gotObjName = _int.GetClassName();
	size_t   x;
	wcstombs_s(&x, _intName, constants.KCHAR_SIZE, _gotObjName, constants.KCHAR_SIZE);

	//Object features
	IDInterruptor = _int.GetId();
	_name = _int.GetName();
	_className = _gotObjName;
	position = _int.GetPosition();
	rotation = _int.GetRotation();
	SetActorLocationAndRotation(position, rotation);
	_fileRoot = _int.GetMeshFileRoot();
	_mesh = _motor->SetMesh(_name, (const TCHAR*)_fileRoot, GetRootComponent(), this);
	_motor->MoveActor(*this, _int.GetPosition());
	_motor->RotateActor(*this, _int.GetRotation());
}

int AInterruptor::GetId()
{
	return IDInterruptor;
}

bool AInterruptor::GetActive()
{
	return active;
}

UMeshComponent* AInterruptor::GetMesh()
{
	return _mesh;
}

TCHAR* AInterruptor::GetMeshFileRoot()
{
	return _fileRoot;
}

TCHAR* AInterruptor::GetName()
{
	return _name;
}

TCHAR* AInterruptor::GetClassName()
{
	return _className;
}

FVector AInterruptor::GetPosition()
{
	return position;
}

FVector AInterruptor::GetRenderPosition()
{
	return renderPosition;
}

FRotator AInterruptor::GetRotation()
{
	return rotation;
}

FRotator AInterruptor::GetRenderRotation()
{
	return renderRotation;
}

void AInterruptor::SetId(int id)
{
	IDInterruptor = id;
}

void AInterruptor::SetActive(bool act)
{
	active = act;
}

void AInterruptor::SetPosition(FVector newPosition)
{
	position = newPosition;
}

void AInterruptor::SetRotation(FRotator newRotation)
{
	rotation = newRotation;
}

// Called when the game starts or when spawned
void AInterruptor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInterruptor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AInterruptor::SetMesh(const TCHAR* fileRoot)
{	
	_fileRoot = (TCHAR*)fileRoot;
	fileRoot = nullptr;
	_mesh = _motor->SetMesh((const TCHAR*)_name, (const TCHAR*)_fileRoot, GetRootComponent(), this);
}

void AInterruptor::SetName(const TCHAR* _nm)
{
	_name = (TCHAR*)_nm;
}

void AInterruptor::SetClassName(const TCHAR* _clssNm)
{
	_className = (TCHAR*)_clssNm;
}

