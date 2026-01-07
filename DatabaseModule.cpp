#include "DatabaseModule.h"
#include <iostream>
#include <fstream>
using namespace std;

void DatabaseModule::connect() 
{
    ofstream ofs("db_test.tmp");

    if (!ofs) 
    {
        m_connected = false;
        throw CustomException<string>("Database connection failed: cannot write to current folder.");
    }

    ofs << "ok\n";
    ofs.close();

    // remove temp file (best effort)
    remove("db_test.tmp");
    m_connected = true;

    cout << "Database connected successfully.\n";
}

void DatabaseModule::disconnect() 
{
    if (m_connected) 
    {
        m_connected = false;
        cout << "Database disconnected.\n";
    }
}

void DatabaseModule::displayModuleInfo() 
{
    cout << "--- Database Module ---\n";
    cout << "Connection status: " << (m_connected ? "Connected" : "Not connected") << "\n";
}
