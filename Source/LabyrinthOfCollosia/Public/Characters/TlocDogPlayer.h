// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TlocPlayer.h"

#include "GameFramework/Character.h"
#include "TlocDogPlayer.generated.h"

UCLASS()
class LABYRINTHOFCOLLOSIA_API ATlocDogPlayer : public ACharacter, public TlocPlayer
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATlocDogPlayer();
	ATlocDogPlayer(int idChrctr, int lvl, int lif, int att, int def, int magdef, int exp, int nxtlvl, int crit, int critProb, int lck, int eva);
	~ATlocDogPlayer();

	//Setters & Getters
	void SetMesh(const TCHAR* fileRoot, int mesh);
	void SetPosition(FVector newPosition);
	void SetRotation(FRotator newRotation);
	
	UStaticMeshComponent* GetMesh();

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
		TlocGauntlet* _gauntlet;
	};

	Equipment playerEquipment;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
