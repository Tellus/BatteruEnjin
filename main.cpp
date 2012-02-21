#include <iostream>

#include "include/RandomNumbers.h"
#include "include/Character.h"
#include "include/Throbulator.h"
#include "include/Sizzlorr.h"

using namespace std;

int main()
{
	// Very UNrandom right now. Fuck it.
    float rng = RandomNumbers::get_number(0,10);

	// On my Win7 x64 MINGW32 this ALWAYS results to 8.
    // cout << rng;

	shared_ptr<Character> first_char(new Sizzlorr());
	shared_ptr<Character> second_char(new Throbulator());
	
	cout << "Throbulator stands ready! Health: ";
	cout << second_char->health;
	cout << "\n";
	
	int turn = 0;
	
	cout << "FIGHT-U\n";
	Action *action;
	shared_ptr<Character> actor;
	while (first_char->health > 0 && second_char->health > 0)
	{
		turn++;
		if ((turn % 2) == 0)
		{
			cout << first_char->name << " prepares for action.\n";
			actor = first_char;
		}
		else
		{
			cout << second_char->name << " prepares for action.\n";
			actor = second_char;
		}
		
		action = actor->action();
	}
	
	if (first_char->health <= 0 && second_char->health <= 0)
	{
		cout << "DRAW-U!\n";
	}
	else if (first_char->health > 0)
	{
		cout << first_char->name << " WINS!\n";
	}
	else
	{
		cout << second_char->name << " WINS!\n";
	}
	
    return 0;
}
