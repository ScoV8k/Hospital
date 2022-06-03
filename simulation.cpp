#include <iostream>
#include <random>
#include <chrono>
#include <string>
#include <thread>
#include "simulation.hpp"
#include "hospital.hpp"
#include "file_manager.hpp"
#include "random_number_generator.hpp"
#include "file_manager_exception.hpp"


using namespace std;


Simulation::Simulation(string inputFilePath, string logFilePath, unsigned int length, unsigned int sleepTime):
length_(length), dayNumber_(1), fileManager_(FileManager(inputFilePath, logFilePath)), sleepTime_(sleepTime){
    try{
        hospital_ = fileManager_.loadHospitalData();
    }
    catch (FileManagerException& e){
        std::cerr << e.what() << endl;
        hospital_ = Hospital();
    };
};

Simulation::Simulation(){};

//settery

void Simulation::setLength(unsigned int length){
    length_ = length;
};

void Simulation::setDayNumber(unsigned int dayNumber){
    dayNumber_ = dayNumber;
};

//gettery

unsigned int Simulation::getLength(){
    return length_;
};

unsigned int Simulation::getDayNumber(){
    return dayNumber_;
};

//inne

void Simulation::runAnIteration(){
    // cout << "początk run an iteration" << endl;
    string eventData;
    RNG randomNumberGenerator = RNG();
    unsigned int randomEventNumber = randomNumberGenerator.getRandomNumber(0, 3);
    vector<string> eventMessages;
    switch (randomEventNumber){
        case 0:
            eventMessages.push_back(hospital_.newPatient("Andrzej", "Nowak"));
            eventMessages.push_back(hospital_.newPatient("Jan", "Egbert"));
            eventMessages.push_back(hospital_.newPatient("Michał", "Kowalski"));
            break;
        case 1:
            eventMessages.push_back(hospital_.newPatient("Róża", "Kowalska"));
            eventMessages.push_back(hospital_.newPatient("Dawid", "Nowak"));
            break;
        case 2:
            eventMessages.push_back(hospital_.newPatient("Janina", "Kowalska"));
            break;
        case 3:
            eventMessages.push_back("Nie przyszedł żaden nowy pacjent");
            break;
        default:
            break;
    }
    vector<string> events = moveHospitalInTimeByAnIteration();
    for (string message : events){
        eventMessages.push_back(message);
    }
    eventMessages.push_back("Ilość pacjentów pod koniec iteracji: " + to_string(hospital_.getPatientAmount()));
    string eventsFormatted = formatEvents(eventMessages);
    std::cout << eventsFormatted << endl;
    eventString_ += eventsFormatted;
    // saveIterationDataToFile(eventsFormatted);
    dayNumber_++;
};

void Simulation::saveIterationDataToFile(){
    fileManager_.saveDataToFile(eventString_);
};

string Simulation::formatEvents(vector<string> eventVector){
    string eventsFormatted;
    for (string event : eventVector){
        eventsFormatted += event;
        eventsFormatted += "\n";
    }
    eventsFormatted += "====================\n";
    return eventsFormatted;
};

vector<string> Simulation::moveHospitalInTimeByAnIteration(){
    vector<string> events = hospital_.moveEverythingInTimeByAnIteration();
    return events;
};

void Simulation::runTheSimulation(){
    while (dayNumber_ != length_){
        runAnIteration();
        sleep(sleepTime_);
    }
    saveIterationDataToFile();
};

void Simulation::sleep(unsigned int milliseconds){
    chrono::milliseconds time(milliseconds);
    this_thread::sleep_for(time);
};