#include "include/BE_Character.h"

namespace BE
{
	namespace Primarch
	{
		float Character::get_piggy()
		{
			return this->behaviour->get_piggy();
		}
		
		Character::Character()
		{
			set_attributes();
			set_resources();
			set_behaviour();
			set_abilities();
			set_event_listeners();
		}
		
		void Character::set_attributes()
		{
			return; // Does nothing... better solution?
		}
		
		void Character::set_resources()
		{
			return; // Does nothing... better solution?
		}
		
		void Character::set_behaviour()
		{
			return; // Does nothing... better solution?
		}
		
		void Character::set_abilities()
		{
			return; // Does nothing... better solution?
		}
		
		void Character::set_event_listeners()
		{
			return; // Does nothing... better solution?
		}
	}
}
