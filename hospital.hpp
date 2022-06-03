#ifndef HOSPITAL_HPP
#define HOSPITAL_HPP
#include <iostream>
#include <vector>
#include <memory>
#include "patient.hpp"
#include "unit.hpp"
#include "doctor.hpp"
#include "nurse.hpp"
#include "lifeguard.hpp"
#include "room.hpp"


using namespace std;


class Hospital{
protected:
    unsigned int queueLength_;
public:
    vector<shared_ptr<Patient>> queue;
    vector<unique_ptr<Unit>> units;
    vector<unique_ptr<Doctor>> doctors;
    vector<unique_ptr<Nurse>> nurses;
    vector<unique_ptr<Lifeguard>> lifeguards;
    vector<shared_ptr<HealthRecord>> healthRecords;
    Hospital();
    void addUnit(string name);
    Unit findUnit(string unitName);
    int getStaffSize() const; // testowanie
    int getUnitsSize() const;
    int getQueueSize() const;
    int getHealthRecordsSize() const;
    // vector<Patient> get_patients() const;
    friend std::ostream& operator<<(std::ostream& os, const Hospital& hospital);
    string printPatients();
    void addDoctor(string name, string surname);
    void addNurse(string name, string surname);
    void addLifeguard(string name, string surname);
    // void addDoctor(unique_ptr<Doctor>& doctor);
    // void addNurse(unique_ptr<Nurse>& nurse);
    // void addLifeguard(unique_ptr<Lifeguard>& lifeguard);
    vector<string> moveEverythingInTimeByAnIteration();
    void addToQueue(shared_ptr<Patient> patientPointer);
    vector<string> examinePatientsInQueue();
    unsigned int getQueueLength();
    void setQueueLength(unsigned int queueLength);
    string newPatient(string name, string surname);
    void moveQueue();
    unsigned int getPatientAmount();
};

#endif