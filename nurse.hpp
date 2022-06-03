#ifndef NURSE_HPP
#define NURSE_HPP
#include <iostream>
#include <memory>
#include "employee.hpp"
#include "patient.hpp"


using namespace std;

class Nurse: public Employee{
public:
    Nurse(string name, string surname);
    string giveMedicine(string medicineName, shared_ptr<Patient> patientPointer);
    string giveJab(string JabName, shared_ptr<Patient> patientPointer);
    friend ostream& operator<<(ostream& stream, const Nurse& nurse);
};

#endif