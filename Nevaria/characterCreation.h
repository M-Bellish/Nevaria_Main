#ifndef H_characterCreation
#define H_characterCreation

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

void pause();
void showHelp();
void statScreen(int pointPool, int str, int intel, int agi, int dex, int con, int wil);
bool checkChoice(int& input, int maxValid);
bool checkChoice(string& choice, int& numChoice);
void checkHelp(string& choice, int& numChoice);
void statAdjustCheck(string& choice, int& numChoice);
void statAdjust(int& stat, int& points);
void characterCreation();

#endif
