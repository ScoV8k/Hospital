#ifndef FILE_MANAGER_EXCEPTION_H
#define FILE_MANAGER_EXCEPTION_H
#include <stdexcept>


using namespace std;


class FileManagerException : public invalid_argument
{
public:
    FileManagerException(string message);
};

#endif
