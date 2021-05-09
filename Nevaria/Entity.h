 #ifndef H_Entity
 #define H_Entity

#include <iostream>
#include <string>
#include <map>
#include "entAttributes.h"
#include "entSkills.h"
#include "entInventory.h"
#include "Constants.h"

 class entity {
 	public:
 		//void craft();
 		//void journal();
        void create(string name, entAttributes stats, entSkills skills);
        string getName();
 		void adjustMoney(int);

 		int getMeleeAttack();
 		int getMagicAttack();
 		int getDefense();
 		int getAfflictions();

        //Constructor
        entity();
        entity(string name, entInventory Inv, entAttributes stats, entSkills skills);

        //Destructor
        ~entity();

 	private:
 		string myName;
        entInventory *myInv;
        entAttributes *myStats;
        entSkills *mySkills;
        int afflictions[9];
        int afflictionsTurnsLeft[9];
 		//int buffs[];
 		int money;

 };

 #endif
