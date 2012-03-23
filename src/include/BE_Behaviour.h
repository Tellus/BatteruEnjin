#pragma once

#include "BE_Primarch.h"

namespace BE
{
	namespace Primarch
	{
		/**
		 * The Behaviour primarch dictates the factors that come into play when the
		 * engine determines the best course of action for a given Character.
		 **/
		class Behaviour : public Primarch
		{
		    public:

			/**
			 * Calculates the piggy value of the Behaviour's parent based on current
			 * state. Behaviour subclasses *need* to implement this since the
			 * calculation is unique to each behaviour. Similarly, each Behaviour
			 * subclass may make certain assumptions about its attached parent.
			 * \return The piggy value. Higher is better.
			 **/
			virtual float get_piggy() = 0;
		};
	}
}
