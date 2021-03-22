#ifndef H_itemArmor
#define H_itemArmor

class armor : public item {
public:
	void calcDefense();

	bool isEnchanted();

	armor(int def, double qual, int maxCon);
	armor(int def, int enchant, double qual, int maxCon);

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