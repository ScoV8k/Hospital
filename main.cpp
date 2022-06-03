#include "unit.hpp"
#include "patient.hpp"
#include "health_record.hpp"
#include "object.hpp"
#include "person.hpp"
#include "room.hpp"
#include "employee.hpp"
#include "lifeguard.hpp"
#include "hospital.hpp"
#include "nurse.hpp"
#include "doctor.hpp"
#include "file_manager.hpp"
#include "simulation.hpp"
#include <iostream>


using namespace std;


int main(int argc, char* argv[]){
    cout<<"Poczatek programu"<<endl;
    string input = argv[1];
    string log = argv[2];
    string length = argv[3];
    string sleepTime = argv[4];

    Simulation simulation = Simulation(input, log, stoi(length), stoi(sleepTime));
    simulation.runTheSimulation();
    return 0;
};