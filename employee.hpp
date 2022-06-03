#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP
#include <memory>
#include <string>
#include <iostream>
#include "person.hpp"

using namespace std;

class Employee: public Person{
public:
    Employee(string name, string surname);
    bool isOcuppied();
    void setOccupied(bool occupiedState);
private:
    bool occupied_;
};

#endif