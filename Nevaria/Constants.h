#ifndef H_Constants
#define H_Constants

//#define NC "\e[0m"
//#define RED "\e[0;31m"
//#define GRN "\e[0;32m"
//#define CYN "\e[0;36m"
//#define REDB "\e[41m"

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "itemClassVirtual.h"
#include "itemArmor.h"
#include "itemWeapon.h"
#include "itemConsumable.h"

using namespace std;

//Skill name list; used to initialize skillLevels with skill names being keys.
//Can be sliced if passed an index to get the name key to slice the skillLevels map
const string skillList[9]{ "blade", "blunt", "axe", "marksman", "defence",
	"spellcasting", "alchemy", "smithing", "enchanting"};

//Skill experience requirements for each skill level
const int skillExpLevelList[9] = {20, 40, 70, 120, 150, 200, 220, 350, 500};

//Magic types
const string Elements[6]{ "Fire", "Lightning", "Ice", "Wind", "Dark", "Holy"};

//Weapons and modifiers
const string wepTypes[10]{"Dagger", "Short Sword", "Long Sword", "Great Sword", "Battle Axe", "Great Axe", "Mace", "Warhammer", "Short Bow", "Long Bow" };
const int wepBaseDamage[10]{3, 4, 7, 12, 5, 14, 5, 15, 3, 8 };
const int wepStaminaCost[10]{2, 3, 6, 10, 5, 12, 4, 14, 4, 9 };
const int wepBaseWgt[10]{2, 3, 6, 10, 5, 12, 4, 14, 4, 9 };

//Armor and modifiers
const string armorSlots[8]{ "Head", "Shoulders","Chest", "Hands", "Legs", "Feet", "Ring", "Amulet" };
const int armorModifier[8]{ 3, 2, 5, 1, 4, 2, 0, 0};

//Materials and modifiers
const string craftMatsTypes[8]{ "Chitin", "Leather", "Iron", "Steel", "Elven Steel", "Dwarven Steel", "Mithril", "Adamantite"};
const double craftMatsWgtMod[8]{0.3, 0.6, 1.0, 1.2, 0.9, 2.0, 0.8, 1.5};
const double craftMatsDmgMod[8]{0.4, 0, 1.0, 1.1, 1.3, 1.9, 1.7, 2.1};
const double craftMatsDefMod[8]{0.5, 0.7, 1.0, 1.2, 1.4, 2.0, 1.6, 1.9};

//status effects
const string debuffNames[8]{ "Bleeding", "Poisoned", "Stunned", "Sundered", "Blinded", "Burning", "Silenced", "Paralyzed" };
//Key: 1 Damage, 2 No actions, 3 Defence down, 4 Accuracy down, 5 No spells
const double debuffEffect[8]{ 1, 1, 2, 3, 4, 1, 5, 2 };

//Starting Equipment





#endif