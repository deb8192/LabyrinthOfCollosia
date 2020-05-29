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
	//NO ES INCORRECTO, PERO NO ES FUNCIONAL EN UNREAL ENGINE
	//ATlocHumanPlayer(int idChrctr, int lvl, int lif, int att, int def, int magdef, int exp, int nxtlvl, int crit, int critProb, int lck, int eva);
	~ATlocHumanPlayer();

	virtual void Update(float DeltaTime) override;
	virtual void Render(float DeltaTime) override;
	void InitLocationRotation();
	void ModifyHudLife(float quantity);

	//Setters & Getters

	void SetWeapon(TlocWeapon* _wpn);
	void SetArmor(TlocArmor* _armr);
	void SetGauntlet(TlocGauntlet* _gntlt);
	void SetMesh(const TCHAR* fileRoot, int mesh);
	void SetWeaponMesh();

	TlocWeapon* GetWeapon();
	TlocArmor* GetArmor();
	TlocGauntlet* GetGauntlet();
	UStaticMeshComponent* GetMesh();
	UStaticMeshComponent* GetWeaponMesh();

	// Human player ingame menu
	FORCEINLINE class UTlocIngameMenu* GetIngameMenu() const
	{
		return IngameMenu;
	}
	// !Human player ingame menu

	// Players HUDs
	FORCEINLINE class UTlocHud* GetHud() const
	{
		return PlayerHud;
	}
	// !Players HUDs
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// THEY ARE PROTECTED BECAUSE THEY DEPEND ON BLUEPRINTS

	// Human player ingame menu

	// Ingame menu class
	TSubclassOf<class UUserWidget> IngameMenuUIClass;

	// Ingame menu object
	UPROPERTY(BlueprintReadWrite, Category = "UI")
		class UTlocIngameMenu* IngameMenu;
	// !Human player ingame menu

	// Player's HUD

	// Ingame HUD class
	TSubclassOf<class UUserWidget> PlayerHudUIClass;

	// Ingame HUD object
	UPROPERTY(BlueprintReadWrite, Category = "UI")
		class UTlocHud* PlayerHud;
	// !Player's HUD

	bool openMenu;

private:


	//Functions to move and rotate character
	UFUNCTION()
	void moveVertically(float value);
	UFUNCTION()
	void moveHorizontally(float value);
	void rotateHorizontally(float value);

	//Functions to open & close menu

	void loadInGameUI();
	void closeInGameUI();
	void checkMenu();
	int* getMemorizedSpellsID();

	//Functions to use menu
	void beginRotateMenuLeft();
	void beginRotateMenuRight();
	void stopRotateMenuLeft();
	void stopRotateMenuRight();
	void rotateMenuLeft();
	void rotateMenuRight();
	void moveMenuUp();
	void moveMenuDown();
	void useMenuElement();
	void chooseTarget();
	void cancel();

	//Functions to load Player's HUD and use it
	void loadHud();
	void modifyHudMaster(float quantity);

	//Functions to eject player's actions
	void action();
	void attack();
	void interact();
	void selectSpell(int selection);
	void unselectSpell();
	void selectItem(int selection);
	void pickupObject();
	void activateInterruptor();
	ATlocObject* checkChest();
	bool checkSpellIngredients(TlocSpell& _spll);

	//Variables
	using Equipment = struct equipmentStructure
	{
		TlocWeapon* _weapon;
		TlocArmor* _armor;
		TlocGauntlet* _gauntlet;
	};

	Equipment playerEquipment;						//Character's set of armor, gauntlet and weapon
	AActor* _enemy;									//Character's objective
	AActor* _object;								//Character's picking object
	bool pickingUp;
	bool interacting;
	bool ticking;
	bool rotate;

	UPROPERTY(VisibleAnywhere)
		UCameraComponent* _playerCamera;
	UPROPERTY(VisibleAnywhere)
		USpringArmComponent* _playerCameraSpringArm;

	//TEST
	//TSubclassOf<AActor> playerSpawn;
	int MyNumber;

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

	//Called to load human player default values
	void LoadPlayer();


	//Getters
	Equipment GetPlayerEquipment();
};
