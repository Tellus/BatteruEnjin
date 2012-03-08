#include "include/BE_Engine.h"

/**
 * Default implementation of turn order. Simply gives input Characters
 * turn order values.
 * \param BE_Character The character to give a turn value to.
 * \return Returns a turn value fit for the lower-is-faster engine turn order.
 **/
int default_turn_order_func(BE_Character)
{
	static int turn_order = 0;
	return turn_order++;
}

BE_GameState* BE_Engine::execute()
{

}
