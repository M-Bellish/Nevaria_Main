//Chase Bell
//Text-Based Adventure RPG
//Title: "Nevaria"

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include "characterCreation.h"
#include "Functions.h"
#include "Screens.h"
//#include "Hub.h"
#include "itemClassVirtual.h"
#include "itemArmor.h"
//#include "itemWeapon.h"
//#include "itemConsumable.h"
#include "entInventory.h"
#include "Entity.h"
//#include "journal.h"

using namespace std;

//bool goToLocation();


int main() {
	entity* player;
	player = new entity();
	int menuNum;
	bool exitFlag = true;

	//Formats screen
	screenSetup();
	//Displays Title screen and main menu.
	menuNum = titleScreen();

	//Menu switch
	switch (menuNum) {
		case 0:
			characterCreation(player);
			break;
		//case 1:
		//	break;
		//case 2:
		//	break;
		default:
			break;
	}


	//if (player->getName() != "") {
	//	do {
	//		exitFlag = goToLocation();
	//	} while (exitFlag);
	//}

	return 0;
}



//Displays the hub screen
//bool goToLocation() {
//
//	bool exitFlag = true;
//	int tempChoice;
//	bool valFlag;
//
//	do {
//		try {
//			hubScreen();
//			do {
//				cin >> tempChoice;
//				cin.clear();
//				cin.ignore(1, '\n');
//				valFlag = checkChoice(tempChoice, 9);
//				if (valFlag)
//					throw backExcept();
//			} while (checkChoice(tempChoice, 9));
//
//			exitFlag = hub(tempChoice);
//		}
//		catch (backExcept backObj) {
//			cin.clear();
//			cin.ignore(1, '\n');
//			cout << "Invalid Input.";
//			Sleep(1000);
//			clearScreen();
//			hubScreen();
//		}
//	} while (valFlag);
//
//	return exitFlag;
//}