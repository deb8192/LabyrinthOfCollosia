// Fill out your copyright notice in the Description page of Project Settings.


#include "TlocObject.h"

// Sets default values
ATlocObject::ATlocObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//mesh = new UStaticMeshComponent("/Game/Models/Characters/GuideMonk_Cube_001");

}

// Called when the game starts or when spawned
void ATlocObject::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATlocObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

