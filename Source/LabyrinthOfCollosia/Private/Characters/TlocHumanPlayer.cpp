// Fill out your copyright notice in the Description page of Project Settings.

#include "../Public/Characters/TlocHumanPlayer.h"
#include "../Public/Characters/TlocEnemy.h"
#include "../Public/Objects/TlocChest.h"
#include "../Public/GlobalConstants.h"

#include "Engine/World.h"
#include "Engine/Scene.h"
#include "ConstructorHelpers.h"

// Sets default values
ATlocHumanPlayer::ATlocHumanPlayer() : TlocPlayer()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	//Player equip and motor
	playerEquipment._weapon = CreateDefaultSubobject<TlocWeapon>(TEXT("PlayerWeapon")); /* NewObject<TlocWeapon>();*/		//Calling the constructor to create a new TlocWeapon object
	_weapon.push_back(playerEquipment._weapon);
	playerEquipment._armor = NULL;
	playerEquipment._gauntlet = NULL;

	_motor = ATlocMotorFacade::GetInstance(this);

	_enemy = NULL;

	//---- MEGA IMPORTANT: THERE ARE SOME CODE SENTENCES THAT CAN BE WRITTEN IN MOTOR ----

	//MESH

	_fileRoot = TEXT("/Game/Models/Characters/Hero-M.Hero-M");
	_charMesh = _motor->SetMesh(TEXT("PlayerMesh"), (const TCHAR*) _fileRoot, GetRootComponent(), this);
	_charMesh->SetupAttachment(GetRootComponent());
	_charMesh->SetRelativeLocation(FVector(GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z - 90));
	_charMesh->SetRelativeRotation(FRotator(GetActorRotation().Pitch, GetActorRotation().Yaw - 90, GetActorRotation().Roll));
	
	//CAMERA

	_playerCameraSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraSpringArm"));
	_playerCameraSpringArm->SetupAttachment(GetRootComponent());
	_playerCameraSpringArm->TargetArmLength = 250.f;

	//Camera target arm
	_playerCameraSpringArm->bEnableCameraLag = true;

	_playerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));
	_playerCamera->SetupAttachment(_playerCameraSpringArm, USpringArmComponent::SocketName);
	_playerCameraSpringArm->SetRelativeLocationAndRotation(FVector(GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z + 45.0), FRotator(-10.0f, 0.0f, 0.0f));


	_wpnMesh = _motor->SetMesh(TEXT("WeaponMesh"), (const TCHAR*)playerEquipment._weapon->GetMeshFileRoot(), GetRootComponent(), this);
	_wpnMesh->SetupAttachment(GetRootComponent());

	_wpnMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 25.0f));
	_wpnMesh->SetRelativeRotation(FRotator(-90.f, 0.0f, 0.0f));

	_wpnMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);

	/*playerEquipment._weapon->GetMesh()->SetupAttachment(GetRootComponent());

	playerEquipment._weapon->GetMesh()->SetRelativeLocation(FVector(0.0f, 0.0f, 25.0f));
	playerEquipment._weapon->GetMesh()->SetRelativeRotation(FRotator(-90.f, 0.0f, 0.0f));

	playerEquipment._weapon->GetMesh()->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	*/


	static ConstructorHelpers::FClassFinder<UUserWidget> IngameMenuUIBPClass(TEXT("/Game/UserInterface/Menu/TlocInGameMenuBP"));

	if (IngameMenuUIBPClass.Class != nullptr)
	{
		IngameMenuUIClass = IngameMenuUIBPClass.Class;
	}

	static ConstructorHelpers::FClassFinder<UUserWidget> PlayerHudUIBPClass(TEXT("/Game/UserInterface/HUD/HUD-BP"));

	if (IngameMenuUIBPClass.Class != nullptr)
	{
		PlayerHudUIClass = PlayerHudUIBPClass.Class;
	}

	openMenu = false;
	


}

//COMENTADO PARA EXPORTACIONES DE PROYECTO

/*ATlocHumanPlayer::ATlocHumanPlayer(int idChrctr, int lvl, int lif, int att, int def, int magdef, int exp, int nxtlvl, int crit, int critProb, int lck, int eva) : TlocPlayer(idChrctr, lvl, lif, att, def, magdef, exp, nxtlvl, crit, critProb, lck, eva)
{
	ATlocHumanPlayer();
}*/

