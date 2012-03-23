#ifndef SIZZLORR_H
#define SIZZLORR_H

#include "include/Character.h"

class Sizzlorr : public Character
{
    public:
        int turn;
		
		Sizzlorr();
		
		Action *action();
    protected:
		Action *spank();
		Action *gravy();
		Action *piggy();
    private:
};

#endif // SIZZLORR_H
