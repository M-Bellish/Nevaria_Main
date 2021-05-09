#ifndef H_itemClassVirtual
#define H_itemClassVirtual

#include <iostream>
#include <string>

using namespace std;

//Virtual base class for all items.
//Contains variables and functions that all items would have.
class item {
public:
	//virtual void generateName() = 0;
	virtual void giveName(string nm);
	virtual string getName();
	virtual int getValue();
	virtual int getWeight();

	//Constructors
	item();
	item(string nm, int val, int wgt);

	//Destructor
	~item();

private:
	string name;
	int value;
	int weight;
};

#endif