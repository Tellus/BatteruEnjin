#pragma once

// From standard includes.
#include <map>
#include <list>

// From custom code.
#include "BE_Behaviour.h"
#include "BE_Effect.h"
#include "BE_Ability.h"
#include "BE_Attribute.h"
#include "BE_Resource.h"
#include "BE_Item.h"
#include "BE_EventListener.h"

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
			Character();
			virtual ~Character() = 0;

			/**
			 * The Behaviour associated with this Character. Used every time the
			 * Character needs to take an action.
			 * \note We're forced to use pointer over value as a value would
			 * force the code to instantiate the otherwise abstract class. This
			 * is not required for pointers.
			 **/
			BE::Primarch::Behaviour* behaviour;

			/**
			 * List of all abilities available to the Character. Remember, we
			 * epxect actual subclasses since Ability is purely virtual.
			 */
			std::list<BE::Primarch::Ability> abilities;
			
			/**
			 * List of resources associated with the character. Subclasses
			 * should have their constructor instantiate all relevant resources
			 * so they will be available during inheritance as well.
			 **/
			std::list<BE::Primarch::Resource> resources;
			
			/**
			 * List of attributes for the Character.
			 **/
			std::list<BE::Primarch::Attribute> attributes;
			
			/**
			 * List of items in possession by the Character.
			 **/
			std::list<BE::Primarch::Item> items;

            /**
             * Event listeners. These mirror the Event list of a langname
			 * Character. We realised that the Event primarchs aren't really
			 * events, they're listeners.
             **/
            std::list<BE::Primarch::EventListener> listeners;
    
			/**
			 * Proxy for calling this->behaviour.get_piggy();
			 * \return The piggy value. Higher is better.
			 * \see Behaviour::get_piggy()
			 **/
			float get_piggy();
			
			/** INITIALIZATION METHODS - ABSTRACT **/
		protected:
			virtual void set_attributes() = 0;
			virtual void set_resources() = 0;
			virtual void set_behaviour() = 0;
			virtual void set_abilities() = 0;
			virtual void set_event_listeners() = 0;
		};
	}
}
