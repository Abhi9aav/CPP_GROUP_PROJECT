#pragma once

#include "AbstractModule.h"
#include "ListTemplate.h"
#include <string>
#include <ostream>
#include <vector>

// Simple Faculty data type
struct Faculty 
{
    int id{};
    std::string name;
};

std::ostream& operator<<(std::ostream& os, const Faculty& f);

class FacultyModule : public AbstractModule 
{
 public:
    void addFaculty();
    bool removeFacultyById(int id);

    const Faculty* findFacultyById(int id) const;
    std::vector<Faculty> findFacultyByName(const std::string& name) const;

    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);

    void displayModuleInfo() override;

 private:
    ListTemplate<Faculty> faculty_;
};



