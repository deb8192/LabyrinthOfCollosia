// Fill out your copyright notice in the Description page of Project Settings.

#include "../Public/Characters/TlocHumanPlayer.h"
#include "../Public/Characters/TlocEnemy.h"
#include "../Public/Objects/TlocChest.h"
#include "../Public/Stage/Interruptor.h"
#include "../Public/GlobalConstants.h"

#include "GameFramework/PlayerController.h"
#include "Engine/World.h"
#include "Engine/Scene.h"
#include "Engine/Engine.h"
#include "ConstructorHelpers.h"

// Sets default values
ATlocHumanPlayer::ATlocHumanPlayer() : TlocPlayer()
{
	GlobalConstants constants;
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	//Player equip and motor
	playerEquipment._weapon = NULL;
	playerEquipment._armor = NULL;
	playerEquipment._gauntlet = NULL;

	_motor = ATlocMotorFacade::GetInstance(this);

	_enemy = NULL;

	//---- MEGA IMPORTANT: THERE ARE SOME CODE SENTENCES THAT CAN BE WRITTEN IN MOTOR ----

	//MESH

	_fileRoot = TEXT("/Game/Models/Characters/Hero-M.Hero-M");
	//_charMesh = _motor->SetMesh(TEXT("PlayerMesh"), (const TCHAR*) _fileRoot, GetRootComponent(), this);
	_charPlMesh = NewObject<USkeletalMeshComponent>(this, TEXT("PlayerMesh"));
	USkeletalMesh* _meshAsset = LoadObject<USkeletalMesh>(NULL, _fileRoot);

	//static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(_directory);

	if (_meshAsset)
	{
		_charPlMesh->SetSkeletalMesh(_meshAsset);
		_charPlMesh->SetWorldScale3D(FVector(1.f));
	}
	_charPlMesh->SetupAttachment(GetRootComponent());
	_charPlMesh->SetRelativeLocation(FVector(GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z - 90));
	_charPlMesh->SetRelativeRotation(FRotator(GetActorRotation().Pitch, GetActorRotation().Yaw - 90, GetActorRotation().Roll));

	//POSITION
	position = lastPosition = renderPosition = FVector(FVector(GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z));
	rotation = lastRotation = renderRotation = defaultRotation = FRotator(GetActorRotation().Pitch, GetActorRotation().Yaw, GetActorRotation().Roll);

	//ANIMATIONS
	characterAnim.push_back(LoadObject<UAnimationAsset>(NULL, TEXT("/Game/Models/Characters/Hero-M_Anim_Armature_Stand.Hero-M_Anim_Armature_Stand")));
	characterAnim.push_back(LoadObject<UAnimationAsset>(NULL, TEXT("/Game/Models/Characters/Hero-M_Anim_Armature_Run.Hero-M_Anim_Armature_Run")));
	characterAnim.push_back(LoadObject<UAnimationAsset>(NULL, TEXT("/Game/Models/Characters/Hero-M_Anim_Armature_Attack.Hero-M_Anim_Armature_Attack")));
	characterAnim.push_back(LoadObject<UAnimationAsset>(NULL, TEXT("/Game/Models/Characters/Hero-M_Anim_Armature_Master.Hero-M_Anim_Armature_Master")));
	
	//CAMERA

	_playerCameraSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraSpringArm"));
	_playerCameraSpringArm->SetupAttachment(GetRootComponent());
	_playerCameraSpringArm->TargetArmLength = 250.f;

	//Camera target arm
	_playerCameraSpringArm->bEnableCameraLag = true;

	_playerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));
	_playerCamera->SetupAttachment(_playerCameraSpringArm, USpringArmComponent::SocketName);
	_playerCameraSpringArm->SetRelativeLocationAndRotation(FVector(GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z + 45.0f), FRotator(-10.0f, 0.0f, 0.0f));

	
	_attackCollision = CreateDefaultSubobject<USphereComponent>(TEXT("AttackCollision"));
	_attackCollision->SetSphereRadius(100.f, true);
	_attackCollision->SetupAttachment(GetRootComponent());
	_attackCollision->SetRelativeLocation(FVector(GetActorLocation().X, GetActorLocation().Y + constants.K1_4PI_RADIAN, GetActorLocation().Z));
	
	_wpnMesh = _motor->SetMesh(TEXT("WeaponMesh"), TEXT("Game/Models/Equipment/Weapons/Gladius.Gladius"), GetRootComponent(), this);
	//_wpnMesh->SetBoundsScale(1.0);
	_wpnMesh->SetupAttachment(_charPlMesh, FName(TEXT("R-Corazon")));

	//_wpnMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 25.0f));
	//_wpnMesh->SetRelativeRotation(FRotator(-90.f, 0.0f, 0.0f));

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
	ticking = false; 
	pickingUp = false;
	interacting = false;
	rotate = false;

	MyNumber = 0;
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
	interacting = false;

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

	openMenu = false;
	ticking = false;
	rotate = false;
}

