// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interruptor.h"
#include "Camera/CameraComponent.h"
#include <Runtime\Engine\Classes\GameFramework\SpringArmComponent.h>

/**
 * 
 */
class LABYRINTHOFCOLLOSIA_API TlocDoor : public AInterruptor
{
public:
	TlocDoor();
	~TlocDoor();

	void InitDoor();
	void ReplaceDoor(TlocDoor& _door);

private: 

	UPROPERTY(VisibleAnywhere)
		UCameraComponent* _doorCamera;
	UPROPERTY(VisibleAnywhere)
		USpringArmComponent* _doorCameraSpringArm;

};
