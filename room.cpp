#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "room.hpp"
#include "patient.hpp"
#include "random_number_generator.hpp"
#include "warder.hpp"


using namespace std;


Room::Room(){
    warder = make_unique<Warder>("Anna", "Kowalska");
};

Room::Room(unsigned int newNumber, unsigned int newCapacity):
number(newNumber), capacity(newCapacity){
    calculateFreePlaces();
    warder = make_unique<Warder>("Anna", "Kowalska");
};

Room::~Room(){};

unsigned int Room::getNumber() const{
    return number;
};

unsigned int Room::getCapacity() const{
    return capacity;
};

unsigned int Room::getFreePlaces() const{
    return freePlaces;
};

void Room::calculateFreePlaces(){
    freePlaces = getCapacity() - roomPatients.size();
};

bool Room::findPatientById(unsigned int ID){
    for (const auto& patient : roomPatients) {
        if ((*patient).getIdentifier() == ID) {
            return true;
        }
    }
    return false;
};

string Room::addPatient(shared_ptr<Patient> patientPointer, string unitName, unsigned int unitId){
    if (freePlaces == 0)
    {
        throw std::out_of_range("No places in room");
    }
    if (!findPatientById(patientPointer -> getIdentifier())){
        string message = "Pacjent #" + to_string(patientPointer -> getIdentifier());
        message += " został przydzielony do oddziału: " + unitName + " #" + to_string(unitId);
        message += ", do pokoju " + to_string(getNumber()) + " #" + to_string(getIdentifier());
        patientPointer -> setHasRoom(true);
        roomPatients.push_back(move(patientPointer));
        calculateFreePlaces();
        return message;
    }
    else{
        throw std::invalid_argument("Pacjent już jest w tym pokoju");
    }
};

string Room::printPatientsInRoom() const
{
    string text = "Patients: ";
    for (const auto& patient: roomPatients)
    {
        text += "\n\t" + to_string((*patient).getIdentifier()) + " " + (*patient).getName() + " " + (*patient).getSurname();
    }
    return text;
};

std::ostream& operator<<(std::ostream& os, const Room& room) {
    os << "Room #" << room.getNumber();
    return os;
};

vector<string> Room::moveEverythingInTimeByAnIteration(){
    vector<string> events;
    for (unsigned int i = 0; i < roomPatients.size(); i++){
        auto& patientPointer = roomPatients[i];
        patientPointer -> moveInTimeByAnIteration();
        if (patientPointer -> getTimeToGo() <= 0){
            patientPointer -> setAboutToLeave(true);
            roomPatients.erase(roomPatients.begin() + i);
            i--;
            //unit queue sprawdzany z poziomu unit
            string message = "Pacjent #" + to_string(patientPointer -> getIdentifier()) += " opuścił szpital";
            events.push_back(message);
        }
        if (patientPointer -> getTimeUntilCheckup() <= 0){
            patientPointer -> setTimeUntilCheckup(patientPointer -> getMaxTimeUntilCheckup());
            string message = "Pacjent #" + to_string(patientPointer -> getIdentifier()) += " idzie na rutynowe badania";
            events.push_back(message);
        }
    }
    vector<string> messages = warderGiveMedicine();
    for (string message : messages){
        events.push_back(message);
    }
    return events;
};

vector<shared_ptr<Patient>> Room::checkForRoutineCheckup(){
    vector<shared_ptr<Patient>> patientsForcheckup;
    for (auto& patient : roomPatients){
        if ((patient -> getTimeUntilCheckup()) == 0){
            shared_ptr<Patient> ptr = make_shared<Patient>(*patient);
            patientsForcheckup.push_back(move(ptr));
        }
    }
    return patientsForcheckup;
};

vector<shared_ptr<Patient>> Room::checkForPatientsNeedingMedicine(){
    vector<shared_ptr<Patient>> patientsInNeedOfDrugs;
    for (auto& patient : roomPatients){
        vector<string> medication = (patient -> healthRecordPointer) -> getMedication();
        for (auto& drug : medication){
            if (drug == "Syrop na kaszel"){
                shared_ptr<Patient> patientPointer = make_shared<Patient>(*patient);
                patientsInNeedOfDrugs.push_back(move(patientPointer));
            }
        }
    }
    return patientsInNeedOfDrugs;
};

vector<string> Room::warderGiveMedicine(){
    vector<shared_ptr<Patient>> patientsNeedingMedicine = checkForPatientsNeedingMedicine();
    return (warder -> giveMedicine(patientsNeedingMedicine));
};