ATlocHumanPlayer::~ATlocHumanPlayer()
{
	PrimaryActorTick.bCanEverTick = false;
	//delete playerEquipment._weapon;
	playerEquipment._weapon = NULL;

	//delete playerEquipment._armor;
	playerEquipment._armor = NULL;

	//delete playerEquipment._gauntlet;
	playerEquipment._gauntlet = NULL;

	_enemy = nullptr;
	_object = nullptr;
	pickingUp = false;

	//Delete UI
	if (IngameMenu && PlayerHud->IsInViewport())
	{
		IngameMenu->RemoveFromViewport();
	}
	IngameMenu = nullptr;
	IngameMenuUIClass = nullptr;
	openMenu = false;

	if (PlayerHud && PlayerHud->IsInViewport())
	{
		PlayerHud->RemoveFromViewport();
	}
	PlayerHud = nullptr;
	PlayerHudUIClass = nullptr;

	_playerCamera = nullptr;

	_playerCameraSpringArm = nullptr;

}


// Called when the game starts or when spawned
void ATlocHumanPlayer::BeginPlay()
{
	Super::BeginPlay();	

	LoadPlayer();

	_motor->RegisterMeshComponent(_charMesh);
	_motor->RegisterMeshComponent(_wpnMesh);
	_wpnMesh->OnComponentBeginOverlap.AddDynamic(this, &ATlocHumanPlayer::OnHumanActorHit);
	_wpnMesh->OnComponentEndOverlap.AddDynamic(this, &ATlocHumanPlayer::OnHumanActorStopHit);
	OnActorBeginOverlap.AddDynamic(this, &ATlocHumanPlayer::OnHumanActorOverlap);
	OnActorEndOverlap.AddDynamic(this, &ATlocHumanPlayer::OnHumanActorStopOverlap);
}

// Called every frame
void ATlocHumanPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ATlocHumanPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	PlayerInputComponent->BindAxis("MoveVertically", this, &ATlocHumanPlayer::moveVertically);
	PlayerInputComponent->BindAxis("MoveHorizontally", this, &ATlocHumanPlayer::moveHorizontally);
	PlayerInputComponent->BindAxis("RotateHorizontally", this, &ATlocHumanPlayer::rotateHorizontally);

	PlayerInputComponent->BindAction("PickUp", IE_Pressed, this, &ATlocHumanPlayer::takeObj);
	PlayerInputComponent->BindAction("Attack", IE_Pressed, this, &ATlocHumanPlayer::attack);
	PlayerInputComponent->BindAction("OpenMenu", IE_Pressed, this, &ATlocHumanPlayer::checkMenu);
	PlayerInputComponent->BindAction("RotLeftMenu", IE_Pressed, this, &ATlocHumanPlayer::rotateMenuLeft);
	PlayerInputComponent->BindAction("RotRightMenu", IE_Pressed, this, &ATlocHumanPlayer::rotateMenuRight);
}


//Function to activate the player's attack
void ATlocHumanPlayer::OnHumanActorHit(UPrimitiveComponent* _weaponMesh, AActor* _other, UPrimitiveComponent* _otherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Hit)
{
	if (!attacking && dynamic_cast<ATlocEnemy*>(_other))
	{
		attacking = true;
		_enemy = _other;
	}
}

//Function to deactivate the player's attack
void ATlocHumanPlayer::OnHumanActorStopHit(UPrimitiveComponent* _weaponMesh, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (attacking)
	{
		attacking = false;
		_enemy = NULL;
	}
}

//Function to activate the player's picking up function
void ATlocHumanPlayer::OnHumanActorOverlap(AActor* _player, AActor* _obj)
{
	if (!pickingUp && dynamic_cast<ATlocObject*>(_obj))
	{
		pickingUp = true;
		_object = _obj;
	}
}

//Function to deactivate the player's picking up function
void ATlocHumanPlayer::OnHumanActorStopOverlap(AActor* _player, AActor* _obj)
{
	if (pickingUp)
	{
		pickingUp = false;
		_object = NULL;
	}
}

void ATlocHumanPlayer::LoadPlayer()
{
	loadHud();
	PlayerHud->SetPlayerPic(player);
}

ATlocHumanPlayer::Equipment ATlocHumanPlayer::GetPlayerEquipment()
{
	return playerEquipment;
}

void ATlocHumanPlayer::moveVertically(float value)
{
	AddMovementInput(GetActorForwardVector(), value);
}

void ATlocHumanPlayer::moveHorizontally(float value)
{

	AddMovementInput(GetActorRightVector(), value);
}

void ATlocHumanPlayer::rotateHorizontally(float value)
{
	GlobalConstants constants;

	AddControllerYawInput(value * constants.KROTATIONSPEED * GetWorld()->GetDeltaSeconds());
}

void ATlocHumanPlayer::loadInGameUI()
{
	if (IngameMenuUIClass == nullptr) return;

	if (IngameMenu == nullptr)
	{
		IngameMenu = CreateWidget<UTlocIngameMenu>(GetWorld(), IngameMenuUIClass);
	}
	if (IngameMenu == nullptr) return;

	IngameMenu->AddToViewport();
}

