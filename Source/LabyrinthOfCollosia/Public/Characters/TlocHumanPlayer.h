// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TlocPlayer.h"

#include "GameFramework/Character.h"
#include "TlocHumanPlayer.generated.h"

UCLASS()
class LABYRINTHOFCOLLOSIA_API ATlocHumanPlayer : public ACharacter , public TlocPlayer
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATlocHumanPlayer();
	ATlocHumanPlayer(int idChrctr, int lvl, int lif, int att, int def, int magdef, int exp, int nxtlvl, int crit, int critProb, int lck, int eva);
	~ATlocHumanPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	//Functions to move and rotate character
	void moveVertically(float value);
	void moveHorizontally(float value);
	void rotateHorizontally(float value);

	//Variables
	using Equipment = struct equipmentStructure
	{
		TlocWeapon* _weapon;
		TlocArmor* _armor;
		TlocGauntlet* _gauntlet;
	};

	Equipment playerEquipment;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//Getters
	Equipment GetPlayerEquipment();
};
