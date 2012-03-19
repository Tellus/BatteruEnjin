#pragma once

#include "BE_Primarch.h"

namespace BE
{
	namespace Primarch
	{
	    /**
	     * The Event class defines triggers, criteria and results of an event.
	     * They are bound to characters.
	     **/
		class Event : BE::Primarch::Primarch
		{
            public:
                vector<BE::Engine::EventCondition> conditions;
                vector<BE::Engine::Ability> abilities;

            
		};
	}
}
