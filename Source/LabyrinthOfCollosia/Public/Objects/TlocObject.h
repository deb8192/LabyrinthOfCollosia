// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/SphereComponent.h"

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

	//Getters & Setters
	void SetMesh(const TCHAR* fileRoot);
	void SetAttributes();
	void SetPosition(FVector newPosition);
	UStaticMeshComponent* GetMesh();
	const TCHAR* GetMeshFileRoot();

private:

	int IDObject;
	char *name;
	const TCHAR * fileRoot;
	float price;


	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* _wpnMesh;
	USphereComponent* _interactionCollision;
};
