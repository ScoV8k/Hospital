#include <memory>
#include <vector>
#include <iostream>
#include "patient.hpp"
#include "health_record.hpp"

HealthRecord::HealthRecord(){};

HealthRecord::HealthRecord(vector<string> diseases, vector<string> medication):
diseases_(diseases), medication_(medication){};

vector<string> HealthRecord::getDiseases()
{
    return diseases_;
};

vector<string> HealthRecord::getMedication()
{
    return medication_;
};

void HealthRecord::setDiseases(vector<string> diseases)
{
    diseases_ = diseases;
};

void HealthRecord::setMedication(vector<string> medication)
{
    medication_ = medication;
};

void HealthRecord::addDisease(string disease)
{
    diseases_.push_back(disease);
};

void HealthRecord::addMedication(string medication)
{
    medication_.push_back(medication);
};

string HealthRecord::getADisease(){
    if (diseases_.size() != 0){
        string disease = diseases_.at(0);
        return disease;
    }
    return "";
};
string HealthRecord::getAMedication(){
    if (medication_.size() != 0){
        string medication = medication_.at(0);
        return medication;
    }
    return "";
};

void HealthRecord::removeMedication(string drugToRemove){
    for (unsigned int i = 0; i < medication_.size(); i++){
        if (medication_[i] == drugToRemove){
            medication_.erase(medication_.begin() + i);
            return;
        }
    }
};

void HealthRecord::removeADisease(string diseaseToRemove){
    for (unsigned int i = 0; i < diseases_.size(); i++){
        if (diseases_[i] == diseaseToRemove){
            diseases_.erase(diseases_.begin() + i);
            return;
        }
    }
};