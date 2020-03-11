// Fill out your copyright notice in the Description page of Project Settings.


#include "TlocIngameMenu.h"
#include "Engine/World.h"
#include "Misc/Paths.h"
#include "GlobalConstants.h"
#include <cmath>
//#include "GameFramework/GameMode.h"

void UTlocIngameMenu::NativeConstruct()
{
	GlobalConstants constants;
	
	AGameModeBase* mode = GetWorld()->GetAuthGameMode();
	if (mode != nullptr)
	{
		//gameMode = dynamic_cast<ATlocGameMode*>(mode);
	}
	for (int i = 0; i < constants.KMAXITEMS; i++)
	{
		setIcons(i);
	}

	center = FVector2D(0.0f, 96.0f);
	lastCalculatedPosition = FVector2D(0.0f, 0.0f);
	rotAngItemMenu = 40.0f;
	//petal = LoadObject<UStaticMesh>(NULL, _directory);
}

void UTlocIngameMenu::NativeTick(const FGeometry& geometry, float deltaTime)
{
}

void UTlocIngameMenu::setIcons(int iterator)
{
	GlobalConstants constants;
	FString directory = constants.KDIR_ITEMS;
	directory += constants.KDIR_ITEMS_128;
	FString name;
	UObject* _resource;
	FSlateBrush* brush = new FSlateBrush();
	FLinearColor bckgrdOpacity = FLinearColor(FVector4(constants.KONE_F, constants.KONE_F, constants.KONE_F, constants.KZERO_F));

	switch (iterator)
	{
		case 1:
			directory += constants.KNAME_NECTAR_128;
			name = constants.KNAME_NECTAR;
			_resource = LoadObject<UObject>(NULL, *directory);
			brush->SetResourceObject(_resource);
			nectar->SetBrush(*brush);
			nectar_btn->SetBackgroundColor(bckgrdOpacity);
			break;

		case 2:
			directory += constants.KNAME_HONEY_128;
			name = constants.KNAME_HONEY;
			_resource = LoadObject<UObject>(NULL, *directory);
			brush->SetResourceObject(_resource);
			honey->SetBrush(*brush);
			honey_btn->SetBackgroundColor(bckgrdOpacity);
			break;

		case 3:
			directory += constants.KNAME_BISQUIT_128;
			name = constants.KNAME_BISQUIT;
			_resource = LoadObject<UObject>(NULL, *directory);
			brush->SetResourceObject(_resource);
			brush->SetImageSize(FVector2D(128, 128));
			bisquit->SetBrush(*brush);
			bisquit_btn->SetBackgroundColor(bckgrdOpacity);
			break;

		case 4:
			directory += constants.KNAME_ELIXIR_128;
			name = constants.KNAME_ELIXIR;
			_resource = LoadObject<UObject>(NULL, *directory);
			brush->SetResourceObject(_resource);
			brush->SetImageSize(FVector2D(128, 128));
			elixir->SetBrush(*brush);
			elixir_btn->SetBackgroundColor(bckgrdOpacity);
			break;

		case 5:
			directory += constants.KNAME_PIXIEDUST_128;
			name = constants.KNAME_PIXIEDUST;
			_resource = LoadObject<UObject>(NULL, *directory);
			brush->SetResourceObject(_resource);
			pixieDust->SetBrush(*brush);
			pixie_btn->SetBackgroundColor(bckgrdOpacity);
			break;

		case 6:
			directory += constants.KNAME_CALLBEAD_128;
			name = constants.KNAME_CALLBEAD;
			_resource = LoadObject<UObject>(NULL, *directory);
			brush->SetResourceObject(_resource);
			callBead->SetBrush(*brush);
			bead_btn->SetBackgroundColor(bckgrdOpacity);
			break;

		case 7:
			directory += constants.KNAME_WINGS_128;
			name = constants.KNAME_WINGS;
			_resource = LoadObject<UObject>(NULL, *directory);
			brush->SetResourceObject(_resource);
			wings->SetBrush(*brush);
			wings_btn->SetBackgroundColor(bckgrdOpacity);
			break;

		case 8:
			directory += constants.KNAME_POUCH_128;
			name = constants.KNAME_POUCH;
			_resource = LoadObject<UObject>(NULL, *directory);
			brush->SetResourceObject(_resource);
			pouch->SetBrush(*brush);
			pouch_btn->SetBackgroundColor(bckgrdOpacity);
			break;

		default:
			directory += constants.KNAME_PETAL_128;
			name = constants.KNAME_PETAL;
			_resource = LoadObject<UObject>(NULL, *directory);
			brush->SetResourceObject(_resource);
			petal->SetBrush(*brush);
			petal_btn->SetBackgroundColor(bckgrdOpacity);
			break;
	}
	_resource = nullptr;
	brush = nullptr;
}

void UTlocIngameMenu::RotateMenu(bool right)
{
	GlobalConstants constants;
	float rotation = rotAngItemMenu;
	FVector2D translation = FVector2D(0.0f, 0.0f);
	if (right)
	{
		rotation *= constants.KMINUS_ONE;
	}
	//Petal translation
	UCanvasPanelSlot* _slot = Cast<UCanvasPanelSlot>(petal_btn->Slot);
	translation = calculateRotation(_slot->GetPosition(), rotation);
	_slot->SetPosition(translation);

	//Nectar translation
	_slot = Cast<UCanvasPanelSlot>(nectar_btn->Slot);
	translation = calculateRotation(_slot->GetPosition(), rotation);
	_slot->SetPosition(translation);

	//Honey translation
	_slot = Cast<UCanvasPanelSlot>(honey_btn->Slot);
	translation = calculateRotation(_slot->GetPosition(), rotation);
	_slot->SetPosition(translation);

	//Bisquit translation
	_slot = Cast<UCanvasPanelSlot>(bisquit_btn->Slot);
	translation = calculateRotation(_slot->GetPosition(), rotation);
	_slot->SetPosition(translation);

	//Elixir translation
	_slot = Cast<UCanvasPanelSlot>(elixir_btn->Slot);
	translation = calculateRotation(_slot->GetPosition(), rotation);
	_slot->SetPosition(translation);

	//Pixie translation
	_slot = Cast<UCanvasPanelSlot>(pixie_btn->Slot);
	translation = calculateRotation(_slot->GetPosition(), rotation);
	_slot->SetPosition(translation);

	//Bead translation
	_slot = Cast<UCanvasPanelSlot>(bead_btn->Slot);
	translation = calculateRotation(_slot->GetPosition(), rotation);
	_slot->SetPosition(translation);

	//Wings translation
	_slot = Cast<UCanvasPanelSlot>(wings_btn->Slot);
	translation = calculateRotation(_slot->GetPosition(), rotation);
	_slot->SetPosition(translation);

	//Pouch translation
	_slot = Cast<UCanvasPanelSlot>(pouch_btn->Slot);
	translation = calculateRotation(_slot->GetPosition(), rotation);
	_slot->SetPosition(translation);
}

FVector2D UTlocIngameMenu::calculateRotation(FVector2D position, float rotAngle)
{
	GlobalConstants constants;
	float degRot = PI * rotAngle / constants.KPI_RADIAN;
	return FVector2D(round((cos(degRot) * position.X) + (sin(degRot) * constants.KMINUS_ONE * (position.Y - center.Y))), round((sin(degRot) * position.X) + (cos(degRot) * (position.Y - center.Y) + center.Y)));
}

void UTlocIngameMenu::substractTranslation(FVector2D* _transl, UCanvasPanelSlot* _slot)
{
	_transl->X -= _slot->GetPosition().X;
	_transl->Y -= _slot->GetPosition().Y;
}

