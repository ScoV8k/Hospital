#ifndef SIMULATION_HPP
#define SIMULATION_HPP
#include "hospital.hpp"
#include "file_manager.hpp"
#include <string>


using namespace std;


class Simulation{
public:
    Simulation();
    Simulation(string inputFilePath, string logFilePath, unsigned int length, unsigned int sleepTime);
    //setter
    void setHospital(Hospital& hospital);
    void setLength(unsigned int length);
    void setDayNumber(unsigned int dayNumber);
    void setFileManager(FileManager fileManager);
    //getter
    Hospital& getHospital();
    unsigned int getLength();
    unsigned int getDayNumber();
    FileManager getFileManager();
    //inne
    void runAnIteration();
    void runTheSimulation();
    void saveIterationDataToFile();
    string formatEvents(vector<string> eventVector);
    vector<string> moveHospitalInTimeByAnIteration();
    /*
    Powyższa funkcja jest wywoływana na szpitalu, szpital wykonuje działania na swoich
    kolekcjach (np. pracownikach) i wywołuje podobną funkcję na obiektach takich jak oddziały
    */
    void sleep(unsigned int milliseconds);
private:
    Hospital hospital_;
    unsigned int length_;
    unsigned int dayNumber_;
    FileManager fileManager_;
    unsigned int sleepTime_;
    string eventString_;
};

#endif