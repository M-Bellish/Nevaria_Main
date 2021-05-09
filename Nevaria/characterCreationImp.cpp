#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <string>
#include <iomanip>
#include <algorithm>
#include <Windows.h>
#include <cwchar>
#include "Functions.h"
#include "Exceptions.h"
#include "Constants.h"
#include "Entity.h"
#include "characterCreation.h"

using namespace std;

//Global variables
string help;
int pointPool = 20;
int str = 10, intel = 10, agi = 10, dex = 10, con = 10, wil = 10;
int statArray[6] = { 10, 10, 10, 10, 10, 10 };
int *statPtr;
int skillPointPool = 3;
string selectedSkills[3]{" ", " ", " "};
int skillArray[3];
int *skillPtr;
int skillPos = 0;

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
		r_Pause();
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
		r_Pause();
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
					numChoice = stoi(choice);
					choice = "";
					valFlag = false;
				}
				else {
					for (int i = 0; i < choice.length(); i++) {
						if (isdigit(choice[i]) != 0 && i != (choice.length() - 1)) {
							continue;
						}
						else if (isdigit(choice[i]) != 0 && i == (choice.length() - 1)) {
							numChoice = stoi(choice);
							choice = "";
							valFlag = false;
						}
						else {
							numChoice = -1;
							valFlag = false;
							break;
						}
					}
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
				r_Pause();
			}
		}
		else if (isdigit(ch)) {
			numChoice = ch - '0';
			valFlag = false;
		}
		else {
			cout << "Invalid Input." << endl;
			r_Pause();
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
		r_Pause();
	}
	else if (tempChoice2 + stat < 10) {
		cout << "Stats can't be lower than 10!" << endl;
		r_Pause();
	}
	else if (tempChoice2 + stat > 18) {
		cout << "A stat can't start with more than 18 points!" << endl;
		r_Pause();
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
				skillArray[i] = numChoice;
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
	return -1;
}

//***************************************************************************************************
//Core function
//Gathers all inputs from user needed to create a character.
void characterCreation(entity* player) {
	//Global Function variables
	int tempChoice = -1;
	int skillChoice = -1;
	string varChoice;
	string charName = "";
	bool statFlag = true;
	bool skillFlag = true;
	clearScreen();

	//Name input block
	do {
		try {
			clearScreen();
			slow_Type("What is your name? ", false, ' ');
			getline(cin, charName);
			if (charName.length() > 20)
				tempChoice = 2;
			else {
				clearScreen();
				slow_Type("Your name is " + charName + ". Is that correct?", false, ' ');
				slow_Type("(0) No, I want to put in a different name.\n(1) Yes, Continue.", false, ' ');

				do {
					cin >> tempChoice;
				} while (checkChoice(tempChoice, 1));
			}

			switch (tempChoice) {
			case 0:
				throw backExcept();
			case 1:
				break;
			case 2:
				throw longNameExcept();
			}
		}
		catch (longNameExcept longObj) {
			charName = longObj.what();
			clearScreen();
		}
		catch (backExcept backObj) {
			cin.clear();
			cin.ignore(1, '\n');
			charName = backObj.what();
			clearScreen();
		}
	} while (charName == "");

	//Sets up and displays stat help screen.
	clearScreen();
	help = "Stat Explanations:\n\nStrength: Affects melee damage. Factors into max Health and Stamina. Determines max encumberance.\n\nIntelligence: Affects magic damage. Determines max Mana.\n\nAgility: Affects your chance to dodge and land critical hits. \nDexterity: Affects weapon accuracy and ranged weapon damage. \nConstitution: Affects physical damage resistance. Factors into max Health and Stamina.\n\nWill: Affects magical damage resistance and chance to critically hit with spells. Factors into max Stamina.\n\nStats can't be lower than 10 or higher than 18 to start with. Use a negative number to take points back from a stat e.g. -2.\nType in \"help\" to view this information again.\n";
	showHelp(help);
	clearScreen();

	//Stat point adjustment block
	do {
		tempChoice = 0;

		checkHelp(varChoice, tempChoice, 0, 6);

		switch (tempChoice) {
		case 0:
			statAdjust(str, pointPool);
			statArray[tempChoice] = str;
			break;
		case 1:
			statAdjust(intel, pointPool);
			statArray[tempChoice] = intel;
			break;
		case 2:
			statAdjust(agi, pointPool);
			statArray[tempChoice] = agi;
			break;
		case 3:
			statAdjust(dex, pointPool);
			statArray[tempChoice] = dex;
			break;
		case 4:
			statAdjust(con, pointPool);
			statArray[tempChoice] = con;
			break;
		case 5:
			statAdjust(wil, pointPool);
			statArray[tempChoice] = wil;
			break;
		case 6:
			if (pointPool != 0) {
				clearScreen();
				cout << "Not all points spent!" << endl;
				r_Pause();
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
	//End stat adjust block

	statPtr = statArray;

	//Sets up and displays skill help screen.
	clearScreen();
	help = "Overview: Skill levels range from 1 to 10. All skills start at level 1 except for preferred skills.\nYou will choose 3 preferred skills that start at level 4. They also gain experience slightly faster.\nSkills gain experience from use and unlock new attacks/abilities as their level increases.\n\nSkill Explanations:\n\nBlade - Your effectiveness with all sharp weapons, ranging from daggers to 2-handed swords.\n\nBlunt - Your effectiveness with 1 & 2-handed maces and hammers.\n\nAxe - Your effectiveness with 1 & 2-handed axes.\n\nMarksman - Your effectiveness with bows.\n\nDefence - Your ability to wear armor effectively and to avoid being hit. \n\nSpellcasting - The effectiveness of spells you cast.\n\nAlchemy - Your ability to craft potions & poisons.\n\nSmithing - Your ability to craft weapons & armor.\n\nEnchanting - Your ability to add magic effects to weapons & armor\n\nType in \"help\" to view this information again.\n\n";
	showHelp(help);
	clearScreen();

	//Preferred skill choice block
	do {
		tempChoice = 0;
		skillChoice = -1;

		checkHelp(varChoice, tempChoice, 1, 9);

		skillChoice = skillSelect(tempChoice);

		switch (skillChoice) {
		case 0:
			clearScreen();
			cout << skillList[tempChoice] << " was unselected." << endl;
			r_Pause();
			break;
		case 1:
			clearScreen();
			cout << skillList[tempChoice] << " was selected." << endl;
			r_Pause();
			break;
		case 2:
			clearScreen();
			cout << "Not all preferred skills selected!" << endl;
			r_Pause();
			break;
		case 3:
			clearScreen();
			tempChoice = -1;
			cout << "Selected Skills: [" << selectedSkills[0] << "] [" << selectedSkills[1] << "] [" << selectedSkills[2] << "]\n\n";
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
			catch (backExcept) {
				cin.clear();
				cin.ignore(1, '\n');
			}
			break;
		case 10:
			showHelp(help);
			break;
		default:
			break;
		}

	} while (skillFlag || skillPointPool != 0);
	//End skill choice block

	skillPtr = skillArray;

	clearScreen();

	player->create(charName, statPtr, skillPtr);

	cout << "Done!" << endl;

}