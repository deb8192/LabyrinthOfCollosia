// Fill out your copyright notice in the Description page of Project Settings.

#include "../Public/Characters/TlocHumanPlayer.h"
#include "../Public/Characters/TlocEnemy.h"
#include "Engine/World.h"
#include "../Public/GlobalConstants.h"
#include "ConstructorHelpers.h"

#include "Engine/Scene.h"

// Sets default values
ATlocHumanPlayer::ATlocHumanPlayer() : TlocPlayer()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AutoPossessPlayer = EAutoReceiveInput::Player0;
	playerEquipment._weapon = CreateDefaultSubobject<TlocWeapon>(TEXT("PlayerWeapon")); /* NewObject<TlocWeapon>();*/		//Calling the constructor to create a new TlocWeapon object
	playerEquipment._armor = NULL;
	playerEquipment._gauntlet = NULL;

	enemy = NULL;

	//MESH
	
	_charMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlayerMesh"));
	_charMesh->SetupAttachment(GetRootComponent());

	static ConstructorHelpers::FObjectFinder<UStaticMesh> PlayerMeshAsset(TEXT("/Game/Models/Characters/Hero-M.Hero-M"));

	if (PlayerMeshAsset.Succeeded())
	{
		_charMesh->SetStaticMesh(PlayerMeshAsset.Object);
		_charMesh->SetWorldScale3D(FVector(1.f));
		_charMesh->SetRelativeLocation(FVector(GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z - 90));
		_charMesh->SetRelativeRotation(FRotator(GetActorRotation().Pitch, GetActorRotation().Yaw - 90, GetActorRotation().Roll));
	}

	//CAMERA

	_playerCameraSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraSpringArm"));
	_playerCameraSpringArm->SetupAttachment(GetRootComponent());
	_playerCameraSpringArm->TargetArmLength = 250.f;

	//Camera target arm
	_playerCameraSpringArm->bEnableCameraLag = true;

	_playerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));
	_playerCamera->SetupAttachment(_playerCameraSpringArm, USpringArmComponent::SocketName);
	_playerCameraSpringArm->SetRelativeLocationAndRotation(FVector(GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z + 45.0), FRotator(-10.0f, 0.0f, 0.0f));

	//playerEquipment._weapon->GetMesh()->SetupAttachment(GetRootComponent());

	_wpnMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlayerWeaponMesh"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> ObjectMeshAsset(playerEquipment._weapon->GetMeshFileRoot());

	if (ObjectMeshAsset.Succeeded())
	{
		_wpnMesh->SetStaticMesh(ObjectMeshAsset.Object);
		_wpnMesh->SetWorldScale3D(FVector(1.f));
		_wpnMesh->SetupAttachment(GetRootComponent());
		_wpnMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 45.0f));
		_wpnMesh->SetRelativeRotation(FRotator(-90.f, 0.0f, 0.0f));
		_wpnMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	}


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


}


// Called when the game starts or when spawned
void ATlocHumanPlayer::BeginPlay()
{
	Super::BeginPlay();	

	_wpnMesh->OnComponentBeginOverlap.AddDynamic(this, &ATlocHumanPlayer::OnHumanActorHit);
	_wpnMesh->OnComponentEndOverlap.AddDynamic(this, &ATlocHumanPlayer::OnHumanActorStopHit);
}

// Called every frame
void ATlocHumanPlayer::Tick(float DeltaTime)
{
	//AddActorWorldOffset(FVector(0, 0, 0));
	//AddActorLocalOffset(FVector(1, 0, 0));
	Super::Tick(DeltaTime);

	/*if (playerEquipment._weapon != NULL)
	{
		playerEquipment._weapon->SetPosition(GetActorLocation());
	}*/

	


}

// Called to bind functionality to input
void ATlocHumanPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	PlayerInputComponent->BindAxis("MoveVertically", this, &ATlocHumanPlayer::moveVertically);
	PlayerInputComponent->BindAxis("MoveHorizontally", this, &ATlocHumanPlayer::moveHorizontally);
	PlayerInputComponent->BindAxis("RotateHorizontally", this, &ATlocHumanPlayer::rotateHorizontally);

	PlayerInputComponent->BindAction("Attack", IE_Pressed, this, &ATlocHumanPlayer::attack);
}

void ATlocHumanPlayer::OnHumanActorHit(UPrimitiveComponent* _weaponMesh, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Hit)
{
	if (!attacking)
	{
		attacking = true;
		enemy = Other;
	}
}

void ATlocHumanPlayer::OnHumanActorStopHit(UPrimitiveComponent* _weaponMesh, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (attacking)
	{
		attacking = false;
		enemy = NULL;
	}
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

void ATlocHumanPlayer::attack()
{
	if (attacking)
	{
		GlobalConstants constants;
		int damage = this->Attack(playerEquipment._weapon);
		if (damage != constants.KMINUS_ONE)
		{
			ATlocEnemy* tlocEnemy = Cast<ATlocEnemy>(enemy);
			tlocEnemy->ModifyLife(-damage);
		}
		attacking = false;
		enemy = NULL;
	}
}

