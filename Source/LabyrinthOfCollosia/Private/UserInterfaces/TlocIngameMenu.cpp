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
	menuSections = constants.KMAX_MENU_SECTIONS;
	verticalDistance = (float) constants.KMENU_VERT_DISTANCE;
	totalVerticalDistance = (float)verticalDistance * menuSections;
	
	for (int i = 0; i < constants.KMAXITEMS; i++)
	{
		setItemIcons(i);
	}

	lastCalculatedPosition = calculatedPosition = renderPosition = FVector2D(0.0f, 0.0f);
}

void UTlocIngameMenu::NativeTick(const FGeometry& geometry, float deltaTime)
{
}

// Function that sets the correct sprite as its icon to the item indicated by the iterator
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

//Function that calls the elements rotation function having in mind the value of selMenu
void UTlocIngameMenu::RotateMenu(bool right)
{
	GlobalConstants constants;
	rotateElements(right);
}

//Function that prepare the menu elements to move them up. The player will move menu up when
//wanted to explore lower elements
void UTlocIngameMenu::MoveMenuUp()
{
	UCanvasPanelSlot* _slot = nullptr;
	//It's changed the menu selector selMenu to activate only the movement and actions of one elements menu
	selMenu++;
	if (selMenu > Menu::WEAPONS)
	{
		selMenu -= menuSections;
	}
	for(int i = 0; i < menuSections; i++)
	{
		_slot = getMenuCanvas(i);
		moveCanvasUp(*_slot);
	}
	moveCanvasToBottom();
	
}

//Function that prepare the menu elements to move them down. The player will move menu down when
//wanted to explore higher elements
void UTlocIngameMenu::MoveMenuDown()
{
	UCanvasPanelSlot* _slot = nullptr;
	//It's changed the menu selector selMenu to activate only the movement and actions of one elements menu
	selMenu--;
	if (selMenu < Menu::ITEMS)
	{
		selMenu += menuSections;
	}
	for (int i = 0; i < menuSections; i++)
	{
		_slot = getMenuCanvas(i);
		moveCanvasDown(*_slot);
	}
	moveCanvasToTop();
}

//Function that sets the spells sprites having in count the filePath route to get the sprite
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

void UTlocIngameMenu::SetWeaponIcons(int numWeapon)	//TO DO: this function it is not definitive, is for testing weapon sprites movement
{
	GlobalConstants constants;

	switch (numWeapon)
	{
	case 1:
		
		Femur->SetVisibility( ESlateVisibility::Visible);
		break;

	case 2:
		
		Axe->SetVisibility(ESlateVisibility::Visible);
		break;

	case 3:
		
		Spear->SetVisibility(ESlateVisibility::Visible);
		break;

	case 4:
		
		Falcata->SetVisibility(ESlateVisibility::Visible);
		break;

	case 5:
		
		IberianAxe->SetVisibility(ESlateVisibility::Visible);
		break;

	case 6:
		
		ViriatusSpear->SetVisibility(ESlateVisibility::Visible);

		break;

	case 7:
		
		SpartanSword->SetVisibility(ESlateVisibility::Visible);
		break;

	case 8:
		
		SpartanAxe->SetVisibility(ESlateVisibility::Visible);
		break;

	case 9:
		
		Doru->SetVisibility(ESlateVisibility::Visible);
		break;

	case 10:
		
		RaSword->SetVisibility(ESlateVisibility::Visible);
		break;

	case 11:
		
		CeremonialAxe->SetVisibility(ESlateVisibility::Visible);
		break;

	case 12:
		
		HorusSpear->SetVisibility(ESlateVisibility::Visible);
		break;

	case 13:
		
		VikingSword->SetVisibility(ESlateVisibility::Visible);
		break;

	case 14:
		
		VikingAxe->SetVisibility(ESlateVisibility::Visible);
		break;

	case 15:
		
		VikingSpear->SetVisibility(ESlateVisibility::Visible);
		break;

	case 16:
		
		Gladius->SetVisibility(ESlateVisibility::Visible);
		break;

	case 17:
		
		RomanAxe->SetVisibility(ESlateVisibility::Visible);
		break;

	case 18:
		
		Pillum->SetVisibility(ESlateVisibility::Visible);
		break;
	}
}

