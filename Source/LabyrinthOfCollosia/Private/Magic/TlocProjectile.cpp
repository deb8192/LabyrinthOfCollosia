// Fill out your copyright notice in the Description page of Project Settings.


#include "TlocProjectile.h"
#include "GlobalConstants.h"

// Sets default values
ATlocProjectile::ATlocProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	_motor = ATlocMotorFacade::GetInstance(this);

	_projectileMesh = _motor->SetMesh(TEXT("ProjectileMesh"), TEXT("StaticMesh'/Engine/BasicShapes/Sphere.Sphere'"), GetRootComponent(), this);

	_originActor = _targetActor = nullptr;
	origin = FVector::ZeroVector;
	target = FVector::ZeroVector;
	directorVector = FVector::ZeroVector;
	position = lastPosition = renderPosition = FVector::ZeroVector;
	rotation = lastRotation = renderRotation = FRotator::ZeroRotator;
	moveTime = 0.f;
	speed = 1000.f;
	pursue = false;
	_spatialCalculusMotor = TlocMotorSpatialCalculus::GetInstance();
}

ATlocProjectile::~ATlocProjectile()
{
	_originActor = _targetActor = nullptr;
	origin = FVector::ZeroVector;
	target = FVector::ZeroVector;
	directorVector = FVector::ZeroVector;
	position = lastPosition = renderPosition = FVector::ZeroVector;
	rotation = lastRotation = renderRotation = FRotator::ZeroRotator;
	moveTime = 0.f;
	speed = 0.f;
	pursue = false;
	delete _spatialCalculusMotor;
}

// Called when the game starts or when spawned
void ATlocProjectile::BeginPlay()
{
	Super::BeginPlay();

	SetActorTickEnabled(false);
	_motor->RegisterMeshComponent(_projectileMesh);

}

// Called every frame
void ATlocProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATlocProjectile::Update(float DeltaTime)
{
	GlobalConstants constants;
	Move();
}


void ATlocProjectile::Render(float rendTime)
{
	GlobalConstants constants;
	moveEntity(constants.KUPDATE_TIME);
	rotateEntity(constants.KUPDATE_TIME);
	updateTimeMove(rendTime);

	//if(renderPosition.X)
	//AddMovementInput(GetActorRightVector(), renderPosition.X);
	//AddMovementInput(GetActorForwardVector(), renderPosition.Y);
	//_motor->MovePlayer(*this, renderPosition);
	//_motor->SetMeshRotation(*this, renderRotation);
}

void ATlocProjectile::SetOrigin(FVector origPos)
{
	origin = origPos;
}

void ATlocProjectile::SetTarget(FVector targPos)
{
	target = targPos;
}

void ATlocProjectile::SetOriginActor(AActor& origAct)
{
	_originActor = &origAct;
}

void ATlocProjectile::SetTargetActor(AActor& targAct)
{
	_targetActor = &targAct;
}

void ATlocProjectile::SetPosition(FVector pos)
{
	position = pos;
}

void ATlocProjectile::SetLastPosition(FVector pos)
{
	lastPosition = pos;
}

void ATlocProjectile::SetDirectorVector()
{
	lookAtTarget();
}

void ATlocProjectile::SetPursue(bool purs)
{
	pursue = purs;
}

void ATlocProjectile::Move()
{
	moveTime = 0.0;
	if (pursue)
	{
		SetTarget(_targetActor->GetActorLocation());
		lookAtTarget();
	}
	moveX();
	moveY();
}

void ATlocProjectile::Rotate(FRotator newRotation)
{
	lastRotation = rotation;
	rotation = newRotation;
}

FVector ATlocProjectile::GetRenderPosition()
{
	return renderPosition;
}

FRotator ATlocProjectile::GetRenderRotation()
{
	return renderRotation;
}

bool ATlocProjectile::GetPursue()
{
	return pursue;
}

void ATlocProjectile::moveEntity(float updTime)
{
	GlobalConstants constants;
	if (position.X != lastPosition.X || position.Y != lastPosition.Y)
	{

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

		renderPosition.X = lastPosition.X * (constants.KONE_F - pt) + position.X * pt;
		renderPosition.Y = lastPosition.Y * (constants.KONE_F - pt) + position.Y * pt;
	}
	if (position.X == lastPosition.X)
	{
		renderPosition.X = constants.KZERO_F;
	}
	if (position.Y == lastPosition.Y)
	{
		renderPosition.Y = constants.KZERO_F;
	}

}

void ATlocProjectile::rotateEntity(float updTime)
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

void ATlocProjectile::updateTimeMove(float rendTime)
{
	moveTime += rendTime;
}

void ATlocProjectile::moveX()
{
	GlobalConstants constants;
	lastPosition.X = position.X;
	position.X += directorVector.X * speed * constants.KUPDATE_TIME;
	if (lastPosition.X == position.X)
	{
		position.X = lastPosition.X = constants.KZERO_F;
	}
}

void ATlocProjectile::moveY()
{
	GlobalConstants constants;
	lastPosition.Y = position.Y;
	position.Y += directorVector.Y * speed * constants.KUPDATE_TIME;
	if (lastPosition.Y == position.Y)
	{
		position.Y = lastPosition.Y = constants.KZERO_F;
	}
}

void ATlocProjectile::lookAtTarget()
{
	float contraRotacion = 0.0f;
	GlobalConstants constants;

	FVector distance = _spatialCalculusMotor->CalculateVectorDistance(origin, target);
	float module = _spatialCalculusMotor->CalculateModule(origin, target);

	distance.Y < 0 ?
		rotation.Yaw = constants.KPI_RADIAN + (constants.RAD_TO_DEG * atan(distance.X / distance.Y)) :
		rotation.Yaw = constants.RAD_TO_DEG * atan(distance.X / distance.Y);


	/*if (huir)
	{
		rotation.Yaw *= -1;
	}*/

	this->Rotate(rotation);
	_spatialCalculusMotor->SetDirectorVector(directorVector, rotation);
}
