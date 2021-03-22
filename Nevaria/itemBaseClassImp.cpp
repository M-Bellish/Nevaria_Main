#include <iostream>
#include <string>
#include "itemBaseClass.h"

using namespace std;

string item::getName() {
	return name;
}

int item::getValue() {
	return value;
}

int item::getWeight() {
	return weight;
}

item::item() {
	name = "";
	value = 0;
	weight = 0;
}

item::item(string nm, int val, int wgt) {

		name = nm;
		value = val;
		weight = wgt;
}