//Function that returns the selected menu and the menu element which is placed at the selectors place to use it
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

			case 4:
				switch (i)
				{
				case 1:
					_slot = Cast<UCanvasPanelSlot>(Axe_btn->Slot);
					break;

				case 2:
					_slot = Cast<UCanvasPanelSlot>(Spear_btn->Slot);
					break;

				case 3:
					_slot = Cast<UCanvasPanelSlot>(SpartanSword_btn->Slot);
					break;

				case 4:
					_slot = Cast<UCanvasPanelSlot>(SpartanAxe_btn->Slot);
					break;

				case 5:
					_slot = Cast<UCanvasPanelSlot>(Doru_btn->Slot);
					break;

				case 6:
					_slot = Cast<UCanvasPanelSlot>(Falcata_btn->Slot);
					break;

				case 7:
					_slot = Cast<UCanvasPanelSlot>(IberianAxe_btn->Slot);
					break;

				case 8:
					_slot = Cast<UCanvasPanelSlot>(ViriatusSpear_btn->Slot);
					break;

				case 9:
					_slot = Cast<UCanvasPanelSlot>(RaSword_btn->Slot);
					break;

				case 10:
					_slot = Cast<UCanvasPanelSlot>(CeremonialAxe_btn->Slot);
					break;

				case 11:
					_slot = Cast<UCanvasPanelSlot>(HorusSpear_btn->Slot);
					break;

				case 12:
					_slot = Cast<UCanvasPanelSlot>(VikingSword_btn->Slot);
					break;

				case 13:
					_slot = Cast<UCanvasPanelSlot>(VikingAxe_btn->Slot);
					break;

				case 14:
					_slot = Cast<UCanvasPanelSlot>(VikingSpear_btn->Slot);
					break;

				case 15:
					_slot = Cast<UCanvasPanelSlot>(Gladius_btn->Slot);
					break;

				case 16:
					_slot = Cast<UCanvasPanelSlot>(RomanAxe_btn->Slot);
					break;

				case 17:
					_slot = Cast<UCanvasPanelSlot>(Pillum_btn->Slot);
					break;

				default:
					if (i >= constants.KMAXMEMORIZED_SPELLS)
					{
						i = constants.KMAXWEAPONS;
					}
					_slot = Cast<UCanvasPanelSlot>(Femur_btn->Slot);
					break;

				}
				break;

			default:
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
		}
		if (_slot->GetPosition().Y == _selectorSlot->GetPosition().Y || (_slot->GetPosition().Y + 5 >= _selectorSlot->GetPosition().Y && _slot->GetPosition().Y <= _selectorSlot->GetPosition().Y) || (_slot->GetPosition().Y >= _selectorSlot->GetPosition().Y && _slot->GetPosition().Y - 5 <= _selectorSlot->GetPosition().Y))
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

UCanvasPanelSlot* UTlocIngameMenu::getLowerMenuCanvas()
{
	UCanvasPanelSlot *_slot = nullptr, *_selectedSlot = nullptr;
	for (int i = 0; i < menuSections; i++)
	{
		_slot = getMenuCanvas(i);
		if (_selectedSlot == nullptr)
		{
			_selectedSlot = _slot;
		}
		else if (_slot != nullptr && _slot->GetPosition().Y > _selectedSlot->GetPosition().Y)
		{
			_selectedSlot = _slot;
		}
	}
	return _selectedSlot;
}

UCanvasPanelSlot* UTlocIngameMenu::getHigherMenuCanvas()
{
	UCanvasPanelSlot* _slot = nullptr, * _selectedSlot = nullptr;
	for (int i = 0; i < menuSections; i++)
	{
		_slot = getMenuCanvas(i);
		if (_selectedSlot == nullptr)
		{
			_selectedSlot = _slot;
		}
		else if (_slot != nullptr && _slot->GetPosition().Y < _selectedSlot->GetPosition().Y)
		{
			_selectedSlot = _slot;
		}
	}
	return _selectedSlot;;
}

