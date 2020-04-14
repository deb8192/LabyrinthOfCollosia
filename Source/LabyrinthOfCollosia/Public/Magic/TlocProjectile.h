// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Motor/TlocMotorFacade.h"
#include "Motor/TlocMotorSpatialCalculus.h"
#include "Components/StaticMeshComponent.h"
#include "TlocProjectile.generated.h"

UCLASS()
class LABYRINTHOFCOLLOSIA_API ATlocProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATlocProjectile();
	~ATlocProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Update(float rendTime);
	void Render(float rendTime);
	void Move();
	void Rotate(FRotator newRotation);

	void SetOrigin(FVector origPos);
	void SetTarget(FVector targPos);
	void SetOriginActor(AActor &origAct);
	void SetTargetActor(AActor &targAct);
	void SetPosition(FVector pos);
	void SetLastPosition(FVector pos);
	void SetDirectorVector();
	void SetPursue(bool purs);

	FVector GetRenderPosition();
	FRotator GetRenderRotation();
	bool GetPursue();

private:

	void moveEntity(float updTime);
	void rotateEntity(float updTime);
	void updateTimeMove(float rendTime);
	void moveX();
	void moveY();
	void lookAtTarget();

	AActor *_originActor, *_targetActor;
	FVector origin;
	FVector target;
	FVector directorVector;
	FVector position, lastPosition, renderPosition;
	FRotator rotation, lastRotation, renderRotation;
	float moveTime;
	float speed;
	bool pursue;
	TlocMotorSpatialCalculus* _spatialCalculusMotor;
	ATlocMotorFacade* _motor;
	UStaticMeshComponent* _projectileMesh;
};
