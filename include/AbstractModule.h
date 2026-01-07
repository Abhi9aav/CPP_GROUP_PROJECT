#pragma once

// Abstract base for all modules
class AbstractModule 
{
public:
    virtual void displayModuleInfo() = 0; 
    virtual ~AbstractModule() = default;
};