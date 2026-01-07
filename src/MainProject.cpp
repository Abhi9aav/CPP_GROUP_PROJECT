#include "MainProject.h"
#include <iostream>
#include <limits>
using namespace std;

void MainProject::displayModuleInfo() 
{
    cout << "\n===== FULL STUDENT MANAGEMENT SYSTEM REPORT =====\n\n";
    cout << "(1) STUDENT MODULE:\n";
    StudentModule::displayModuleInfo();
    cout << "\n(2) FACULTY MODULE:\n";
    FacultyModule::displayModuleInfo();
    cout << "\n(3) DATABASE MODULE:\n";
    DatabaseModule::displayModuleInfo();
}

void MainProject::saveAll() 
{
    saveStudentsToFile("students.txt");
    saveFacultyToFile("faculty.txt");
}

void MainProject::run() 
{
    loadStudentsFromFile("students.txt");
    loadFacultyFromFile("faculty.txt");

    bool running = true;
    while (running) {
        cout << "\n===== STUDENT MANAGEMENT SYSTEM MENU =====\n";
        cout << "1. Add Student\n";
        cout << "2. Add Faculty\n";
        cout << "3. Show Students\n";
        cout << "4. Show Faculty\n";
        cout << "5. Remove Student by ID\n";
        cout << "6. Remove Faculty by ID\n";
        cout << "7. Connect to Database (simulate)\n";
        cout << "8. Save to files\n";
        cout << "9. Show Full Report\n";
        cout << "0. Exit\n";
        cout << "Choose option: ";

        int choice;
        if (!(cin >> choice)) 
        {
            cin.clear();
            string junk;
            getline(cin, junk);
            cout << "Invalid input. Try again.\n";
            continue;
        }

        switch (choice) 
        {
            case 1:
                StudentModule::addStudent();
                break;
            case 2:
                FacultyModule::addFaculty();
                break;
            case 3:
                StudentModule::displayModuleInfo();
                break;
            case 4:
                FacultyModule::displayModuleInfo();
                break;
            case 5: 
            {
                cout << "Enter student id to remove: ";
                int id; cin >> id;
                if (StudentModule::removeStudentById(id))
                    cout << "Student removed.\n";
                else
                    cout << "Student id not found.\n";
                break;
            }
            case 6: 
            {
                cout << "Enter faculty id to remove: ";
                int id; cin >> id;
                if (FacultyModule::removeFacultyById(id))
                    cout << "Faculty removed.\n";
                else
                    cout << "Faculty id not found.\n";
                break;
            }
            case 7:
                try 
                {
                    DatabaseModule::connect();
                } catch (const CustomException<string>& ex) 
                {
                    cout << "[CUSTOM EXCEPTION] " << ex.what() << "\n";
                }
                break;
            case 8:
                saveAll();
                break;
            case 9:
                displayModuleInfo();
                break;
            case 0:
                cout << "Saving before exit...\n";
                saveAll();
                running = false;
                break;
            default:
                cout << "Unknown option.\n";
        }
    }

    disconnect();
    cout << "Goodbye.\n";
}
