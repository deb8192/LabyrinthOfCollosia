// Fill out your copyright notice in the Description page of Project Settings.


#include "Interruptor.h"

// Sets default values
AInterruptor::AInterruptor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	_motor = ATlocMotorFacade::GetInstance(this);

	active = false;
	rotationSpeed = 0.0;
	moveTime = 0.0;
	_interactionCollision = CreateDefaultSubobject<USphereComponent>(TEXT("InteractionCollision"));
	_interactionCollision->SetSphereRadius(125.f, true);
	SetRootComponent(_interactionCollision);
	_fileRoot = TEXT("/Game/Models/Stages/Stages-objects/Interruptor.Interruptor");

	_name = TEXT("interruptor");
	_className = TEXT("Interruptor");

	_mesh = _motor->SetMesh(_name, (const TCHAR*)_fileRoot, GetRootComponent(), this);
	_mesh->SetupAttachment(_interactionCollision);

	_interactionCollision->SetRelativeLocation(FVector(GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z + 45.0f));
	_mesh->SetRelativeLocation(FVector(GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z - 45.0f));
	
	_doorCameraSpringArm = NewObject<USpringArmComponent>(this, (TEXT("CameraSpringArm")));
	_doorCameraSpringArm->AttachTo(GetRootComponent());
	_doorCameraSpringArm->TargetArmLength = 750.f;

	//Camera target arm
	_doorCameraSpringArm->bEnableCameraLag = true;

	_doorCamera = NewObject<UCameraComponent>(this, (TEXT("DoorCamera")));
	_doorCamera->AttachTo(_doorCameraSpringArm, USpringArmComponent::SocketName);
	_doorCameraSpringArm->SetRelativeLocationAndRotation(FVector(GetActorLocation().X-300.0f, GetActorLocation().Y + 200, GetActorLocation().Z + 300.0f), FRotator(-30.0f, -20.0f, 0.0f));
}

AInterruptor::~AInterruptor()
{
	_interactionCollision = nullptr;
	_mesh = nullptr;
	position = FVector::ZeroVector;
	rotation = defaultRotation = activeRotation = FRotator::ZeroRotator;

	_motor = nullptr;
	IDInterruptor = 0;
	_name = nullptr;
	_className = nullptr;
	_fileRoot = nullptr;
	active = false;
	rotationSpeed = 0.0;
	moveTime = 0.0;
}

void AInterruptor::InitLocationRotation(FVector loc, FRotator rot, FRotator actRot)
{
	position = lastPosition = renderPosition = loc;
	rotation = lastRotation = renderRotation = defaultRotation = rot;
	activeRotation = defaultRotation - actRot;
}

void AInterruptor::InitRotationSpeed(float spd)
{
	rotationSpeed = spd;
}

void AInterruptor::ActivateDeactivateInterruptor()
{
	active = !active;
}

void AInterruptor::Update(float updTime)
{
	updateRotation(updTime);
}

void AInterruptor::Render(float rendTime)
{
	GlobalConstants constants;
	rotateEntity(constants.KUPDATE_TIME);
	updateTimeMove(rendTime);
	//_motor->SetMeshRotation();
}

