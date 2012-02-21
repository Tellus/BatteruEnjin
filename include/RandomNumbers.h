#ifndef RANDOMNUMBERS_H
#define RANDOMNUMBERS_H

#include <boost/random.hpp>

class RandomNumbers
{
    public:
        static float get_float(float start, float end);
		static int get_int(int start, int end);
    protected:
    private:
};

#endif // RANDOMNUMBERS_H
