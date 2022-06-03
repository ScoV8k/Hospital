#ifndef FILE_MANAGER_HPP
#define FILE_MANAGER_HPP
#include <iostream>
#include "hospital.hpp"

using namespace std;

class FileManager{
public:
    FileManager();
    FileManager(string inputFilePath, string outputFilePath);
    Hospital loadHospitalData();
    void saveDataToFile(string eventsFormatted);
private:
    string inputFilePath_;
    string outputFilePath_;
};

#endif