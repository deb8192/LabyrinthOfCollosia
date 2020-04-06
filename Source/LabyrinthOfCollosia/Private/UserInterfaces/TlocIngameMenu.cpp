// Fill out your copyright notice in the Description page of Project Settings.


#include "TlocIngameMenu.h"
#include "Engine/World.h"
#include "GlobalConstants.h"
#include <cmath>
//#include "GameFramework/GameMode.h"

void UTlocIngameMenu::NativeConstruct()
{
	GlobalConstants constants;

	selMenu = Menu::ITEMS;
	
	AGameModeBase* mode = GetWorld()->GetAuthGameMode();
	if (mode != nullptr)
	{
		//gameMode = dynamic_cast<ATlocGameMode*>(mode);
	}
	for (int i = 0; i < constants.KMAXITEMS; i++)
	{
		setItemIcons(i);
	}

	center = FVector2D(0.0f, 96.0f);
	lastCalculatedPosition = FVector2D(0.0f, 0.0f);
	rotAngItemMenu = 40.0f;
	//petal = LoadObject<UStaticMesh>(NULL, _directory);
}

void UTlocIngameMenu::NativeTick(const FGeometry& geometry, float deltaTime)
{
}

void UTlocIngameMenu::setItemIcons(int iterator)
{
	GlobalConstants constants;
	FString directory = constants.KDIR_ITEMS;
	directory += constants.KDIR_ICONS_128;
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
	if (!right)
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

void UTlocIngameMenu::SetSpellsIcons(int numSpell, TCHAR* filePath)
{
	GlobalConstants constants;
	UObject* _resource;
	FSlateBrush* brush = new FSlateBrush();
	FLinearColor bckgrdOpacity = FLinearColor(FVector4(constants.KONE_F, constants.KONE_F, constants.KONE_F, constants.KZERO_F));

	switch (numSpell)
	{
	case 1:
		_resource = LoadObject<UObject>(NULL, filePath);
		brush->SetResourceObject(_resource);
		Spell_1->SetBrush(*brush);
		Spell_1_btn->SetBackgroundColor(bckgrdOpacity);
		break;

	case 2:
		_resource = LoadObject<UObject>(NULL, filePath);
		brush->SetResourceObject(_resource);
		Spell_2->SetBrush(*brush);
		Spell_2_btn->SetBackgroundColor(bckgrdOpacity);
		break;

	case 3:
		_resource = LoadObject<UObject>(NULL, filePath);
		brush->SetResourceObject(_resource);
		Spell_3->SetBrush(*brush);
		Spell_3_btn->SetBackgroundColor(bckgrdOpacity);
		break;

	case 4:
		_resource = LoadObject<UObject>(NULL, filePath);
		brush->SetResourceObject(_resource);
		Spell_4->SetBrush(*brush);
		Spell_4_btn->SetBackgroundColor(bckgrdOpacity);
		break;

	case 5:
		_resource = LoadObject<UObject>(NULL, filePath);
		brush->SetResourceObject(_resource);
		Spell_5->SetBrush(*brush);
		Spell_5_btn->SetBackgroundColor(bckgrdOpacity);
		break;

	case 6:
		_resource = LoadObject<UObject>(NULL, filePath);
		brush->SetResourceObject(_resource);
		Spell_6->SetBrush(*brush);
		Spell_6_btn->SetBackgroundColor(bckgrdOpacity);
		break;

	case 7:
		_resource = LoadObject<UObject>(NULL, filePath);
		brush->SetResourceObject(_resource);
		Spell_7->SetBrush(*brush);
		Spell_7_btn->SetBackgroundColor(bckgrdOpacity);
		break;

	case 8:
		_resource = LoadObject<UObject>(NULL, filePath);
		brush->SetResourceObject(_resource);
		Spell_8->SetBrush(*brush);
		Spell_8_btn->SetBackgroundColor(bckgrdOpacity);
		break;

	default:
		_resource = LoadObject<UObject>(NULL, filePath);
		brush->SetResourceObject(_resource);
		Spell_0->SetBrush(*brush);
		Spell_0_btn->SetBackgroundColor(bckgrdOpacity);
		break;
	}
	_resource = nullptr;
	brush = nullptr;
}

int* UTlocIngameMenu::GetSelectedObject()
{
	GlobalConstants constants; 
	UCanvasPanelSlot* _slot = nullptr;
	UCanvasPanelSlot* _selectorSlot = Cast<UCanvasPanelSlot>(menuSelector->Slot);
	bool found = false;
	int i = 0;
	int* solution = new int[2];
	while (!found && i < constants.KMAXWEAPONS)//CORREGIR: SE SUPONE QUE AQUÍ PASA POR TODOS LOS ELEMENTOS DEL MENU Y SOLO SE TIENEN EN CUENTA HECHIZOS
	{
		switch (selMenu)
		{
			case 0:
				switch (i)
				{
					case 1:
						_slot = Cast<UCanvasPanelSlot>(nectar_btn->Slot);
						break;
					
					case 2:
						_slot = Cast<UCanvasPanelSlot>(honey_btn->Slot);
						break;
					
					case 3:
						_slot = Cast<UCanvasPanelSlot>(bisquit_btn->Slot);
						break;
					
					case 4:
						_slot = Cast<UCanvasPanelSlot>(elixir_btn->Slot);
						break;
					
					case 5:
						_slot = Cast<UCanvasPanelSlot>(pixie_btn->Slot);
						break;
					
					case 6:
						_slot = Cast<UCanvasPanelSlot>(bead_btn->Slot);
						break;
					
					case 7:
						_slot = Cast<UCanvasPanelSlot>(wings_btn->Slot);
						break;
					
					case 8:
						_slot = Cast<UCanvasPanelSlot>(pouch_btn->Slot);
						break;

					default:
						if (i >= constants.KMAXITEMS)
						{
							i = constants.KMAXWEAPONS;
						}
						_slot = Cast<UCanvasPanelSlot>(petal_btn->Slot);
						break;
						
				}
				break;
			
			case 1:
				switch (i)
				{
				case 1:
					_slot = Cast<UCanvasPanelSlot>(Spell_1_btn->Slot);
					break;

				case 2:
					_slot = Cast<UCanvasPanelSlot>(Spell_2_btn->Slot);
					break;

				case 3:
					_slot = Cast<UCanvasPanelSlot>(Spell_3_btn->Slot);
					break;

				case 4:
					_slot = Cast<UCanvasPanelSlot>(Spell_4_btn->Slot);
					break;

				case 5:
					_slot = Cast<UCanvasPanelSlot>(Spell_5_btn->Slot);
					break;

				case 6:
					_slot = Cast<UCanvasPanelSlot>(Spell_6_btn->Slot);
					break;

				case 7:
					_slot = Cast<UCanvasPanelSlot>(Spell_7_btn->Slot);
					break;

				case 8:
					_slot = Cast<UCanvasPanelSlot>(Spell_8_btn->Slot);
					break;

				default:
					if (i >= constants.KMAXMEMORIZED_SPELLS)
					{
						i = constants.KMAXWEAPONS;
					}
					_slot = Cast<UCanvasPanelSlot>(Spell_0_btn->Slot);
					break;

				}
				break;
		}
		if (_slot->GetPosition().Equals(_selectorSlot->GetPosition()))
		{
			found = true;
			solution[0] = selMenu;
			solution[1] = i;
			return solution;
		}
		else i++;
	}
	return nullptr;
}

FVector2D UTlocIngameMenu::calculateRotation(FVector2D position, float rotAngle)
{
	GlobalConstants constants;
	float degRot = PI * rotAngle / constants.KPI_RADIAN;
	return FVector2D(round((cos(degRot) * position.X) + (sin(degRot) * constants.KMINUS_ONE * (position.Y - center.Y))), round((sin(degRot) * position.X) + (cos(degRot) * (position.Y - center.Y) + center.Y)));
}

//InterPolation??
void UTlocIngameMenu::substractTranslation(FVector2D* _transl, UCanvasPanelSlot* _slot)
{
	_transl->X -= _slot->GetPosition().X;
	_transl->Y -= _slot->GetPosition().Y;
}

