#ifndef THROB_H
#define THROB_H

#include "include/Character.h"

class Throbulator : public Character
{
    public:
		int headache;
	
        Throbulator();
		
		Action *action();
    protected:
		Action *throb();
		Action *headbutt();
		Action *splode();
    private:
};

#endif // THROB_H
