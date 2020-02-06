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

	void replaceObject(FVector pos, FRotator rot, TCHAR* _path, UStaticMeshComponent* _mesh);

	//Getters & Setters
	void SetMesh(const TCHAR* fileRoot);
	void SetAttributes();
	void SetPosition(FVector newPosition);
	void SetRotation(FRotator newRotation);
	UStaticMeshComponent* GetMesh();
	FVector GetPosition();
	FRotator GetRotation();
	TCHAR* GetMeshFileRoot();

private:

	FVector position;
	FRotator rotation;

	int IDObject;
	TCHAR* _name;
	TCHAR* _fileRoot;
	float price;

	//Facade variables
	ATlocMotorFacade* _motor;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* _wpnMesh;
	USphereComponent* _interactionCollision;
};
