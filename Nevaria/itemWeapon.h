#ifndef H_itemWeapon
#define H_itemWeapon

#include <string>
#include "itemClassVirtual.h"

class weapon : public item {
public:
	void sharpenWeapon();
	void calcDamage();

	bool isEnchanted();
	bool isPoisoned();

//Constructors
	//constructor for non-enchanted weapons.
	weapon(int def, double qual, int maxCon);
	//constructor for enchanted weapons.
	weapon(int def, int enchant, double qual, int maxCon);

private:
	int baseDamage;
	int finalDamage;
	int enchantment;
	int poisonValue;
	int poisonHitsRemaining;
	int critChance;
	int critModifier;
	int maxStack;
	int currentStack;
	

	double craftQuality;
	int maxCondition;
	int currentCondition;

};

#endif