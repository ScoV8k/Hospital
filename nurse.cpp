#include <memory>
#include <string>
#include <iostream>
#include "nurse.hpp"
#include "patient.hpp"


using namespace std;


Nurse::Nurse(string name, string surname):Employee(name, surname){};

string Nurse::giveMedicine(string medicineName, shared_ptr<Patient> patientPointer)
{
    // patientPointer -> getHealthRecordPointer() -> addMedication(medicationName);
    string message = "Pielęgniarka #" + to_string(getIdentifier()) + " dała pacjentowi #" + to_string((*patientPointer).getIdentifier()) + medicineName;
    return message;
}

string Nurse::giveJab(string JabName, shared_ptr<Patient> patientPointer)
{
    // patientPointer -> getHealthRecordPointer() -> addMedication(medicationName);
    string message = "Pielęgniarka #" + to_string(getIdentifier()) + " dała pacjentowi #" + to_string((*patientPointer).getIdentifier()) + JabName;
    return message;
}

ostream& operator<<(ostream& stream, const Nurse& nurse){ // <== Object????????
    stream << "Pielęgniarka #" << nurse.getIdentifier();
    return stream;
};