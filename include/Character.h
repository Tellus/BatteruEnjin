#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include "include/Action.h"

class Character
{
    public:
        std::string name;

        float health;
        float health_max;
        float attack;
		
		virtual Action *action() = 0; // MUST be implemented.
    protected:
    private:
};

#endif // CHARACTER_H
