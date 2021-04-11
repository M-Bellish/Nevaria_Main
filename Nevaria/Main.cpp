#include <iostream>
#include <cstdlib>
#include <map>
#include <string>
#include <algorithm>
#include "entSkills.h"
#include "Constants.h"
#include "characterCreation.h"
//#include "Hub.cpp"
//#include "itemBaseClass.h"
//#include "itemArmor.h"
//#include "itemWeapon.h"
//#include "itemConsumable.h"
//#include "inventory.h"
//#include "Entity.h"
//#include "journal.h"

using namespace std;



//The output of the "help" option. Intentionally global
//so that it can be updated from any location in the program
//to hold the relevant options for the situation.
//string help;

int main() {
	bool exitFlag = true;
	
	//character creation input variables
	//player object variable
	
	//Create Player Dialogue
		//ask for name - DONE
		//explain stats - DONE
		//stat distribution loop - DONE
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

