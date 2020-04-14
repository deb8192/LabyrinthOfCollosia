// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "Components/MenuAnchor.h"
#include "Components/Button.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/CanvasPanel.h"
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
	void MoveMenuUp();
	void MoveMenuDown();

	void SetSpellsIcons(int numSpell, TCHAR* filePath);
	void SetWeaponIcons(int numWeapon, TCHAR* filePath);
	int* GetSelectedObject();

	//---- Motion menu variables ----//	

	enum Menu : int
	{
		ITEMS = 0,
		SPELLS,
		ARMORS,
		GAUNTLETS,
		WEAPONS
	};

private:
	//class ATlocGameMode* gameMode;

	UPROPERTY(meta = (BindWidget))
		UMenuAnchor* ingameMenuAnchor;

	//----		Menu		----//

	//Selector
	UPROPERTY(meta = (BindWidget))
		UImage* menuSelector;

	//----     Item Menu    ----//

	UPROPERTY(meta = (BindWidget))
		UCanvasPanel* ItemCanvas;

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
	

	//----     Spell Menu    ----//

	UPROPERTY(meta = (BindWidget))
		UCanvasPanel* SpellCanvas;

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

	//----     Armor Menu    ----//

	UPROPERTY(meta = (BindWidget))
		UCanvasPanel* ArmorCanvas;

	//Butons
	UPROPERTY(meta = (BindWidget))
		UButton* LinenTunic_btn;

	UPROPERTY(meta = (BindWidget))
		UButton* SpartanCuirass_btn;

	UPROPERTY(meta = (BindWidget))
		UButton* LeatherArmor_btn;

	UPROPERTY(meta = (BindWidget))
		UButton* ScaleArmor_btn;

	UPROPERTY(meta = (BindWidget))
		UButton* GermanicTunic_btn;

	UPROPERTY(meta = (BindWidget))
		UButton* CenturionCape_btn;

	//Butons' images
	UPROPERTY(meta = (BindWidget))
		UImage* LinenTunic;

	UPROPERTY(meta = (BindWidget))
		UImage* SpartanCuirass;

	UPROPERTY(meta = (BindWidget))
		UImage* LeatherArmor;

	UPROPERTY(meta = (BindWidget))
		UImage* ScaleArmor;

	UPROPERTY(meta = (BindWidget))
		UImage* GermanicTunic;

	UPROPERTY(meta = (BindWidget))
		UImage* CenturionCape;

	//----     Gauntlet Menu    ----//

	UPROPERTY(meta = (BindWidget))
		UCanvasPanel* GauntletCanvas;

	//Butons
	UPROPERTY(meta = (BindWidget))
		UButton* CelticShield_btn;

	UPROPERTY(meta = (BindWidget))
		UButton* LegionaryShield_btn;

	UPROPERTY(meta = (BindWidget))
		UButton* SpartanShield_btn;

	UPROPERTY(meta = (BindWidget))
		UButton* EgipcianShield_btn;

	UPROPERTY(meta = (BindWidget))
		UButton* VikingShield_btn;

	UPROPERTY(meta = (BindWidget))
		UButton* AchillesShield_btn;

	//Butons' images
	UPROPERTY(meta = (BindWidget))
		UImage* CelticShield;

	UPROPERTY(meta = (BindWidget))
		UImage* LegionaryShield;

	UPROPERTY(meta = (BindWidget))
		UImage* SpartanShield;

	UPROPERTY(meta = (BindWidget))
		UImage* EgipcianShield;

	UPROPERTY(meta = (BindWidget))
		UImage* VikingShield;

	UPROPERTY(meta = (BindWidget))
		UImage* AchillesShield;

	//----     Weapon Menu    ----//

	UPROPERTY(meta = (BindWidget))
		UCanvasPanel* WeaponCanvas;

	//Butons
	UPROPERTY(meta = (BindWidget))
		UButton* Femur_btn;

	UPROPERTY(meta = (BindWidget))
		UButton* Axe_btn;

	UPROPERTY(meta = (BindWidget))
		UButton* Spear_btn;

	UPROPERTY(meta = (BindWidget))
		UButton* SpartanSword_btn;

	UPROPERTY(meta = (BindWidget))
		UButton* SpartanAxe_btn;

	UPROPERTY(meta = (BindWidget))
		UButton* Doru_btn;

	UPROPERTY(meta = (BindWidget))
		UButton* Falcata_btn;

	UPROPERTY(meta = (BindWidget))
		UButton* IberianAxe_btn;

	UPROPERTY(meta = (BindWidget))
		UButton* ViriatusSpear_btn;

	UPROPERTY(meta = (BindWidget))
		UButton* RaSword_btn;

	UPROPERTY(meta = (BindWidget))
		UButton* CeremonialAxe_btn;

	UPROPERTY(meta = (BindWidget))
		UButton* HorusSpear_btn;

	UPROPERTY(meta = (BindWidget))
		UButton* VikingSword_btn;

	UPROPERTY(meta = (BindWidget))
		UButton* VikingAxe_btn;

	UPROPERTY(meta = (BindWidget))
		UButton* VikingSpear_btn;

	UPROPERTY(meta = (BindWidget))
		UButton* Gladius_btn;

	UPROPERTY(meta = (BindWidget))
		UButton* RomanAxe_btn;

	UPROPERTY(meta = (BindWidget))
		UButton* Pillum_btn;

	//Butons' images
	UPROPERTY(meta = (BindWidget))
		UImage* Femur;

	UPROPERTY(meta = (BindWidget))
		UImage* Axe;

	UPROPERTY(meta = (BindWidget))
		UImage* Spear;

	UPROPERTY(meta = (BindWidget))
		UImage* SpartanSword;

	UPROPERTY(meta = (BindWidget))
		UImage* SpartanAxe;

	UPROPERTY(meta = (BindWidget))
		UImage* Doru;

	UPROPERTY(meta = (BindWidget))
		UImage* Falcata;

	UPROPERTY(meta = (BindWidget))
		UImage* IberianAxe;

	UPROPERTY(meta = (BindWidget))
		UImage* ViriatusSpear;

	UPROPERTY(meta = (BindWidget))
		UImage* RaSword;

	UPROPERTY(meta = (BindWidget))
		UImage* CeremonialAxe;

	UPROPERTY(meta = (BindWidget))
		UImage* HorusSpear;

	UPROPERTY(meta = (BindWidget))
		UImage* VikingSword;

	UPROPERTY(meta = (BindWidget))
		UImage* VikingAxe;

	UPROPERTY(meta = (BindWidget))
		UImage* VikingSpear;

	UPROPERTY(meta = (BindWidget))
		UImage* Gladius;

	UPROPERTY(meta = (BindWidget))
		UImage* RomanAxe;

	UPROPERTY(meta = (BindWidget))
		UImage* Pillum;

	int selMenu, menuSections;
	float verticalDistance, totalVerticalDistance;
	FVector2D calculatedPosition, lastCalculatedPosition, renderPosition;


	//Functions
	void setItemIcons(int iterator);
	UCanvasPanelSlot* getLowerMenuCanvas();
	UCanvasPanelSlot* getHigherMenuCanvas();
	UCanvasPanelSlot* getMenuCanvas(int sel);
	TArray<UPanelSlot*> getSubSlots();
	void moveCanvasUp(UCanvasPanelSlot& _slot);
	void moveCanvasDown(UCanvasPanelSlot& _slot);
	void moveCanvasToTop();
	void moveCanvasToBottom();
	void rotateElements(bool right);
	FVector2D calculateRotation(FVector2D position, float rotAngle);
	void substractTranslation(FVector2D* _transl, UCanvasPanelSlot* _slot);
};
