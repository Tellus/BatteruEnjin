#include "include/Throbulator.h"

Throbulator::Throbulator()
{
    //ctor
	this->name = "Throbulator";
    this->health = this->health_max = 150;
    this->attack = 30;
	this->headache = 0;
}

// We let each character hardcode their action for now. Simpler.
Action *Throbulator::action()
{
	if ((this->health/this->health_max) > 0.3)
	{
		return this->headbutt();
	}
	else if (this->headache == 100)
	{
		return this->splode();
	}
	else
	{
		return this->throb();
	}
}

Action *Throbulator::throb()
{
	this->headache += 10;
	
	return new Action("Head Throb", "Throbulators veinous head starts to pump his FILTHY greyish liquid BLOOOOOD further through his head-thing", 0);
}

Action *Throbulator::headbutt()
{
	this->health -= 15;
	
	return new Action("Headbutt", "Thrusting forwards, Throbulator crushes his big stupid head into his enemy, spilling blood and other squishy bits everywhere in the process.", this->attack*2);
}

Action *Throbulator::splode()
{
	this->health = 0;
	
	return new Action("'splode", "The thumping. The thumping, it is impetuous! With an explosion of pure gut, blood and Throbulator-matter, the puny being is no more. In the air, the words 'feel nothing anymore' is whispered.", this->attack*3);
}
