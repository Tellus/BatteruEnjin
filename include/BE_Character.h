#pragma once

// From standard includes.
#include <map>
#include <vector>

// From custom code.
#include "BE_Primarch.h"
#include "BE_Behaviour.h"
#include "BE_Effect.h"
#include "BE_Ability.h"
#include "BE_Attribute.h"
#include "BE_Resource.h"

using namespace std;

namespace BE
{
	namespace Primarch
	{

		/**
		 * Character matches the Character primarch of InvaderScript. Something
		 * obvious that has sprung from our design considerations is that everything
		 * that takes place in a battle/scenario is started by a Character and affects
		 * a Character (possibly the same one). I made a pretty hand-drawn flowchart for
		 * this.
		 */
		class Character : public Primarch
		{
			public:
			virtual ~Character() = 0;

			/**
			 * Pointer to the Behaviour associated with this Character. Used every time
			 * the Character needs to take an action.
			 **/
			Behaviour* behaviour;

			/**
			 * Vector of all abilities available to the Character. Remember, we except
			 * actual subclasses since Ability is purely virtual.
			 */
			vector<Ability> abilities;
			vector<Resource> resources;
			vector<Attribute> attributes;

			/**
			 * Proxy for calling this->behaviour->get_piggy();
			 * \return The piggy value. Higher is better.
			 * \see Behaviour::get_piggy()
			 **/
			float get_piggy();
		};
	}
}
