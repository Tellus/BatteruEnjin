#pragma once

#include <vector>

// #include "BE_Character.h"
#include "BE_Primarch.h"

namespace BE
{
	namespace Primarch
	{
	    class Character;
	
	    /**
	     * The Ability Primarch describes an ability usable by a Character (the
	     * Ability must also be bound to the Character to be considered usable).
	     * \todo Add a proper cost mechanism. Can the Modifier base be applied
	     * to create a formalised "modify/reference" mechanism for arbitrary
	     * Primarch data?
	     **/
		class Ability : public Primarch
		{
		    public:
		    std::vector<BE::Primarch::Character> *targets;
		};
	}
}
