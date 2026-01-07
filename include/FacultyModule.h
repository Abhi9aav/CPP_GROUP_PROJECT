#pragma once

#include "AbstractModule.h"
#include "ListTemplate.h"
#include <string>
#include <ostream>

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

    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);

    void displayModuleInfo() override;

 private:
    ListTemplate<Faculty> faculty_;
};



