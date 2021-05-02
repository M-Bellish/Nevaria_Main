#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include "Constants.h"
#include "characterCreation.h"

using namespace std;

//
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
//
class longNameExcept {
public:
	longNameExcept() {
		message = "Name entered is too long. Limit of name length is 20 characters";
	}
	longNameExcept(string str) {
		message = str;
	}
	string what() {
		return message;
	}
private:
	string message;
};
//
class ExitExcept {
};

//*********************************************************************************************

string help;
int pointPool = 16;
int str = 10, intel = 10, agi = 10, dex = 10, con = 10, wil = 10;
int skillPointPool = 3;
string selectedSkills[3]{" ", " ", " "};
int skillPos = 0;

using namespace std;

//Displays screen for distributing stats.
void statScreen() {
	cout << "Points Remaining: " << pointPool << endl << endl;
	cout << "(0) Strength: " << str << "\n(1) Intelligence: " << intel << "\n(2) Agility: " << agi << "\n(3) Dexterity: " << dex << "\n(4) Constitution: " << con << "\n(5) Will: " << wil << "\n(6) Ready to continue.\n" << endl;
}

//Displays screen for selecting prefered skills.
void skillScreen() {
	cout << "Skills Remaining: " << skillPointPool << endl;
	cout << "Selected Skills: [" << selectedSkills[0] << "] [" << selectedSkills[1] << "] [" << selectedSkills[2] << "]" << endl;
	cout << "(0) Blade\n(1) Blunt\n(2) Axe\n(3) Marksman\n(4) Defence\n(5) Spellcasting\n(6) Alchemy\n(7) Smithing\n(8) Enchanting\n(9) Ready to continue.\n" << endl;
}

//Used to verify standard number inputs.
bool checkChoice(int& input, int maxValid) {
	if (input == 10)
		return false;
	else if (input > maxValid || input < 0) {
		cout << "Invalid Input. Enter a valid option." << endl;
		pause();
		clearScreen();
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
void checkHelp(string& choice, int& numChoice, int statOrSkill, int validOptionCount) {
	char ch = 0;
	bool valFlag = true;
	
	do {
		do {
			clearScreen();
			if (statOrSkill == 0) {
				statScreen();
				cout << "Input the stat to adjust: ";
			}
			else {
				skillScreen();
				cout << "Input the skill to select: ";
			}
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
	} while (checkChoice(numChoice, validOptionCount));
}

//Evaluates input to ensure it won't break anything.
//Inputs that are invalid but harmless are still
//passed and handled by statAdjust.
void statAdjustCheck(string& choice, int& numChoice) {
	bool valFlag = true;
	char ch;

	do {
		cin.clear();
		clearScreen();
		statScreen();			
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

//Checks if stat will remain within starting limitations
//and adjusts stat if within limits and points are available.
void statAdjust(int& stat, int& points) {
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

//Checks if skill is already on list, adds it to selectedSkills if not on
//list and empty slot available. Removes skill from list if already on list.
int skillSelect(int numChoice) {
	if (numChoice == 10)
		return numChoice;
	else if (numChoice == 9 && skillPointPool > 0)
		return 2;
	else if (numChoice == 9 && skillPointPool == 0)
		return 3;

	for (int i = 2; i > -1; i--) {
		if (selectedSkills[i] == " ")
			skillPos = i;
	}

	if (numChoice <= 8) {
		for (int i = 0; i < 3; i++) {
			if (selectedSkills[i] == skillList[numChoice]) {
				skillPos = i;
				selectedSkills[i] = " ";
				skillPointPool++;
				return 0;
			}
		}

		if (skillPointPool > 0) {
			selectedSkills[skillPos] = skillList[numChoice];
			skillPointPool--;
			return 1;
		}
	}

}

//
void characterCreation() {
	int tempChoice = -1;
	int skillChoice = -1;
	string varChoice;
	string charName = "";
	bool statFlag = true;
	bool skillFlag = true;

	do {
		try {
			cout << "What is your name? " << endl;
			getline(cin, charName);
			if (charName.length() > 20)
				throw longNameExcept();
			clearScreen();
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
		catch (longNameExcept longObj) {
			charName = "";
			cout << longObj.what() << endl;
		}
		catch (backExcept backObj) {
			cin.clear();
			cin.ignore(1, '\n');
			charName = backObj.what();
			clearScreen();
		}
	} while (charName == "");

	clearScreen();
	help = "Stat Explanations: \n\nStrength - Affects melee damage. Factors into max Health and Stamina. Determines max encumberance. \n\nIntelligence - Affects magic damage. Determines max Mana. \n\nAgility - Affects your chance to dodge and land critical hits. \n\nDexterity - Affects weapon accuracy and ranged weapon damage. \n\nConstitution - Affects physical damage resistance. Factors into max Health and Stamina. \n\nWill - Affects magical damage resistance and chance to critically hit with spells. Factors into max Stamina.\n\nStats can't be lower than 10 or higher than 18 to start with.\nUse a negative number to take points back from a stat e.g. -2.\n\nType in \"help\" to view this information again.\n\n";
	showHelp(help);
	clearScreen();

	do {
		tempChoice = 0;

		checkHelp(varChoice, tempChoice, 0, 6);

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


	clearScreen();
	help = "Skill Explanations:\n\nBlade - Your effectiveness with sharp weapons from daggers to 2-handed swords.\n\nBlunt - Your effectiveness with 1 & 2-handed maces and hammers.\n\nAxe - Your effectiveness with 1 & 2-handed axes.\n\nMarksman - Your effectiveness with bows.\n\nDefence - Your ability to wear armor effectively and to avoid being hit. \n\nSpellcasting - The effectiveness of spells you cast.\n\nAlchemy - Your ability to craft potions & poisons.\n\nSmithing - Your ability to craft weapons & armor.\n\nEnchanting - Your ability to add magic effects to weapons & armor\n\nType in \"help\" to view this information again.\n\n";
	showHelp(help);
	clearScreen();

	do {
		tempChoice = 0;
		skillChoice = -1;

		checkHelp(varChoice, tempChoice, 1, 9);

		skillChoice = skillSelect(tempChoice);

		switch (skillChoice) {
		case 0:
			cout << skillList[tempChoice] << " was unselected." << endl;
			pause();
			break;
		case 1:
			cout << skillList[tempChoice] << " was selected." << endl;
			pause();
			break;
		case 2:
			cout << "Not all preferred skills selected!" << endl;
			pause();
			break;
		case 3:
			tempChoice = -1;
			cout << "Are you sure?\n(0) No\n(1) Yes" << endl;
			try {
				do {
					cin >> tempChoice;
				} while (checkChoice(tempChoice, 1));

				switch (tempChoice) {
				case 0:
					throw backExcept();
					break;
				case 1:
					skillFlag = false;
					break;
				}
			}
			catch (backExcept backObj) {
				cin.clear();
				cin.ignore(1, '\n');
				clearScreen();
			}
			break;
		case 10:
			showHelp(help);
			break;
		default:
			break;
		}

	} while (skillFlag || skillPointPool != 0);

	cout << "Done!" << endl;

}