void ATlocHumanPlayer::Update(float DeltaTime)
{
	TlocPlayer::Update(DeltaTime);
	GlobalConstants constants;
	if (lastPosition.Y != position.Y || lastPosition.X != position.X)
	{
		if (!moving)
		{
			moving = true;
			_charPlMesh->PlayAnimation(characterAnim[1], true);
		}
	}
	else
	{
		if (moving)
		{
			moving = false;
			_charPlMesh->PlayAnimation(characterAnim[0], true);
		}
	}
}

void ATlocHumanPlayer::Render(float DeltaTime)
{
	TlocPlayer::Render(DeltaTime);
}

void ATlocHumanPlayer::InitLocationRotation()
{

	position = lastPosition = renderPosition = FVector(GetActorLocation());
	rotation = lastRotation = renderRotation = FRotator(GetActorRotation());

}


// Called when the game starts or when spawned
void ATlocHumanPlayer::BeginPlay()
{
	Super::BeginPlay();	

	LoadPlayer();

	SetActorTickEnabled(false);

	_charPlMesh->PlayAnimation(characterAnim[0], true);

	_charPlMesh->RegisterComponent();
	//_motor->RegisterMeshComponent(_charPlMesh);
	//_motor->RegisterMeshComponent(_wpnMesh);
	_attackCollision->OnComponentBeginOverlap.AddDynamic(this, &ATlocHumanPlayer::OnHumanActorHit);
	_attackCollision->OnComponentEndOverlap.AddDynamic(this, &ATlocHumanPlayer::OnHumanActorStopHit);
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
	//Player movement
	PlayerInputComponent->BindAxis("MoveVertically", this, &ATlocHumanPlayer::moveVertically);
	PlayerInputComponent->BindAxis("MoveHorizontally", this, &ATlocHumanPlayer::moveHorizontally);
	PlayerInputComponent->BindAxis("RotateHorizontally", this, &ATlocHumanPlayer::rotateHorizontally);

	//Menu interaction
	PlayerInputComponent->BindAction("OpenMenu", IE_Pressed, this, &ATlocHumanPlayer::checkMenu);
	PlayerInputComponent->BindAction("RotLeftMenu", IE_Pressed, this, &ATlocHumanPlayer::beginRotateMenuLeft);
	PlayerInputComponent->BindAction("RotLeftMenu", IE_Released, this, &ATlocHumanPlayer::stopRotateMenuLeft);
	PlayerInputComponent->BindAction("RotRightMenu", IE_Pressed, this, &ATlocHumanPlayer::beginRotateMenuRight);
	PlayerInputComponent->BindAction("RotRightMenu", IE_Released, this, &ATlocHumanPlayer::stopRotateMenuRight);
	PlayerInputComponent->BindAction("UpIngameMenu", IE_Pressed, this, &ATlocHumanPlayer::moveMenuUp);
	PlayerInputComponent->BindAction("DownIngameMenu", IE_Pressed, this, &ATlocHumanPlayer::moveMenuDown);
	//PlayerInputComponent->BindAction("Use", IE_Pressed, this, &ATlocHumanPlayer::useMenuElement);

	//Choosing target
	PlayerInputComponent->BindAction("SelectTargetLeft", IE_Pressed, this, &ATlocHumanPlayer::selectTargetLeft);
	PlayerInputComponent->BindAction("SelectTargetRight", IE_Pressed, this, &ATlocHumanPlayer::selectTargetRight);
	//PlayerInputComponent->BindAction("ChooseTarget", IE_Pressed, this, &ATlocHumanPlayer::chooseTarget);
	PlayerInputComponent->BindAction("Cancel", IE_Pressed, this, &ATlocHumanPlayer::cancel);
	

	//Player actions
	PlayerInputComponent->BindAction("PickUp", IE_Pressed, this, &ATlocHumanPlayer::interact);
	PlayerInputComponent->BindAction("Attack", IE_Pressed, this, &ATlocHumanPlayer::action);


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

//Function to activate the player's picking up or interact function
void ATlocHumanPlayer::OnHumanActorOverlap(AActor* _player, AActor* _obj)
{
	if (!pickingUp && dynamic_cast<ATlocObject*>(_obj))
	{
		pickingUp = true;
		_object = _obj;
	}
	else if (!interacting && dynamic_cast<AInterruptor*>(_obj))
	{
		interacting = true;
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
	if (interacting)
	{
		interacting = false;
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
	GlobalConstants constants;
	if (mode == PlayingMode::NORMAL)
	{
		moveTime = 0.0;
		lastPosition.Y = position.Y;
		position.Y += value * speed * constants.KUPDATE_TIME;
		if (lastPosition.Y == position.Y)
		{
			position.Y = lastPosition.Y = constants.KZERO_F;
		}
	}
}

void ATlocHumanPlayer::moveHorizontally(float value)
{
	GlobalConstants constants;
	if (mode == PlayingMode::NORMAL)
	{
		moveTime = 0.0;
		lastPosition.X = position.X;
		position.X += value * speed * constants.KUPDATE_TIME;
		if (lastPosition.X == position.X)
		{
			position.X = lastPosition.X = constants.KZERO_F;
		}
	}
}

void ATlocHumanPlayer::rotateHorizontally(float value)
{
	if (mode == PlayingMode::NORMAL)
	{
		moveTime = 0.0;
		GlobalConstants constants;
		lastRotation.Yaw = rotation.Yaw;
		rotation.Yaw += value * constants.KROTATIONSPEED * constants.KUPDATE_TIME;
	}
}

void ATlocHumanPlayer::loadInGameUI()
{
	if (IngameMenuUIClass == nullptr) return;

	if (IngameMenu == nullptr)
	{
		IngameMenu = CreateWidget<UTlocIngameMenu>(GetWorld(), IngameMenuUIClass);
		if (_memorizedSpells.size() > 0)
		{
			for (int i = 0; i < _memorizedSpells.size(); i++)
			{
				IngameMenu->SetSpellsIcons(i, _memorizedSpells[i]->GetIconFilePath());
				_memorizedSpells[i]->SetMenuId(i);
			}
		}
	}
	if (IngameMenu == nullptr) return;
	if (!IngameMenu->IsInViewport())
	{
		IngameMenu->AddToViewport();
	}
	if (IngameMenu->GetVisibility() != ESlateVisibility::Visible)
	{
		IngameMenu->SetVisibility(ESlateVisibility::Visible);
	}
}

void ATlocHumanPlayer::closeInGameUI()
{
	if (IngameMenu->GetVisibility() != ESlateVisibility::Hidden)
	{
		IngameMenu->SetVisibility(ESlateVisibility::Hidden);
	}
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

int* ATlocHumanPlayer::getMemorizedSpellsID()
{
	GlobalConstants constants;
	int* spellsID = new int[10];
	if (_memorizedSpells.size() > constants.KZERO)
	{
		for (int i = 0; i < _memorizedSpells.size(); i++)
		{
			spellsID[i] = _memorizedSpells[i]->GetId();
		}
	}
	return spellsID;
}

void ATlocHumanPlayer::beginRotateMenuLeft()
{
	rotate = true;
	rotateMenuLeft();
}

void ATlocHumanPlayer::beginRotateMenuRight()
{
	rotate = true;
	rotateMenuRight();
}

void ATlocHumanPlayer::stopRotateMenuLeft()
{
	rotate = false;
}

void ATlocHumanPlayer::stopRotateMenuRight()
{
	rotate = false;
}

void ATlocHumanPlayer::rotateMenuLeft()
{
	if (mode == PlayingMode::NORMAL)
	{
		if (openMenu && rotate)
		{
			IngameMenu->RotateMenu(false);
		}
	}
}

void ATlocHumanPlayer::rotateMenuRight()
{
	if (mode == PlayingMode::NORMAL)
	{
		if (openMenu && rotate)
		{
			IngameMenu->RotateMenu(true);
		}
	}
}

void ATlocHumanPlayer::moveMenuUp()
{
	if (mode == PlayingMode::NORMAL)
	{
		IngameMenu->MoveMenuDown();
	}
}

void ATlocHumanPlayer::moveMenuDown()
{

	if (mode == PlayingMode::NORMAL)
	{
		IngameMenu->MoveMenuUp();
	}
}

void ATlocHumanPlayer::useMenuElement()
{
	int* options = new int[2];
	if (openMenu)
	{
		options = IngameMenu->GetSelectedObject();
		switch (options[0])
		{
			case 1:
				selectSpell(options[1]);
			case 2:
			//	selectSpell(options[1]);
			case 3:
			//	selectSpell(options[1]);
			case 4:
			//	selectSpell(options[1]);
			default:
				selectItem(options[1]);
		}
	}
}

void ATlocHumanPlayer::chooseTarget()
{
	if (_attackingSpell && _attackingSpellIngredients.size() > 0)
	{
		mode = PlayingMode::CASTING_SPELL;
	}
	/*GlobalConstants constants;
	switch (_attackingSpell->GetKindTarget())
	{
	case 0:
		if (targetSelector > _targetEnemies.size())
		{
			_attackingSpell->CastSpell(_targetEnemies);
		}
		else
		{
			_attackingSpell->CastSpell(*_targetEnemies[targetSelector]);
		}
		break;
	case 1:
		if (targetSelector > _targetPlayers.size())
		{
			_attackingSpell->CastSpell(_targetPlayers);
		}
		else
		{
			_attackingSpell->CastSpell(*_targetPlayers[targetSelector]);
		}
		break;
	case 2:
		if (targetSelector > _targetPlayers.size())
		{
			_attackingSpell->CastSpell(_targetPlayers);
		}
		else
		{
			_attackingSpell->CastSpell(*_targetPlayers[targetSelector]);
		}
		break;
	case 3:
		if (targetSelector > _targetPlayers.size())
		{
			_attackingSpell->CastSpell(_targetPlayers);
		}
		else
		{
			_attackingSpell->CastSpell(*_targetPlayers[targetSelector]);
		}
		break;
	case 4:
		if (targetSelector > _targetObjects.size())
		{
			_attackingSpell->CastSpell(_targetObjects);
		}
		else
		{
			_attackingSpell->CastSpell(*_targetObjects[targetSelector]);
		}
		break;
	}*/
}

void ATlocHumanPlayer::cancel()
{
	GlobalConstants constants;
	if (mode == PlayingMode::TARGET_SELECTION)
	{
		mode = PlayingMode::NORMAL;
		_motor->SetViewTarget(*this, *this, constants.KUPDATE_TIME);
		unselectSpell();	//WORK WITH OBJECTS TO
	}
}


void ATlocHumanPlayer::loadHud()
{
	if (PlayerHudUIClass == nullptr) return;

	PlayerHud = CreateWidget<UTlocHud>(GetWorld(), PlayerHudUIClass);
	if (PlayerHud == nullptr) return;

	PlayerHud->AddToViewport();
}

void ATlocHumanPlayer::ModifyHudLife(float quantity)
{
	/*if(!invulnerable)
	{*/
		float percent = life / defaultLife;
		PlayerHud->ModifyLifeBar(percent);
		modifyHudMaster(abs(quantity));
	//}
}

void ATlocHumanPlayer::modifyHudMaster(float quantity)
{
	GlobalConstants constants;
	if (master < defaultMaster)
	{
		master += quantity;
		PlayerHud->ModifyMasterBar(master/defaultMaster);
		if (master >= defaultMaster)
		{
			master = defaultMaster;
		}
	}
}

void ATlocHumanPlayer::action()
{
	if (mode == PlayingMode::NORMAL)
	{
		attack();
		useMenuElement();
	}
	else if (mode == PlayingMode::TARGET_SELECTION)
	{
		chooseTarget();
	}
}

void ATlocHumanPlayer::attack()
{
	if(master >= defaultMaster)
	{
		_charPlMesh->PlayAnimation(characterAnim[3], false);
	}
	else	_charPlMesh->PlayAnimation(characterAnim[2], false);
	//If player is attacking some enemy
	if (!openMenu && attacking)
	{
		//It's calculated the attack damage
		GlobalConstants constants;
		int damage = this->Attack(playerEquipment._weapon);

		//If hit doesn't miss
		if (damage != constants.KMINUS_ONE)
		{
			if (_enemy)
			{
				//Enemy's life is modified with damage value
				ATlocEnemy* tlocEnemy = Cast<ATlocEnemy>(_enemy);
				tlocEnemy->ModifyLife(-damage);
			}
		}
	}
}

void ATlocHumanPlayer::interact()
{
	if (!openMenu)
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
		else if(interacting && _object != NULL)
		{
			//Calling function that activates the interruptor
			activateInterruptor();
		}
	}
}

/*******************************   Select Spell  ********************************
****  Function that checks if the player has the spell's identified by the   ****
**** ID in selection. If true, calls checkSpellIngredients passing the spell ****
*********************************************************************************
*				In:		int selection() (spell's ID)
*
*				Out:
*
*/
void ATlocHumanPlayer::selectSpell(int selection)
{
	GlobalConstants constants;
	bool prepared = false;
	if (selection >= constants.KZERO && selection < _memorizedSpells.size())
	{
		int i = 0;
		bool found = false;
		while (!found && i < _memorizedSpells.size())
		{
			if (_memorizedSpells[i]->GetMenuId() == selection)
			{
				//This function prepares the spell if player has the ingredients
				prepared = checkSpellIngredients(*_memorizedSpells[i]);
				found = true; 
				i = _memorizedSpells.size();
			}
			else
			{
				i++;
			}
		}
	}
	if (prepared)
	{
		SetMode(PlayingMode::TARGET_SELECTION);
	}
}

/**************************************   Unselect Spell  *************************************
****  Function that unsets the prepared spell and changes TARGET_SELECTIONS mode to NORMAL ****
***********************************************************************************************
*				In:		
*
*				Out:
*
*/
void ATlocHumanPlayer::unselectSpell()
{
	GlobalConstants constants;
	SetMode(PlayingMode::NORMAL);
	_attackingSpell = nullptr;
	for (int i = 0; i < _attackingSpellIngredients.size(); i++)
	{
		_attackingSpellIngredients[i] = nullptr;
	}
}

void ATlocHumanPlayer::selectItem(int selection)
{
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
					if (_ingredients[i]->GetQuantity() > constants.KZERO && _ingredients[i]->GetIngredientID() == _ing->GetIngredientID())
					{
						_ingredients[i]->AddQuantity(_ing->GetQuantity());
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
void ATlocHumanPlayer::activateInterruptor()
{
	AInterruptor* _interruptor = Cast<AInterruptor>(_object);
	_interruptor->ActivateDeactivateInterruptor();
}

/***************************  check Chest  ***************************
*** Function that checks if the taken object is a chest or not.   ****
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

/*************************  Check Spell Ingredients  *************************
*** Function that checks if the player has the needed ingredients to cast ****
***  the spell. If true, prepare the spell to cast it against the target  ****
******************************************************************************
*				In:		TlocSpell &_spell (selected spell to check and prepare)
*
*				Out:	bool found (answer for the spell check)
*/
bool ATlocHumanPlayer::checkSpellIngredients(TlocSpell &_spll)
{
	GlobalConstants constants;
	std::vector<int> _selectedIngredients;
	_selectedIngredients.reserve(constants.KMAXINGREDIENTS);
	int* _quantities = new int[3];
	int i = 0;
	bool found = true;
	std::vector<TlocIngredients*> spellIng = _spll.GetIngredients();

	//Bucle to check each one of the spell's ingredients
	while (i < spellIng.size() && found)
	{
		int j = 0;
		//It goes into j bucle if player has got ingredients
		if (j < _ingredients.size())
		{
			//Bucle to looking for the selected spell's ingredient in _ingredients vector
			while (j < _ingredients.size() && found)
			{
				//If player has the ingredient
				if (_ingredients[j]->GetIngredientID() == spellIng[i]->GetIngredientID())
				{
					//and if there are enought ingredients, we finish j bucle, get quantity and selected ingredient and continue bucle i
					if (spellIng[i]->GetQuantity() <= _ingredients[j]->GetQuantity())
					{
						_selectedIngredients.push_back(j);
						_quantities[i] = spellIng[i]->GetQuantity();
						j = _ingredients.size();
					}
					//If there are not enought ingredients, we finish both bucles and return without make the spell
					else 
					{
						found = false;
						if (GEngine)
						{
							const int32 AlwaysAddKey = -1; // Passing -1 means that we will not try and overwrite an   
														   // existing message, just add a new one  
							GEngine->AddOnScreenDebugMessage(AlwaysAddKey, 0.5f, FColor::Yellow, TEXT("You don't have enought ingredients") + FString::FromInt(MyNumber));

							const int32 MyNumberKey = 0; // Not passing -1 so each time through we will update the existing message instead  
														 // of making a new one  
							GEngine->AddOnScreenDebugMessage(MyNumberKey, 5.f, FColor::Yellow, FString::FromInt(MyNumber));

							++MyNumber; // Increase MyNumber so we can see it change on screen  
						}
					}
				}
				//If the ID ingredients does not coincide, the ingredient's bucle continues
				else j++;
			}
		}
		//If player doesn't have got ingredients, bucles are ended
		else found = false;
		i++;
	}
	if (found)
	{
		//We prepare the spell for attack and change mode to select target
		_attackingSpell = &_spll;
		for (i = 0; i < _selectedIngredients.size(); i++)
		{
			_attackingSpellIngredients.push_back(_ingredients[_selectedIngredients[i]]);
		}
	}
	return found;
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
	if (playerEquipment._weapon != NULL)
	{
		playerEquipment._weapon->SetMesh(playerEquipment._weapon->GetMeshFileRoot());
		_wpnMesh = _motor->SetMesh((const TCHAR*) playerEquipment._weapon->GetName(), (const TCHAR*)playerEquipment._weapon->GetMeshFileRoot(), GetRootComponent(), this);
		_wpnMesh->SetupAttachment(_charPlMesh, FName(TEXT("R-Corazon1Socket")));
		_wpnMesh->SetRelativeRotation(FRotator(playerEquipment._weapon->GetActorRotation().Pitch, playerEquipment._weapon->GetActorRotation().Yaw, playerEquipment._weapon->GetActorRotation().Roll -90));
		_wpnMesh->RegisterComponent();
	}
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
