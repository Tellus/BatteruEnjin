#include <iostream>

#include "include/RandomNumbers.h"
#include "include/Character.h"
#include "include/Throbulator.h"
#include "include/Sizzlorr.h"

using namespace std;

int main()
{
	// Very UNrandom right now. Fuck it.
    // float rng = RandomNumbers::get_number(0,10);
	// On my Win7 x64 MINGW32 this ALWAYS results to 8.
    // cout << rng;

	// shared_ptr<Character> first_char(new Sizzlorr());
	// shared_ptr<Character> second_char(new Throbulator());

	Character *first_char = new Sizzlorr();
	Character *second_char = new Throbulator();
	
	int turn = 0;
	
	cout << "WELCOME! TO BATTERU! ENJIN!\n\n";
	cout << "Tonight, you will see:\n";
	
	cout << first_char->name << " VERSUS " << second_char->name << "\n";
	
	cout << "\n\n\nNow... fight-U!\n";
	
	Action *action;
//	shared_ptr<Character> actor;
//	shared_ptr<Character> target;
	Character *actor;
	Character *target;
	while (first_char->health > 0 && second_char->health > 0)
	{
		turn++;
		if ((turn % 2) == 0)
		{
			actor = first_char;
			target = second_char;
		}
		else
		{
			actor = second_char;
			target = first_char;
		}
		
		action = actor->action();
		
		cout << actor->name << " performs " << action->action_name << "\n";
		
		cout << action->message << "\n";
		
		if (action->damage > 0)
		{
			float modifier = (float)RandomNumbers::get_int(80,150);
			modifier /= 100;
			float dmg = (action->damage * modifier);
			target->health -= dmg;
		
			cout << target->name << " takes ";
			cout << dmg;
			cout << " damage (modifier=";
			cout << modifier;
			cout << ").\n";
		}
		
		/*
		cout << "Random number: ";
		cout << RandomNumbers::get_int(1,150);
		cout << "\n";
		*/
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
