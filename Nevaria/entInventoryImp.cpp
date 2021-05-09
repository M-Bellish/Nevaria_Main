#include <iostream>
#include "itemClassVirtual.h"
#include "itemArmor.h"
#include "entInventory.h"

using namespace std;

armor entInventory::checkEquipped(int index) {
	return itemsEquipped[index];
}


//Constructor
entInventory::entInventory() {

 }

entInventory::~entInventory() {
	delete [] itemsEquipped;
}