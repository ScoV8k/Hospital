#ifndef PERSON_HPP
#define PERSON_HPP
#include <string>
#include <iostream>
#include "object.hpp"


using namespace std;

class Person: public Object{
public:
    Person();
    Person(string name, string surname);
    // settery
    void setName(string name);
    void setSurname(string name);
    // gettery
    string getName() const;
    string getSurname() const;
protected:
    //zmienne
    string name_;
    string surname_;
};

#endif

