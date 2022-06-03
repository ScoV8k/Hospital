#include <memory>
#include <string>
#include <iostream>
#include <vector>
#include "unit.hpp"
#include "patient.hpp"


using namespace std;


Patient::Patient(string name, string surname, shared_ptr<HealthRecord> healthRecord):
Person(name, surname){
    healthRecordPointer = move(healthRecord);
    timeUntilNextCheckup_ = 5;
    timeToGo_ = 8;
    aboutToLeave_ = false;
    hasRoom_ = false;
};

void Patient::setHealthRecordPointer(shared_ptr<HealthRecord> newHealthRecordPointer)
{
    healthRecordPointer = move(newHealthRecordPointer);
};

std::ostream& operator<<(std::ostream& os, const Patient& patient) {
    os << "Pacjent #" << patient.getIdentifier();
    return os;
};

void Patient::moveInTimeByAnIteration(){
    timeToGo_--;
    timeUntilNextCheckup_--;
};

void Patient::setTimeToGo(unsigned int timeToGo){
    timeToGo_ = timeToGo;
};

unsigned int Patient::getTimeToGo(){
    return timeToGo_;
};

void Patient::addMedicationToRecord(string medication)
{
    (*healthRecordPointer).addMedication(medication);
}

void Patient::addDiseaseToRecord(string disease)
{
    (*healthRecordPointer).addDisease(disease);
}

bool Patient::hasRoom(){
    return hasRoom_;
};

void Patient::setHasRoom(bool hasRoom){
    hasRoom_ = hasRoom;
};

void Patient::setMaxTimeUntilCheckup(unsigned int time){
    maxTimeUntilNextCheckup_ = time;
};

unsigned int Patient::getMaxTimeUntilCheckup(){
    return maxTimeUntilNextCheckup_;
};

void Patient::setTimeUntilCheckup(unsigned int time){
    timeUntilNextCheckup_ = time;
};

unsigned int Patient::getTimeUntilCheckup(){
    return timeUntilNextCheckup_;
};

bool Patient::isAboutToLeave(){
    return aboutToLeave_;
};

void Patient::setAboutToLeave(bool newAboutToLeave)
{
    aboutToLeave_ = newAboutToLeave;
};

signed int Patient::getTimeUntilOperation(){
    return timeUntilOperation_;
};

void Patient::setTimeUntilOperation(unsigned int time){
    timeUntilOperation_ = time;
};

string Patient::getADisease(){
    return (healthRecordPointer -> getADisease());
};

vector<string> Patient::getDiseases(){
    return (healthRecordPointer -> getDiseases());
};