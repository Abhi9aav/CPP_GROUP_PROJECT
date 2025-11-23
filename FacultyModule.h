#ifndef FACULTYMODULE_H
#define FACULTYMODULE_H

#include "AbstractModule.h"
#include "ListTemplate.h"
#include <string>
#include <fstream>
using namespace std;

// Simple Faculty data type
struct Faculty 
{
    int id;
    string name;
};

inline ostream& operator<<(ostream& os, const Faculty& f) 
{
    os << f.id << " : " << f.name;
    return os;
}

class FacultyModule : public AbstractModule 
{
 protected:
    ListTemplate<Faculty> facultyList;

 public:
    void addFaculty();
    bool removeFacultyById(int id);
    Faculty* findFacultyById(int id);
    void saveFacultyToFile(const string& filename);
    void loadFacultyFromFile(const string& filename);
    void displayModuleInfo() override;
};

#endif

