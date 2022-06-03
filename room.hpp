#ifndef ROOM_HPP
#define ROOM_HPP
#include <iostream>
#include <vector>
#include <memory>
#include "patient.hpp"
#include "object.hpp"
#include "warder.hpp"


using namespace std;


class Room: public Object{
protected:
    unsigned int number;
    unsigned int capacity;
    unsigned int freePlaces;
public:
    vector<shared_ptr<Patient>> roomPatients;
    unique_ptr<Warder> warder;
    Room();
    Room(unsigned int newNumber, unsigned int newCapacity);
    ~Room();
    unsigned int getNumber() const;
    unsigned int getCapacity() const;
    unsigned int getFreePlaces() const;
    void calculateFreePlaces();
    bool findPatientById(unsigned int ID);
    string addPatient(shared_ptr<Patient> patientPoint, string unitName, unsigned int unitId);
    void removePatientById(unsigned int ID);
    string printPatientsInRoom() const;
    friend std::ostream& operator<<(std::ostream& os, const Room& room);
    vector<string> moveEverythingInTimeByAnIteration();
    vector<shared_ptr<Patient>> checkForRoutineCheckup();
    vector<shared_ptr<Patient>> checkForPatientsNeedingMedicine();
    vector<string> warderGiveMedicine();
};

#endif