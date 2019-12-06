// Fill out your copyright notice in the Description page of Project Settings.

#include "../Public/Characters/TlocHumanPlayer.h"
#include "../Public/Characters/TlocEnemy.h"
#include "Engine/World.h"
#include "../Public/GlobalConstants.h"

// Sets default values
ATlocHumanPlayer::ATlocHumanPlayer() : TlocPlayer()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	playerEquipment._weapon = NULL;
	playerEquipment._armor = NULL;
	playerEquipment._gauntlet = NULL;

}

//COMENTADO PARA EXPORTACIONES DE PROYECTO

/*ATlocHumanPlayer::ATlocHumanPlayer(int idChrctr, int lvl, int lif, int att, int def, int magdef, int exp, int nxtlvl, int crit, int critProb, int lck, int eva) : TlocPlayer(idChrctr, lvl, lif, att, def, magdef, exp, nxtlvl, crit, critProb, lck, eva)
{
	ATlocHumanPlayer();
}*/

ATlocHumanPlayer::~ATlocHumanPlayer()
{
	PrimaryActorTick.bCanEverTick = false;
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
	GetWorld()->SpawnActor<AActor>(playerSpawn);
	//OnActorHit.AddDynamic(this, &ATlocHumanPlayer::OnHumanActorHit);
	
}

// Called every frame
void ATlocHumanPlayer::Tick(float DeltaTime)
{
	//AddActorWorldOffset(FVector(0, 0, 0));
	//AddActorLocalOffset(FVector(1, 0, 0));
	//Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATlocHumanPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	PlayerInputComponent->BindAxis("MoveVertically", this, &ATlocHumanPlayer::moveVertically);
	PlayerInputComponent->BindAxis("MoveHorizontally", this, &ATlocHumanPlayer::moveHorizontally);
	PlayerInputComponent->BindAxis("RotateHorizontally", this, &ATlocHumanPlayer::rotateHorizontally);

	PlayerInputComponent->BindAction("Attack", IE_Pressed, this, &ATlocHumanPlayer::attack);
}

void ATlocHumanPlayer::OnHumanActorHit(AActor *player, AActor *enemy)
{
	int damage = this->Attack();
	ATlocEnemy *tlocEnemy = Cast<ATlocEnemy>(enemy);
	tlocEnemy->ModifyLife(damage);

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

void ATlocHumanPlayer::attack()
{
	Attack(playerEquipment._weapon);
}

