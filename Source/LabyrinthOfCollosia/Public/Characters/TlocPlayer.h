// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TlocCharacter2.h"

/**
 *
 */

UCLASS()
class LABYRINTHOFCOLLOSIA_API ATlocPlayer : public ATlocCharacter2
{

public:
	// Sets default values for this character's properties
	ATlocPlayer();
	ATlocPlayer(int idChrctr, int lvl, int lif, int att, int def, int exp, int nxtlvl);
	~ATlocPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Variables
	int nextLevel;
	int experience;

public:	

	bool Defense();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
