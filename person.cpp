#include <iostream>
#include "person.hpp"
#include "hospital.hpp"

using namespace std;

Person::Person(){};

Person::Person(string name, string surname):name_(name), surname_(surname){};

string Person::getName() const{
    return name_;
};

string Person::getSurname() const{
    return surname_;
};

void Person::setName(string name){
    name_ = name;
};

void Person::setSurname(string surname){
    surname_ = surname;
};