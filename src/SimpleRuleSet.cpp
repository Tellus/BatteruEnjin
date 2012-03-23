#include "include/SimpleRuleSet.h"

bool *SimpleRuleSet::turn_cmp(BE::Primarch::Character *c1, BE::Primarch::Character *c2)
{
    // We always let the first character take the first turn. Simple.
    return true;
}

virtual bool SimpleRuleSet::has_winner(BE::Engine::GameState *cur_state)
{
    unsigned int num_pos = 0; // Number of positive health found.
    
    // We cound characters with positive health. More than 1 means an automatic
    // false return value.
    
    for (
}
