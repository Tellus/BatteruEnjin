#include "include/FF_Character.h"

namespace FF
{
	WarriorOfLight::WarriorOfLight() : Character()
	{
		// Character() should initialize the vectors for resources, etc.
		WarriorOfLight(int strength, int agility, int intelligence, int stamina, int luck)
		{
			// Set attributes.
			this->str = strength;
			this->agil = agility;
			this->intl = intelligence;
			this->stam = stamina;
			this->lck = luck;
			
			this->acc = this->agil + (this->luck / 2);
			this->def = (this->stam + this->agil) / 3;
			this->mdef = (this->stam + this->intl) / 3;
			this->eva = (this->agil + (this->lck / 2) - 0;
			
			this->hp = this->stam * 20;
			this->mp = this->intl * 15;
		}
	}
}