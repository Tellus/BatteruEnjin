#ifndef Throbulator_H
#define Throbulator_H

#include <string>

using namespace std;

/**
 * The action class represents the action taken by a character. We use this
 * wrapper to dynamically pass actions to the engine allowing it to use 
 * standardised pieces and discard the rest until plugged to change its
 * behaviour. I guess optimally we should have a signalling framework allow
 * the action to define a bunch of engine standard events to be fired that
 * frontend code can pick up and play with.
 */
class Action // lawsuit :P
{
    public:
		/*
		 * Printable name of the action.
		 */
		string action_name;
		
		/*
		 * A message that can be displayed for dramatic effect. We leave to the
		 * character to determine the format (so they can reference themselves
		 * in the third person, make-shift dialogue or a world event).
		 */
		string message;
		
		/*
		 * Damage output from the character. Should be modified by the rules
		 * established for the game and, for advanced coding, by special rules
		 * on the opposing character. Remember, letting characters themselves
		 * handle results is not good for competition.
		 */
		float damage;
	
		// For now, unimplemented. This is where poison, slow, sleep, bade case
		// of hair - it's all stacked here for addition.
		// ActionEffect effects[];
	
		Action();
		Action(string name, string msg, float dmg);
    protected:
    private:
};

#endif // Throbulator_H
