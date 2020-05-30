#pragma once

#include "CoreMinimal.h"

using GlobalConstants = struct Constants
{
	/*** Booleans ***/
	const bool KTRUE = true;
	const bool KFALSE = false;

	/*** Cardinals for calculus ***/

	const int KUNITY = 1;
	const int KTWO = 2;
	const int KTHREE = 3;
	const int KFOUR = 4;
	const int KPERCENT = 100;
	size_t KCHAR_SIZE = 32;

	/*** Trigonometric calculus ***/
	const float DEG_TO_RAD = 0.0174532925199432957f;
	const float RAD_TO_DEG = 57.295779513082320876f;
	const int KPI_RADIAN = 180;
	const int K3_2PI_RADIAN = 270;
	const int K2PI_RADIAN = 360;
	const int K1_2PI_RADIAN = 90;
	const int K1_4PI_RADIAN = 45;

	/*** Speeds ***/

	const int KROTATIONSPEED = 15;

	/*** Return values ***/

	const int KZERO = 0;
	const int KONE = 1;
	const int KMINUS_ONE = -1;

	/*** Float values ***/

	const float KZERO_F = 0.0f;
	const float KONE_F = 1.0f;
	const float KTEN_PERCENT = 0.1f;

	/*** Default values ***/

	const float KRENDER_TIME = 1.0f / 60.0f;
	const float KUPDATE_TIME = 1.0f / 15.0f;
	const float KINVULNERABLE_TIME = 1.5;
	const float KNO_COWARD_TIME = 10.0;
	const float KRUN_AWAY_TIME = 5.0;
	const float KMASTER_TIME = 5.0;
	const float KCAMERA_CHANGE_TIME = 4.0;
	const float KMAX_TARGET_DISTANCE = 2000.f;
	const float KCAMERA_DISTANCE = 250.f;
	const float KHALF_CAMERA_DISTANCE = 125.f;
	const int KMAX_NUM_PLAYERS = 2;
	const int KBASICDAMAGE = 2;
	const int KMASTER_DAMAGE = 4;
	const int KMAX_NUM_TARGETS = 30;
	const int KMAX_NUM_DIRECTORIES = 4;
	const int KMAX_VARIABLE_DAMAGE = 5;
	const int KMIN_VARIABLE_DAMAGE = -2;
	const int KMAX_MENU_SECTIONS = 5;
	const int KMENU_VERT_DISTANCE = 1140;
	const char* KEMPTY_STRING = "";

	//	-Directory

	const char* KVOID = "";
	const char* KFIRST_LEVEL_NAME = "Hall";
	const char* KEXTENSION_JSON = ".json";
	const char* KDIR_JSON_NEW_GAME = "Json/New_Game/Player";
	const char* KDIR_JSON_OBJ = "Json/Objects/";
	const char* KDIR_JSON_INT = "Json/Interruptors/";
	const char* KDIR_JSON_ENM = "Json/Enemies/";
	const char* KDIR_GLADIUS_MESH = "/Game/Models/Stages/Stages-objects/Gladius.Gladius";
	const char* KDIR_CHEST_MESH = "/Game/Models/Stages/Stages-objects/Vessel_Cube.Vessel_Cube";
	const char* KDIR_CHEST_AUX_MESH = "/Game/Models/Stages/Stages-objects/Vessel_Sphere.Vessel_Sphere";

	//	-Menu directories

	const char* KDIR_ITEMS = "/Game/Sprites/Items/";
	const char* KDIR_SPELLS = "/Game/Sprites/Spells/";
	const char* KDIR_ICONS_128 = "Icons-128/";
	const char* KNAME_PETAL_128 = "Petal-128px.Petal-128px";
	const char* KNAME_PETAL = "Petal";
	const char* KNAME_NECTAR_128 = "Nectar-128px.Nectar-128px";
	const char* KNAME_NECTAR = "Nectar";
	const char* KNAME_HONEY_128 = "Honey-128px.Honey-128px";
	const char* KNAME_HONEY = "Honey";
	const char* KNAME_BISQUIT_128 = "Bisquit-128px.Bisquit-128px";
	const char* KNAME_BISQUIT = "Bisquit";
	const char* KNAME_ELIXIR_128 = "Elixir-128px.Elixir-128px";
	const char* KNAME_ELIXIR = "Elixir";
	const char* KNAME_PIXIEDUST_128 = "PixieDust-128px.PixieDust-128px";
	const char* KNAME_PIXIEDUST = "PixieDust";
	const char* KNAME_CALLBEAD_128 = "CallBead-128px.CallBead-128px";
	const char* KNAME_CALLBEAD = "CallBead";
	const char* KNAME_POUCH_128 = "Pouch-128px.Pouch-128px";
	const char* KNAME_POUCH = "Pouch";
	const char* KNAME_WINGS_128 = "Wings-128px.Wings-128px";
	const char* KNAME_WINGS = "Wings";
	const char* KNAME_HEAL_128 = "Heal-128px.Heal-128px";
	const char* KNAME_HEAL = "Heal";
	const char* KNAME_FLASH_128 = "Flash-128px.Flash-128px";
	const char* KNAME_FLASH = "Flash";

	//	-HUD directories

	const char* KDIR_PLAYERS = "/Game/Sprites/HUD/HUD-512px-pictures/";
	const char* KNAME_HUMAN_PLAYER = "HumanPlayer";
	const char* KNAME_DOG_PLAYER = "DogPlayer";
	const char* KNAME_HUMAN_PLAYER_M = "HumanPlayerPic.HumanPlayerPic";
	const char* KNAME_HUMAN_PLAYER_F = "HumanPlayerPicF.HumanPlayerPicF";



	//	-Stages directories

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
	const char* KSPELL = "TlocSpell";
	const char* KITEM = "TlocItem";
	const char* KHEALT_ITEM = "TlocHealtItem";
	const char* KCALL_BEAD_ITEN = "TlocCallBeadItem";
	const char* KSTATUS_ITEM = "TlocStatusItem";
	const char* KCHEST_CLASS = "TlocChest";
	const char* KPLAYER = "TlocPlayer";
	const char* KHUMAN_PLAYER = "TlocHumanPlayer";
	const char* KDOG_PLAYER = "TlocDogPlayer";
	const char* KENEMY = "TlocEnemy";
	const char* KDOOR = "TlocDoor";
	const char* KLEVER = "TlocLever";
	const char* KINTERRUPTOR = "Interruptor";

	//	-Properties

	const char* KID = "ID";
	const char* KLEVEL = "level";
	const char* KLIFE = "life";
	const char* KMASTER = "master";
	const char* KATTACK = "attack";
	const char* KDEFENSE = "defense";
	const char* KMAGIC_DEFENSE = "magicDef";
	const char* KEVASION = "evasion";
	const char* KLUCK = "luck";
	const char* KCOWARD = "coward";
	const char* KCRITICAL_HIT = "criticalHit";
	const char* KCRITICAL_PROB = "criticalProb";
	const char* KCRITICAL_DAMAGE_INC = "criticalDamageInc";
	const char* KCRITICAL_PROBABILITY_INC = "criticalProbabilityInc";
	const char* KEXPERIENCE = "experience";
	const char* KNEXT_LEVEL = "nextLevel";
	const char* KNAME = "name";
	const char* KPRICE = "price";
	const char* KCLASS_NAME = "className";
	const char* KFILE_DIRECTORY = "fileDirectory";
	const char* KPOSITION = "position";
	const char* KROTATION = "rotation";
	const char* KACTIVE_ROTATION = "activeRotation";
	const char* KCHEST = "chest";
	const char* KQUANTITY = "quantity";
	const char* KDESCRIPTION = "description";
	const char* KBASIC_POWER = "basicPower";
	const char* KACTIVE = "active";
	const char* KSPEED_STR = "speed";
	const char* KINGREDIENTS_ID = "ingredientID";
	const char* KHEALTH_ITEMS_ID = "healthID";
	const char* KHEALTH_RECOVERED = "healthRecovered";
	const char* KTARGET = "target";


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
	const int KMAXALCHEMY_LEVEL = 10;


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
	const int KPOISON = 11;
	const int KPLAGE = 12;
	const int KHYPNOTIZED = 13;
	const int KSTOP = 14;
	const int KCORROSION = 15;
	const int KBURNED = 16;
	const int KDISRUPT = 17;
};