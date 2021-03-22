// #ifndef H_Entity
// #define H_Entity

// class entity {
// 	public:
// 		void rest();
// 		void craft();
// 		void journal();
// 		void adjustMoney(int);

// 		int meleeAttack();
// 		int magicAttack();
// 		int getDefense();
// 		int getAfflictions();

// 		//entity(string, inventory, attributes, skills)

// 	private:
// 		string myName;
// 		inventory myInv;
// 		attributes myStats;
// 		skills mySkills;
// 		int afflictions;
// 		int afflictionsTurnsLeft;
// 		int buffs;
// 		int money;

// };

// #endif


// // class charStats
// // {
// // public:
// // 	void setAll(int, int, int, int, int, int);
// // 	void setStrength(int);
// // 	void setIntelligence(int);
// // 	void setAgility(int);
// // 	void setDexterity(int);
// // 	void setConstitution(int);
// // 	void setWill(int);
// // 		//Functions for setting initial stat values
// // 		//and increasing the stat when player levels up.

// // 	void getAll(int &strength, int &intelligence, int &agility, int &dexterity, int &constitution, int &will);
// // 	int getStrength();
// // 	int getIntelligence();
// // 	int getAgility();
// // 	int getDexterity();
// // 	int getConstitution();
// // 	int getWill();
// // 		//Functions for getting current value of a character's attributes.
// // 		//Used for displaying character sheet and algorithm calculations.

// // 	charStats();

// // private:
// // 	int strength; 
// // 		//Affects melee dmg & ranged dmg to a lesser degree and max encumberance.
// // 	int intelligence;
// // 		//Affects magic dmg and max mana.
// // 	int agility;
// // 		//Affects dodge chance, crit chance, and
// // 		//chance to avoid detection when sneaking.
// // 	int dexterity;
// // 		//Affects hit chance with all weapons, crit chance, and ranged damage.
// // 	int constitution;
// // 		//Affects max health & stamina and adds to base dmg resistance.
// // 	int will;
// // 		//Affects stamina & magic crit chance and adds to magic resistance chance.
// // 	//***Character's primary attributes.***
// // };

// // 

// // class derivedStats
// // {
// // public:
// // 	void adjustCurrentHealth(int);
// // 		//Function for dealing damage and healing of PC or NPC.
// // 	void adjustCurrentMana(int);
// // 		//Function for expending mana when magic is used and for
// // 		//recovering mana through rest or item use.
// // 	void adjustCurrentStamina(int);
// // 		//Function for expending stamina when an action is taken and
// // 		//for recovering stamina through rest, item use, or ability.
// // 			//***For all "adjust" functions, passing a positive int
// // 			//***increases the resource and a negative int reduces it.

// // 	int getCurrentHealth();
// // 	int getCurrentMana();
// // 	int getCurrentStamina();

// // private:
// // 	int maxHealth;
// // 	int maxMana;
// // 	int maxStamina;
// 		//Character's maximum value for resource values; current value
// 		//should never surpass max. This value is determined primarily by
// 		//stats and will be adjusted anytime a correlating stat is changed.
// };

// // class faction
// // {
// // public:
// // 	string getFactionName();
	

// // private:
// // 	string factionName;
// // 	string factionRanks[][];
	


// // };

// // class characterFactionRelations
// // {
// // public:
// // 	string factionsAttachedTo();
// // 	int getCharRelation;

// // private:
// // 	string factionsAttachedTo[];
// // 	int charRelation;


// // };

// // class character{
// // 	public:


// // 	private:
// // 		charStats myStats;
// // 		derivedStats charResources;


// // };
