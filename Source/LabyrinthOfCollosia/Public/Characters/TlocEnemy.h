// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TlocCharacter.h"

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TlocEnemy.generated.h"

UCLASS()
class LABYRINTHOFCOLLOSIA_API ATlocEnemy : public ACharacter, public TlocCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATlocEnemy();
	ATlocEnemy(int idChrctr, int lvl, int lif, int att, int def, int magdef, int crit, int critProb, int lck, int eva);
	~ATlocEnemy();

	//Character's functions
	void ModifyLife(float quantity);
	int  Attack();
	//int  Attack(TlocPlayer* _ply);
	int Magic();
	void Transact();
	void Talk();
	void Move();
	void Defend();

	//Setters & Getters
	void SetMesh(const TCHAR* fileRoot, int mesh);
	void SetPosition(FVector newPosition);
	void SetRotation(FRotator newRotation);

	UStaticMeshComponent* GetMesh();
	FVector GetPosition();
	FRotator GetRotation();

	TCHAR* GetMeshFileRoot();
	TArray<TCHAR*> GetMeshesFileRoot();

	bool GetDefend();
	int GetLife();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void replaceEnemy(ATlocEnemy* _enm);

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:

	UStaticMeshComponent* _auxCharMesh;
	UStaticMeshComponent* _auxCharMesh2;

	TCHAR* _auxFilePath;
	TCHAR* _auxFilePath2;

};
