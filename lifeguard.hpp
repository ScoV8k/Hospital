#ifndef LIFEGUARD_HPP
#define LIFEGUARD_HPP
#include <memory>
#include <string>
#include <iostream>
#include "employee.hpp"
#include "patient.hpp"

using namespace std;


class Lifeguard: public Employee{
public:
    Lifeguard(string name, string surname);
    string giveDefibrillation(shared_ptr<Patient> patientPointer);
    friend ostream& operator<<(ostream& stream, const Lifeguard& lifeguard);
};

#endif