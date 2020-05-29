// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GlobalConstants.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "..\Public\Motor\TlocMotorFacade.h"
#include <LabyrinthOfCollosia\Public\Motor\TlocMotorFacade.h>
#include "Camera/CameraComponent.h"
#include <Runtime\Engine\Classes\GameFramework\SpringArmComponent.h>
#include "Interruptor.generated.h"

UCLASS()
class LABYRINTHOFCOLLOSIA_API AInterruptor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInterruptor();
	~AInterruptor();
	
	void InitLocationRotation(FVector loc, FRotator rot, FRotator actRot);
	void InitRotationSpeed(float spd);
	void ActivateDeactivateInterruptor();
	void Update(float updTime);
	void Render(float rendTime);
	void updateRotation(float updTime);
	void rotateEntity(float updTime);
	void updateTimeMove(float rendTime);

	int GetId();
	bool GetActive();
	UStaticMeshComponent* GetMesh();
	TCHAR* GetMeshFileRoot();
	TCHAR* GetName();
	TCHAR* GetClassName();
	FVector GetPosition();
	FVector GetRenderPosition();
	FRotator GetRotation();
	FRotator GetActiveRotation();
	FRotator GetRenderRotation();
	float GetSpeedRotation();

	void SetId(int id);
	void SetActive(bool act);
	void SetMesh(const TCHAR* fileRoot);
	void SetName(const TCHAR* _nm);
	void SetClassName(const TCHAR* _clssNm);
	void SetPosition(FVector newPosition);
	void SetRotation(FRotator newRotation);


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void replaceInterruptor(AInterruptor& _int);

	USphereComponent* _interactionCollision;
	UStaticMeshComponent* _mesh;
	FVector position, lastPosition, renderPosition;
	FRotator rotation, lastRotation, renderRotation, defaultRotation, activeRotation;
	float moveTime, rotationSpeed;

	ATlocMotorFacade* _motor;
	int IDInterruptor;
	TCHAR* _name;
	TCHAR* _className;
	TCHAR* _fileRoot;
	bool active;

	UPROPERTY(VisibleAnywhere)
		UCameraComponent* _doorCamera;
	UPROPERTY(VisibleAnywhere)
		USpringArmComponent* _doorCameraSpringArm;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


};