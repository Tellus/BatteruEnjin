#pragma once

#include "BE_Primarch.h"

namespace BE
{
	namespace Primarch
	{
		/**
		 * The resource class represents a value with a clear min/max value, as well
		 * as a current, initial and base value. Finally, it supports modifiers.
		 **/
		class Resource : BE::Primarch::Primarch
		{
			public:
				float min,max,current,initial,base;

		
		};
	}
}
