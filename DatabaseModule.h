#ifndef DATABASEMODULE_H
#define DATABASEMODULE_H

#include "AbstractModule.h"
#include "CustomException.h"
#include <string>
using namespace std;


class DatabaseModule : public AbstractModule 
{
 protected:
    bool m_connected = false;
 public:
    void connect();              
    void disconnect();
    bool isConnected() const { return m_connected; }

  
    void displayModuleInfo() override;
};

#endif

