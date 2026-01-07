#ifndef MAINPROJECT_H
#define MAINPROJECT_H

#include "StudentModule.h"
#include "FacultyModule.h"
#include "DatabaseModule.h"
using namespace std;

// MainProject inherits the three modules.

class MainProject : public StudentModule, public FacultyModule, public DatabaseModule
{
public:
    
    void displayModuleInfo() override;

    // main
    void run();

   
    void saveAll();
};

#endif
