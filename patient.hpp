#ifndef PATIENT_HPP
#define PATIENT_HPP
#include <memory>
#include <iostream>
#include <vector>
#include "person.hpp"
#include "health_record.hpp"


using namespace std;


class Patient: public Person{
protected:
    // shared_ptr<Unit> unitPointer_;
    // shared_ptr<Room> roomPointer_;
    unsigned int timeToGo_;
    bool hasRoom_;
    unsigned int maxTimeUntilNextCheckup_;
    unsigned int timeUntilNextCheckup_;
    bool aboutToLeave_;
    signed int timeUntilOperation_;
public:
    Patient();
    Patient(string name, string surname, shared_ptr<HealthRecord> healthRecord);
    void addMedicationToRecord(string medication);
    void addDiseaseToRecord(string disease);
    void setTimeToGo(unsigned int timeToGo);
    unsigned int getTimeToGo();
    void setHealthRecordPointer(shared_ptr<HealthRecord> newHealthRecordPointer);
    friend std::ostream& operator<<(std::ostream& os, const Patient& patient);
    void moveInTimeByAnIteration();
    bool hasRoom();
    void setHasRoom(bool hasRoom);
    void setMaxTimeUntilCheckup(unsigned int time);
    unsigned int getMaxTimeUntilCheckup();
    void setTimeUntilCheckup(unsigned int time);
    unsigned int getTimeUntilCheckup();
    bool isAboutToLeave();
    void setAboutToLeave(bool newAboutToLeave);
    signed int getTimeUntilOperation();
    void setTimeUntilOperation(unsigned int time);
    string getADisease();
    vector<string> getDiseases();
    shared_ptr<HealthRecord> healthRecordPointer;
};

#endif