// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <vector>
#include <queue>
#include "..\Public\Magic\TlocSpell.h"
#include "..\Public\Magic\TlocIngredients.h"
#include "..\Public\Objects\TlocItem.h"
#include "..\Public\Objects\Weapons\TlocWeapon.h"
#include "..\Public\Objects\TlocArmor.h"
#include "..\Public\Objects\TlocGauntlet.h"
#include "..\Public\Motor\TlocMotorFacade.h"
#include "Camera/CameraComponent.h"
#include <Runtime\Engine\Classes\GameFramework\SpringArmComponent.h>
//#include "TlocEnemy.h"

#include "CoreMinimal.h"


/**
 * TlocCharacters is an interface that will contain the expresion of character's main function 
 */
class LABYRINTHOFCOLLOSIA_API TlocCharacter
{
public:

	// Called when the game starts or when spawned
	virtual ~TlocCharacter() {};

	virtual void Update(float DeltaTime) = 0;
	virtual void Render(float rendTime) = 0;
	virtual void ModifyLife(float quantity) = 0;				//Adds or substracts as many as quantity value is
	virtual int Attack() = 0;									//Calculates hit damage
	virtual int Magic() = 0;									//Calculates magic damage
	virtual void Transact() = 0;								//Function for buying or selling objects
	virtual void Talk() = 0;									//Function to talk with anyone
	virtual void Move() = 0;									//Function to move the character
	virtual void Defend() = 0;									//Function to activate or desactivate defense state
	virtual void AddWeapon(TlocWeapon &wpn) = 0;								//Function to add weapons to weapons vector
	
	// Getters & Setters
	virtual int GetID() = 0;
	virtual int GetLevel() = 0;
	virtual int GetLife() = 0;
	virtual float GetDefaultLife() = 0;
	virtual float GetMaster() = 0;
	virtual float GetDefaultMaster() = 0;
	virtual int GetAttack() = 0;
	virtual int GetDefense() = 0;
	virtual int GetMagicDefense() = 0;
	virtual float GetCriticalHit() = 0;
	virtual float GetCriticalProb() = 0;
	virtual int GetEvasion() = 0;
	virtual int GetLuck() = 0;
	virtual bool GetDefend() = 0;
	virtual int GetAttacking() = 0;
	//virtual int GetTalons() = 0;
	virtual int GetJewels() = 0;
	//virtual int GetCredits() = 0;
	virtual bool GetInvulnerable() = 0;
	virtual float GetInvulnerableTime() = 0;
	virtual UStaticMeshComponent* GetMesh() = 0;
	virtual FVector GetPosition() = 0;
	virtual FRotator GetRotation() = 0;
	virtual FVector GetRenderPosition() = 0;
	virtual FRotator GetRenderRotation() = 0;
	virtual std::vector<TlocIngredients*> GetIngredients() = 0;
	virtual std::vector<TlocSpell*> GetSpells() = 0;
	virtual TlocSpell* GetAttackingSpell() = 0;
	virtual std::vector<TlocSpell* > GetMemorizedSpells() = 0;
	virtual std::vector<std::vector<TlocItem*>> GetItems() = 0;
	virtual std::vector<TlocWeapon* > GetWeapons() = 0;
	virtual std::vector<TlocArmor*> GetArmors() = 0;
	virtual std::vector<TlocGauntlet*> GetGauntlets() = 0;
	virtual std::queue<int> GetBuffAilments() = 0;
	virtual std::queue<float> GetBuffAilmentsTime() = 0;
	virtual TCHAR* GetName() = 0;
	virtual TCHAR* GetClassName() = 0;
	virtual std::vector<AActor*> GetTargetEnemies() = 0;
	virtual std::vector<AActor*> GetTargetPlayers() = 0;
	virtual std::vector<AActor*> GetTargetObjects() = 0;

