#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include "Constants.h"
#include "characterCreation.h"

using namespace std;

class backExcept {
};
class longStringExcept {
};
class ExitExcept {
};

//*********************************************************************************************

string help;
int pointPool = 16;
int str = 10, intel = 10, agi = 10, dex = 10, con = 10, wil = 10;

void statScreen(int pointsLeft, int str, int intel, int agi, int dex, int con, int wil) {
	cout << "Points Remaining: " << pointsLeft << endl << endl;
	cout << "(0) Strength: " << str << "\n(1) Intelligence: " << intel << "\n(2) Agility: " << agi << "\n(3) Dexterity: " << dex << "\n(4) Constitution: " << con << "\n(5) Will: " << wil << "\n(6) Ready to continue.\n" << endl;
}

//Used to verify standard number inputs.
bool checkChoice(int& input, int maxValid) {
	if (input == 10)
		return false;
	else if (input > maxValid || input < 0) {
		cout << "Invalid Input. Enter a valid option." << endl;
		pause();
		system("clear");
		return true;
	}
	else
		return false;
}

//Used to verify "help" input.
bool checkChoice(string& choice, int& numChoice) {
	transform(choice.begin(), choice.end(), choice.begin(), ::tolower);

	if (choice != "help") {
		choice = "";
		cout << "Invalid Input." << endl;
		pause();
		return true;
	}
	else {
		numChoice = 10;
		choice = "";
		return false;
	}
}

//Checks if the input was an int or a string.
//Used at any choice branch where the "help" command might be entered.
void checkHelp(string& choice, int& numChoice) {
	char ch = 0;
	bool valFlag = true;
	
	do {
		do {
			//system("CLS");
			system("clear");
			statScreen(pointPool, str, intel, agi, dex, con, wil);
			cout << "Input the stat to adjust: ";
			cin >> choice;
			ch = choice[0];

			if (isdigit(ch) != 0) {
				if (choice.length() == 1) {
					numChoice = ch - '0';
					choice = "";
					valFlag = false;
				}
				else {
					numChoice = -1;
					valFlag = false;
				}
			}
			else if (isalpha(ch))
				valFlag = checkChoice(choice, numChoice);
			else {
				numChoice = -1;
				valFlag = false;
			}
		} while (valFlag);
	} while (checkChoice(numChoice, 6));
}

//Evaluates input to ensure it won't break anything.
//Inputs that are invalid but harmless are still
//passed and handled by statAdjust.
void statAdjustCheck(string& choice, int& numChoice) {
	bool valFlag = true;
	char ch;

	do {
		cin.clear();
		//system("CLS");
		system("clear");
		statScreen(pointPool, str, intel, agi, dex, con, wil);			
		cout << "Input how many points to add/remove: ";
		cin >> choice;
		ch = choice[0];
		if (choice.length() > 1) {
			if ((ch == '-' && isdigit(choice[1]))) {
				numChoice = (0 - (choice[1] - '0'));
				valFlag = false;
			}
			else if (isalpha(ch)) {
				if (checkChoice(choice, numChoice) == false) {
					showHelp(help);
				}
			}
			else {
				cout << "Invalid Input." << endl;
				pause();
			}
		}
		else if (isdigit(ch)) {
			numChoice = ch - '0';
			valFlag = false;
		}
		else {
			cout << "Invalid Input." << endl;
			pause();
		}
	} while (valFlag);
}

//
void statAdjust(int& stat, int& points) {
	bool valFlag = true;
	string varChoice2 = "";
	int tempChoice2 = 0;

	statAdjustCheck(varChoice2, tempChoice2);

	if (tempChoice2 > points) {
		cout << "You don't have that many points left to spend!" << endl;
		pause();
	}
	else if (tempChoice2 + stat < 10) {
		cout << "Stats can't be lower than 10!" << endl;
		pause();
	}
	else if (tempChoice2 + stat > 18) {
		cout << "A stat can't start with more than 18 points!" << endl;
		pause();
	}
	else {
		stat = stat + tempChoice2;
		points = points - tempChoice2;
	}
}

//
void characterCreation() {
	int tempChoice = -1;
	string varChoice;
	//	int skill1, skill2, skill3;
	string charName = "";
	bool statFlag = true;
	bool skillFlag = false;

	do {
		try {
			cout << "What is your name? " << endl;
			getline(cin, charName);
			if (charName.length() > 20)
				throw longStringExcept();
			system("clear");
			//system("CLS");
			cout << "Your name is " << charName << ". Is that correct?" << endl;
			cout << "(0) No, I want to put in a different name.\n(1) Yes, Continue." << endl;

			do {
				cin >> tempChoice;
			} while (checkChoice(tempChoice, 1));

			switch (tempChoice) {
			case 0:
				throw backExcept();
			case 1:
				break;
			}
		}
		catch (longStringExcept) {
			charName = "";
			cout << "Name entered is too long." << endl;
		}
		catch (backExcept) {
			cin.clear();
			cin.ignore(1, '\n');
			charName = "";
			//Linux
			system("clear");
			//Windows
			//system("CLS");
		}
	} while (charName == "");

	system("clear");
	//system("CLS");
	help = "Stat Explanations: \n\nStrength - Affects melee damage. Factors into max Health and Stamina. Determines max encumberance. \n\nIntelligence - Affects magic damage. Determines max Mana. \n\nAgility - Affects your chance to dodge and land critical hits. \n\nDexterity - Affects weapon accuracy and ranged weapon damage. \n\nConstitution - Affects physical damage resistance. Factors into max Health and Stamina. \n\nWill - Affects magical damage resistance and chance to critically hit with spells. Factors into max Stamina.\n\nStats can't be lower than 10 or higher than 18 to start with.\nUse a negative number to take points back from a stat e.g. -2.";
	showHelp(help);
	system("clear");
	//system("CLS");

	do {
		tempChoice = 0;

		checkHelp(varChoice, tempChoice);

		switch (tempChoice) {
		case 0:
			statAdjust(str, pointPool);
			break;
		case 1:
			statAdjust(intel, pointPool);
			break;
		case 2:
			statAdjust(agi, pointPool);
			break;
		case 3:
			statAdjust(dex, pointPool);
			break;
		case 4:
			statAdjust(con, pointPool);
			break;
		case 5:
			statAdjust(wil, pointPool);
			break;
		case 6:
			if (pointPool != 0) {
				cout << "Not all points spent!" << endl;
				pause();
				break;
			}
			else if (pointPool == 0) {
				statFlag = false;
				break;
			}
		case 10:
			showHelp(help);
			break;
		default:
			break;
		}

	} while (statFlag || pointPool != 0);

	cout << "Done!" << endl;

}