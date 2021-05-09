#ifndef H_Functions
#define H_Functions


using namespace std;


//Used to clear the screen
//Primarily used for easily switching between the
//clear screen functions for Windows Terminal & Bash.
void clearScreen();

//Stops the program until the user presses Enter.
//Used for anytime the user needs time to read the screen.
void r_Pause();

//Purely aesthetic. Forces characters in a given string to be printed individually.
//Gives it a "gamey" feel.
void slow_Type(string temp, bool fillSpace, char fill);

//Displays the help screen using the string currently stored in help and then pauses.
void showHelp(string help);

#endif