UCanvasPanelSlot* UTlocIngameMenu::getMenuCanvas(int sel)
{
	UCanvasPanelSlot *_slot = nullptr;
	switch (sel)
	{
	case 1:
		_slot = Cast<UCanvasPanelSlot>(SpellCanvas->Slot);
		break;
	case 2:
		_slot = Cast<UCanvasPanelSlot>(ArmorCanvas->Slot);
		break;
	case 3:
		_slot = Cast<UCanvasPanelSlot>(GauntletCanvas->Slot);
		break;
	case 4:
		_slot = Cast<UCanvasPanelSlot>(WeaponCanvas->Slot);
		break;
	default:
		_slot = Cast<UCanvasPanelSlot>(ItemCanvas->Slot);
		break;
	}
	return _slot;
}

TArray<UPanelSlot*> UTlocIngameMenu::getSubSlots()
{
	switch (selMenu)
	{
	case 0:
		return ItemCanvas->GetSlots();
	case 1:
		return SpellCanvas->GetSlots();
	case 2:
		return ArmorCanvas->GetSlots();
	case 3:
		return GauntletCanvas->GetSlots();
	case 4:
		return WeaponCanvas->GetSlots();
	default:
		return ItemCanvas->GetSlots();
	}
}

//Function that moves menu elements up
void UTlocIngameMenu::moveCanvasUp(UCanvasPanelSlot& _slot)
{
	_slot.SetPosition(FVector2D(_slot.GetPosition().X, _slot.GetPosition().Y - verticalDistance));
}

//Function that moves menu elements down
void UTlocIngameMenu::moveCanvasDown(UCanvasPanelSlot& _slot)
{
	_slot.SetPosition(FVector2D(_slot.GetPosition().X, _slot.GetPosition().Y + verticalDistance));
}

//Function that moves the lower element to top
void UTlocIngameMenu::moveCanvasToTop()
{
	UCanvasPanelSlot* _slot = getLowerMenuCanvas();
	_slot->SetPosition(FVector2D(_slot->GetPosition().X, _slot->GetPosition().Y - totalVerticalDistance));
}

//Function that moves the higher element to bottom
void UTlocIngameMenu::moveCanvasToBottom()
{
	UCanvasPanelSlot* _slot = getHigherMenuCanvas();
	_slot->SetPosition(FVector2D(_slot->GetPosition().X, _slot->GetPosition().Y + totalVerticalDistance));
}

//Function that rotates the elements of the selected menu
void UTlocIngameMenu::rotateElements(bool right)
{
	GlobalConstants constants;
	FVector2D translation = FVector2D(0.0f, 0.0f);
	int numElements = getSubSlots().Num();

	//It's obtained the rotation angle by dividing 360º into the selected menu number of elements
	float rotation = (float)constants.K2PI_RADIAN / (float)numElements;
	if (right)
	{
		rotation *= constants.KMINUS_ONE;
	}

	for (int i = 0; i < numElements; i++)
	{
		UCanvasPanelSlot *_slot = Cast<UCanvasPanelSlot>(getSubSlots()[i]); 
		translation = calculateRotation(_slot->GetPosition(), rotation);
		_slot->SetPosition(translation);
	}
}

//Function that calculates the element menu trans lation having in mind its position and the rotation angle to move it
FVector2D UTlocIngameMenu::calculateRotation(FVector2D position, float rotAngle)
{
	GlobalConstants constants;
	float degRot = PI * rotAngle / constants.KPI_RADIAN;
	return FVector2D(round((cos(degRot) * position.X) + (sin(degRot) * constants.KMINUS_ONE * position.Y)), round((sin(degRot) * position.X) + (cos(degRot) * position.Y)));
}

//InterPolation??
void UTlocIngameMenu::substractTranslation(FVector2D* _transl, UCanvasPanelSlot* _slot)
{
	_transl->X -= _slot->GetPosition().X;
	_transl->Y -= _slot->GetPosition().Y;
}

