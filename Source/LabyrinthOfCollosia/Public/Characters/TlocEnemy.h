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

	//Getters & Setters

	// -Getters TlocCharacter
	int GetID();
	int GetLevel();
	int GetLife();
	float GetDefaultLife();
	float GetMaster();
	float GetDefaultMaster();
	int GetAttack();
	int GetDefense();
	int GetMagicDefense();
	float GetCriticalHit();
	float GetCriticalProb();
	int GetEvasion();
	int GetLuck();
	bool GetDefend();
	int GetAttacking();
	//int GetTalons();
	int GetJewels();
	//int GetCredits();
	bool GetInvulnerable();
	float GetInvulnerableTime();
	UStaticMeshComponent* GetMesh();
	FVector GetPosition();
	FRotator GetRotation();
	TCHAR* GetMeshFileRoot();
	TArray<TCHAR*> GetMeshesFileRoot();
	
	// -Setters TlocCharacter
	void SetInitialLife(float lif);
	void SetInitialMaster(float mstr);
	void SetID(int id);
	void SetLevel(int lvl);
	void SetLife(float lif);
	void SetDefaultLife(float dfltLif);
	void SetMaster(float mstr);
	void SetDefaultMaster(float dfltMstr);
	void SetAttack(int att);
	void SetDefense(int def);
	void SetMagicDefense(int magDef);
	void SetCriticalHit(float critHit);
	void SetCriticalProb(float critProb);
	void SetEvasion(int ev);
	void SetLuck(int lck);
	void SetDefend(bool dfnd);
	void SetAttacking(bool attckng);
	//void SetTalons(int tlns);
	void SetJewels(int jwls);
	//void SetCredits(int crdts);
	void SetInvulnerable(bool inv);
	void SetInvulnerableTime(float invTime);
	void SetMesh(const TCHAR* fileRoot, int mesh);
	void SetPosition(FVector newPosition);
	void SetRotation(FRotator newRotation);


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
