#include "employee.hpp"

using namespace std;

Employee::Employee(string name, string surname):
Person(name, surname), occupied_(false){};

bool Employee::isOcuppied(){
    return occupied_;
};

void Employee::setOccupied(bool occupiedState){
    occupied_ = occupiedState;
};