	virtual void SetInitialLife(float lif) = 0;
	virtual void SetInitialMaster(float mstr) = 0;
	virtual void SetID(int id) = 0;
	virtual void SetLevel(int lvl) = 0;
	virtual void SetLife(float lif) = 0;
	virtual void SetDefaultLife(float dfltLif) = 0;
	virtual void SetMaster(float mstr) = 0;
	virtual void SetDefaultMaster(float dfltMstr) = 0;
	virtual void SetAttack(int att) = 0;
	virtual void SetDefense(int def) = 0;
	virtual void SetMagicDefense(int magDef) = 0;
	virtual void SetCriticalHit(float critHit) = 0;
	virtual void SetCriticalProb(float critProb) = 0;
	virtual void SetEvasion(int ev) = 0;
	virtual void SetLuck(int lck) = 0;
	virtual void SetDefend(bool dfnd) = 0;
	virtual void SetAttacking(bool attckng) = 0;
	//virtual void SetTalons(int tlns) = 0;
	virtual void SetJewels(int jwls) = 0;
	//virtual void SetCredits(int crdts) = 0;
	virtual void SetInvulnerable(bool inv) = 0;
	virtual void SetInvulnerableTime(float invTime) = 0;
	virtual void SetMesh(const TCHAR* fileRoot, int mesh) = 0;
	virtual void SetPosition(FVector newPosition) = 0;
	virtual void SetRotation(FRotator newRotation) = 0;
	virtual void SetIngredients(std::vector<TlocIngredients*> &_ing) = 0;
	virtual void SetSpells(std::vector<TlocSpell*> &_splls) = 0;
	virtual void SetMemorizedSpells(std::vector<TlocSpell*> &_memSplls) = 0;
	virtual void SetItems(std::vector<std::vector<TlocItem*>> &_itms) = 0;
	virtual void SetWeapons(std::vector<TlocWeapon*> &_wpns) = 0;
	virtual void SetArmors(std::vector<TlocArmor*> &_armrs) = 0;
	virtual void SetGauntlets(std::vector<TlocGauntlet*> &_gntlt) = 0;
	virtual void SetBuffAilments(std::queue<int> &_bffsAil) = 0;
	virtual void SetBuffAilmentsTime(std::queue<float> &_bffsAilTime) = 0;
	virtual void SetName(TCHAR* _nm) = 0;
	virtual void SetClassName(TCHAR* _clssNm) = 0;
	virtual void SetTargetEnemies(std::vector<AActor*>& _enm) = 0;
	virtual void SetTargetPlayers(std::vector<AActor*>& _all) = 0;
	virtual void SetTargetObjects(std::vector<AActor*>& _obj) = 0;

protected:

	// Functions
	virtual void moveEntity(float updTime) = 0;
	virtual void rotateEntity(float updTime) = 0;
	virtual void updateTimeMove(float rendTime) = 0;


	// Variables
	int ID;											//Character's ID
	int level;										//Character's level
	float life;										//Character's life
	float defaultLife;								//Character's whole life
	float master;									//Character's spetial attack points
	float defaultMaster;							//Character's special attack max points
	int attack;										//Character's attack
	int defense;									//Character's defense
	int magicDef;									//Character's magic defense
	float criticalHit;								//Character's critical hit damage
	float criticalProb;								//Character's critical hit probability
	int evasion;									//Character's hit evade probability
	int luck;										//Character's hit probability
	bool defending;									//Character's defending state
	bool attacking;									//Character's attacking state									//Character's picking up state
	//int talons;									//Character's Prehistoria money
	int jewels;										//Character's Antiqua money
	//int credits;									//Character's Onmitopia money
	bool invulnerable;
	float invulnerableTime;
	std::vector<TlocIngredients*> _ingredients;		//Character's ingredient list
	std::vector<TlocSpell*> _learnedSpells;			//Character's learned spell list
	std::vector<TlocSpell*> _memorizedSpells;		//Character's memorized spell list from the learned spell list
	std::vector<std::vector<TlocItem*>> _items;		//Character's menu items
	std::vector<TlocWeapon*> _weapon;				//Character's weapons
	std::vector<TlocArmor*> _armor;					//Character's armors
	std::vector<TlocGauntlet*> _gauntlet;			//Character's gauntlets
	std::queue<int> _buffsAilments;					//Character's active buffs or ailments
	std::queue<float> buffsAilmentsTime;			//Character's active buffs or ailments' time

	TlocSpell* _attackingSpell;						//Character's prepared spell to Cast
	std::vector<TlocIngredients*> _attackingSpellIngredients;	//Character's prepared spell ingredients
	std::vector<AActor*> _targetEnemies;			//Character's enemy targets
	std::vector<AActor*> _targetPlayers;				//Character's ally targets
	std::vector<AActor*> _targetObjects;			//Character's object targets

	TCHAR* _name;
	TCHAR* _className;
	FVector position, lastPosition, renderPosition;
	FRotator rotation, lastRotation, renderRotation, defaultRotation;
	float speed, moveTime, rotateTime;

	//Facade variables
	ATlocMotorFacade* _motor;

	//Unreal variables
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent *_charMesh;
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* _wpnMesh;

	TCHAR* _fileRoot;
};