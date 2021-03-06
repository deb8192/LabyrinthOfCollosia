// Fill out your copyright notice in the Description page of Project Settings.


#include "TlocDogPlayer.h"
#include "../Public/GlobalConstants.h"

// Sets default values
ATlocDogPlayer::ATlocDogPlayer()
{
	GlobalConstants constants;
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;

	_fileRoot = TEXT("/Game/Models/Characters/Hero-M.Hero-M");

	_motor = ATlocMotorFacade::GetInstance(this);

	//MESH

	_charMesh = _motor->SetMesh(TEXT("DogPlayerMesh"), (const TCHAR*)_fileRoot, GetRootComponent(), this);
	_charMesh->SetupAttachment(GetRootComponent());
	_charMesh->SetRelativeLocation(FVector(GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z - 90));
	_charMesh->SetRelativeRotation(FRotator(GetActorRotation().Pitch, GetActorRotation().Yaw - 90, GetActorRotation().Roll));

	_attackCollision = CreateDefaultSubobject<USphereComponent>(TEXT("AttackCollision"));
	_attackCollision->SetSphereRadius(100.f, true);
	_attackCollision->SetupAttachment(GetRootComponent());
	_attackCollision->SetRelativeLocation(FVector(GetActorLocation().X, GetActorLocation().Y + constants.K1_4PI_RADIAN, GetActorLocation().Z));

}

ATlocDogPlayer::~ATlocDogPlayer()
{
	//PrimaryActorTick.bCanEverTick = false;
}

void ATlocDogPlayer::Update(float DeltaTime)
{
	TlocPlayer::Update(DeltaTime);
}

void ATlocDogPlayer::Render(float DeltaTime)
{
	TlocPlayer::Render(DeltaTime);
}

// Called when the game starts or when spawned
void ATlocDogPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATlocDogPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATlocDogPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATlocDogPlayer::SetMesh(const TCHAR* fileRoot, int mesh)
{
	_fileRoot = (TCHAR*)fileRoot;
	fileRoot = NULL;
	switch (mesh)
	{
		case 2:
			_charMesh = _motor->SetMesh((const TCHAR*)_name, (const TCHAR*)_fileRoot, GetRootComponent(), this);
			//_charMesh->SetupAttachment(rootComponent);

			break;

		/*case 3:
			_auxCharMesh2 = _motor->SetMesh(TEXT("Auxiliar mesh 2"), (const TCHAR*)_fileRoot, GetRootComponent(), this);
			_auxCharMesh2->SetupAttachment(rootComponent);

			break;
			*/
		default:
			_charMesh = _motor->SetMesh((const TCHAR*)_name, (const TCHAR*)_fileRoot, GetRootComponent(), this);
			//_charMesh->SetupAttachment(rootComponent);

			break;

	}
}

void ATlocDogPlayer::SetPosition(FVector newPosition)
{
	SetActorLocation(newPosition);
	TlocPlayer::SetPosition(newPosition);
}

void ATlocDogPlayer::SetRotation(FRotator newRotation)
{
	SetActorRotation(newRotation);
	TlocPlayer::SetRotation(newRotation);
}

UStaticMeshComponent* ATlocDogPlayer::GetMesh()
{
	return _wpnMesh;
}


