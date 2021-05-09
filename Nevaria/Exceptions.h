#ifndef H_Exceptions
#define H_Exceptions

#include <iostream>
#include <string>
#include "Functions.h"

//Universal exception for going back within a menu, either 
//by choice or due to an invalid input.
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

//Exception for preventing excessively long names.
class longNameExcept {
public:
	longNameExcept() {
		message = "Name entered is too long. Limit of name length is 20 characters.";
	}
	longNameExcept(string str) {
		message = str;
	}
	string what() {
		string r_Pause;
		clearScreen();
		do {
			message = "Name entered is too long. Limit of name length is 20 characters\n\nPress Enter to continue...";
			std::cout << message << endl;
			getline(cin, r_Pause);
		} while (false);
		return "";
	}
private:
	string message;
};


#endif