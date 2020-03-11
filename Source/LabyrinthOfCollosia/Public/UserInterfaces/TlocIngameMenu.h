// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "Components/MenuAnchor.h"
#include "Components/Button.h"
#include "Components/CanvasPanelSlot.h"
//#include "TlocGameMode.h"
#include "TlocIngameMenu.generated.h"

/**
 * 
 */
UCLASS()
class LABYRINTHOFCOLLOSIA_API UTlocIngameMenu : public UUserWidget
{
	GENERATED_BODY()

public:
	void NativeConstruct() override;
	void NativeTick(const FGeometry& geometry, float deltaTime) override;

	void RotateMenu(bool right);



private:
	//class ATlocGameMode* gameMode;

	FVector2D center;
	FVector2D lastCalculatedPosition;
	float rotAngItemMenu;

	UPROPERTY(meta = (BindWidget))
		UMenuAnchor* ingameMenuAnchor;

	//Butons
	UPROPERTY(meta = (BindWidget))
		UButton* petal_btn;

	UPROPERTY(meta = (BindWidget))
		UButton* nectar_btn;

	UPROPERTY(meta = (BindWidget))
		UButton* honey_btn;

	UPROPERTY(meta = (BindWidget))
		UButton* bisquit_btn;

	UPROPERTY(meta = (BindWidget))
		UButton* elixir_btn;

	UPROPERTY(meta = (BindWidget))
		UButton* pixie_btn;

	UPROPERTY(meta = (BindWidget))
		UButton* bead_btn;

	UPROPERTY(meta = (BindWidget))
		UButton* wings_btn;

	UPROPERTY(meta = (BindWidget))
		UButton* pouch_btn;

	//Butons' images
	UPROPERTY(meta = (BindWidget))
		UImage* petal;

	UPROPERTY(meta = (BindWidget))
		UImage* nectar;

	UPROPERTY(meta = (BindWidget))
		UImage* honey;

	UPROPERTY(meta = (BindWidget))
		UImage* bisquit;

	UPROPERTY(meta = (BindWidget))
		UImage* elixir;

	UPROPERTY(meta = (BindWidget))
		UImage* pixieDust;

	UPROPERTY(meta = (BindWidget))
		UImage* callBead;

	UPROPERTY(meta = (BindWidget))
		UImage* wings;

	UPROPERTY(meta = (BindWidget))
		UImage* pouch;
	

	//Functions
	void setIcons(int iterator);
	FVector2D calculateRotation(FVector2D position, float rotAngle);
	void substractTranslation(FVector2D* _transl, UCanvasPanelSlot* _slot);
};
