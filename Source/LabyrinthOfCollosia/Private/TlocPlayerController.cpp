// Fill out your copyright notice in the Description page of Project Settings.


#include "TlocPlayerController.h"
#include "GameFramework/CharacterMovementComponent.h"

#include "Characters/TlocHumanPlayer.h"


void ATlocPlayerController::BeginPlay()
{
	SetActorTickEnabled(false);

	dynamic_cast<ACharacter*>(Cast<ATlocHumanPlayer>(AcknowledgedPawn))->GetCharacterMovement()->JumpZVelocity = 500;
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
	Cast<ATlocHumanPlayer>(AcknowledgedPawn)->Update(DeltaTime);
	//PlayerTick(DeltaTime);
	ProcessPlayerInput(DeltaTime, false);
	
}

void ATlocPlayerController::Render(float DeltaTime)
{
	//TickPlayerInput(DeltaTime, false);
	Cast<ATlocHumanPlayer>(AcknowledgedPawn)->Render(DeltaTime);
}
