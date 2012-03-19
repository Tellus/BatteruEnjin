#pragma once

#include "BE_Character.h"

namespace BE
{
	namespace Engine
	{
	    enum GAMESTATE_CLONE_FLAGS {ALL_VOLATILE, NONE_VOLATILE, DEFAULT_VOLATILE};
	
		/**
		 * The game state class contains an entire snapshot of a battle. Basically, it's
		 * a systematic clone of every object within the engine. Objects that are marked
		 * as non-volatile are directly referenced instead.
		 * \see Primarch::is_volatile
		 **/
		class GameState
		{
		    public:
		    /**
		     * Accounts for the entirety of our current game state design.
		     * Everything ties into Characters right now.
		     **/
		    vector<Character>* characters;
		    
		    /**
		     * Creates an empty GameState object. Quite, quite useless until
		     * filled.
		     **/
		    GameState();
		    
		    /**
		     * Creates a new GameState object as a clone of another GameState
		     * object. Overrides default copy-constructor behaviour (is that
		     * even necessary?
		     * \param from The GameState to clone. Uses default volatility.
		     * \return A new GameState object, copied with default settings from
		     * a parent.
		     **/
		    GameState(GameState* from);
		    
		    /**
		     * Creates a new GameState object as a conditioned clone of another
		     * GameState object.
		     * \param from GameState to clone.
		     * \param volatility How the clone process should respect volatile
		     * Primarch objects. DEFAULT_VOLATILE respects the objects' own
		     * volatility setting, ALL_VOLATILE assumes they are all volatile
		     * (and thus creates a completely new copy), NONE_VOLATILE assumes
		     * none are volatile (and will thus create a shallow copy, wherein
		     * all pointer references go directly to the original Primarch
		     * objects.
		     * \return A new GameState object with values copied from its
		     * parent.
		     **/
		    GameState(GameState* from, GAMESTATE_CLONE_FLAGS volatility);
		    
		    /**
		     * Adds a new Character to the game state.
		     * \param to_add Pointer to the Character to add.
		     * \throws GameStateDuplicateCharacterException if you try to add an
		     * already existing Character in the state.
		     **/
		    void add_character(Character* to_add);
		    
		    /**
		     * Removes the referenced Character from the game state.
		     * \param to_remove Pointer to the Character to remove.
		     * \note This method uses pointer arithmetic to identify and remove
		     * the Character.
		     **/
		    void remove_character(Character* to_add);
		    
		    /**
		     * Removes a Character from the game state.
		     * \param name Name of the Character to remove.
		     * \throws GameStateCharacterNotFoundException if the name did not
		     * match any of the Characters in the game state.
		     **/
		    void remove_character(const char* name);
		    
		    /**
		     * Removes a Character from the game state by its unique id.
		     * \param id The BE Identifier assigned to the Character.
		     * \todo Figure out if this is useful, considering the pointer
		     * overload might be even more broad.
		     **/
		    void remove_character(BE::Engine::Identifier id);
		    
		    /**
		     * Retrieves a Character from the game state.
		     * \param name The name of the character to retrieve.
		     * \returns A pointer to the Character in the game state. Volatile.
		     * \throws GameStateCharacterNotFoundException if the name did not
		     * match any in the game state.
		     **/
		    Character* get_character(const char* name);
		};
	}
}
