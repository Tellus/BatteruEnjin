#include "BE_Character.h"

namespace FF
{
	class WarriorOfLight : BE::Primarch::Character
	{
	public:
		// Prime attributes (all of them are flat)
		Strength str;
		Agility agil;
		Intelligence intl;
		Stamina stam;
		Luck lck;
		
		// Secondary attributes
		Accuracy acc;	// Melee: agil+(lck/2) | Caster: (int/2 + lck/2)
		Defense def;	// (sta+agil)/3
		Evasion eva;	// (agil+(luck/2))-(ACType)
		MagicDefense mdef;	// (stam+intl)/3
		
		// Resources
		Health hp;	// sta*20
		Mana mp;	// intl*15
		
		WarriorOfLight(int strength, int agility, int intelligence, int stamina, int luck);
	};
}