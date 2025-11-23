#include "StudentModule.h"
#include <iostream>
#include <fstream>
#include <limits>
using namespace std;

void StudentModule::addStudent() 
{
    cout << "Enter student id (int): ";
    int id;

    if (!(cin >> id)) 
    {
        cin.clear();
        string junk; getline(cin, junk);
        cout << "Invalid id input.\n";
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter student name: ";
    string name;
    getline(cin, name);

    // avoid duplicates
    for (const auto& s : students.all()) 
    {
        if (s.id == id) 
        {
            cout << "Student with id " << id << " already exists.\n";
            return;
        }
    }

    Student s;
    s.id = id;
    s.name = name;

    students.add(s);
    cout << "Student added: " << s << "\n";
}

bool StudentModule::removeStudentById(int id) 
{
    const auto& all = students.all();
    for (size_t i = 0; i < all.size(); i++) 
    {
        if (all[i].id == id) 
        {
            students.removeAt(i);
            return true;
        }
    }
    return false;
}



void StudentModule::saveStudentsToFile(const string& filename)
 {
    ofstream ofs(filename.c_str());
    if (!ofs) {
        cout << "ERROR: cannot open student file.\n";
        return;
    }

    for (const auto& s : students.all()) 
    {
        ofs << s.id << "," << s.name << "\n";
    }
    ofs.close();

    cout << "Students saved to " << filename << "\n";
}

void StudentModule::loadStudentsFromFile(const string& filename) 
{
    ifstream ifs(filename.c_str());
    if (!ifs) return;

    string line;
    while (getline(ifs, line)) 
    {
        if (line.empty()) continue;

        size_t comma = line.find(',');
        if (comma != string::npos) 
        {
            int id = stoi(line.substr(0, comma));
            string name = line.substr(comma + 1);

            Student s{ id, name };
            students.add(s);
        }
    }

    ifs.close();
}

void StudentModule::displayModuleInfo() 
{
    cout << "--- Student Module ---\n";

    if (students.size() == 0) 
    {
        cout << "(no students)\n";
        return;
    }

    students.show();
}

