#pragma once

#include "AbstractModule.h"
#include "ListTemplate.h"
#include <string>
#include <ostream>


// Simple Student data type
struct Student 
{
    int id{};
    std::string name;
};

// allow printing Student 
std::ostream& operator<<(std::ostream& os, const Student& s);

class StudentModule : public AbstractModule 
{
 public:
    void addStudent();
    bool removeStudentById(int id);

    const Student* findbyID(int id) const;
    std::vector<Student> findStudentbyName(const std::string& name) const;

    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);

    void displayModuleInfo() override;

 private:
    ListTemplate<Student> students_;
};



