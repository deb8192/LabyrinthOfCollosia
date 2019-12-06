// Fill out your copyright notice in the Description page of Project Settings.


#include "TlocGameMode.h"
#include <iostream>
#include "Engine/World.h"

ATlocGameMode::ATlocGameMode()
{
	//humanPlayer = CreateNewObject;
	DefaultPawnClass = ATlocHumanPlayer::StaticClass();
	//DefaultPawnClass->
}

ATlocGameMode::~ATlocGameMode()
{
}

void ATlocGameMode::BeginPlay()
{
	Super::BeginPlay();
	//GEngine->AddOnScreenDebugMessage(-1, -1, FColor::Red, TEXT("Actor Spawning"));

	FTransform *SpawnLocation = new FTransform(FVector(20, 0, 0));
	//humanPlayer = new ATlocHumanPlayer(0, 1, 50, 25, 20, 15, 0, 100, 2, 15, 75, 35);
	GetWorld()->SpawnActor(ATlocHumanPlayer::StaticClass(), SpawnLocation);
}



