// Fill out your copyright notice in the Description page of Project Settings.



#include "TlocAIEnemiesController.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "ConstructorHelpers.h"
#include "../Public/Characters/TlocHumanPlayer.h"
#include "../Public/Characters/TlocEnemy.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "../AI/BehaviorTree/TlocBehaviorTreeEnemies.h"
#include "../public/GlobalConstants.h"

ATlocAIEnemiesController::ATlocAIEnemiesController()
{
	GlobalConstants constants;
	FString path = TEXT("/Game/AI/EnemiesBT");
	_enemyBehaviorTree = Cast<UBehaviorTree>(StaticLoadObject(UBehaviorTree::StaticClass(), nullptr, *path));
	Blackboard = CreateDefaultSubobject<UBlackboardComponent>(TEXT("EnemyBlackboard"));
	//_behaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("EnemyBehaviorTreeComponent"));
	AIPerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("EnemyPerception"));
	UAISenseConfig_Sight* vision = NewObject<UAISenseConfig_Sight>();

	vision->SightRadius = 1500;
	vision->LoseSightRadius = 2500;
	vision->PeripheralVisionAngleDegrees = constants.K1_2PI_RADIAN;
	vision->SetMaxAge(1.0);
	vision->DetectionByAffiliation.bDetectEnemies = true;
	vision->DetectionByAffiliation.bDetectFriendlies = true;
	vision->DetectionByAffiliation.bDetectNeutrals = true;

	AIPerceptionComponent->ConfigureSense(*vision);
}

ATlocAIEnemiesController::~ATlocAIEnemiesController()
{
}

// Called when the game starts or when spawned
void ATlocAIEnemiesController::BeginPlay()
{
	Super::BeginPlay();
	SetActorTickEnabled(true);
	
	//UAISenseConfig* senses = NewObject<UAISenseConfig>();
}
void ATlocAIEnemiesController::OnPerceptionUpdated(const TArray<AActor*> &UpdatedActors)
{
	for (AActor* Actor : UpdatedActors)
	{
		if (Actor->IsA<ATlocHumanPlayer>())
		{
			Blackboard->SetValueAsObject(blackBoardKeyName, Actor);
		}
	}

}

void ATlocAIEnemiesController::OnPosses(APawn* _enemy)
{
	Super::OnPossess(_enemy);
	//GetCharacter()->GetCharacterMovement()->MaxWalkSpeed = 4.0;
	if (_enemyBehaviorTree)
	{
		Blackboard->InitializeBlackboard(*_enemyBehaviorTree->BlackboardAsset);

		RunBehaviorTree(_enemyBehaviorTree);
		_behaviorTreeComponent = Cast<UBehaviorTreeComponent>(BrainComponent);
		_behaviorTreeComponent->StartTree(*_enemyBehaviorTree);
	}
	Blackboard->SetValueAsBool(blackBoardKeyNameCoward, dynamic_cast<ATlocEnemy*>(_enemy)->GetCoward());
	Blackboard->SetValueAsBool(blackBoardKeyNameNotCoward, !dynamic_cast<ATlocEnemy*>(_enemy)->GetCoward());
	AIPerceptionComponent->OnPerceptionUpdated.AddDynamic(this, &ATlocAIEnemiesController::OnPerceptionUpdated);
	dynamic_cast<ACharacter*>(_enemy)->GetCharacterMovement()->MaxWalkSpeed = dynamic_cast<ATlocEnemy*>(_enemy)->GetSpeed();
}
void ATlocAIEnemiesController::Update(float DeltaTime)
{
	Cast<ATlocEnemy>(GetPawn())->Update(DeltaTime);
	
}
void ATlocAIEnemiesController::Render(float DeltaTime)
{
	Cast<ATlocEnemy>(GetPawn())->Render(DeltaTime);

}