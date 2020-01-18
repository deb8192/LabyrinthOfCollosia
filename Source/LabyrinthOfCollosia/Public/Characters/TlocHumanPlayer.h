// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TlocPlayer.h"

#include <Runtime\Engine\Classes\GameFramework\SpringArmComponent.h>
#include "GameFramework/Character.h"
#include "TlocHumanPlayer.generated.h"

UCLASS()
class LABYRINTHOFCOLLOSIA_API ATlocHumanPlayer : public ACharacter , public TlocPlayer
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties

	ATlocHumanPlayer();
	//NO ES INCORRECTO, PERO NO ES FUNCIONAL EN UNREAL ENGINE
	//ATlocHumanPlayer(int idChrctr, int lvl, int lif, int att, int def, int magdef, int exp, int nxtlvl, int crit, int critProb, int lck, int eva);
	~ATlocHumanPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:


	//Functions to move and rotate character
	void moveVertically(float value);
	void moveHorizontally(float value);
	void rotateHorizontally(float value);

	void attack();
	void takeObj();
	void pickupObject();

	//Variables
	using Equipment = struct equipmentStructure
	{
		TlocWeapon* _weapon;
		TlocArmor* _armor;
		TlocGauntlet* _gauntlet;
	};

	Equipment playerEquipment;
	AActor* _enemy;
	AActor* _object;
	bool pickingUp;									//Character picking up state


	UPROPERTY(VisibleAnywhere)
	UCameraComponent* _playerCamera; 
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* _playerCameraSpringArm;

	//TEST
	//TSubclassOf<AActor> playerSpawn;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
		void OnHumanActorHit(UPrimitiveComponent* _weaponMesh, AActor* _other, UPrimitiveComponent* _otherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Hit);
	UFUNCTION()
		void OnHumanActorStopHit(UPrimitiveComponent* _weaponMesh, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	UFUNCTION()
		void OnHumanActorOverlap(AActor* _player, AActor* _obj);
	UFUNCTION()
		void OnHumanActorStopOverlap(AActor* _player, AActor* _obj);

	//Getters
	Equipment GetPlayerEquipment();
};
