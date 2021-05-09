#include <iostream>
#include <map>
#include <string>
#include "itemClassVirtual.h"
#include "itemArmor.h"

using namespace std;

void armor::createArmor(string nm, int val, int wgt, int def, int enchant, double qual, int maxCon) {

	baseDefense = def;
	craftQuality = qual;
	finalDefense = static_cast<int>(baseDefense * craftQuality);
	enchanted = true;
	enchantment = enchant;
	maxCondition = maxCon;
	currentCondition = maxCon;
}

int armor::getDefense() {
	 return finalDefense;
}

bool armor::isEnchanted() {
	 return enchanted;
}

//Constructors
armor::armor() {

	baseDefense = 0;
	craftQuality = 0;
	finalDefense = 0;
	enchanted = false;
	enchantment = 0;
	maxCondition = 0;
	currentCondition = 0;
}

armor::armor(string nm, int val, int wgt, int def, double qual, int maxCon) 
					: item(nm, val, wgt) {

	baseDefense = def;
	craftQuality = qual;
	finalDefense = static_cast<int>(baseDefense * craftQuality);
	enchanted = false;
	enchantment = 0;
	maxCondition = maxCon;
	currentCondition = maxCon;


}

armor::armor(string nm, int val, int wgt, int def, int enchant, double qual, int maxCon) 
					: item(nm, val, wgt) {

	baseDefense = def;
	craftQuality = qual;
	finalDefense = static_cast<int>(baseDefense * craftQuality);
	enchanted = true;
	enchantment = enchant;
	maxCondition = maxCon;
	currentCondition = maxCon;

}