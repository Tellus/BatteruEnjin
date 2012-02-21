#include "include/Sizzlorr.h"

Sizzlorr::Sizzlorr()
{
    //ctor
	this->name = "Sizzlorr";
    this->health = this->health_max = 350;
    this->attack = 45;
	this->turn = 0; // Turn counter for AI-like behaviour... thing.
}

Action *Sizzlorr::spank()
{
    // rng the shit out of this thing.
	return new Action("Spatula Spank", "Sizzlorr raises his mighty metal-onium spatula and thwacks it forward.", this->attack);
}

Action *Sizzlorr::gravy()
{
	return new Action("Gravy Grave", "An explosion of greasy, hot, gravy death spurts from the Frylord's backpack.", this->attack*2);
}

Action *Sizzlorr::piggy()
{
	return new Action("Super Piggy Mega Attack Mach Oink", "Piggies! Piggies everywhere! Feel the piggy wrath of deathy-death!", this->attack*3);
}

Action *Sizzlorr::action()
{
	this->turn += 1;

	if (this->health < 80)
	{
		return this->piggy();
	}
	else if (turn % 2 == 0)
	{
		return this->spank();
	}
	else
	{
		return this->gravy();
	}
}