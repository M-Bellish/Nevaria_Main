#include <iostream>
#include <cstdlib>
#include <map>
#include <string>
#include "entSkills.h"
#include "Constants.h"
//#include "Hub.cpp"
//#include "itemBaseClass.h"
//#include "itemArmor.h"
//#include "itemWeapon.h"
//#include "itemConsumable.h"
//#include "inventory.h"
//#include "Entity.h"
//#include "journal.h"

using namespace std;

class backExcept {
};
class longStringExcept {
};
class ExitExcept {
};
void characterCreation();


int main() {
	bool exitFlag = false;
	string help;
	//character creation input variables
	//player object variable
	
	//Create Player Dialogue
		//ask for name
		//explain stats
		//stat distribution loop
		//explain skills
		//skill sellect loop
		//initialize player object with input variables
		//end character creation
	characterCreation();

	//explain "help" function
	//pause
	//list town options
	// while (exitFlag != true) 
	// {

	// 	int location;
	// 	cin >> location;
	// 	hub(location);

	// } 

	return 0;
}


bool checkChoice(int input, int maxValid) {
	if (input > maxValid || input < 0) {
		cout << "Input invalid. Enter a valid option." << endl;
		return true;
	}
	return false;
}

void pause() {
	string pause;
	do {
		cin.clear();
		cin.ignore(1, '\n');
		cout << "Press Enter to continue..." << endl;
  	getline(cin, pause);
	}
	while (false);
}

void statAdjust(int &stat, int &points) {
	int tempChoice2 = 0;

	cout << "Input how many points to add/take: ";
	cin >> tempChoice2;

	if (tempChoice2 > points || tempChoice2 + stat < 10 || tempChoice2 > points) {
		cout << "Invalid Input." << endl;
		pause();
	}
	else if (tempChoice2 + stat > 18) {
		cout << "A stat can't start with more than 18 points." << endl;
		pause();
	}
	else {
		stat = stat + tempChoice2;
		points = points - tempChoice2;
	}
}

void statChoiceCheck(int &choice) {
	do {
	cout << "Input the stat to adjust: ";
	cin >> choice;
	} while (checkChoice(choice, 6));
}

using namespace std;

void characterCreation() {
	int tempChoice;
	int pointPool = 16;
	int str = 10, intel = 10, agi = 10, dex = 10, con = 10, wil = 10;
	int skill1, skill2, skill3;
	string charName = "";
	bool statFlag = true;
	bool skillFlag = false;

	do {
		try {
			cout << "What is your name? " << endl;
			getline(cin, charName);
			if (charName.length() > 20)
				throw longStringExcept();
			cout << "Your name is " << charName << ". Is that correct?" << endl;
			cout << "(0) No, I want to put in a different name.\n(1) Yes, Continue." << endl;

			do {
				cin >> tempChoice;
			}
			while (checkChoice(tempChoice, 1));

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
			system("clear");//Linux
			//system("CLS");//Windows
		}
	}
	while (charName == "");

	system("clear");
	//system("CLS");

	cout << "Stats: \n\nStrength - Affects melee damage. Factors into max Health and Stamina. Determines max encumberance. \n\nIntelligence - Affects magic damage. Determines max Mana. \n\nAgility - Affects your chance to dodge and land critical hits. \n\nDexterity - Affects weapon accuracy and ranged weapon damage. \n\nConstitution - Affects physical damage resistance. Factors into max Health and Stamina. \n\nWill - Affects magical damage resistance and chance to critically hit with spells. Factors into max Stamina.\n" << endl;

	pause();

	do {
		tempChoice = 0;
		system("clear");
		//system("CLS");
		cout << "Points Remaining: " << pointPool << endl;
		cout << "(0) Strength: " << str << "\n(1) Intelligence: " << intel << "\n(2) Agility: " << agi << "\n(3) Dexterity: " << dex << "\n(4) Constitution: " << con << "\n(5) Will: " << wil << "\n(6) Ready to continue." << endl;

	statChoiceCheck(tempChoice);

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
	}

	}	while (statFlag || pointPool != 0);

	cout << "Done!" << endl;

}