#ifndef WARDER_HPP
#define WARDER_HPP
#include "employee.hpp"
#include "patient.hpp"


class Warder: public Employee{
public:
    Warder(string name, string surname);
    vector<string> giveMedicine(vector<shared_ptr<Patient>> patients);
};

#endif