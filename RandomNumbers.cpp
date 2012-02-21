#include "include/RandomNumbers.h"

float RandomNumbers::get_number(float start, float end)
{
    boost::random::mt19937 rng;         // produces randomness out of thin air
                                        // see pseudo-random number generators
    boost::random::uniform_real_distribution<> dist(start, end);
                                        // distribution that maps to 1..6
                                        // see random number distributions
    int x = dist(rng);                   // simulate the randomity-ness-thingy.
    return x;
}
