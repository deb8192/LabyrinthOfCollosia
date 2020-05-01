// Fill out your copyright notice in the Description page of Project Settings.


#include "TlocDoor.h"

TlocDoor::TlocDoor() : AInterruptor()
{
	
}

TlocDoor::~TlocDoor()
{
	_doorCameraSpringArm = nullptr;
	_doorCamera = nullptr;
}

void TlocDoor::InitDoor()
{
	//CAMERA

	_doorCameraSpringArm = NewObject<USpringArmComponent>(this, (TEXT("CameraSpringArm")));
	_doorCameraSpringArm->AttachTo(GetRootComponent());
	_doorCameraSpringArm->TargetArmLength = 750.f;

	//Camera target arm
	_doorCameraSpringArm->bEnableCameraLag = true;

	_doorCamera = NewObject<UCameraComponent>(this, (TEXT("DoorCamera")));
	_doorCamera->AttachTo(_doorCameraSpringArm, USpringArmComponent::SocketName);
	_doorCameraSpringArm->SetRelativeLocationAndRotation(FVector(GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z + 500.0f), FRotator(-30.0f, 0.0f, 0.0f));
}

void TlocDoor::ReplaceDoor(TlocDoor& _door)
{
	replaceInterruptor(_door);
}
