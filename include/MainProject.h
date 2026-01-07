#pragma once

#include "StudentModule.h"
#include "FacultyModule.h"
#include "DatabaseModule.h"


// MainProject inherits the three modules.

class MainProject
{
public:
    
    void displayModuleInfo();
    void run();  // main
    void saveAll();

private:
    StudentModule studentModule_;
    FacultyModule facultyModule_;
    DatabaseModule databaseModule_;

};


