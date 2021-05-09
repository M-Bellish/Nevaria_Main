#include <iostream>
#include <string>

using namespace std;

void tavern() {
	int num;
	cout << "You arrive at the tavern. What do you do?" << endl;
	cout << "0(Go Back)  1()" << endl;
	cin >> num;

	switch (num) {
	case 0:
		break;
	default:
		break;
	}
}

void charSheet() {

}

//void journal() {
//
//}

void mageGuild() {
	int num;
	cout << "You arrive at the tavern. What do you do?" << endl;
	cout << "0(Go Back)  1()" << endl;
	cin >> num;

	switch (num) {
	case 0:
		break;
	default:
		break;
	}
}

void advGuild() {
	int num;
	cout << "You arrive at the tavern. What do you do?" << endl;
	cout << "0(Go Back)  1()" << endl;
	cin >> num;

	switch (num) {
	case 0:
		break;
	default:
		cout << "Invalid Input." << endl;
	}
}

void arena() {
	int num;
	cout << "You arrive at the tavern. What do you do?" << endl;
	cout << "0(Go Back)  1()" << endl;
	cin >> num;

	switch (num) {
	case 0:
		break;
	default:
		cout << "Invalid Input." << endl;
	}
}

void home() {
	int num;
	cout << "You arrive at the tavern. What do you do?" << endl;
	cout << "0(Go Back)  1()" << endl;
	cin >> num;

	switch (num) {
	case 0:
		break;
	default:
		cout << "Invalid Input." << endl;
	}
}

void leaveTown() {
	int num;
	cout << "You arrive at the tavern. What do you do?" << endl;
	cout << "0(Go Back)  1()" << endl;
	cin >> num;

	switch (num) {
	case 0:
		break;
	default:
		cout << "Invalid Input." << endl;
	}
}

void merchWeapon() {
	int num;
	cout << "" << endl;
	cout << "0()  1()" << endl;
	cin >> num;

	switch (num) {
	case 0:
		break;
	default:
		cout << "Invalid Input." << endl;
	}
}

void merchArmor() {
	int num;
	cout << "" << endl;
	cout << "0()  1()" << endl;
	cin >> num;

	switch (num) {
	case 0:
		break;
	default:
		cout << "Invalid Input." << endl;
	}
}

void merchPotion() {
	int num;
	cout << "" << endl;
	cout << "0()  1()" << endl;
	cin >> num;

	switch (num) {
	case 0:
		break;
	default:
		cout << "Invalid Input." << endl;
	}
}

void merchMaterials() {
	int num;
	cout << "" << endl;
	cout << "0()  1()" << endl;
	cin >> num;

	switch (num) {
	case 0:

	default:
		cout << "Invalid Input." << endl;
	}
}

void merchant() {
	int num;
	cout << "Welcome, what are you looking for?" << endl;
	cout << "0(Go Back)  1(Weapons)  2(Armor)  3(Potions)  4(Crafting Materials)" << endl;
	cin >> num;

	switch (num) {
	case 0:
		break;
	case 1:
		merchWeapon();
		break;
	case 2:
		merchArmor();
		break;
	case 3:
		merchPotion();
		break;
	case 4:
		merchMaterials();
		break;
	}
}

bool hub(int location) {

	switch (location) {
	case 0: //Exit Game
		return false;
	case 1: //Character Sheet
		charSheet();
		break;
		//case 2: //Journal
		//	journal();
		//	break;
	case 3: //Tavern
		tavern();
		break;
	case 4: //Merchant
		merchant();
		break;
	case 5: //Mage's Guild
		mageGuild();
		break;
	case 6: //Adventurer's Guild
		advGuild();
		break;
	case 7: //Arena
		arena();
		break;
	case 8: //Tavern
		tavern();
		break;
	case 9: //Leave town
		leaveTown();
		break;
	default:
		cout << "Can't find that location." << endl;
	}
	return true;
}

