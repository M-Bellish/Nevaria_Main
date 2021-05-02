#ifndef H_Functions
#define H_Functions

#include <iostream>
#include <string>

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
	//system("clear");
	system("CLS");
}
//Stops the program until the user presses Enter.
//Used for anytime the user needs time to read the screen.
void pause() {
	string pause;
	do {
		cin.clear();
		cin.ignore(1, '\n');
		cout << "Press Enter to continue..." << endl;
		getline(cin, pause);
	} while (false);
}
//Displays the help screen currently stored in help.
void showHelp(string help) {
	clearScreen();
	cout << help << endl;
	pause();
}

#endif