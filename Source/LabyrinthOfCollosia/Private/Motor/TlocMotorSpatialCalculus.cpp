// Fill out your copyright notice in the Description page of Project Settings.


#include "TlocMotorSpatialCalculus.h"
#include <cmath>
#include "GlobalConstants.h"

TlocMotorSpatialCalculus* TlocMotorSpatialCalculus::_unic_instance = 0;

bool TlocMotorSpatialCalculus::CheckIsInAttackRange(const FVector& actorPosition, const FVector& targetPosition)
{
    GlobalConstants constants;
    float module = CalculateModule(actorPosition, targetPosition);
    bool inRange = false;
    if (module <= constants.KMAX_TARGET_DISTANCE)
    {
        inRange = true;
    }
    return inRange;
}

FVector TlocMotorSpatialCalculus::CalculateVectorDistance(const FVector& positionA, const FVector& positionB)
{
    //We get the distance vectorand the module between actorPositionand targetPostion
    FVector distance = FVector(abs(positionA.X - positionB.X), abs(positionA.Y - positionB.Y), abs(positionA.Z - positionB.Z));
    return distance;
}
float TlocMotorSpatialCalculus::CalculateModule(const FVector& position)
{
   //We get vector module
    float module = pow(position.X, 2) + pow(position.Y, 2) + pow(position.Z, 2);
    module = sqrt(module);
    return module;
}

float TlocMotorSpatialCalculus::CalculateModule(const FVector& positionA, const FVector& positionB)
{
    FVector distance = CalculateVectorDistance(positionA, positionB);

    //We get the distance in one value (vector module)
    float module = pow(distance.X, 2) + pow(distance.Y, 2) + pow(distance.Z, 2);
    module = sqrt(module);
    return module;
}

FVector TlocMotorSpatialCalculus::SetDirectorVector(FVector& directorVector, FRotator& rotation)
{
    GlobalConstants constants;
    directorVector.X = sin(PI * rotation.Yaw / constants.KPI_RADIAN);
    directorVector.Y = cos(PI * rotation.Yaw / constants.KPI_RADIAN);
    directorVector.Z = 0.0f;
    Normalize(directorVector);
    return directorVector;
}

void TlocMotorSpatialCalculus::Normalize(FVector& vector)
{
    float module = CalculateModule(vector);
    vector.X /= module;
    vector.Y /= module;
    vector.X /= module;
}

TlocMotorSpatialCalculus::TlocMotorSpatialCalculus()
{
}

TlocMotorSpatialCalculus::~TlocMotorSpatialCalculus()
{
}
