// Fill out your copyright notice in the Description page of Project Settings.


#include "../Public/Characters/TlocHumanPlayer.h"
#include "Engine/World.h"
#include "../Public/GlobalConstants.h"

// Sets default values
ATlocHumanPlayer::ATlocHumanPlayer()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;
	playerEquipment._weapon = NULL;
	playerEquipment._armor = NULL;
	playerEquipment._gauntlet = NULL;

}

ATlocHumanPlayer::ATlocHumanPlayer(int idChrctr, int lvl, int lif, int att, int def, int magdef, int exp, int nxtlvl, int crit, int critProb, int lck, int eva) : TlocPlayer(idChrctr, lvl, lif, att, def, magdef, exp, nxtlvl, crit, critProb, lck, eva)
{
	ATlocHumanPlayer();
}

ATlocHumanPlayer::~ATlocHumanPlayer()
{
	//PrimaryActorTick.bCanEverTick = false;
	delete playerEquipment._weapon;
	playerEquipment._weapon = NULL;

	delete playerEquipment._armor;
	playerEquipment._armor = NULL;

	delete playerEquipment._gauntlet;
	playerEquipment._gauntlet = NULL;

}


// Called when the game starts or when spawned
void ATlocHumanPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATlocHumanPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATlocHumanPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	PlayerInputComponent->BindAxis("MoveVertically", this, &ATlocHumanPlayer::moveVertically);
	PlayerInputComponent->BindAxis("MoveHorizontally", this, &ATlocHumanPlayer::moveHorizontally);
	PlayerInputComponent->BindAxis("RotateHorizontally", this, &ATlocHumanPlayer::rotateHorizontally);
}

ATlocHumanPlayer::Equipment ATlocHumanPlayer::GetPlayerEquipment()
{
	return playerEquipment;
}

void ATlocHumanPlayer::moveVertically(float value)
{
	AddMovementInput(GetActorForwardVector(), value);
}

void ATlocHumanPlayer::moveHorizontally(float value)
{

	AddMovementInput(GetActorRightVector(), value);
}

void ATlocHumanPlayer::rotateHorizontally(float value)
{
	GlobalConstants constants;

	AddControllerYawInput(value * constants.KROTATIONSPEED * GetWorld()->GetDeltaSeconds());
}

