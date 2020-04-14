// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class LABYRINTHOFCOLLOSIA_API TlocMotorSpatialCalculus
{
public:

	//clase singleton en public
	~TlocMotorSpatialCalculus();

	static TlocMotorSpatialCalculus* GetInstance() //esto se utiliza para crear el objeto una sola vez
	{
		if (!_unic_instance)
			//We created an Unreal object, so we use NewObject<ObjClass>() (NewObject because this is not the constructor).
			_unic_instance = new TlocMotorSpatialCalculus();
		return _unic_instance;
	}
	//fin singleton public
	bool CheckIsInAttackRange(const FVector &actorPosition, const FVector &targetPosition);
	FVector CalculateVectorDistance(const FVector& positionA, const FVector& positionB);
	float CalculateModule(const FVector& position);
	float CalculateModule(const FVector& positionA, const FVector& positionB);
	FVector SetDirectorVector(FVector &directorVector, FRotator& rotation);
	void Normalize(FVector& vector);

private:
	//clase singleton 
	TlocMotorSpatialCalculus();
	static TlocMotorSpatialCalculus* _unic_instance;

	//fin clase singleton private

};
