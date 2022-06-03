#include <random>
#include <chrono>
#include <iostream>
#include "random_number_generator.hpp"


using namespace std;


RNG::RNG(){};

unsigned int RNG::getRandomNumber(unsigned int lowerBound, unsigned int upperBound){
    unsigned int seed = chrono::system_clock::now().time_since_epoch().count();
    mt19937 mersenne_generator{seed};
    uniform_real_distribution<float> distance{(float)lowerBound, (float)upperBound+1};
    unsigned int randomNumber = (unsigned int)distance(mersenne_generator);
    return randomNumber;
}