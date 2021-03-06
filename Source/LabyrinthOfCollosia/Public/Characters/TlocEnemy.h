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

	void Update(float DeltaTime);
	void Render(float rendTime);
	//Character's functions
	void ModifyLife(float quantity);
	int  Attack();
	//int  Attack(TlocPlayer* _ply);
	int Magic();
	void Transact();
	void Talk();
	void Move();
	void Defend();
	void AddWeapon(TlocWeapon& wpn);

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
	FVector GetRenderPosition();
	FRotator GetRenderRotation();
	TCHAR* GetMeshFileRoot();
	TArray<TCHAR*> GetMeshesFileRoot();
	std::vector<TlocIngredients*> GetIngredients();
	std::vector<TlocSpell*> GetSpells();
	TlocSpell* GetAttackingSpell();
	std::vector<TlocSpell* > GetMemorizedSpells();
	std::vector<std::vector<TlocItem*>> GetItems();
	std::vector<TlocWeapon* > GetWeapons();
	std::vector<TlocArmor*> GetArmors();
	std::vector<TlocGauntlet*> GetGauntlets();
	std::queue<int> GetBuffAilments();
	std::queue<float> GetBuffAilmentsTime();
	TCHAR* GetName();
	TCHAR* GetClassName();
	std::vector<AActor*> GetTargetEnemies();
	std::vector<AActor*> GetTargetPlayers();
	std::vector<AActor*> GetTargetObjects();

	// -Getters TlocEnemy
	bool GetCoward();
	float GetSpeed();
	
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
	void SetIngredients(std::vector<TlocIngredients*>& _ing);
	void SetSpells(std::vector<TlocSpell*>& _splls);
	void SetMemorizedSpells(std::vector<TlocSpell*>& _memSplls);
	void SetItems(std::vector<std::vector<TlocItem*>>& _itms);
	void SetWeapons(std::vector<TlocWeapon*>& _wpns);
	void SetArmors(std::vector<TlocArmor*>& _armrs);
	void SetGauntlets(std::vector<TlocGauntlet*>& _gntlt);
	void SetBuffAilments(std::queue<int>& _bffsAil);
	void SetBuffAilmentsTime(std::queue<float>& _bffsAilTime);
	void SetName(TCHAR* _nm);
	void SetClassName(TCHAR* _clssNm);
	void SetTargetEnemies(std::vector<AActor*>& _enm);
	void SetTargetPlayers(std::vector<AActor*>& _all);
	void SetTargetObjects(std::vector<AActor*>& _obj);

	// -Getters TlocEnemy
	void SetCoward(bool cwrd);
	void SetSpeed(float spd);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnEnemyActorHit(UPrimitiveComponent* _attackCollision, AActor* _other, UPrimitiveComponent* _otherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Hit);
	UFUNCTION()
	void OnEnemyActorStopHit(UPrimitiveComponent* _attackCollision, AActor* _other, UPrimitiveComponent* _otherComp, int32 OtherBodyIndex);

	// Functions
	void moveEntity(float updTime);
	void rotateEntity(float updTime);
	void updateTimeMove(float rendTime);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void replaceEnemy(ATlocEnemy* _enm);

	//Stearing behaviors
	float RunAway(FVector runawayPos);
	void Wander();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:

	int attackEnemy();
	void calculateRunawayRoute(FVector runawayPos);

	UStaticMeshComponent* _auxCharMesh;
	UStaticMeshComponent* _auxCharMesh2;

	TCHAR* _auxFilePath;
	TCHAR* _auxFilePath2;

	UPROPERTY(VisibleAnywhere)
		USpringArmComponent* _targetCameraSpringArm;
	UPROPERTY(VisibleAnywhere)
		UCameraComponent* _targetCamera;

	AActor* _enemy;
	bool coward;
	float noCowardTime;
	bool jump;
	bool projectil;
	bool runningAway;
	float runAwayTime;
	float wanderTime;
};
