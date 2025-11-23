#include "FacultyModule.h"
#include <iostream>
#include <fstream>
#include <limits>
using namespace std;

void FacultyModule::addFaculty() 
{
    cout << "Enter faculty id (int): ";
    int id;
    if (!(cin >> id)) 
    {
        cin.clear();
        string junk; getline(cin, junk);
        cout << "Invalid id input.\n";
        return;
    }

    
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter faculty name: ";
    string name;
    getline(cin, name);

    // avoid duplicates
    for (const auto& f : facultyList.all()) 
    {
        if (f.id == id) {
            cout << "Faculty with id " << id << " already exists. Skipping.\n";
            return;
        }
    }

    Faculty f; 
    f.id = id; 
    f.name = name;
    facultyList.add(f);

    cout << "Faculty added: " << f << "\n";
}

bool FacultyModule::removeFacultyById(int id) 
{
    const auto& all = facultyList.all();
    for (size_t i = 0; i < all.size(); ++i) 
    {
        if (all[i].id == id) 
        {
            facultyList.removeAt(i);
            return true;
        }
    }
    return false;
}

Faculty* FacultyModule::findFacultyById(int id)
{
    (void)id; 
    return nullptr;
}

void FacultyModule::saveFacultyToFile(const string& filename) 
{
    ofstream ofs(filename.c_str());
    if (!ofs) {
        cout << "Failed to open faculty file for writing: " << filename << "\n";
        return;
    }

    for (const auto& f : facultyList.all()) 
    {
        ofs << f.id << "," << f.name << "\n";
    }

    ofs.close();
    cout << "Faculty saved to " << filename << "\n";
}

void FacultyModule::loadFacultyFromFile(const string& filename) 
{
    ifstream ifs(filename.c_str());
    if (!ifs) 
    {
        return;
    }
    
    string line;
    while (getline(ifs, line)) 
    {
        if (line.empty()) 
        {
            continue;
        }

        size_t comma = line.find(',');

        if (comma != string::npos) 
        {
            int id = stoi(line.substr(0, comma));
            string name = line.substr(comma + 1);

            Faculty f{ id, name };
            facultyList.add(f);
        }
    }

    ifs.close();
}

void FacultyModule::displayModuleInfo() 
{
    cout << "--- Faculty Module ---\n";

    if (facultyList.size() == 0) 
    {
        cout << "(no faculty)\n";
        return;
    }

    facultyList.show();
}
