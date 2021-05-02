#ifndef H_Functions
#define H_Functions

#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <string.h>
#include <unistd.h>
#include <cctype>

using namespace std;

//Universal exception for going back within a menu.
class backExcept {
public:
	backExcept() {
		message = "";
	}
	backExcept(string str) {
		message = str;
	}
	string what() {
		return message;
	}
private:
	string message;
};

//Used to clear the screen
//Primarily used for easily switching between the
//clear screen functions for Windows Terminal & Bash.
void clearScreen() {
	system("clear");
	//system("CLS");
}
//Stops the program until the user presses Enter.
//Used for anytime the user needs time to read the screen.
void r_Pause() {
	string r_Pause;
	do {
		cin.clear();
		cin.ignore(1, '\n');
		cout << "Press Enter to continue..." << endl;
		getline(cin, r_Pause);
	} while (false);
}

void slow_Type(string temp, bool fillSpace = false, char fill = ' ') {
	int len = temp.length();
	int count;
	bool lastWasSpace = false;

	for (int i = 0, count = 0; i < len; i++, count++) {
		if (isspace(temp[i]) && lastWasSpace){count = 0;}
		else if (count >= 60 && isspace(temp[i])){cout << endl; cout.flush(); count = 0; lastWasSpace = true;}
		
		if (fillSpace == true && isspace(temp[i])) {temp[i] = fill;}

		cout << setw(1) << temp[i];
		cout.flush();
		usleep(10000);
		lastWasSpace = isspace(temp[i]);
	}
	cout << endl;
}

//Displays the help screen currently stored in help.
void showHelp(string help) {
	clearScreen();
	slow_Type(help);
	cout << endl;
	r_Pause();
}

#endif