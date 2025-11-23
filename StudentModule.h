#ifndef STUDENTMODULE_H
#define STUDENTMODULE_H

#include "AbstractModule.h"
#include "ListTemplate.h"
#include <string>
#include <fstream>
using namespace std;

// Simple Student data type
struct Student 
{
    int id;
    string name;
};

// allow printing Student 
inline ostream& operator<<(ostream& os, const Student& s) 
{
    os << s.id << " : " << s.name;
    return os;
}

class StudentModule : public AbstractModule 
{
 protected:
    ListTemplate<Student> students;
 public:
    void addStudent();
    bool removeStudentById(int id);
    void saveStudentsToFile(const string& filename);
    void loadStudentsFromFile(const string& filename);
    void displayModuleInfo() override;
};

#endif

