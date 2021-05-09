#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <string>
#include <ctime>
#include <Windows.h>
#include "Functions.h"


using namespace std;

//Used to clear the screen
//Primarily used for easily switching between the
//clear screen functions for Windows Terminal & Bash.
void clearScreen() {
	//system("clear");
	std::system("CLS");
}

//Stops the program until the user presses Enter.
//Used for anytime the user needs time to read the screen.
void r_Pause() {
	string r_Pause;
	do {

		cin.clear();
		std::cout << "Press Enter to continue..." << endl;
		getline(cin, r_Pause);
		cin.ignore(1, '\n');
	} while (false);
}

//Purely aesthetic. Forces characters in a given string to be printed individually.
//Gives it a "gamey" feel.
void slow_Type(string temp, bool fillSpace = false, char fill = ' ') {
	size_t len = temp.length();
	bool lastWasSpace = false;


	for (int i = 0, count = 0; i < len; i++, count++) {
		if (isspace(temp[i]) && lastWasSpace) { count = 0; }
		else if (count >= 80 && isspace(temp[i])) { std::cout << endl; std::cout.flush(); count = 0; lastWasSpace = true; }

		if (fillSpace == true && isspace(temp[i])) { temp[i] = fill; }

		std::cout << setw(1) << temp[i];
		std::cout.flush();
		Sleep(4);
		lastWasSpace = isspace(temp[i]);
	}
	std::cout << endl;
}

//Displays the help screen using the string currently stored in help and then pauses.
void showHelp(string help) {
	clearScreen();
	slow_Type(help);
	std::cout << endl;
	r_Pause();
}
