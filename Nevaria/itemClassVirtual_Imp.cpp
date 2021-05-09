#include <iostream>
#include <string>
#include "itemClassVirtual.h"

using namespace std;

//void item::generateName() {
//
//}

void item::giveName(string nm) {
	name = nm;
}

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

item::~item() {

}