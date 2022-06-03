#include <iostream>
#include <vector>
#include <memory>
#include "room.hpp"
#include "unit.hpp"
#include "random_number_generator.hpp"

using namespace std;


Unit::Unit(){};

Unit::Unit(string newName):
name(newName){
    unique_ptr<Room> room1 = make_unique<Room>(12, 60);
    unique_ptr<Room> room2 = make_unique<Room>(234, 30);
    unique_ptr<Room> room3 = make_unique<Room>(27, 12);
    unique_ptr<Room> room4 = make_unique<Room>(345, 30);
    unique_ptr<Room> room5 = make_unique<Room>(211, 25);

    rooms.push_back(move(room1));
    rooms.push_back(move(room2));
    rooms.push_back(move(room3));
    rooms.push_back(move(room4));
    rooms.push_back(move(room5));
};

string Unit::getName()
{
    return name;
};

int Unit::getNumberOfPatients()
{
    int amount = 0;
    for (const auto& roomPointer: rooms)
    {
        amount += (*roomPointer).roomPatients.size();
    }
    return amount;
};

string Unit::addPatientToRoom(shared_ptr<Patient> patientPointer){
    RNG randomNumberGenerator = RNG();
    int index = randomNumberGenerator.getRandomNumber(0, (rooms.size()-1));
    if (rooms[index] -> getFreePlaces() > 0)
    {
        return rooms[index] -> addPatient(move(patientPointer), getName(), getIdentifier());
    }
    else
    {
        for (const auto& room: rooms){
            if (room -> getFreePlaces() > 0){
                return room -> addPatient(move(patientPointer), getName(), getIdentifier());
            }
        }
    }
    return "Nie ma wolnych miejsc. Pacjent #" + to_string(patientPointer -> getIdentifier())
    + "zostaje oddelegowany do innego szpitala";
}

vector<string> Unit::moveEverythingInTimeByAnIteration(){
    vector<string> events;
    for (const auto& roomPointer: rooms){
        vector<string> messages = (roomPointer->moveEverythingInTimeByAnIteration());
        for (string message : messages){
            events.push_back(message);
        }
    }
    checkForRoutineCheckup();
    vector<string> response = examinePatientsInQueue();
    for (string msg : response){
        events.push_back(msg);
    }
    return events;
};

void Unit::checkForRoutineCheckup(){
    for (auto& room : rooms){
        vector<shared_ptr<Patient>> patientsForCheckup = move(room -> checkForRoutineCheckup());
        for (auto& patient : patientsForCheckup){
            queue.push_back(move(patient));
        }
    }
};

vector<string> Unit::examinePatientsInQueue(){
    vector<string> events;
    if (queue.size() != 0){
        unsigned int doctorIndex = 0;
        while ((doctorIndex != doctors.size()) && (queue[0] != nullptr)){
            if (doctors[doctorIndex] -> isOcuppied() == false){
                if (queue[0] -> isAboutToLeave()){
                    queue.erase(queue.begin());
                    continue;
                }
                string doctorMessage = (doctors[doctorIndex] -> consulatationWithPatient(move(queue[0])));
                events.push_back(doctorMessage);
                queue.erase(queue.begin());
            }
            doctorIndex++;
        }
    }
    return events;
};

unsigned int Unit::getPatientAmount(){
    unsigned int total = 0;
    for (const auto& room : rooms){
        total += (room -> roomPatients.size());
    }
    return total;
};

void Unit::addDoctor(string name, string surname){
    unique_ptr<Doctor> doctor = make_unique<Doctor>(name, surname);
    doctors.push_back(move(doctor));
};

void Unit::addNurse(string name, string surname){
    unique_ptr<Nurse> nurse = make_unique<Nurse>(name, surname);
    nurses.push_back(move(nurse));
};

void Unit::addLifeguard(string name, string surname){
    unique_ptr<Lifeguard> lifeguard = make_unique<Lifeguard>(name, surname);
    lifeguards.push_back(move(lifeguard));
};