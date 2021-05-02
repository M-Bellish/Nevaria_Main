//Chase Bell
//Text-Based Adventure RPG
//Title: "Nevaria"

#include <iostream>
#include <cstdlib>
#include <map>
#include <string>
#include <algorithm>
#include "Constants.h"
#include "entSkills.h"
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


int main() {
	bool exitFlag = true;
	
	//character creation input variables
	//player object variable
	
	//Create Player Dialogue
		//ask for name - DONE
		//explain stats - DONE
		//stat distribution loop - DONE
		//explain skills - DONE
		//skill select loop - DONE
		//initialize player object with input variables - 
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
