#ifndef H_Inventory
#define H_Inventory

#include "itemClassVirtual.h"
#include "itemArmor.h"

using namespace std;

class entInventory {
public:
	armor checkEquipped(int index);

	entInventory();

	~entInventory();

private:
	armor itemsEquipped[8];


};

#endif