#ifndef H_itemConsumable
#define H_itemConsumable


class consumable : public item {
public:
	void consume();

	consumable(bool recipe, int uses, int eff1, int eff2);

private:
	bool isRecipe;
	int numOfUsesLeft;
	int effect1;
	int effect2;



};

#endif