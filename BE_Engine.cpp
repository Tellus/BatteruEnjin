#include "include/BE_Engine.h"

namespace BE
{
	namespace Engine
	{
		/**
		 * Default implementation of turn order. Simply gives input Characters
		 * turn order values.
		 * \param for_char The character to give a turn value to.
		 * \return Returns a turn value fit for the lower-is-faster engine turn order.
		 **/
		int default_turn_order_func(BE::Primarch::Character* for_char)
		{
			static int turn_order = 0;
			return turn_order++;
		}
    
    
        /**
         * Executes at step.
         * \todo Write this f'in thing!
         **/
		GameState* Engine::execute()
		{
            GameState *now = this->get_gamestate();
            // Do something useful.
            return now;
		}
		
		/**
		 * Simulates a Character Ability use.
		 * \todo Finish this thing.
		 **/
		GameState* Engine::simulate(BE::Primarch::Character* character, BE::Primarch::Ability* ability, BE::Engine::GameState* from_state)
		{
		    if (from_state == 0) from_state = this->get_gamestate();
		    
		    // Do something 
		    
		    return from_state;
		}
		
		Engine::Engine(BE::Primarch::Character* first_char, BE::Primarch::Character* second_char)
		{
		    this->turn_highest_goes_first = false;
		}
		
		GameState* Engine::get_gamestate(bool cloned)
		{
		    return new GameState();
		}
	}
}