void ATlocHumanPlayer::closeInGameUI()
{
	IngameMenu->RemoveFromViewport();
	//IngameMenu = nullptr;
}

void ATlocHumanPlayer::checkMenu()
{
	if (openMenu)
	{
		openMenu = false;
		closeInGameUI();
	}
	else
	{
		openMenu = true;
		loadInGameUI();
	}
}

void ATlocHumanPlayer::rotateMenuLeft()
{
	if (openMenu)
	{
		IngameMenu->RotateMenu(false);
	}
}

void ATlocHumanPlayer::rotateMenuRight()
{
	if (openMenu)
	{
		IngameMenu->RotateMenu(true);
	}
}


void ATlocHumanPlayer::loadHud()
{
	if (PlayerHudUIClass == nullptr) return;

	PlayerHud = CreateWidget<UTlocHud>(GetWorld(), PlayerHudUIClass);
	if (PlayerHud == nullptr) return;

	PlayerHud->AddToViewport();
}

void ATlocHumanPlayer::modifyHudLife(/*float quantity*/)
{
	//TEST
	ModifyLife(-25);
	float percent = life / defaultLife;
	PlayerHud->ModifyLifeBar(percent);
	modifyHudMaster(-25/defaultLife);
}

void ATlocHumanPlayer::modifyHudMaster(float quantity)
{
	GlobalConstants constants;
	if (quantity < constants.KZERO_F)
	{
		PlayerHud->ModifyMasterBar(abs(quantity));
	}
}

void ATlocHumanPlayer::attack()
{
	//If player is attacking some enemy
	if (attacking)
	{
		//It's calculated the attack damage
		GlobalConstants constants;
		int damage = this->Attack(playerEquipment._weapon);

		//If hit doesn't miss
		if (damage != constants.KMINUS_ONE)
		{
			//Enemy's life is modified with damage value
			ATlocEnemy* tlocEnemy = Cast<ATlocEnemy>(_enemy);
			tlocEnemy->ModifyLife(-damage);
		}
		//Stoping player's attack and erasing target enemy.
		attacking = false;
		_enemy = NULL;
	}
}

void ATlocHumanPlayer::takeObj()
{
	if (pickingUp && _object != NULL)
	{
		//Calling function that saves the object in players inventory
		pickupObject();
		pickingUp = false;

		//After keeping the object, it is destroyed from the stage
		_object->Destroy();
		_object = NULL;
	}
}

/************************** pick up Object **************************
***  Function that push the object taken from the game stage  ****
***	into its correspondant array according to the object type ****
******************************************************************
*				In:
*
*				Out:
*
*/
void ATlocHumanPlayer::pickupObject()
{

	GlobalConstants constants;
	if (_object != NULL)
	{
		ATlocObject* _obj = checkChest();

		if (_obj != nullptr)
		{
			//It's made able the char* and const char* chains comparation copying TCHAR* _gotObjName (_obj class name) into char* _objName
			char* _objName = (char*)malloc(constants.KCHAR_SIZE);
			TCHAR* _gotObjName = _obj->GetClassName();
			size_t   x;
			wcstombs_s(&x, _objName, constants.KCHAR_SIZE, _gotObjName, constants.KCHAR_SIZE);

			//It obtains _obj's child class and identifies which one is it's child class
			//WEAPONS
			if ((strcmp(_objName, constants.KSWORD) == 0) || (strcmp(_objName, constants.KSPEAR) == 0) || (strcmp(_objName, constants.KAXE) == 0))
			{
				TlocWeapon* _wpn = (TlocWeapon*)_obj;
				_weapon.push_back(_wpn);
				UE_LOG(LogTemp, Warning, TEXT("You picked up a weapon."));
			}
			//GAUNTLETS
			else if (strcmp(_objName, constants.KGAUNTLET) == 0)
			{
				TlocGauntlet* _glt = (TlocGauntlet*)_obj;
				_gauntlet.push_back(_glt);
				UE_LOG(LogTemp, Warning, TEXT("You picked up a gauntlet."));
			}
			//ARMORS
			else if (strcmp(_objName, constants.KARMOR) == 0)
			{
				TlocArmor* _arm = (TlocArmor*)_obj;
				_armor.push_back(_arm);
				UE_LOG(LogTemp, Warning, TEXT("You picked up an armor."));
			}
			//INGREDIENTS
			else if (strcmp(_objName, constants.KINGREDIENT) == 0)
			{
				TlocIngredients* _ing = (TlocIngredients*)_obj;
				int i = 0;
				while (i < _ingredients.size())
				{
					if (_ingredients[i].front() != nullptr && _ingredients[i].front()->GetID() == _ing->GetID())
					{
						_ingredients[i].push_back(_ing);
						i = _ingredients.size();
					}
					else
					{
						i++;
					}
				}
				UE_LOG(LogTemp, Warning, TEXT("You picked up an ingredient."));
			}
			//ITEMS
			else if (strcmp(_objName, constants.KITEM) == 0)
			{
				TlocItem* _itm = (TlocItem*)_obj;
				int i = 0;
				while (i < _items.size())
				{
					if (_items[i].front() != nullptr && _items[i].front() == _itm)
					{
						_items[i].push_back(_itm);
						i = _items.size();
					}
					else
					{
						i++;
					}
				}
				UE_LOG(LogTemp, Warning, TEXT("You picked up an item."));
			}
		}
		else UE_LOG(LogTemp, Warning, TEXT("The chest it's been opened yet."));
	}
}
/***************************  check Chest  ***************************
*** Function than checks if the taken object is a chest or not.   ****
***	In case of being a not opened chest, returns the object that  ****
*** remains inside and, if it is not a chest, returns the proper  ****
*** object.														  ****
**********************************************************************
*				In:
*
*				Out:	ATlocObject* _object (taken world object)
*
*/
ATlocObject* ATlocHumanPlayer::checkChest()
{
	GlobalConstants constants;
	//It's made able the char* and const char* chains comparation copying TCHAR* _gotObjName (_obj class name) into char* _objName
	char* _objName = (char*)malloc(constants.KCHAR_SIZE);
	ATlocObject* _obj = Cast<ATlocObject>(_object);
	TCHAR* _gotObjName = _obj->GetClassName();
	size_t   x;
	wcstombs_s(&x, _objName, constants.KCHAR_SIZE, _gotObjName, constants.KCHAR_SIZE);
	if (strcmp(_objName, constants.KCHEST_CLASS) == 0)
	{
		TlocChest* _chest = Cast<TlocChest>(_object);
		if (!_chest->GetOpened())
		{
			_chest->SetOpened(constants.KTRUE);
			return _chest->GetObject();
		}
		else return nullptr;
	}
	else
	{
		return _obj;
	}
}

