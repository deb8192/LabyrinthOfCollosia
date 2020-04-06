// Fill out your copyright notice in the Description page of Project Settings.


#include "TlocPlayerController.h"

#include "Characters/TlocHumanPlayer.h"


void ATlocPlayerController::BeginPlay()
{
	SetActorTickEnabled(false);
}

ATlocPlayerController::ATlocPlayerController()
{
	PrimaryActorTick.bCanEverTick = true;

}

ATlocPlayerController::~ATlocPlayerController()
{
}

// Called every frame
void ATlocPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATlocPlayerController::Update(float DeltaTime)
{
	AcknowledgedPawn->OnActorBeginOverlap.Get();
	AcknowledgedPawn->OnActorEndOverlap.Get();
	PlayerTick(DeltaTime);
	//ProcessPlayerInput(DeltaTime, false);
	

}

void ATlocPlayerController::Render(float DeltaTime)
{
	//TickPlayerInput(DeltaTime, false);
	Cast<ATlocHumanPlayer>(AcknowledgedPawn)->Render(DeltaTime);
}
