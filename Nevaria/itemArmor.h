#ifndef H_itemArmor
#define H_itemArmor



class armor : public item {
public:
	void createArmor(string nm, int val, int wgt, int def, int enchant, double qual, int maxCon);

	//calculates final defense
	int getDefense();


	bool isEnchanted();

	//Constructors
	armor();
	armor(string nm, int val, int wgt, int def, double qual, int maxCon);
	armor(string nm, int val, int wgt, int def, int enchant, double qual, int maxCon);

private:

	int baseDefense;
	int finalDefense;
	bool enchanted;
	int enchantment;
	double craftQuality;
	int maxCondition;
	int currentCondition;

};

#endif