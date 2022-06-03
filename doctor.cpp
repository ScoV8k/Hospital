#include <memory>
#include <string>
#include <iostream>
#include "doctor.hpp"
#include "patient.hpp"
#include "random_number_generator.hpp"


Doctor::Doctor(string name, string surname):Employee(name, surname){};

string Doctor::addPatientDisease(string diseaseName, shared_ptr<Patient> patientPointer)
{
    patientPointer -> addDiseaseToRecord(diseaseName);
    string message = "U pacjenta #" + to_string((*patientPointer).getIdentifier()) + " zdiagnozowano nową chorbę: " + diseaseName + ". ";
    if (diseaseName == "Zapalenie płuc"){
        message += addPatientMedicine("Syrop na kaszel", move(patientPointer));
    }
    return message;
}

string Doctor::addPatientMedicine(string medicationName, shared_ptr<Patient> patientPointer)
{
    patientPointer -> addMedicationToRecord(medicationName);
    string message = "Pacjentowi #" + to_string((*patientPointer).getIdentifier()) + " przypisano: " + medicationName + ". ";
    return message;
}

string Doctor::consulatationWithPatient(shared_ptr<Patient> patientPointer)
{
    string message = "Lekarz #" + to_string(getIdentifier()) + " przeprowadził konsultacje z pacjentem # " + to_string(patientPointer -> getIdentifier()) + ". ";
    shared_ptr<Patient> tempPtr = make_shared<Patient>(*patientPointer);
    string randomDiseaseMessage = (addRandomDisease(tempPtr));
    message += randomDiseaseMessage;
    string surgeryMessage = checkForSurgery(move(patientPointer));
    if (surgeryMessage != ""){
        message += surgeryMessage;
    }
    return message;
}

ostream& operator<<(ostream& stream, const Doctor& doctor){ // <== Object????????
    stream << "Lekarz #" << doctor.getIdentifier();
    return stream;
};

string Doctor::carryOutSurgery(shared_ptr<Patient> patientPointer){
    string message = "Doktor #" + to_string(getIdentifier()) + " przeprowadził operację na pacjencie #";
    message += to_string((patientPointer -> getIdentifier())) + ". ";
    shared_ptr<HealthRecord> healthRecord = move(patientPointer -> healthRecordPointer);
    healthRecord -> removeADisease("Rak");
    return message;
};

string Doctor::addRandomDisease(shared_ptr<Patient> patientPointer){
    RNG randomNumberGenerator = RNG();
    unsigned int diseaseIndex = randomNumberGenerator.getRandomNumber(0, 3);
    string randomDisease = possibleDiseases_[diseaseIndex];
    return addPatientDisease(randomDisease, move(patientPointer));
};

string Doctor::checkForSurgery(shared_ptr<Patient> patientPointer){
    vector <string> diseases = (patientPointer -> healthRecordPointer) -> getDiseases();
    for (const auto& disease : diseases){
        if (disease == "Rak"){
            return carryOutSurgery(move(patientPointer));
        }
    }
    return "";
};

const string Doctor::possibleDiseases_[4] = {"Koronawirus", "Zapalenie płuc", "Rak", "Choroba serca"};

string Doctor::getRecommendedUnit(string disease){
    if (disease == "Koronawirus"){
        return "Oddział zakaźny";
    }
    if (disease == "Zapalenie płuc"){
        return "Oddział zakaźny";
    }
    if (disease == "Rak"){
        return "Oddział wewnętrzny";
    }
    if (disease == "Choroba serca"){
        return "Oddział kardiologiczny";
    }
    return "Oddział wewnętrzny";
};