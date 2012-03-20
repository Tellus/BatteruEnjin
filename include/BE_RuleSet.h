#include "BE_Character.h"
#include "BE_GameState.h"

namespace BE
{
    namespace Engine
    {
        /**
         * The rule set is defined externally in C++, not InvaderScript, for one
         * basic reason. Because the rule set demands some heavily imperative code in
         * order to properly represent some of the more complex rulesets (see World of
         * Darkness and the health system, for example).
         **/
        class RuleSet
        {
        public:
            /**@{*/
            /**
             * Compare method used by the Engine when determining turn order. The
             * function should work just like a standard compare function when used on
             * C++ stl collections (list, for example) - indeed, this is exactly what
             * fucking happens.
             * \param c1 The first character to compare with.
             * \param c2 The second character to compare with.
             * \return True if the first character should come before the second
             * character in the turn order. False otherwise.
             * \note In scenarios with more than two characters, the Engine will call
             * this method for several pairs of characters until the turn order is
             * fully determined.
             **/
            virtual bool turn_cmp(BE::Primarch::Character c1, BE::Primarch::Character c2);
            virtual bool turn_cmp(BE::Primarch::Character *c1, BE::Primarch::Character *c2);
            /**@}*/
            
            /**
             * Method called by Engine to determine who has won a scenario.
             * \param cur_state The current game state at the conclusion of the battle.
             * \return Reference to the winning Character, or NULL if either the battle
             * is still active or no winner could be determined.
             **/
            virtual BE::Primarch::Character* get_winner(const BE::Engine::GameState *cur_state);
            
            /**
             * Method called by Engine to determine whether the scenario should continue
             * unfolding or if a winner can be determined by the current state.
             * \param cur_state The current game state as held by Engine.
             * \return True if a winner can be decided, false otherwise.
             **/
            virtual bool has_winner(BE::Engine::GameState *cur_state);
        }
    }
};
