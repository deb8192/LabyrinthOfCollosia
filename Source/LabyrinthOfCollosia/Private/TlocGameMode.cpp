// Fill out your copyright notice in the Description page of Project Settings.


#include "TlocGameMode.h"
#include "TlocGameState.h"
#include <iostream>

ATlocGameMode::ATlocGameMode()
{
	_world = GetWorld();								//Get the world to manage it
	DefaultPawnClass = ATlocHumanPlayer::StaticClass();	//Associate player's pawn with player's default class
	GameStateClass = ATlocGameState::StaticClass();

	enemies.reserve(30);

	PrimaryActorTick.bCanEverTick = true;
}

ATlocGameMode::~ATlocGameMode()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ATlocGameMode::BeginPlay()
{
	Super::BeginPlay();

	const FActorSpawnParameters SpawnParam = FActorSpawnParameters();
	const FVector SpawnLocation = FVector(600, 0, 130);

	const FTransform transform = FTransform(FQuat(FRotator(0, -90, 0)), SpawnLocation, FVector(1, 1, 1));
	
	//_humanPlayer = DefaultPawnClass.GetDefaultObject();

	enemies.push_back(_world->SpawnActor<ATlocEnemy>(ATlocEnemy::StaticClass(), transform, SpawnParam));
	_world->SpawnActor<TlocWeapon>(TlocWeapon::StaticClass(), FVector(-500, -70, 100), FRotator::ZeroRotator, SpawnParam);



	/*
	PlayerControllerClass.GetDefaultObject()->UnPossess();
	PlayerControllerClass.GetDefaultObject()->Possess(_humanPlayer);*/
}

// Called every frame
void ATlocGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	enemies[0]->AddActorWorldOffset(FVector(0.0f, 0.0f, 0.0f), true);

	if (!enemies.empty() && enemies[0]->GetLife() <= 0)
	{
		enemies[0]->Destroy();
		enemies.erase(enemies.begin());
		UE_LOG(LogTemp, Warning, TEXT("You killed the enemy."));
	}



}



