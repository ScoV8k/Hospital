#ifndef DOCTOR_HPP
#define DOCTOR_HPP
#include <memory>
#include <string>
#include <iostream>
#include "employee.hpp"
#include "health_record.hpp"
#include "patient.hpp"


using namespace std;

class Doctor: public Employee{
public:
    Doctor(string name, string surname);
    string addPatientDisease(string diseaseName, shared_ptr<Patient> patientPointer);
    string addRandomDisease(shared_ptr<Patient> patientPointer);
    string removePatientDisease(string diseaseName, shared_ptr<Patient> patientPointer);
    string addPatientMedicine(string medicationName, shared_ptr<Patient> patientPointer);
    string removePatientMedicine(string medicationName, shared_ptr<Patient> patientPointer);
    string consulatationWithPatient(shared_ptr<Patient> patientPointer);
    string carryOutSurgery(shared_ptr<Patient> patientPointer);
    friend ostream& operator<<(ostream& stream, const Doctor& doctor);
    string checkForSurgery(shared_ptr<Patient> patientPointer);
    const static string possibleDiseases_[4];
    string getRecommendedUnit(string disease);
};

#endif