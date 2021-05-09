#include <iostream>
#include <string>
#include <map>
 #include "entAttributes.h"
 #include "entSkills.h"
 #include "entInventory.h"
 #include "Entity.h"

 using namespace std;

 //void entity::craft() {

 //}
 //void entity::journal() {

 //}
 void entity::create(string aName, entAttributes attributes, entSkills skills) {
	 myName = aName;
	 myStats = new entAttributes(attributes);
	 mySkills = new entSkills(skills);
	 afflictions[8] = {};
	 afflictionsTurnsLeft[8] = {};
	 //buffs = ;
	 money = 0;
 }

 string entity::getName() {
	 return myName;
 }

 void entity::adjustMoney(int num) {
	 money = (money + num);
 }

 int entity::getMeleeAttack() {
	 return 0;
 }
 int entity::getMagicAttack() {
	 return 0;
 }
 int entity::getDefense() {
	 int total = 0;
	 for (int i = 1; i < 8; i++) {
		total += (myInv->checkEquipped(i).getDefense());
	 }
	 return total;
 }
 int entity::getAfflictions() {
	 return 0;
 }
 //Constructors
 entity::entity() {
	 myName = "";
	 myInv = nullptr;
	 myStats = nullptr;
	 mySkills = nullptr;
	 afflictions[8] = {};
	 afflictionsTurnsLeft[8] = {};
	 money = 0;
 }

 entity::entity(string aName, entInventory inv, entAttributes attributes, entSkills skills)
 {
	myName = aName;
	myInv = new entInventory(inv);
	myStats = new entAttributes(attributes);
	mySkills = new entSkills(skills);
	afflictions[8] = {};
	afflictionsTurnsLeft[8] = {};
	//buffs = ;
	money = 0;

 }

 //Destructor
 entity::~entity() {
	 delete myInv;
	 delete myStats;
	 delete mySkills;
 }