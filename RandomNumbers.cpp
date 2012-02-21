#include "include/RandomNumbers.h"

float RandomNumbers::get_float(float start, float end)
{
    boost::random::mt19937 rng;         // produces randomness out of thin air
                                        // see pseudo-random number generators
    boost::random::uniform_real_distribution<> dist(start, end);
                                        // distribution that maps to start..end
                                        // see random number distributions
										
    return dist(rng);                   // simulate the randomity-ness-thingy.
}

int RandomNumbers::get_int(int start, int end)
{
	boost::mt19937 rng;                 // produces randomness out of thin air
                                      // see pseudo-random number generators
  boost::uniform_int<> six(start,end);       // distribution that maps to 1..6
                                      // see random number distributions
  boost::variate_generator<boost::mt19937, boost::uniform_int<> >
           die(rng, six);             // glues randomness with mapping
  int x = die();                      // simulate rolling a die
  
  return x;
}