void ATlocHumanPlayer::SetWeapon(TlocWeapon* _wpn)
{
	playerEquipment._weapon = _wpn;
}

void ATlocHumanPlayer::SetArmor(TlocArmor* _armr)
{
	playerEquipment._armor = _armr;
}

void ATlocHumanPlayer::SetGauntlet(TlocGauntlet* _gntlt)
{
	playerEquipment._gauntlet = _gntlt;
}

void ATlocHumanPlayer::SetMesh(const TCHAR* fileRoot, int mesh)
{
	switch (mesh)
	{
	case 2:
		_charMesh = _motor->SetMesh((const TCHAR*)_name, (const TCHAR*)_fileRoot, GetRootComponent(), this);
		break;

		/*case 3:
			_auxCharMesh2 = _motor->SetMesh(TEXT("Auxiliar mesh 2"), (const TCHAR*)_fileRoot, GetRootComponent(), this);
			break;
			*/
	default:
		_charMesh = _motor->SetMesh((const TCHAR*)_name, (const TCHAR*)_fileRoot, GetRootComponent(), this);
		break;

	}
}

void ATlocHumanPlayer::SetWeaponMesh()
{
	playerEquipment._weapon->SetMesh(playerEquipment._weapon->GetMeshFileRoot());
	playerEquipment._weapon->GetMesh()->SetupAttachment(GetRootComponent());
	playerEquipment._weapon->GetMesh()->SetRelativeLocation(FVector(GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z - 90));
	playerEquipment._weapon->GetMesh()->SetRelativeRotation(FRotator(GetActorRotation().Pitch, GetActorRotation().Yaw - 90, GetActorRotation().Roll)); 
	playerEquipment._weapon->GetMesh()->OnComponentBeginOverlap.AddDynamic(this, &ATlocHumanPlayer::OnHumanActorHit);
	playerEquipment._weapon->GetMesh()->OnComponentEndOverlap.AddDynamic(this, &ATlocHumanPlayer::OnHumanActorStopHit);
}

TlocWeapon* ATlocHumanPlayer::GetWeapon()
{
	return playerEquipment._weapon;
}

TlocArmor* ATlocHumanPlayer::GetArmor()
{
	return playerEquipment._armor;
}

TlocGauntlet* ATlocHumanPlayer::GetGauntlet()
{
	return playerEquipment._gauntlet;
}

UStaticMeshComponent* ATlocHumanPlayer::GetMesh()
{
	return _charMesh;
}

UStaticMeshComponent* ATlocHumanPlayer::GetWeaponMesh()
{
	return playerEquipment._weapon->GetMesh();
}
