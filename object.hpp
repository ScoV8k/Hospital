#ifndef OBJECT_HPP
#define OBJECT_HPP
#include <iostream>
#include <limits>
#include <vector>


using namespace std;


class Object{
public:
    Object();
    //getter
    unsigned int getIdentifier() const;
    //setter
    void setIdentifier(unsigned int identifier);
    //destruktor
    virtual ~Object();
    //inne
    static unsigned int chooseObjectIdentificator();
    static unsigned int counter;
protected:
    unsigned int identifier_;
};

#endif