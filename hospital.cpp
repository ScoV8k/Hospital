#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "hospital.hpp"
#include "unit.hpp"
#include "patient.hpp"
#include "doctor.hpp"
#include "lifeguard.hpp"
#include "nurse.hpp"


using namespace std;


Hospital::Hospital(){
    unique_ptr<Unit> unit1 = make_unique<Unit>("Oddział kardiologiczny");
    unique_ptr<Unit> unit2 = make_unique<Unit>("Oddział zakaźny");
    unique_ptr<Unit> unit3 = make_unique<Unit>("Oddział wewnętrzny");
    units.push_back(move(unit1));
    units.push_back(move(unit2));
    units.push_back(move(unit3));

};

void Hospital::addUnit(string name){
    unique_ptr<Unit> unit = make_unique<Unit>(name); //, rooms);
    units.push_back(move(unit));
};

string Hospital::newPatient(string name, string surname){
    shared_ptr<HealthRecord> healthRecord = make_shared<HealthRecord>();
    shared_ptr<HealthRecord> healthRecord2 = make_shared<HealthRecord>(*healthRecord);
    shared_ptr<Patient> patientPointer = make_shared<Patient>(name, surname, move(healthRecord));
    healthRecords.push_back(move(healthRecord2));
    string message = "Do szpitala przybył pacjent #" + to_string(patientPointer -> getIdentifier());
    addToQueue(move(patientPointer));
    return message;
};

void Hospital::addToQueue(shared_ptr<Patient> patientPointer)
{
    queue.push_back(move(patientPointer));
};

int Hospital::getStaffSize() const{
    int size;
    size = nurses.size() + lifeguards.size() + doctors.size();
    return size;
}

int Hospital::getUnitsSize() const{
    return units.size();
}

int Hospital::getHealthRecordsSize() const{
    return healthRecords.size();
}

int Hospital::getQueueSize() const {
    return queue.size();
}

void Hospital::addDoctor(string name, string surname){
    unique_ptr<Doctor> doctor = make_unique<Doctor>(name, surname);
    doctors.push_back(move(doctor));
};

void Hospital::addNurse(string name, string surname){
    unique_ptr<Nurse> nurse = make_unique<Nurse>(name, surname);
    nurses.push_back(move(nurse));
};

void Hospital::addLifeguard(string name, string surname){
    unique_ptr<Lifeguard> lifeguard = make_unique<Lifeguard>(name, surname);
    lifeguards.push_back(move(lifeguard));
};


vector<string> Hospital::moveEverythingInTimeByAnIteration(){
    vector<string> events;
    vector<string> patientExaminationMsgs = examinePatientsInQueue();
    for (string message : patientExaminationMsgs){
        events.push_back(message);
    }
    for (const auto& unitPointer: units){
        vector<string> messages = (unitPointer -> moveEverythingInTimeByAnIteration());
        for (string message : messages){
            events.push_back(message);
        }
    }
    return events;
};

unsigned int Hospital::getQueueLength(){
    return queueLength_;
};

void Hospital::setQueueLength(unsigned int queueLength){
    queueLength_ = queueLength;
};

vector<string> Hospital::examinePatientsInQueue(){
    vector<string> events;
    if (queue.size() != 0){
        unsigned int doctorIndex = 0;
        while ((doctorIndex != doctors.size()) && (queue[0] != nullptr)){
            if (doctors[doctorIndex] -> isOcuppied() == false){
                if (queue[0] -> hasRoom() == false){
                    shared_ptr<Patient> patientPointer = move(queue[0]);
                    shared_ptr<Patient> ptr = make_shared<Patient>(*patientPointer);
                    string consultationMessage = (doctors[doctorIndex] -> consulatationWithPatient(ptr));
                    vector<string> diseases = (patientPointer -> getDiseases());
                    string disease;
                    if (diseases.size() != 0){
                        disease = diseases[0];
                    }
                    string recommendedUnit = doctors[doctorIndex] -> getRecommendedUnit(disease);
                    for (auto& unit : units){
                        if ((unit -> getName()) == recommendedUnit){
                            consultationMessage += (unit -> addPatientToRoom(move(patientPointer)));
                            events.push_back(consultationMessage);
                        }
                    }
                }
                // cout<<queue.size()<<endl;
                queue.erase(queue.begin());
            }
            doctorIndex++;
        }
    }
    return events;
};

unsigned int Hospital::getPatientAmount(){
    unsigned int total = 0;
    for (auto& unit : units){
        total += (unit -> getPatientAmount());
    }
    return total;
};