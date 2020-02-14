#pragma once

#include "CoreMinimal.h"

using GlobalConstants = struct Constants
{
	/*** Cardinals for calculus ***/

	const int KUNITY = 1;
	const int KPERCENT = 100;
	size_t KCHAR_SIZE = 32;


	/*** Speeds ***/

	const int KROTATIONSPEED = 15;

	/*** Return vlues ***/

	const int KZERO = 0;
	const int KMINUS_ONE = -1;


	/*** Default values ***/

	const int KLEVEL_NUM = 6;
	const float KINVULNERABLE_TIME = 1.5;
	const int KBASICDAMAGE = 2;
	const int KMAX_NUM_DIRECTORIES = 4;
	const int KMAX_VARIABLE_DAMAGE = 5;
	const int KMIN_VARIABLE_DAMAGE = -2;
	const char* KEMPTY_STRING = "";

	//	-Directory
	const char* KFIRST_LEVEL_NAME = "Hall";
	const char* KEXTENSION_JSON = ".json";
	const char* KDIR_JSON_OBJ = "Json/Objects/";
	const char* KDIR_JSON_ENM = "Json/Enemies/";
	const char* KDIR_CHEST_MESH = "/Game/Models/Stages/Stages-objects/Vessel_Cube.Vessel_Cube";
	const char* KDIR_CHEST_AUX_MESH = "/Game/Models/Stages/Stages-objects/Vessel_Sphere.Vessel_Sphere";

	const char* KEXTENSION_UMAP = ".umap";
	const char* KDIR_LEVELS = "Models/Stages";
	const char* KDIR_HALL = "Hall/";
	const char* KDIR_MINITAURUS_STAGE = "Stage-PreMinitaurus/";
	const char* KNAME_HALL = "Hall";
	const char* KNAME_MINITAURUS_STAGE = "Stage-PreMinitaurus";

	/*** JSON objects ***/
	//	-Classes

	const char* KOBJECT = "objects";
	const char* KWEAPON = "TlocWeapon";
	const char* KSWORD = "TlocSword";
	const char* KSPEAR = "TlocSpear";
	const char* KAXE = "TlocAxe";
	const char* KARMOR = "TlocArmor";
	const char* KGAUNTLET = "TlocGauntlet";
	const char* KINGREDIENT = "TlocIngredients";
	const char* KHEALT_ITEM = "TlocHealtItem";
	const char* KCALL_BEAD_ITEN = "TlocCallBeadItem";
	const char* KSTATUS_ITEM = "TlocStatusItem";
	const char* KCHEST_CLASS = "TlocChest";

	//	-Properties

	const char* KCHEST = "chest";

	/*** JSON enemies ***/

	const char* KENEMY = "TlocEnemy";

	//	-Name variables

	const char* KPOSITION = "position";
	const char* KROTATION = "rotation";
	const char* KNAME = "name";
	const char* KFILE_DIRECTORY = "fileDirectory";
	const char* KPRICE = "price";
	const char* KATTACK = "attack";
	const char* KDEFENSE = "defense";
	const char* KCRITICAL_DAMAGE_INC = "criticalDamageInc";
	const char* KCRITICAL_PROBABILITY_INC = "criticalProbabilityInc";

	const char* KINGREDIENTS_ID = "ingredientID";
	const char* KHEALTH_ITEMS_ID = "healthID";

	const char* KHEALTH_RECOVERED = "healthRecovered";


	/*** Max number of ***/

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


	/*** Buffs & Ailments ***/
	
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