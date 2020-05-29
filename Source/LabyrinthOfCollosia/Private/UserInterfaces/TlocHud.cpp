// Fill out your copyright notice in the Description page of Project Settings.


#include "TlocHud.h"
#include "GlobalConstants.h"

void UTlocHud::NativeConstruct()
{
	GlobalConstants constants;
	UCanvasPanelSlot* _slot = Cast<UCanvasPanelSlot>(MasterBar->Slot);
	lifeBarDefaultWidth = Cast<UCanvasPanelSlot>(LifeBar->Slot)->GetSize().X;
	masterBarDefaultWidth = _slot->GetSize().X;
	_slot->SetSize(FVector2D(constants.KZERO_F, _slot->GetSize().Y));
	lifeBarCurrentWidth = lifeBarDefaultWidth;
	masterBarCurrentWidth = constants.KZERO_F;
}

void UTlocHud::NativeTick(const FGeometry& geometry, float deltaTime)
{
}

void UTlocHud::SetPlayerPic(int plyr)
{
	GlobalConstants constants;
	FString directory = constants.KDIR_PLAYERS;
	FString name;
	UObject* _resource;
	FSlateBrush* brush = new FSlateBrush();
	FLinearColor bckgrdOpacity = FLinearColor(FVector4(constants.KONE_F, constants.KONE_F, constants.KONE_F, constants.KZERO_F));
	switch (plyr)
	{
		case 1:

			directory += constants.KNAME_HUMAN_PLAYER_F;
			name = constants.KNAME_HUMAN_PLAYER;
			_resource = LoadObject<UObject>(NULL, *directory);
			brush->SetResourceObject(_resource);
			PlayerPic->SetBrush(*brush);
			break;

		default:
			directory += constants.KNAME_HUMAN_PLAYER_M;
			name = constants.KNAME_HUMAN_PLAYER;
			_resource = LoadObject<UObject>(NULL, *directory);
			brush->SetResourceObject(_resource);
			PlayerPic->SetBrush(*brush);
			break;
	}
}

void UTlocHud::ModifyLifeBar(float percent)
{
	GlobalConstants constants;
	UCanvasPanelSlot* _slot = Cast<UCanvasPanelSlot>(LifeBar->Slot);
	lifeBarCurrentWidth = lifeBarDefaultWidth * percent;
	if (lifeBarCurrentWidth > lifeBarDefaultWidth)
	{
		lifeBarCurrentWidth = lifeBarDefaultWidth;
	}
	else if (lifeBarCurrentWidth < constants.KZERO_F)
	{
		lifeBarCurrentWidth = constants.KZERO_F;
	}
	_slot->SetSize(FVector2D(lifeBarCurrentWidth, _slot->GetSize().Y));
}

void UTlocHud::ModifyMasterBar(float percent)
{
	GlobalConstants constants;
	UCanvasPanelSlot* _slot = Cast<UCanvasPanelSlot>(MasterBar->Slot);
	masterBarCurrentWidth = masterBarDefaultWidth * percent;
	if (masterBarCurrentWidth > masterBarDefaultWidth)
	{
		masterBarCurrentWidth = masterBarDefaultWidth;
	}
	else if (masterBarCurrentWidth < constants.KZERO_F)
	{
		masterBarCurrentWidth = constants.KZERO_F;
	}
	_slot->SetSize(FVector2D(masterBarCurrentWidth, _slot->GetSize().Y));
}
