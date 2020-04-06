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
	void SetSpellsIcons(int numSpell, TCHAR* filePath);
	int* GetSelectedObject();

private:
	//class ATlocGameMode* gameMode;

	UPROPERTY(meta = (BindWidget))
		UMenuAnchor* ingameMenuAnchor;

	//----     Objects Menu    ----//
	//Selector
	UPROPERTY(meta = (BindWidget))
		UImage* menuSelector;

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
	

	//----     Objects Menu    ----//

	//Butons
	UPROPERTY(meta = (BindWidget))
		UButton* Spell_0_btn;

	UPROPERTY(meta = (BindWidget))
		UButton* Spell_1_btn;

	UPROPERTY(meta = (BindWidget))
		UButton* Spell_2_btn;

	UPROPERTY(meta = (BindWidget))
		UButton* Spell_3_btn;

	UPROPERTY(meta = (BindWidget))
		UButton* Spell_4_btn;

	UPROPERTY(meta = (BindWidget))
		UButton* Spell_5_btn;

	UPROPERTY(meta = (BindWidget))
		UButton* Spell_6_btn;

	UPROPERTY(meta = (BindWidget))
		UButton* Spell_7_btn;

	UPROPERTY(meta = (BindWidget))
		UButton* Spell_8_btn;

	//Butons' images
	UPROPERTY(meta = (BindWidget))
		UImage* Spell_0;

	UPROPERTY(meta = (BindWidget))
		UImage* Spell_1;

	UPROPERTY(meta = (BindWidget))
		UImage* Spell_2;

	UPROPERTY(meta = (BindWidget))
		UImage* Spell_3;

	UPROPERTY(meta = (BindWidget))
		UImage* Spell_4;

	UPROPERTY(meta = (BindWidget))
		UImage* Spell_5;

	UPROPERTY(meta = (BindWidget))
		UImage* Spell_6;

	UPROPERTY(meta = (BindWidget))
		UImage* Spell_7;

	UPROPERTY(meta = (BindWidget))
		UImage* Spell_8;

	//---- Motion menu variables ----//	

	enum Menu : int
	{
		ITEMS = 0,
		WEAPONS,
		ARMORS,
		GAUNTLETS,
		SPELLS
	};

	int selMenu;
	FVector2D center;
	FVector2D lastCalculatedPosition;
	float rotAngItemMenu;


	//Functions
	void setItemIcons(int iterator);
	FVector2D calculateRotation(FVector2D position, float rotAngle);
	void substractTranslation(FVector2D* _transl, UCanvasPanelSlot* _slot);
};
