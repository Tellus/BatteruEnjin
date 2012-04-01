#pragma once

#include <vector>

#include "BE_Primarch.h"
#include "BE_Effect.h"

namespace BE
{
	namespace Primarch
	{
		class Character;
	
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
	    class Ability
	    {
        public:
           /**
		   
		    */
           std::vector<Primarch*> targets;
           
		   /**
		    * Vector of Effects related to this ability. Each one will have
			* methods invoked to affect the active target.
			*/
           std::vector<BE::Primarch::Effect> effects;
           
		   /**
		    * Returns a vector of supported types in string format.
			* \return vector<string> of supported types.
			*/
		   virtual std::vector<std::string> get_supported_types();
		   
		   /**
		    * Applies the ability to a target. Should validate the target, then
			* apply a series of effects on it.
			* \param target The target of the ability. Must be of the valid
			* types for the ability.
			*/
		   void use(Primarch *target);
		   
		   /**
		    * Applies the ability to a vector of targets. Otherwise identical to
			* use(Primarch).
			* \param targets Vector of targets to target. All of them should be
			* valid targets for the ability.
			**/
		   void use(std::vector<Primarch> *targets);
		   
		protected:
			
		};
	}
}
