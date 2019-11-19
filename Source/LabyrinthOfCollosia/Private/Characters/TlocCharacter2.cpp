// Fill out your copyright notice in the Description page of Project Settings.


#include "..\Public\Characters\TlocCharacter2.h"
#include "..\Public\GlobalConstants.h"
#include "Engine/World.h"

// Sets default values
ATlocCharacter2::ATlocCharacter2()
{
	GlobalConstants constants;
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	_ingredients.reserve(constants.KMAXINGREDIENTS);
	_spells.reserve(constants.KMAXSPELLS);
}

ATlocCharacter2::ATlocCharacter2(int idChrctr, int lvl, int lif, int att, int def)
{
	ATlocCharacter2();
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ID = idChrctr;
	level = lvl;
	life = lif;
	attack = def;

}

ATlocCharacter2::~ATlocCharacter2()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ATlocCharacter2::BeginPlay()
{
	Super::BeginPlay();

}

void ATlocCharacter2::modifyLife(float quantity)
{
}

void ATlocCharacter2::move()
{
}

// Called every frame
void ATlocCharacter2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATlocCharacter2::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	PlayerInputComponent->BindAxis("MoveVertically", this, &ATlocCharacter2::moveVertically);
	PlayerInputComponent->BindAxis("MoveHorizontally", this, &ATlocCharacter2::moveHorizontally);
	PlayerInputComponent->BindAxis("RotateHorizontally", this, &ATlocCharacter2::rotateHorizontally);
}



void ATlocCharacter2::moveVertically(float value)
{
	AddMovementInput(GetActorForwardVector(), value);
}

void ATlocCharacter2::moveHorizontally(float value)
{

	AddMovementInput(GetActorRightVector(), value);
}

void ATlocCharacter2::rotateHorizontally(float value)
{
	GlobalConstants constants;

	AddControllerYawInput(value * constants.KROTATIONSPEED * GetWorld()->GetDeltaSeconds());
}