void AInterruptor::updateRotation(float updTime)
{
	moveTime = 0.0;
	GlobalConstants constants;
	if (active && rotation != activeRotation)
	{
		if (rotation.Yaw != activeRotation.Yaw)
		{
			lastRotation.Yaw = rotation.Yaw;
			if (rotation.Yaw < activeRotation.Yaw)
			{
				rotation.Yaw += rotationSpeed;
			}
			else if (rotation.Yaw > activeRotation.Yaw)
			{
				rotation.Yaw -= rotationSpeed;
			}
		}
		else if (rotation.Roll != activeRotation.Roll)
		{
			lastRotation.Roll = rotation.Roll;
			if (rotation.Roll < activeRotation.Roll)
			{
				rotation.Roll += rotationSpeed;
			}
			else if (rotation.Roll > activeRotation.Roll)
			{
				rotation.Roll -= rotationSpeed;
			}
		}
		if (abs(rotation.Roll) + rotationSpeed >= abs(activeRotation.Roll))
		{
			rotation.Roll = activeRotation.Roll;
		}
		if (abs(rotation.Yaw) + rotationSpeed >= abs(activeRotation.Yaw))
		{
			rotation.Yaw = activeRotation.Yaw;
		}
	}
	else if (!active && rotation != defaultRotation)
	{
		if (rotation.Yaw != defaultRotation.Yaw)
		{
			lastRotation.Yaw = rotation.Yaw;
			if (rotation.Yaw < defaultRotation.Yaw)
			{
				rotation.Yaw += rotationSpeed;
			}
			else if (rotation.Yaw > defaultRotation.Yaw)
			{
				rotation.Yaw -= rotationSpeed;
			}
		}
		else if (rotation.Roll != defaultRotation.Roll)
		{
			lastRotation.Roll = rotation.Roll;
			if (rotation.Roll < defaultRotation.Roll)
			{
				rotation.Roll += rotationSpeed;
			}
			else if (rotation.Roll > defaultRotation.Roll)
			{
				rotation.Roll -= rotationSpeed;
			}
		}
		if (abs(rotation.Roll) + rotationSpeed > abs(defaultRotation.Roll))
		{
			rotation.Roll = defaultRotation.Roll;
		}
		if (abs(rotation.Yaw) + rotationSpeed > abs(defaultRotation.Yaw))
		{
			rotation.Yaw = defaultRotation.Yaw;
		}
	}
	else
	{
		if(lastRotation.Yaw != rotation.Yaw)
			lastRotation.Yaw = rotation.Yaw;
		if (lastRotation.Roll != rotation.Roll)
			lastRotation.Roll = rotation.Roll;
	}
}

void AInterruptor::rotateEntity(float updTime)
{
	GlobalConstants constants;

	//pt es el porcentaje de tiempo pasado desde la posicion
	//de update antigua hasta la nueva
	float pt = moveTime / updTime;

	if (pt > constants.KONE_F)
	{
		pt = constants.KONE_F;
	}
	else if (pt < constants.KZERO_F)
	{
		pt = constants.KZERO_F;
	}
	renderRotation.Roll = lastRotation.Roll * (constants.KONE_F - pt) + rotation.Roll * pt;
	renderRotation.Pitch = lastRotation.Pitch * (constants.KONE_F - pt) + rotation.Pitch * pt;
	renderRotation.Yaw = lastRotation.Yaw * (constants.KONE_F - pt) + rotation.Yaw * pt;
}

void AInterruptor::updateTimeMove(float rendTime)
{
	moveTime += rendTime;
}

void AInterruptor::replaceInterruptor(AInterruptor& _int)
{
	GlobalConstants constants;

	char* _intName = (char*)malloc(constants.KCHAR_SIZE);
	TCHAR* _gotObjName = _int.GetClassName();
	size_t   x;
	wcstombs_s(&x, _intName, constants.KCHAR_SIZE, _gotObjName, constants.KCHAR_SIZE);

	IDInterruptor = _int.GetId();
	active = _int.GetActive();
	_name = _int.GetName();
	_className = _gotObjName;
	_fileRoot = _int.GetMeshFileRoot(); 

	InitLocationRotation(_int.GetPosition(), _int.GetRotation(), _int.GetActiveRotation());
	activeRotation = _int.GetActiveRotation();
	InitRotationSpeed(_int.GetSpeedRotation());
	_motor->MoveActor(*this, _int.GetPosition());
	//_motor->RotateActor(*this, _int.GetRotation());

	_mesh = _motor->SetMesh((const TCHAR*)_name, (const TCHAR*)_fileRoot, GetRootComponent(), this);
	_motor->RegisterMeshComponent(_mesh);
}

int AInterruptor::GetId()
{
	return IDInterruptor;
}

bool AInterruptor::GetActive()
{
	return active;
}

UStaticMeshComponent* AInterruptor::GetMesh()
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
FRotator AInterruptor::GetActiveRotation()
{
	return activeRotation;
}

FRotator AInterruptor::GetRenderRotation()
{
	return renderRotation;
}
float AInterruptor::GetSpeedRotation()
{
	return rotationSpeed;
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

