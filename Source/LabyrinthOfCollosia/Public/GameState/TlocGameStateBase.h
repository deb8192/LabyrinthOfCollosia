// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
//#include <stack>
//#include "TlocStateManager.h"
#include "GameFramework/GameStateBase.h"
#include "TlocGameStateBase.generated.h"

/**
 * 
 */
UCLASS()
class LABYRINTHOFCOLLOSIA_API ATlocGameStateBase : public AGameStateBase
{
	GENERATED_BODY()

//public:

	/*ATlocGameStateBase();
	~ATlocGameStateBase();

	void BeginPlayingState(unsigned int player, unsigned int money);*/

	//virtual ~ATlocGameStateBase() = default;
	//virtual void Iniciar() = 0;
	//virtual void Render() = 0;
	//virtual void Update() = 0;

//private:

	//ITlocStateManager* _state;
	//std::stack<ITlocStateManager*> _stateStack;
	
};
