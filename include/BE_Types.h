#pragma once

/**
 * Type definition file.
 * Contains definitions of global references that the Engine makes use of.
 **/
 
include "BE_Engine.h"
include "BE_Character.h"

namespace BE
{
    namespace Engine
    {
        /**
         * Global, relative reference to the topmost Character owning an active
         * object. Automatically set by the Engine to whichever Character is
         * taking a turn.
         **/
        BE::Primarch::Character *owner;

        /**
         * Global, relative reference to the user (Character) of an Ability...
         * shouldn't this really be owner as well?
         **/
        BE::Primarch::Character *user;

        /**
         * In our current gladiatorial model, there is only one enemy Character,
         * and he's always not the current active Character.
         * enemy is always set to the opposite of owner.
         **/
        BE::Primarch::Character *enemy;

        /**
         * The target of an active ability. Bad juju for threaded computing.
         **/
        BE::Primarch::Character *target;
    }
}
