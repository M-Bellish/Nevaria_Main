#ifndef H_Screens
#define H_Screens

//#define _WIN32_WINNT 0x0500

#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <string>
#include <iomanip>
#include <algorithm>
#include <Windows.h>
#include <cwchar>
#include <ctime>
#include "characterCreation.h"
#include "Functions.h"
#include "Exceptions.h"

using namespace std;

int titleScreen();
void refreshTitle();
int titleChoiceHandler();


void screenSetup() {
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;
	cfi.dwFontSize.Y = 22;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	wcscpy_s(cfi.FaceName, L"Consolas");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), false, &cfi);

	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);

	MoveWindow(console, r.left, r.top, 80, 100, true);
	for (int j = 0; j < 100; ++j)
	{
		for (int i = 0x41; i < 0x5B; ++i)
			cout << (char)i;
	}
	cout << endl;
	MoveWindow(console, r.left, r.top, r.right - r.left, r.bottom - r.top, true);
	clearScreen();
}


//Creates title screen upon program startup.
int titleScreen() {

	int menuChoice;

	system("Color 0C");
	cout << setfill('#') << setw(80) << "\n"; cout.flush();
	slow_Type("        *  \\  |  * ____|  \\ \\     /   * \\      *  _\\   *_ _|     * \\   ", true, ' ');
	slow_Type("        *   \\ |  * __|     \\ \\   /   * _ \\    *  |  |    *|     * _ \\  ", true, ' ');
	slow_Type("        * |\\  |  * |        \\ \\ /   * ___ \\   *  __<     *|    * ___ \\ ", true, ' ');
	slow_Type("        *_| \\_|  *_____|     \\_/   *_/    _\\  *_| \\_\\  *_ _|  *_/    _\\", true, ' ');
	cout << setfill('#') << setw(80) << "\n"; cout.flush();
	cout << "\n\n\n";

	cout << setfill(' ') << setw(5) << " ";
	slow_Type("Welcome to Nevaria... Enter the number next to an option to select it.", true, ' '); cout << endl;

	cout << setfill(' ') << setw(20) << " ";
	slow_Type("(0) Create Character", true, ' '); cout << endl;
	cout << setfill(' ') << setw(20) << " ";
	slow_Type("(1) Load Character *UNDER CONSTRUCTION*", true, ' '); cout << endl;
	cout << setfill(' ') << setw(20) << " ";

	menuChoice = titleChoiceHandler();

	return menuChoice;
}

//Handles title screen option selection.
int titleChoiceHandler() {

	int tempChoice;
	bool valFlag = true;

	do {
		try {
			
			do {
				cin >> tempChoice;
				cin.clear();
				cin.ignore(1, '\n');
			} while (checkChoice(tempChoice, 1));

			switch (tempChoice) {
			case 0:
				valFlag = false;
				break;
			//case 1:
			//	valFlag = false;
			//	break;
			//case 2:
			//	valFlag = false;
			//	break;
			default:
				throw backExcept();
				break;
			}
		}
		catch (backExcept backObj) {
			cin.clear();
			cin.ignore(1, '\n');
			cout << setfill(' ') << setw(20) << " ";
			cout << "Invalid Input.";
			Sleep(1000);
			refreshTitle();
		}
	} while (valFlag);

	return tempChoice;
}

void refreshTitle() {
	clearScreen();
	cout << setfill('#') << setw(80) << "\n"; cout.flush();
	cout << "        *  \\  |  * ____|  \\ \\     /   * \\      *  _\\   *_ _|     * \\   " << "\n";
	cout << "        *   \\ |  * __|     \\ \\   /   * _ \\    *  |  |    *|     * _ \\  " << "\n";
	cout << "        * |\\  |  * |        \\ \\ /   * ___ \\   *  __<     *|    * ___ \\ " << "\n";
	cout << "        *_| \\_|  *_____|     \\_/   *_/    _\\  *_| \\_\\  *_ _|  *_/    _\\" << "\n";
	cout << setfill('#') << setw(80) << "\n"; cout.flush();
	cout << "\n\n\n";
	cout << setfill(' ') << setw(5) << " ";
	cout << "Welcome to Nevaria... Enter the number next to an option to select it.\n\n";
	cout << setfill(' ') << setw(20) << ' ';
	cout << "(0) Create Character\n\n";
	cout << setfill(' ') << setw(20) << ' ';
	cout << "(1) Load Character *UNDER CONSTRUCTION*\n\n";
	cout << setfill(' ') << setw(20) << " ";
	//cout << "(2) Instructions *UNDER CONSTRUCTION*"; cout << endl;
}


void combatScreen() {

}


void hubScreen() {

	cout << "What would you like to do?\n(0) EXIT GAME\n\n(1)Check Character Sheet\n(2)\n(3)\n(4)\n(5)\n(6)\n(7)\n(8)\n(9)\n" << endl;


}

void mapScreen() {

}



#endif