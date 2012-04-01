#pragma once

// From standard includes.
#include <map>
#include <list>

// From custom code.
#include "BE_Primarch.h"
#include "BE_Behaviour.h"
#include "BE_Effect.h"
#include "BE_Ability.h"
#include "BE_Attribute.h"
#include "BE_Resource.h"
#include "BE_Item.h"
#include "BE_Event.h"

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
		class Character
		{
			public:
			virtual ~Character() = 0;

			/**
			 * The Behaviour associated with this Character. Used every time the
			 * Character needs to take an action.
			 **/
			Behaviour behaviour;

			/**
			 * List of all abilities available to the Character. Remember, we
			 * epxect actual subclasses since Ability is purely virtual.
			 */
			list<Ability> abilities;
			
			/**
			 * List of resources associated with the character. Subclasses
			 * should have their constructor instantiate all relevant resources
			 * so they will be available during inheritance as well.
			 **/
			list<Resource> resources;
			
			/**
			 * List of attributes for the Character.
			 **/
			list<Attribute> attributes;
			
			/**
			 * List of items in possession by the Character.
			 **/
			list<Item> items;

            /**
             * List of events bound to the Character. The engine will register
             * them on initialization and react as appropriate.
             **/
            list<Event> events;
    
			/**
			 * Proxy for calling this->behaviour.get_piggy();
			 * \return The piggy value. Higher is better.
			 * \see Behaviour::get_piggy()
			 **/
			float get_piggy();
			
			void notify(const BE::Engine::Event *e);
		};
	}
}
