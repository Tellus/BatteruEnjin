#pragma once

// Circular dependancy, thing.
// #include "BE_Character.h"

namespace BE
{
	namespace Primarch
	{
		// Forward dec.
		class Character;
	
		/**
		 * The resource class represents a value with a clear min/max value, as well
		 * as a current, initial and base value. Finally, it supports modifiers.
		 **/
		class Resource
		{
		public:
			float min,max,current,initial,base;

			BE::Primarch::Character *parent;
			
			/**
			 * Creates a new resource with a speicific character as parent.
			 */
			Resource(BE::Primarch::Character *parent);
			~Resource();
		};
	}
}
