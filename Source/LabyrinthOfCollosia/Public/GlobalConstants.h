#pragma once

#include "CoreMinimal.h"

using GlobalConstants = struct Constants
{
	//Cardinals for calculus

	const int KUNITY = 1;
	const int KPERCENT = 100;


	//Speeds

	const int KROTATIONSPEED = 15;

	//Return vlues

	const int KZERO = 0;
	const int KMINUS_ONE = -1;


	//Default values

	const float KINVULNERABLE_TIME = 1.5;
	const int KBASICDAMAGE = 2;
	const int KMAX_VARIABLE_DAMAGE = 5;
	const int KMIN_VARIABLE_DAMAGE = -2;


	//Max number of

	const int KMAXUSES = 100;
	const int KMAXACTIVE_BUFFS_AILMENTS = 4;
	const int KMAXSPELLS = 34;
	const int KMAXMEMORIZED_SPELLS = 9;
	const int KMAXINGREDIENTS = 22;
	const int KMAXITEMS = 9;
	const int KMAXNUM_OF_ITEMS = 9;
	const int KMAXWEAPONS = 18;
	const int KMAXARMORS = 10;
	const int KMAXGAUNTLETS = 10;
	const int KMAXLEVEL = 99;
	const int KMAXEQUIPEMENT_LEVEL = 10;


	//Buffs & Ailments
	
	const int KEXTRALIFE = 0;
	const int KDEFEND = 1;
	const int KCONFOUND = 2;
	const int KSPEED = 3;
	const int KATLAS = 4;
	const int KREGROWTH = 5;
	const int KBARRIER = 6;
	const int KFORCEFIELD = 7;
	const int KREFLECT = 8;
	const int KENERGIZE = 9;
	const int KSHIELD = 10;
};