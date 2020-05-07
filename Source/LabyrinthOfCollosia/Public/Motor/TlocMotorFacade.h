// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "Engine/Scene.h"
#include "Camera/PlayerCameraManager.h"
#include "CoreMinimal.h"
#include "Object.h"
#include "GameFramework/Character.h"
#include "ConstructorHelpers.h"
#include "TlocMotorFacade.generated.h"

/**
 *
 */

UCLASS()
class LABYRINTHOFCOLLOSIA_API ATlocMotorFacade : public ACharacter
{
	GENERATED_BODY()

public:
	//clase singleton en public
	~ATlocMotorFacade();

	static ATlocMotorFacade* GetInstance(UObject* _obj) //esto se utiliza para crear el objeto una sola vez
	{
		if (!_unic_instance)
			//We created an Unreal object, so we use NewObject<ObjClass>() (NewObject because this is not the constructor).
			_unic_instance = NewObject<ATlocMotorFacade>(_obj, TEXT("Motor"));
		return _unic_instance;
	}
	//fin singleton public

	//Functions

	//Function that moves the player camera to the target enemy
	void SetViewTarget(const UObject &worldContextObject, AActor& target, float blendTime);
	//Function that sets a mesh to an object
	UStaticMeshComponent* SetMesh(const TCHAR* _name, const TCHAR* _directory, USceneComponent* rootComponent, UObject *obj);
	//Function that sets an object mesh into the world
	void RegisterMeshComponent(UStaticMeshComponent* _mesh);
	//Function that removes an object mesh from the world
	void DestroyMeshComponent(UStaticMeshComponent* _mesh);

	void MovePlayer(APawn& actor, FVector position);
	void MoveActor(AActor& actor, FVector position);
	void RotateActor(AActor& actor, FRotator rotation);

	void SetMeshPosition(AActor& actor, FVector position);
	void SetMeshRotation(UStaticMeshComponent& actor, FRotator rotation);


	void BeginPlay();

	void Tick(float DeltaTime);

private:
	//clase singleton 
	ATlocMotorFacade();
	static ATlocMotorFacade* _unic_instance;

	//fin clase singleton private
	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* _mesh;

};
