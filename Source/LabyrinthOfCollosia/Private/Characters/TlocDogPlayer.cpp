// Fill out your copyright notice in the Description page of Project Settings.


#include "TlocDogPlayer.h"

// Sets default values
ATlocDogPlayer::ATlocDogPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

ATlocDogPlayer::~ATlocDogPlayer()
{
}

// Called when the game starts or when spawned
void ATlocDogPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATlocDogPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATlocDogPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

