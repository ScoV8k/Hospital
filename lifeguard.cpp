#include <memory>
#include <string>
#include <iostream>
#include "lifeguard.hpp"

Lifeguard::Lifeguard(string name, string surname):Employee(name, surname){};

string Lifeguard::giveDefibrillation(shared_ptr<Patient> patientPointer)
{
    string message = getName() + " przeprowadził defibrylację na pacjęcie # " + to_string((*patientPointer).getIdentifier());
    return message;
}

ostream& operator<<(ostream& stream, const Lifeguard& lifeguard){ // <== Object????????
    stream << "Ratownik #" << lifeguard.getIdentifier();
    return stream;
}