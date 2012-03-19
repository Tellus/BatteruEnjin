#pragma once

#include <vector>

#include "BE_Primarch.h"

namespace BE
{
	namespace Primarch
	{
	    struct AbilityCostStruct
	    {
	        
	    };
	
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
		       // std::vector<BE::Primarch::Character> *targets;
		       // This REALLY should be Characters, but it avoids circular
		       // dependencies. And who knows, perhaps abilities should be able
		       // to enchant weapons and the like?
		       std::vector<BE::Primarch::Primarch> *targets;
		       
		       std::vector<BE::Primarch::Effect> *effects;
		       
		       std::vector<
		};
	}
}
