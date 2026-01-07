#ifndef ABSTRACTMODULE_H
#define ABSTRACTMODULE_H

#include <iostream>
using namespace std;

// Abstract base for all modules
class AbstractModule 
{
public:
    virtual void displayModuleInfo() = 0; 
    virtual ~AbstractModule() {}
};

#endif
