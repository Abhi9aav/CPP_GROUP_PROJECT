#include "FacultyModule.h"


#include <iostream>
#include <fstream>
#include <limits>

void FacultyModule::addFaculty() 
{
    std::cout << "Enter faculty id (int): ";
    int id{};

    if (!(std::cin >> id)) 
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid id input.\n";
        return;
    }

    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter faculty name: ";
    std::string name;
    std::getline(std::cin, name);

    // avoid duplicates
    for (const auto& faculty : faculty_.all()) 
    {
        if (faculty.id == id) 
        {
            std::cout << "Faculty with id " << id << " already exists. Skipping.\n";
            return;
        }
    }

    faculty_.add(Faculty{id, name});
    std::cout << "Faculty added: " << Faculty{id, name} << "\n";
}

bool FacultyModule::removeFacultyById(int id) 
{
    const auto& allFaculty = faculty_.all();

    for (std::size_t i = 0; i < allFaculty.size(); ++i) 
    {
        if (allFaculty[i].id == id) 
        {
            faculty_.removeAt(i);
            return true;
        }
    }
    return false;
}

const Faculty* FacultyModule::findById(int id) const
{
    for(const auto& faculty : faculty_.all())
    {
        if(faculty.id == id)
        {
            return &faculty;
        }
    }
    return nullptr;
}

std::vector<Faculty> FacultyModule::findFacultyByName(const std::string& keyword) const
{
    std::vector<Faculty> results;

    for(const auto& faculty : faculty_.all())
    {
        if(faculty.name.find(keyword) != std::string::npos)
        {
            results.push_back(faculty);
        }
    }
    return results;
}

bool FacultyModule::updateFacultyName(int id, const std::string& newName)
{
    for(auto& faculty : faculty_.allMutable())
    {
        if(faculty.id == id)
        {
            faculty.name = newName;
            return true;
        }
    }
    return false;
}

void FacultyModule::saveToFile(const std::string& filename) const 
{
    std::ofstream outFile(filename);
    if (!outFile) 
    {
        std::cout << "Failed to open faculty file for writing: " << filename << "\n";
        return;
    }

    for (const auto& faculty : faculty_.all()) 
    {
        outFile << faculty.id << "," << faculty.name << "\n";
    }

    std::cout << "Faculty saved to " << filename << "\n";
}

void FacultyModule::loadFromFile(const std::string& filename) 
{
    std::ifstream inFile(filename);
    if (!inFile) 
    {
        return;
    }
    
    std::string line;
    while (std::getline(inFile, line)) 
    {
        if (line.empty()) 
        {
            continue;
        }

        const auto commaPos = line.find(',');

        if (commaPos == std::string::npos) 
        {
            continue;
        }
        const int id = std::stoi(line.substr(0, commaPos));
        const std::string name = line.substr(commaPos + 1);
        faculty_.add(Faculty{id, name});
    }
}

void FacultyModule::displayModuleInfo() 
{
    std::cout << "--- Faculty Module ---\n";

    if (faculty_.size() == 0) 
    {
        std::cout << "(no faculty)\n";
        return;
    }

    for (const auto& faculty : faculty_.all())
    {
    std::cout << faculty << '\n';
    }

}

std::ostream& operator<<(std::ostream& os, const Faculty& faculty)
{
    os << faculty.id << " : " << faculty.name;
    return os;
}

