#include <iostream>
#include <stdlib.h>
#include <string>
#include <map>
#include "entSkills.h"
#include "Constants.h"

using namespace std;

int entSkills::getSkillLevel(string skillName) {
	return skillLevels[skillName];
}

int entSkills::calcSkillExp(string) {
	return 1;//placeholder for algorithm
}

void entSkills::gainSkillExp(string skillName) {
	int tempIndex = (skillLevels[skillName]);
	entSkillExp[tempIndex] = (entSkillExp[tempIndex] + calcSkillExp(skillName));
	skillUpCheck(tempIndex);
}

void entSkills::skillUpCheck(int index) {
	int overExpHolder = 0;

	if (entSkillExp[index] >= skillExpLevelList[index])
	{
		//Calculates and stores any experience gained over the requirement.
		overExpHolder = (entSkillExp[index] % skillExpLevelList[index]);
		//Sets the experience for the given skill to the amount over reqirement.
		entSkillExp[index] = overExpHolder;
		//Raises given skill level by 1.
		skillLevels[skillList[index]]++;
	}	
}

entSkills::entSkills(int index[3])
{
	for (int i = 0; i < 9; i++)
		skillLevels[skillList[i]] = 1;

	for (int i = 0; i < 3; i++)
		skillLevels[skillList[index[i]]] = 4;

	level = 1;

	entSkillExp[8] = {};
}

entSkills::entSkills(int sk1, int sk2, int sk3, int sk4, int sk5, int sk6)
{
	skillLevels[skillList[0]] = sk1;
	skillLevels[skillList[1]] = sk2;
	skillLevels[skillList[2]] = sk3;
	skillLevels[skillList[3]] = sk4;
	skillLevels[skillList[4]] = sk5;
	skillLevels[skillList[5]] = sk6;

	level = 1;

	entSkillExp[8] = {};
}