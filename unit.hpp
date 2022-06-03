#ifndef UNIT_HPP
#define UNIT_HPP
#include <iostream>
#include <vector>
#include <memory>
#include "room.hpp"
#include "doctor.hpp"
#include "nurse.hpp"
#include "lifeguard.hpp"


using namespace std;


class Unit: public Object{
protected:
    string name;
public:
    Unit();
    Unit(string newName);
    vector<unique_ptr<Room>> rooms;
    // Unit(string name, vector<Room>& rooms);
    string getName();
    // vector<Room>& getRooms();
    int getNumberOfPatients();// const;
    string getRoomsString();// const;
    bool findPatientById(unsigned int identifier);
    string addPatientToRoom(shared_ptr<Patient> patientPoint);
    void removePatientById(unsigned int identidfier);
    string patientList();
    string printPatients();
    friend std::ostream& operator<<(std::ostream& os, const Unit& unit);
    vector<string> moveEverythingInTimeByAnIteration();
    vector<shared_ptr<Patient>> queue;
    void checkForRoutineCheckup();
    vector<string> examinePatientsInQueue();
    unsigned int getPatientAmount();
    vector<unique_ptr<Doctor>> doctors;
    vector<unique_ptr<Nurse>> nurses;
    vector<unique_ptr<Lifeguard>> lifeguards;
    void addDoctor(string name, string surname);
    void addNurse(string name, string surname);
    void addLifeguard(string name, string surname);

};

#endif