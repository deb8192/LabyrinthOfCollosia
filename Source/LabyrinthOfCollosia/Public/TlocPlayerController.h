// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TlocPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class LABYRINTHOFCOLLOSIA_API ATlocPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ATlocPlayerController();
	~ATlocPlayerController();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called each 1/15 seconds
	void Update(float DeltaTime);
	void Render(float DeltaTime);

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
};
