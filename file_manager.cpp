#include "file_manager.hpp"
#include "patient.hpp"
#include "doctor.hpp"
#include "nurse.hpp"
#include "lifeguard.hpp"
#include <fstream>
#include <exception>
#include <string>
#include "file_manager_exception.hpp"

using namespace std;

FileManager::FileManager(){};

FileManager::FileManager(string inputFilePath, string outputFilePath):
inputFilePath_(inputFilePath), outputFilePath_(outputFilePath){};

Hospital FileManager::loadHospitalData()
{
    fstream file;
    file.open(inputFilePath_);
    if (file.good())
    {
        Hospital hospital;
        while (!file.eof())
        {
            string entryType;
            file >> entryType;
            if (entryType == "Simulation")
            {
                //...
            }
            else if (entryType == "Person")
            {
                string name;
                string surname;
                string role;
                file >> name >> surname >> role;
                if (role == "Patient"){
                    unsigned int departament;
                    file >> departament;
                    shared_ptr<HealthRecord> healthRecord = make_shared<HealthRecord>();
                    shared_ptr<HealthRecord> healthRecord2 = make_shared<HealthRecord>(*healthRecord);
                    shared_ptr<Patient> patientPointer = make_shared<Patient>(name, surname, move(healthRecord));
                    file >> entryType;
                    unsigned int elementAmount;
                    if (entryType == "Diseases"){
                        file >> elementAmount;
                        for (unsigned int i = 0; i<elementAmount; i++){
                            string disease;
                            file >> disease;
                            patientPointer->addDiseaseToRecord(disease);
                        }
                    }
                    file >> entryType;
                    if (entryType == "Medicines"){
                        file >> elementAmount;
                        for (unsigned int i = 0; i<elementAmount; i++){
                            string medication;
                            file >> medication;
                            patientPointer->addMedicationToRecord(medication);
                        }
                    }
                    hospital.healthRecords.push_back(move(healthRecord2));
                    hospital.units[departament] -> addPatientToRoom(move(patientPointer));
                    //...
                }
                else if (role == "Employee"){
                    string specialization;
                    string place;
                    file >> specialization >> place;
                    if (place == "Hospital")
                    {
                        if (specialization == "Doctor"){
                            hospital.addDoctor(name, surname);
                        }
                        else if (specialization == "Nurse"){
                            hospital.addNurse(name, surname);
                        }
                        else if (specialization == "Lifeguard"){
                            hospital.addLifeguard(name, surname);
                        }
                    }
                    else if (place == "Unit")
                    {
                        int unit;
                        file >> unit;
                        if (specialization == "Doctor"){
                            hospital.units[unit] -> addDoctor(name, surname);
                        }
                        else if (specialization == "Nurse"){
                            hospital.units[unit] -> addNurse(name, surname);
                        }
                        else if (specialization == "Lifeguard"){
                            hospital.units[unit] -> addLifeguard(name, surname);
                        }
                    }
                }
            }
        }

        file.close();
        return hospital;
    }
    throw FileManagerException("An error occured when reading the file");
};

void FileManager::saveDataToFile(string string)
{
    fstream file;
    file.open(outputFilePath_);
    if (file.good()){
        file << string;
    }
    // file.close();
};
