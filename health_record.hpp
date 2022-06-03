#ifndef HEALTH_RECORD_HPP
#define HEALTH_RECORD_HPP
#include <iostream>
#include <memory>


class HealthRecord{
public:
    HealthRecord();
    HealthRecord(vector<string> diseases, vector<string> medication);
    //gettery
    vector<string> getDiseases();
    vector<string> getMedication();
    //settery
    void setDiseases(vector<string> diseases);
    void setMedication(vector<string> medication);
    void addDisease(string disease);
    void addMedication(string medication);
    string getADisease();
    string getAMedication();
    void removeMedication(string drugToRemove);
    void removeADisease(string diseaseToRemove);
protected:
    vector<string> diseases_;
    vector<string> medication_;
};

#endif