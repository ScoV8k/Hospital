#include <string>
#include <memory>
#include <vector>
#include "warder.hpp"
#include "patient.hpp"
#include "random_number_generator.hpp"
#include "health_record.hpp"


using namespace std;


Warder::Warder(string name, string surname):
Employee(name, surname){};

vector<string> Warder::giveMedicine(vector<shared_ptr<Patient>> patients){
    vector<string> events;
    RNG randomNumberGenerator = RNG();
    for (auto& patient : patients){
        unsigned int random = randomNumberGenerator.getRandomNumber(0, 1);
        if (random == 0){
            shared_ptr<HealthRecord> healthRecord = make_shared<HealthRecord>(*(patient -> healthRecordPointer));
            healthRecord -> removeMedication("Syrop na kaszel");
            healthRecord -> removeADisease("Zapalenie płuc");
            string message = "Pacjent #" + to_string(patient -> getIdentifier()) + " wyzdrowiał z zapalenia płuc";
            events.push_back(message);
        }
    }
    return events;
};