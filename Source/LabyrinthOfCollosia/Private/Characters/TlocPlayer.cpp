// Fill out your copyright notice in the Description page of Project Settings.

#include "../Public/Characters/TlocPlayer.h"
#include "Camera/CameraComponent.h"
#include "Components/SkeletalMeshComponent.h"

// Sets default values
ATlocPlayer::ATlocPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

ATlocPlayer::ATlocPlayer(int idChrctr, int lvl, int lif, int att, int def, int exp, int nxtlvl) : ATlocCharacter2(idChrctr, lvl, lif, att, def)
{
	experience = exp;
	nextLevel = nxtlvl;
}

ATlocPlayer::~ATlocPlayer()
{
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void ATlocPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATlocPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATlocPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}


bool ATlocPlayer::Defense()
{
	return false;
}

