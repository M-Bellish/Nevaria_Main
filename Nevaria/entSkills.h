#ifndef H_entSkills
#define H_entSkills

using namespace std;

#include "Constants.h"

class entSkills{
	public:
		//Gets current skill level of skill name passed to it.
		int getSkillLevel(string);
		//Calculate amount of experience to add to a skill.
		int calcSkillExp(string);

		//
		void gainSkillExp(string);
		void skillUpCheck(int);

	//Constructors
		entSkills(int[3]);
		entSkills(int, int, int, int, int, int);

	private:
		int level;

		//Key pair list of skill names and current level.
		//Current level can be gotten by slicing the map.
		//Example: skillLevels["blade"]
		map<string, int> skillLevels;

		//List of Player's experience in each skill. Aligns with skillList indexes and is init to 0 for each skill.
		int entSkillExp[9];
};

#endif