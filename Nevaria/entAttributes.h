#ifndef H_entAttributes
#define H_entAttributes

class entAttributes {
public:
//Functions for setting initial stat values
//and increasing the stat when player levels up.
	void setAll(int, int, int, int, int, int);
	void adjustStrength(int);
	void adjustIntelligence(int);
	void adjustAgility(int);
	void adjustDexterity(int);
	void adjustConstitution(int);
	void adjustWill(int);

//Functions for calculating/setting derived stats
	void calcMaxHealth();
	void calcMaxMana();
	void calcMaxStamina();

//***For all "adjustCurrent" functions, passing a positive int
//***increases the resource and a negative int reduces it.

	//Function for dealing damage and healing of PC or NPC.
	void adjustCurrentHealth(int);
	//Function for expending mana when magic is used and for
	//recovering mana through rest or item use
	void adjustCurrentMana(int);
	//Function for expending stamina when an action is taken and
	//for recovering stamina through rest, item use, or ability.
	void adjustCurrentStamina(int);

//Functions for getting current value of a character's attributes.
//Used for displaying character sheet and algorithm calculations.
	void getAll(int& str, int& intel, int& agi, int& dex, int& con, int& wil);
	int getStrength();
	int getIntelligence();
	int getAgility();
	int getDexterity();
	int getConstitution();
	int getWill();


//Functions for getting current value of a character's current or max derived attributes.
	int getCurrentHealth();
	int getCurrentMana();
	int getCurrentStamina();
	int getMaxHealth();
	int getMaxMana();
	int getMaxStamina();

//Constructors
	//Constructor for new character
	entAttributes(int* &list);
	//entAttributes(int str, int intel, int agi, int dex, int con, int wil);
	//Constructor used to generate enemies
	entAttributes(int str, int intel, int agi, int dex, int con,
		int wil, int hlth, int mana, int stam);

private:

	int strength;
	//Affects melee dmg & ranged dmg to a lesser degree and max encumberance.
	int intelligence;
	//Affects magic dmg and max mana.
	int agility;
	//Affects dodge chance, crit chance, and
	//chance to avoid detection when sneaking.
	int dexterity;
	//Affects hit chance with all weapons, crit chance, and ranged damage.
	int constitution;
	//Affects max health & stamina and adds to base dmg resistance.
	int will;
	//Affects stamina & magic crit chance and adds to magic resistance chance.
//***Character's primary attributes.***


//Character's maximum and current value for derived attributes. Current
//value should never surpass max and should be adjusted when taking damage,
//healing, spellcasting, etc. Max value is determined primarily by
//stats and should be adjusted anytime a correlating stat is changed.
	int currentHealth;
	int currentMana;
	int currentStamina;
	int maxHealth;
	int maxMana;
	int maxStamina;

	int baseDodgeChance;
	int baseCritChance;
	int magicCritChance;
	int baseAccuracy;
	int baseDmgRes;
	int baseMagRes;
	

};

#endif