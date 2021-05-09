#ifndef H_characterCreation
#define H_characterCreation

#include <iostream>
#include <cstdlib>
#include <string>
#include "Entity.h"

using namespace std;


void statScreen();
void skillScreen();
bool checkChoice(int& input, int maxValid);
bool checkChoice(string& choice, int& numChoice);
void checkHelp(string& choice, int& numChoice, int statOrSkill, int validOptionCount);
void statAdjustCheck(string& choice, int& numChoice);
void statAdjust(int& stat, int& points);
int skillSelect(int numChoice);
void characterCreation(entity* player);



#endif
