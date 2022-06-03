#include "object.hpp"

unsigned int Object::counter = 0;

Object::Object()
{
    identifier_ = Object::chooseObjectIdentificator();
};

unsigned int Object::getIdentifier() const{
    return identifier_;
};

void Object::setIdentifier(unsigned int identifier){
    identifier_ = identifier;
};

Object::~Object(){};

unsigned int Object::chooseObjectIdentificator(){
    unsigned int id = counter;
    counter++;
    return id;
};