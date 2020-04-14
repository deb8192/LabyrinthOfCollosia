// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/SphereComponent.h"
#include "..\Public\Motor\TlocMotorFacade.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TlocObject.generated.h"

UCLASS()
class LABYRINTHOFCOLLOSIA_API ATlocObject : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATlocObject();
	virtual ~ATlocObject() {};

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void ReplaceObject(ATlocObject* _obj);
	void ReplaceMesh(const TCHAR* fileRoot);

	void RegisterMeshComponent();
	void DestroyMeshComponent();

	//Getters & Setters
	void SetName(const TCHAR* _nm);
	void SetClassName(const TCHAR* _clsNm);
	void SetPrice(float pric);
	void SetAttributes();
	void SetPosition(FVector newPosition);
	void SetRotation(FRotator newRotation);
	void SetMesh(const TCHAR* fileRoot);
	void SetMeshFileRoot(const TCHAR* fileRoot);

	int GetIDObject();
	TCHAR* GetName();
	TCHAR* GetClassName();
	float GetPrice();
	USphereComponent* GetInteractionCollision();
	FVector GetPosition();
	FRotator GetRotation();
	UStaticMeshComponent* GetMesh();
	TCHAR* GetMeshFileRoot();

protected:

	FVector position;
	FRotator rotation;

	int IDObject;
	TCHAR* _name;
	TCHAR* _className;
	TCHAR* _fileRoot;
	TCHAR* _spriteFileRoot;
	float price;

	//Facade variables
	ATlocMotorFacade* _motor;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* _wpnMesh;
	USphereComponent* _interactionCollision;
};
