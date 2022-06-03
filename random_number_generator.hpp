#include <random>
#include <chrono>


class RNG{
public:
    RNG();
    unsigned int getRandomNumber(unsigned int lowerBound, unsigned int upperBound);
};