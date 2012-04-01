#include "BE_RuleSet.h"

/**
 * A simple example implementation of the RuleSet class. The rules are:
 * - Effects affecting health do so unaffected.
 * - Effects affecting mana also do so unaffected.
 * - Turn order is first in, first out.
 * - The winner is the character left with positive health.
 **/
class SimpleRuleSet : BE::Engine::RuleSet
{
	bool turn_cmp(BE::Primarch::Character *c1, BE::Primarch::Character *c2);
	bool has_winner(BE::Engine::GameState *cur_state);
};
