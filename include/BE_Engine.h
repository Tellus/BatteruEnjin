#pragma once

#include <vector>

#include "BE_Character.h"
#include "BE_GameState.h"

namespace BE
{
	namespace Engine
	{
		enum ENGINE_EXECUTION_MODE {EEM_CONTINOUS, EEM_SINGLE_STEP};

		/**
		 * The engine is the core executionary device of our framework. In short, the
		 * engine handles the following:
		 *	- Characters
		 *	- Teams
		 *	- Turns
		 *	- Decision-making for Character-bound Behaviour objects.
		 *	- Globally (static) available references to keyword references from script.
		 *		- User (updated before AI tree calculation to point to current Char).
		 *		- Target (container of targets for an ability).
		 *		- etc (see language reference for a comprehensive list of these refs)
		 * Do note, however, that the engine delegates actions to the objects in play.
		 * While it will calculate rule-specific results to avoid cheating, it will
		 * prefer to let other objects handle the preliminary work (an effect
		 * determining damage, for example, or an ability creating and invoking those
		 * effects).
		 **/
		class Engine
		{
			public:
			/**
			 * This member will always point to a \emph{copy} of the currently active
			 * Character. This is to prevent accidental (or intentional?) direct
			 * manipulation of the object.
			 * The reference is updated prior to running a specific Character's turn.
			 **/
			static BE::Primarch::Character *User;
			// Insert more of these. We need Ally, Team, Enemy, Enemies, etc.	

			/**
			 * The execution mode determines how the engine should be running.
			 * Currently valid modes are:
			 * - EEM_CONTINOUS. The engine runs without yielding control, passing event
			 *		signals back to any registered methods. Mostly useful for debugging,
			 *		text-based or summary-type frontends, and definitely not for
			 *		interactive frontends.
			 * - EEM_SINGLE_STEP. The engine executes an entire turn and then yields to
			 *  	the calling environment. Useful for stepwise environments, GUI-based
			 *		frontends and principally where interaction would be desired between
			 *		each turn.
			 **/
			ENGINE_EXECUTION_MODE execution_mode;	

			/**
			 * Contains references to all characters in play. The vector is unsorted if
			 * no rules pertaining to turn order were passed.
			 **/
			vector<BE::Primarch::Character>* characters;

			/**
			 * Determines if the highest or lowest turn number is considered the first.
			 * Implemented as although the default implementation considers the lowest
			 * number as the earliest turn, D&D has the highest initiative rollas the
			 * earliest turn.
			 * \todo Find a better name for this var.
			 **/
			bool turn_highest_goes_first;

			/**
			 * Function pointer to function that calculatse turn order value. This
			 * function is called for each character passed during engine
			 * initialization, and the value determines the character's placement in the
			 * characters container, thus their turn order.
			 * The default implementation will assign character's increasing turn
			 * numbers without considering attributes.
			 **/
			// int (*turn_order_func)(*BE:Primarch::Character);

			/**
			 * Creates a new Engine, prepared to simulate a battle between two distinct
			 * Characters. This is one of the most basic constructors, and the engine
			 * will run in continous mode.
			 * \param first_char Pointer to the first character in the battle.
			 * \param second_char Pointer to the second character in the battle.
			 * \note The engine randomly picks the first character to take a turn since
			 * this initialization model contains very few (... too few?) game params.
			 **/
			Engine(BE::Primarch::Character *first_char, BE::Primarch::Character *second_char);

			/**
			 * Executes the engine in its current mode.
			 * \return A GameState object representing the state of the battle
			 * \emph{after} execution.
			 * \note Execution mode is determined by execution_mode. If continous, the
			 * GameState will simply contain the summary of the battle (final state),
			 * while stepwise will return the state at the conclusion of the last step.
			 **/
			GameState* execute();
			
			/**
			 * Simulates an ability used by a specific character and returns the
			 * resulting gamestate. Non-volatile.
			 * \param character The Character to perform the ability.
			 * \param ability The ability the Character should perform.
			 * \param from_state Optional state to use as basis instead of the
			 * current game state in the active scenario.
			 * \return Resulting GameState after the ability has been used and
			 * its effects calculated.
			 * \throws AbilityUseException if the ability's conditions cannot
			 * be met (insufficient cost, invalid target, etc).
			 * \throws CorruptGameStateException if the passed GameState is
			 * corrup or otherwise invalid. This is most notable if you try to
			 * pass a GameState from an entirely different scenario.
			 **/
			GameState* simulate(BE::Primarch::Character* character, BE::Primarch::Ability* ability, BE::Engine::GameState* from_state=0);
			
			/**
			 * Compiles the current game state into a GameState object. The
			 * GameState may be a copy or directly reference so the frontend can
			 * modify the state to fit the game setting.
			 * \param cloned Clone the GameState (so it cannot be modified) or
			 * create a GameState of direct references.
			 * \return The current game state is returned in a manner matching
			 * that of the input parameter.
			 **/
			GameState* get_gamestate(bool cloned = true);
			
			
		};
	}
}
