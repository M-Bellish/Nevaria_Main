#include <iostream>
#include "entAttributes.h"

using namespace std;

void entAttributes::setAll(int str, int intel, int agi, int dex,
	int con, int wil) {
	strength = str;
	intelligence = intel;
	agility = agi;
	dexterity = dex;
	constitution = con;
	will = wil;
}
void entAttributes::adjustStrength(int i){
	strength = (strength + i);
}
void entAttributes::adjustIntelligence(int i){
	intelligence = (intelligence + i);
}
void entAttributes::adjustAgility(int i){
	agility = (agility + i);
}
void entAttributes::adjustDexterity(int i){
	dexterity = (dexterity + i);
}
void entAttributes::adjustConstitution(int i){
	constitution = (constitution + i);
}
void entAttributes::adjustWill(int i){
	will = (will + i);
}

void entAttributes::calcMaxHealth(){
	maxHealth = (constitution);
}
void entAttributes::calcMaxMana(){

}
void entAttributes::calcMaxStamina(){

}
void entAttributes::adjustCurrentHealth(int i){
	currentHealth = (currentHealth + i);
}
void entAttributes::adjustCurrentMana(int i){
	currentMana = (currentMana + i);
}
void entAttributes::adjustCurrentStamina(int i){
	currentStamina = (currentStamina + i);
}

void entAttributes::getAll(int& str, int& intel, int& agi, int& dex, int& con, int& wil){
	str = strength;
	intel = intelligence;
	agi = agility;
	dex = dexterity;
	con = constitution;
	wil = will;
}
int entAttributes::getStrength(){
	return strength;
}
int entAttributes::getIntelligence(){
	return intelligence;
}
int entAttributes::getAgility(){
	return agility;
}
int entAttributes::getDexterity(){
	return dexterity;
}
int entAttributes::getConstitution(){
	return constitution;
}
int entAttributes::getWill(){
	return will;
}

int entAttributes::getCurrentHealth(){
	return currentHealth;
}
int entAttributes::getCurrentMana(){
	return currentMana;
}
int entAttributes::getCurrentStamina(){
	return currentStamina;
}
int entAttributes::getMaxHealth(){
	return maxHealth;
}
int entAttributes::getMaxMana(){
	return maxMana;
}
int entAttributes::getMaxStamina(){
	return maxStamina;
}

entAttributes::entAttributes(int* &list)
{
	strength = list[0];
	intelligence = list[1];
	agility = list[2];
	dexterity = list[3];
	constitution = list[4];
	will = list[5];
	currentHealth = 1;
	currentMana = 1;
	currentStamina = 1;
	maxHealth = 1;
	maxMana = 1;
	maxStamina = 1;
}

entAttributes::entAttributes(int str, int intel, int agi, int dex,
	int con, int wil, int hlth, int man, int stam)
{
	strength = str;
	intelligence = intel;
	agility = agi;
	dexterity = dex;
	constitution = con;
	will = wil;
	currentHealth = hlth;
	currentMana = man;
	currentStamina = stam;
	maxHealth = hlth;
	maxMana = man;
	maxStamina = stam;
}
