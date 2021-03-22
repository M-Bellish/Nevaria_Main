#ifndef H_itemBaseClass
#define H_itemBaseClass

using namespace std;

class item {
public:
	virtual void generateName() = 0;
	virtual void giveName() = 0;

	virtual string getName();
	virtual int getValue();
	virtual int getWeight();

	item();
	item(string nm, int val, int wgt);

private:
	string name;
	int value;
	int weight;
};

#endif