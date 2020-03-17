// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Components/CanvasPanelSlot.h"
#include "TlocHud.generated.h"

/**
 * 
 */
UCLASS()
class LABYRINTHOFCOLLOSIA_API UTlocHud : public UUserWidget
{
	GENERATED_BODY()

public:
	void NativeConstruct() override;
	void NativeTick(const FGeometry& geometry, float deltaTime) override;
	
	//Functions
	void SetPlayerPic(int plyr);

	void ModifyLifeBar(float percent);
	void ModifyMasterBar(float percent);

private:

	float lifeBarDefaultWidth;
	float masterBarDefaultWidth;
	float lifeBarCurrentWidth;
	float masterBarCurrentWidth;


	//HUD's images
	UPROPERTY(meta = (BindWidget))
		UImage* PlayerPicFrame;

	UPROPERTY(meta = (BindWidget))
		UImage* PlayerPic;

	UPROPERTY(meta = (BindWidget))
		UImage* PlayerPicBackground;

	UPROPERTY(meta = (BindWidget))
		UImage* HudBackground;

	UPROPERTY(meta = (BindWidget))
		UImage* BarsFrame;

	UPROPERTY(meta = (BindWidget))
		UImage* BarsBackground;

	UPROPERTY(meta = (BindWidget))
		UImage* LifeBar;

	UPROPERTY(meta = (BindWidget))
		UImage* MasterBar;

	UPROPERTY(meta = (BindWidget))
		UImage* Gems;

	UPROPERTY(meta = (BindWidget))
		UTextBlock* GemsAmount;

	UPROPERTY(meta = (BindWidget))
		UImage* WeaponFrame;

	UPROPERTY(meta = (BindWidget))
		UImage* WeaponBackground;

	UPROPERTY(meta = (BindWidget))
		UImage* WeaponPic;

	UPROPERTY(meta = (BindWidget))
		UImage* ArmorFrame;

	UPROPERTY(meta = (BindWidget))
		UImage* ArmorBackground;

	UPROPERTY(meta = (BindWidget))
		UImage* ArmorPic;

	UPROPERTY(meta = (BindWidget))
		UImage* BraceletFrame;

	UPROPERTY(meta = (BindWidget))
		UImage* BraceletBackground;

	UPROPERTY(meta = (BindWidget))
		UImage* BraceletPic;

	UPROPERTY(meta = (BindWidget))
		UImage* SpellBackground_1;

	UPROPERTY(meta = (BindWidget))
		UImage* SpellBackground_2;

	UPROPERTY(meta = (BindWidget))
		UImage* SpellFrame_1;

	UPROPERTY(meta = (BindWidget))
		UImage* SpellFrame_2;

	UPROPERTY(meta = (BindWidget))
		UImage* SpellPic_1;

	UPROPERTY(meta = (BindWidget))
		UImage* SpellPic_2;
	
};
